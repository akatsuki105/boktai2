import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

// MergeSplitTail <parentAddr> <fakeAddr> <endAddr>
// 偽の関数 (親のエピローグを Ghidra が切り出したもの) を親に統合する。
// docs/for-ai-agent/ghidra-split-functions.md 参照。
public class MergeSplitTail extends GhidraScript {
  public void run() throws Exception {
    String[] args = getScriptArgs();
    if (args.length != 3) { println("ABORT: 引数は <parent> <fake> <end>"); return; }
    AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
    FunctionManager fm = currentProgram.getFunctionManager();
    ReferenceManager rm = currentProgram.getReferenceManager();
    Address aParent = sp.getAddress(Long.parseLong(args[0], 16));
    Address aFake = sp.getAddress(Long.parseLong(args[1], 16));
    Address aEnd = sp.getAddress(Long.parseLong(args[2], 16));

    Function parent = fm.getFunctionAt(aParent);
    if (parent == null) { println("ABORT: 親の関数が無い " + aParent); return; }
    if (parent.getBody().getMaxAddress().compareTo(aFake) >= 0) {
      println("ABORT: 親の body が既に " + parent.getBody().getMaxAddress() + " まで届いている"); return;
    }
    Function fake = fm.getFunctionAt(aFake);
    if (fake == null) { println("ABORT: 偽の関数が無い " + aFake); return; }
    if (fake.getBody().getMaxAddress().compareTo(aEnd) > 0) {
      println("ABORT: 偽の関数が end を超えている " + fake.getBody()); return;
    }
    Function after = fm.getFunctionContaining(aEnd.add(1));
    if (after != null) { println("ABORT: end の直後が " + after.getName() + " の中"); return; }

    // 1. bl による長距離分岐が CALL 扱いなので JUMP に直す (先にやらないと削除時に再生成される)
    int fixed = 0;
    for (Reference r : rm.getReferencesTo(aFake)) {
      if (r.getReferenceType() != RefType.UNCONDITIONAL_CALL) continue;
      Address from = r.getFromAddress();
      if (from.compareTo(aParent) < 0 || from.compareTo(aEnd) > 0) { println("ABORT: 想定外の呼び出し元 " + from); return; }
      int op = r.getOperandIndex();
      rm.delete(r);
      rm.addMemoryReference(from, aFake, RefType.UNCONDITIONAL_JUMP, SourceType.USER_DEFINED, op);
      fixed++;
    }
    println("参照を JUMP に変更: " + fixed + " 件");

    // 2. 削除
    String fakeName = fake.getName();
    if (!fm.removeFunction(aFake)) { println("ABORT: removeFunction 失敗"); return; }
    println("削除: " + fakeName);

    // 3. 空きを確認して body に追加
    for (Address a = aFake; a.compareTo(aEnd) <= 0; a = a.add(2)) {
      Function o = fm.getFunctionContaining(a);
      if (o != null && !o.getEntryPoint().equals(aParent)) { println("ABORT: " + a + " が " + o.getName() + " に属している"); return; }
    }
    AddressSet body = new AddressSet(parent.getBody());
    Address oldMax = body.getMaxAddress();
    body.addRange(aFake, aEnd);
    parent.setBody(body);
    println(parent.getName() + " body: max " + oldMax + " -> " + parent.getBody().getMaxAddress());
  }
}
