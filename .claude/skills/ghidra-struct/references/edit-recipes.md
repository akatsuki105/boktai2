# Safe struct-edit recipes (GhidraScript via run_script_inline)

Why scripts: the HTTP struct endpoints pack, rename, or wipe signatures (see
`http-api.md`). The Ghidra Java API offers edits that keep every other byte
where it is:

| Need | API | Keeps layout? |
|---|---|---|
| Put a typed field on undefined bytes | `Structure.replaceAtOffset(off, dt, len, name, comment)` | yes |
| Turn a defined field back into undefined bytes | `Structure.clearComponent(ordinal)` | yes (does **not** pack) |
| Add undefined bytes at the end | `Structure.growStructure(n)` | yes |
| Rename a field exactly | `DataTypeComponent.setFieldName(name)` | yes |
| Create a new struct | `new StructureDataType(CategoryPath, name, size, dtm)` + `dtm.addDataType(sd, DataTypeConflictHandler.DEFAULT_HANDLER)` | — |
| Retype a function local | `Variable.setDataType(dt, SourceType.USER_DEFINED)` | — |
| Delete a type | `dtm.remove(dt, monitor)` (retarget its users first) | — |

## Rules for every edit script

1. **Look types up by exact name** with `dtm.findDataTypes(name, list)`.
   Never hard-code a category path (`/u32` does not exist; it is
   `/gba/types/u32`, and some types live under `/mft/...`).
2. **Never name a helper `find`** — `FlatProgramAPI.find(String)` is final, so
   the script fails to compile. Use `ft`.
3. **Guard before mutating.** Abort if any type lookup failed or a size is not
   what the evidence says (e.g. `Particle` must be 40).
4. **Check sizes before and after inside the script** and print both. A size
   change on an existing struct means something went wrong.
5. **Be idempotent.** An exception can leave earlier statements committed.
   Before creating a type, reuse it if it already exists with the right size;
   after a failed run, read the current layout before re-running.
6. **Put the evidence in the field comment** (which function, which access).

## Template

```java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.util.*;

public class EditFoo extends GhidraScript {   // class name = file name; keep it unique
  DataTypeManager dtm;
  DataType ft(String name) {
    List<DataType> l = new ArrayList<>();
    dtm.findDataTypes(name, l);
    for (DataType d : l) if (d.getName().equals(name)) return d;
    return null;
  }
  public void run() throws Exception {
    dtm = currentProgram.getDataTypeManager();
    DataType u8 = ft("u8"), u16 = ft("u16"), particle = ft("Particle"), target = ft("Foo");
    if (u8 == null || u16 == null || particle == null || !(target instanceof Structure)) {
      println("ABORT: type not found"); return;
    }
    if (particle.getLength() != 40) { println("ABORT: size mismatch"); return; }

    // optional: new element type, reused if a previous run already created it
    DataType elem = ft("q_FooElem");
    if (elem == null) {
      StructureDataType sd = new StructureDataType(new CategoryPath("/entity.h"), "q_FooElem", 44, dtm);
      sd.replaceAtOffset(0x00, particle, 40, "base", "passed as Particle* to FUN_0822d9f0");
      sd.replaceAtOffset(0x28, u8, 1, "q_active", "tested != 0 in FUN_xxxx");
      elem = dtm.addDataType(sd, DataTypeConflictHandler.DEFAULT_HANDLER);
    }

    Structure s = (Structure) target;
    int before = s.getLength();
    s.replaceAtOffset(0x70, particle, 40, "ptcl", "passed as Particle* to FUN_0822d9f0");
    s.replaceAtOffset(0xA0, new ArrayDataType(elem, 8, 44), 352, "elems", "stride 0x2C in FUN_xxxx");
    println("Foo size " + before + " -> " + s.getLength());
  }
}
```

## Replacing a defined placeholder (e.g. `u8 aUnk_14[2]` → two fields)

Find the component's ordinal, `clearComponent(ordinal)`, then `replaceAtOffset`
the new fields. The bytes in between become undefined; nothing shifts.

## Growing a type that is embedded elsewhere

Changing a struct's size changes every struct that embeds it. Before growing:

1. List every composite that embeds the type (or an array of it) —
   `scripts/TypeUsers.java` prints them with offsets.
2. For each embedding, check that the bytes right after it are undefined
   (`Structure.getComponentContaining(off)` on each byte). If a placeholder
   such as `u8 aUnk_5c[4]` sits there, `clearComponent` it first.
3. `growStructure(n)`, add the new field, then confirm every embedding
   container kept its size.

A placeholder that sits right after the embedded type in several unrelated
containers is itself evidence that the type is larger than currently defined.

## Merging a duplicate type (T2 into T)

1. Grow/fix `T` first so the sizes match.
2. In every composite, `replaceAtOffset` components typed `T2` (or `T2[n]`
   → `new ArrayDataType(T, n, len)`), keeping name and comment.
3. Retype function locals/parameters that use `T2` (`Variable.setDataType`).
4. Re-scan for remaining users, then `dtm.remove(T2, monitor)`.

## Script runner caveats

`run_script_inline` writes the code to `~/ghidra_scripts/<ClassName>.java` and
compiles it with every other script there. A script that once failed to
compile keeps being reported ("with 1 file failing in previous build(s)") in
later outputs — Ghidra caches it, and it stays even after the files are
deleted, so just ignore that line (the `run_ghidra_script.ts` runner strips
it). The server deletes scripts that ran successfully but leaves failed ones
behind as `<ClassName>.java` and `<ClassName>.java_failed`; delete the ones you
generated so the directory does not fill up.

The file is rewritten on every run, so an existing script in `~/ghidra_scripts`
with the same class name is silently overwritten. Give one-off scripts
distinctive class names (e.g. `FreezeEffectEdit1`), never generic ones such as
`Scan` or `Fix`. The `run_ghidra_script.ts` runner already strips the stale
"failing in previous build(s)" note from its output.
