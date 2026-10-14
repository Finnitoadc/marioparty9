# Mario Party 9 (SSQE01) — guía para trabajar en el decomp

Decompilación byte a byte de Mario Party 9 (Wii, NTSC-U). El DOL y los 115 REL deben quedar
**idénticos** al original. Regla de oro: **no se sube nada si `ninja` no termina con
"116 files OK"**.

## Puesta en marcha

1. Extraer tu propia copia del juego:
   - `main.dol` → `orig/SSQE01/sys/main.dol`
   - los REL de `files/modules/*.rel.lz` → descomprimirlos con
     `build/tools/dtk.exe nlzss decompress` y dejarlos como `orig/SSQE01/files/modules/<nombre>.rel`
   - los archivos del juego **nunca** se suben al repo (`.gitignore` ya los excluye).
2. `pip install ninja` y luego `python configure.py && ninja`. dtk y los compiladores se
   descargan solos en `build/`. Un build desde cero tarda ~2 min y ocupa ~1.5 GB.
3. Para verificar a mano: `build/tools/dtk.exe shasum -c config/SSQE01/build.sha1`.
4. objdiff (opcional) se instala aparte; `tools/tune_shared.py` tiene su ruta hardcodeada.

En Windows la shell es Git Bash: las barras invertidas se pierden en heredocs; usar `/`.

## Cómo está organizado

- `config/SSQE01/` — splits y símbolos del DOL; `config/SSQE01/rels/<módulo>/` los de cada REL.
- `src/REL/strap/`, `src/REL/Introduction/` — código propio de esos módulos.
- `src/REL/shared/g_<hash8>.cpp` — **funciones compartidas**: la misma función copiada en
  muchos REL (librerías inline/plantillas). Un `.cpp` cubre todas las copias: se compila una
  vez por módulo. Es la vía con más rendimiento (~80% de las funciones REL son copias).
- `tools/mp9/data/cand2.json` — grupos candidatos (asm normalizado + dónde está cada copia).
- `tools/mp9/data/skip.txt` — grupos que se intentaron y no salieron, con el motivo.
- `tools/mp9/data/nonmatching.txt` — grupos registrados como `NonMatching`.
- `tools/mp9/wip/` — intentos sin terminar (no se compilan).

## Flujo para funciones compartidas

```sh
python tools/mp9/progress.py          # % de funciones/bytes REL coincidentes
python tools/mp9/queue.py 30          # próximos grupos pendientes (más copias primero)
# escribir src/REL/shared/g_<hash8>.cpp con la función extern "C" shared_g_<hash8>
python tools/mp9/trytext.py <hash8>   # compila y compara con el asm del grupo
python tools/mp9/sync.py              # registra todo lo de src/REL/shared (idempotente)
python configure.py && ninja          # tiene que decir 116 files OK
```

- `trytext.py` imprime `MATCH 100%` o un diff lado a lado. Compara también el destino de los
  saltos (`.L+N` = índice de instrucción relativo): un salto que va a otro sitio rompe el
  binario aunque las instrucciones sean iguales.
- `MATCH 100% (+blr)`: dtk separó el `blr` que el compilador deja tras una llamada final;
  `sync.py` lo incluye en la unidad automáticamente.
- Si un grupo no sale: mover el `.cpp` a `tools/mp9/wip/` y anotar el hash y el motivo en
  `skip.txt`. Para deshacer un grupo ya registrado: `python tools/mp9/unregister.py <hash8>`.
- Mejor trabajar por lotes: escribir 20–40 `.cpp`, probarlos con `trytext.py`, quitar los que
  fallan, `sync.py` y un solo `ninja` al final.

## Trucos del compilador (MWCC, `-O4,p`)

- **Vtables sin inventar clases**: declarar structs con métodos `virtual` que nunca se
  definen. La entrada n de la vtable está en `8 + 4*n` (el slot 0 es `lwz r12, 0x8(r12)`).
  Rellenar los huecos con `virtual void vXXX();`.
- **El vptr va después de los campos declarados antes del primer `virtual`**:
  `struct O { int pad[5]; virtual void f(); };` pone el vptr en `0x14`
  (`lwz r12, 0x14(r3)`). Sin campos previos queda en 0.
- Miembro con vtable propia en `self+0x238`: declararlo como miembro de ese tipo
  (`lwzu r12, 0x238(r3)`).
- Destructores: `if (self != 0) { ...; if (del > 0) fn_8020B5FC(self); } return self;`.
  `fn_8020B5FC` es `operator delete`. Un `if (&self->miembro != 0)` genera el `addic.` que se
  ve en el original; si el miembro está en offset 0 no se genera.
- `cmplw`/`clrlwi` ⇒ tipos `unsigned`. `lbz` + `cmpwi` ⇒ `unsigned char`.
- Si el original hace `clrlwi r5, r5, 16` justo antes de pasar un argumento, el parámetro es
  `int` y se castea al llamar: `f(a, (unsigned short)b)`.
- Parámetros que se reenvían sin tocar (p. ej. `r4` sigue vivo en la llamada) cuentan: si un
  registro aparece "corrido" (usa `r5` en vez de `r4`), falta un parámetro.
- Copia de struct de 12 bytes `lwz r4,0; lwz r0,4; stw r0,4; stw r4,0; lwz r0,8; stw r0,8`:
  sale con locales `int` explícitos guardando `y` antes que `x` (ver `g_e81a5b7e.cpp`).
- Escribir los `return` tempranos primero; `a || b` vs `!a && b` cambia destinos de salto.
- Sin resolver todavía: `x - x` que el compilador no simplifica, diferencias puras de
  scheduling/asignación de registros (ver `skip.txt`).

## Trabajar entre varios

- Cada uno en su rama (`git checkout -b <nombre>/<tema>`); fusionar seguido con la rama
  principal (`decomp`).
- **Repartirse la cola para no hacer el mismo grupo**: una persona toma los hashes que empiezan
  por `0`–`7` y la otra `8`–`f` (o acordar módulos concretos para código no compartido).
- Solo hace falta subir los `.cpp` nuevos + lo que genera `sync.py`. Si al fusionar hay
  conflictos en `config/SSQE01/rels/**` o `configure.py`, **no los resuelvas a mano**:

  ```sh
  git checkout --theirs config/SSQE01/rels configure.py   # quedarse con un lado entero
  python tools/mp9/sync.py                                 # vuelve a registrar los grupos del otro lado
  python configure.py && ninja                             # 116 files OK
  git add -A && git commit
  ```

  Ojo: `--theirs configure.py` descarta tus cambios de ese archivo. Si el conflicto no es solo
  en las líneas `Object(..., "REL/shared/...")`, resolver `configure.py` a mano y usar
  `--theirs` solo para `config/SSQE01/rels`.
  (Para los `.cpp` de `src/REL/shared/` no hay conflictos: cada grupo es un archivo distinto.)
- Anotar en `skip.txt` lo que no salió, así el otro no repite el intento.
- No hacer commit de `build/`, `orig/` ni nada del juego.
