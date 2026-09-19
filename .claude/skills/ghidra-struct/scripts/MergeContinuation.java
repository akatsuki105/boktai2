import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

// MergeContinuation <parent> <fake> [fake...]
// プロローグを持たない「続き」の関数群を親に吸収する。body は和集合を取るので
// プール定数のギャップはそのまま保たれる。docs/for-ai-agent/ghidra-split-functions.md 参照。
public class MergeContinuation extends GhidraScript {
  public void run() throws Exception {
    String[] args = getScriptArgs();
    if (args.length < 2) { println("ABORT: 引数は <parent> <fake>..."); return; }
    AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
    FunctionManager fm = currentProgram.getFunctionManager();
    ReferenceManager rm = currentProgram.getReferenceManager();

    Address aParent = sp.getAddress(Long.parseLong(args[0], 16));
    Function parent = fm.getFunctionAt(aParent);
    if (parent == null) { println("ABORT: 親の関数が無い " + aParent); return; }

    List<Address> fakes = new ArrayList<>();
    AddressSet merged = new AddressSet(parent.getBody());
    Address maxEnd = parent.getBody().getMaxAddress();
    for (int i = 1; i < args.length; i++) {
      Address a = sp.getAddress(Long.parseLong(args[i], 16));
      Function f = fm.getFunctionAt(a);
      if (f == null) { println("ABORT: 関数が無い " + a); return; }
      if (a.compareTo(parent.getBody().getMaxAddress()) <= 0) { println("ABORT: " + a + " が親の body 内"); return; }
      fakes.add(a);
      merged.add(f.getBody());
      if (f.getBody().getMaxAddress().compareTo(maxEnd) > 0) maxEnd = f.getBody().getMaxAddress();
      println("吸収対象: " + f.getName() + " " + f.getBody());
    }
    Function after = fm.getFunctionContaining(maxEnd.add(1));
    if (after != null && !after.getEntryPoint().equals(aParent)) { println("ABORT: 直後が " + after.getName() + " の中"); return; }

    // 1. bl による長距離分岐が CALL 扱いなので JUMP に直す (先にやらないと削除時に再生成される)
    int fixed = 0;
    for (Address a : fakes) {
      for (Reference r : rm.getReferencesTo(a)) {
        if (r.getReferenceType() != RefType.UNCONDITIONAL_CALL) continue;
        Address from = r.getFromAddress();
        if (from.compareTo(aParent) < 0 || from.compareTo(maxEnd) > 0) { println("ABORT: 想定外の呼び出し元 " + from + " -> " + a); return; }
        int op = r.getOperandIndex();
        rm.delete(r);
        rm.addMemoryReference(from, a, RefType.UNCONDITIONAL_JUMP, SourceType.USER_DEFINED, op);
        fixed++;
      }
    }
    println("参照を JUMP に変更: " + fixed + " 件");

    // 2. 削除
    for (Address a : fakes) {
      String n = fm.getFunctionAt(a).getName();
      if (!fm.removeFunction(a)) { println("ABORT: removeFunction 失敗 " + a); return; }
      println("削除: " + n);
    }

    // 3. 親以外の関数が範囲に残っていないか確認して body を差し替え
    AddressIterator it = merged.getAddresses(true);
    while (it.hasNext()) {
      Address a = it.next();
      Function o = fm.getFunctionContaining(a);
      if (o != null && !o.getEntryPoint().equals(aParent)) { println("ABORT: " + a + " が " + o.getName() + " に属している"); return; }
    }
    Address oldMax = parent.getBody().getMaxAddress();
    parent.setBody(merged);
    println(parent.getName() + " body: max " + oldMax + " -> " + parent.getBody().getMaxAddress()
      + " ranges=" + parent.getBody().getNumAddressRanges());
  }
}
