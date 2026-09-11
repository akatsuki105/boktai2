import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import java.util.*;

// 使い方 (run_ghidra_script.ts 経由): TypeUsers <型名> [直後に見るバイト数=4]
//
// 型のレイアウトやサイズを変える前に、影響範囲をすべて列挙する:
//   STRUCT  その型(またはその配列)を値として埋め込んでいる構造体と、埋め込みの直後のバイトの中身 ("." は未定義)
//   FUNC    戻り値・引数・ローカル変数でその型を使っている関数 (ポインタ・配列要素経由も含む)
//   DATA    その型が付いているグローバル変数
public class TypeUsers extends GhidraScript {
  String target;

  boolean refers(DataType dt) {
    if (dt == null) return false;
    if (dt instanceof Pointer) return refers(((Pointer) dt).getDataType());
    if (dt instanceof Array) return refers(((Array) dt).getDataType());
    return dt.getName().equals(target);
  }

  boolean embeds(DataType dt) {
    if (dt instanceof Array) return embeds(((Array) dt).getDataType());
    return dt.getName().equals(target);
  }

  public void run() throws Exception {
    String[] a = getScriptArgs();
    if (a.length < 1) { println("usage: TypeUsers <TypeName> [bytesAfter]"); return; }
    target = a[0];
    int after = a.length >= 2 ? Integer.decode(a[1]) : 4;
    StringBuilder sb = new StringBuilder();
    int nStruct = 0, nFunc = 0, nData = 0;

    Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
    while (it.hasNext()) {
      DataType dt = it.next();
      if (!(dt instanceof Composite)) continue;
      Composite comp = (Composite) dt;
      for (DataTypeComponent c : comp.getDefinedComponents()) {
        if (!embeds(c.getDataType())) continue;
        nStruct++;
        sb.append(String.format("STRUCT %s size=%d off=0x%X len=%d type=%s name=%s", comp.getPathName(),
            comp.getLength(), c.getOffset(), c.getLength(), c.getDataType().getName(), c.getFieldName()));
        if (comp instanceof Structure && after > 0) {
          Structure s = (Structure) comp;
          int end = c.getOffset() + c.getLength();
          int lastOff = -1;
          sb.append("  after:");
          for (int o = end; o < end + after; o++) {
            if (o >= s.getLength()) { sb.append(" [end]"); break; }
            DataTypeComponent n = s.getComponentContaining(o);
            if (n == null || n.getDataType() == DataType.DEFAULT) { sb.append(" ."); continue; }
            if (n.getOffset() == lastOff) continue;
            lastOff = n.getOffset();
            sb.append(String.format(" [0x%X %s %s]", n.getOffset(), n.getDataType().getName(), n.getFieldName()));
          }
        }
        sb.append("\n");
      }
    }

    for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
      boolean hit = refers(f.getReturnType());
      for (Parameter p : f.getParameters()) if (refers(p.getDataType())) hit = true;
      for (Variable v : f.getLocalVariables()) if (refers(v.getDataType())) hit = true;
      if (hit) {
        nFunc++;
        sb.append("FUNC   ").append(f.getEntryPoint()).append("  ").append(f.getSignature().getPrototypeString()).append("\n");
      }
    }

    DataIterator di = currentProgram.getListing().getDefinedData(true);
    while (di.hasNext()) {
      Data d = di.next();
      if (refers(d.getDataType())) {
        nData++;
        sb.append("DATA   ").append(d.getAddress()).append("  ").append(d.getDataType().getName())
          .append("  ").append(d.getLabel()).append("\n");
      }
    }

    sb.append(String.format("\n%s: %d struct embeddings, %d functions, %d globals\n", target, nStruct, nFunc, nData));
    println(sb.toString());
  }
}
