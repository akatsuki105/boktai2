import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.util.*;

// 使い方 (run_ghidra_script.ts 経由): StructCandidates <サイズ|-> [先頭の型名]
//
// 新しい構造体を作る前に、既存の構造体でないかを確認するための候補一覧を出す:
//   - 全体サイズが一致する構造体 ("-" でサイズ条件を外す)
//   - 先頭フィールドが指定した型の構造体 (既知の型を基底にした struct { Base base; ... } の形)
// 各行にどちらの条件で一致したかと、先頭のいくつかのフィールドを表示する。
public class StructCandidates extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    if (a.length < 1) { println("usage: StructCandidates <size|-> [headType]"); return; }
    int size = a[0].equals("-") ? -1 : Integer.decode(a[0]);
    String head = a.length >= 2 ? a[1] : null;

    List<String> lines = new ArrayList<>();
    Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
    while (it.hasNext()) {
      DataType dt = it.next();
      if (!(dt instanceof Structure)) continue;
      Structure s = (Structure) dt;
      DataTypeComponent c0 = s.getNumDefinedComponents() > 0 ? s.getDefinedComponents()[0] : null;
      boolean bySize = size >= 0 && s.getLength() == size;
      boolean byHead = head != null && c0 != null && c0.getOffset() == 0 && c0.getDataType().getName().equals(head);
      if (!bySize && !byHead) continue;
      StringBuilder sb = new StringBuilder();
      sb.append(bySize ? "[size]" : "      ").append(byHead ? "[head] " : "       ");
      sb.append(String.format("%-40s size=%-5d fields=%d  ", s.getPathName(), s.getLength(), s.getNumDefinedComponents()));
      int shown = 0;
      for (DataTypeComponent c : s.getDefinedComponents()) {
        if (shown++ == 4) { sb.append(" ..."); break; }
        sb.append(String.format(" 0x%X:%s %s;", c.getOffset(), c.getDataType().getName(), c.getFieldName()));
      }
      lines.add(sb.toString());
    }
    Collections.sort(lines);
    println(String.join("\n", lines) + "\n\n" + lines.size() + " candidate(s)");
  }
}
