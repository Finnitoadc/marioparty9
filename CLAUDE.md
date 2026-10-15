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
  Se amplía con `python tools/mp9/cand_extend.py <min_módulos> <max_instr>` (tras un `ninja`
  completo): agrega grupos nuevos sin tocar los existentes ni repetir funciones ya agrupadas.
  Hoy incluye grupos de ≥3 módulos y ≤120 instrucciones.
- `tools/mp9/data/skip.txt` — grupos que se intentaron y no salieron, con el motivo.
- `tools/mp9/data/nonmatching.txt` — grupos registrados como `NonMatching`.
- `tools/mp9/wip/` — intentos sin terminar (no se compilan).

## Flujo para funciones compartidas

```sh
python tools/mp9/progress.py          # % de funciones/bytes REL coincidentes
python tools/mp9/queue.py 30          # próximos grupos pendientes (más copias primero)
python tools/mp9/show.py <hash8>      # asm completo del grupo (saltos como .L+N)
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
  En un `srwi.` de un bit, escribir el ternario con la condición negada (`!o->bit ? a : b`).
- **Punteros a miembro**: `addi r12, ...; bl __ptmf_scall; nop` (y `bl __ptmf_test`) salen de
  `typedef void (Obj::*Func)(); if (self->func) (self->*(self->func))();` (ver `g_28d28ab6.cpp`).
  `return !self->func;` da el test solo.
- **`subf r0, r0, r0` (x - x que no se simplifica)**: es un `clear()` tipo vector inlineado:
  `char* Begin(){return data;} char* End(){return data+count;}
  void Erase(char* f, char* l){count -= l - f;}` y `Erase(Begin(), End())` (ver `g_258c18a0.cpp`).
  Los `beq` repetidos antes son `if (b != 0)` anidados (usar un puntero local `Buffer* b`).
- **Todas las cargas y luego todos los stores** (registros en orden inverso):
  - pasar el struct por valor: `void f(S* dst, S src) { *dst = src; }` (copias de 16/48 bytes);
  - o recibirlo por `const S&` (`g_620c69e4.cpp`);
  - o meter las locales en un `static inline` que reciba `const S&` (`g_032f8a2f.cpp`).
- `const Obj* self` cambia el scheduling (sube un `lfs` por encima del `stwu`).
- Declarar las locales en orden inverso cambia qué registro recibe cada una.
- Devolver un struct de 12 bytes por valor (puntero oculto en r3): `return Vec(a, b, c);`.
- `andi. 0xfd` + `ori 2` sale de `p[0xBB] &= 0xFD; p[0xBB] |= 2;`.
- **Paired singles** (`psq_l`, `ps_*`): son rutinas asm del SDK (PSVECAdd, PSVECDotProduct…).
  Se escriben como `extern "C" asm void f(...) { nofralloc ... blr }` copiando el asm
  (ver `g_007f666f.cpp`).
- Los nombres de la DOL pueden cambiar (p. ej. `fn_8020BDC8` → `__ptmf_test`). `cand2.json`
  tiene los nombres viejos y `trytext.py` los traduce con su tabla `ALIAS`. No llamar a
  funciones por el nombre viejo en el código.
- **Solo rutinas hoja del SDK en asm** (PSVEC*/PSMTX*: solo instrucciones `ps_*`/`psq_*`, sin
  comparaciones ni saltos de lógica). Si la función tiene prólogo, `bl`, `fcmpo`/saltos o mezcla
  `fabs`/`fmuls` con `ps_*`, es C con paired singles inlineados: escribirla entera en asm no
  cuenta como decompilada (va a `wip/`).
- `fn_8020B514` es `operator new`: `void* p = fn_8020B514(size); if (p) p = ctor(p);`
  (ver `g_1f25f6da.cpp`). `fn_8020BCD0(arr, dtor, size, n)` es `__destroy_arr`; pasar el
  destructor como `(void*)shared_g_XXXX`.
- `delete p` sobre un objeto con `virtual ~T()` da la vcall del slot 0x8 con `li r4, 1`; la
  llamada explícita `p->~T()` da `li r4, -1`. No agregar un `if (p)` propio: `delete` ya
  comprueba null y saldría un `beq` duplicado.
- Puntero local a un miembro + método inline (`Ptr* p = &self->m; if (p != 0) p->Release();`)
  da `addic. r3, rX, off` y las cargas a través de r3 (ver `g_69c2e268.cpp`).
- Copia campo a campo con cada carga seguida de su store: origen por puntero **no const**
  (el compilador supone aliasing). Con `const` o asignación de struct agrupa las cargas.
- Tres cargas float con registros invertidos: declarar `float z; float y; float x;` y asignar
  después (ver `g_5fb84994.cpp`).
- Si un bucle sale con contador/offset en registros cambiados, moverlo a un método inline del
  contenedor (ver `g_67f78c2c.cpp`). Iteradores de plantilla: recibirlos por `It&`.
- `std::min/max` sobre `const float&` (`return a < b ? ...`) reproduce las cadenas
  `fcmpo`/selección de puntero (`g_585af956.cpp`).
- Comparación de punteros como bool: `cur >= start` da `orc`/`srwi 31`; `cur < start` da
  `xor`/`cntlzw`.
- Campos `bool`: `!b` da `cntlzw`+`srwi 5`; con `unsigned char` sale `extrwi`.
- Strings con SSO: bit `isLong:1` en la palabra 0, longitud corta `*(unsigned char*)this & 0x7F`,
  larga en +4, puntero en +8; `char` es unsigned en este compilador (usar `signed char` si hay
  `extsb`). Bucle de búsqueda: `int i` contra `unsigned n` (`g_35badb40.cpp`).
- `li rN, 0` en un registro guardado antes de un `if` y un `stw rN` dentro: era un bucle de una
  iteración sobre un array de 1 elemento (`for (int i = 0; i < 1; i++) { ... a[i] = 0; }`,
  ver `g_67dcf62b.cpp`).
- `if (p) { delete p; p = 0; }` da el doble `beq` antes de la vcall del destructor
  (`g_1f1ae3a7.cpp`).
- Destructor inline de un miembro anidado: escribir `if (&p->b != 0) { if (p->b.owned) ... }`
  contra el padre, no con un puntero local, para obtener `addic. r0` (`g_2477a1f4.cpp`).
- Comparación de strings estilo MSL: datos y tamaño en un solo if/else sobre `isLong`, y una
  cadena `return -1 / 0 / 1` en vez de asignar a `r`. Las locales con `&` reciben slots de
  pila en orden de declaración.
- Un `long long` como primer miembro hace que la copia guarde la segunda palabra primero
  (`lwz a; lwz b; stw b; stw a`).
- Sin resolver todavía: diferencias puras de scheduling/asignación de registros, en especial
  el orden `slwi`/`subf` en `clear()` de vectores de elementos virtuales y las copias de
  globales con `lwzu` (ver `skip.txt`).

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
- **Con agentes en paralelo** (en el mismo checkout): darle a cada agente una lista de hashes
  distinta, de tu rango. Los agentes solo crean `src/REL/shared/g_<hash>.cpp` (o lo mueven a
  `tools/mp9/wip/` si no sale) y prueban con `trytext.py`, que usa archivos temporales por
  hash, así que no chocan entre sí. **No** deben correr `ninja`, `configure.py`, `sync.py` ni
  git: eso lo hace una sola sesión al final (`sync.py` → `ninja` → commit).
- No hacer commit de `build/`, `orig/` ni nada del juego.
