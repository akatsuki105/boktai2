import { get, post } from "./http.ts";

const toHexAddr = (addr: number): string => `0x${addr.toString(16).toUpperCase().padStart(8, "0")}`;

export type FunctionInfo = {
  name: string;
  entry: number; // 関数の先頭アドレス
  signature: string;
};

// addr を含む関数の情報を返す (get_function_by_address)。addr が関数の途中を指していても、その関数を返す。
// addr を含む関数がなければ例外を投げる。
export const getFunctionByAddress = async (addr: number, timeoutSec: number = 60): Promise<FunctionInfo> => {
  const text = await get("get_function_by_address", { address: toHexAddr(addr) }, timeoutSec);
  const name = text.match(/^Function: (\S+)/m)?.[1];
  const entry = text.match(/^Entry: ([0-9A-Fa-f]+)/m)?.[1];
  const signature = text.match(/^Signature: (.*)$/m)?.[1];
  if (!name || !entry) {
    throw new Error(`get_function_by_address: ${toHexAddr(addr)} に関数がありません: ${text.trim()}`);
  }
  return { name, entry: parseInt(entry, 16), signature: signature ?? "" };
};

// addr を含む関数をリネームする (rename_function_by_address)。サーバーの応答メッセージを返す。
// addr が関数の途中を指していてもその関数がリネームされるので、必要なら先に getFunctionByAddress で先頭か確かめること。
export const renameFunctionByAddress = async (addr: number, newName: string, timeoutSec: number = 60): Promise<string> => {
  const text = await post("rename_function_by_address", { function_address: toHexAddr(addr), new_name: newName }, timeoutSec);
  let json: Record<string, unknown>;
  try {
    json = JSON.parse(text);
  } catch {
    throw new Error(`rename_function_by_address: JSON ではない応答が返りました: ${text.trim()}`);
  }
  if (json.status !== "success") {
    throw new Error(`rename_function_by_address: リネームに失敗しました: ${text.trim()}`);
  }
  return String(json.message ?? "");
};

// 逆アセンブルの1命令。operands は "r1,[0x08013b98]" のような Ghidra の表記のまま。
export type Instruction = { addr: number; mnemonic: string; operands: string };

// addr にある関数を Ghidra で逆アセンブルし、命令の配列を返す (disassemble_function)。
export const disassembleFunction = async (addr: number, timeoutSec: number = 60): Promise<Instruction[]> => {
  const text = await get("disassemble_function", { address: toHexAddr(addr) }, timeoutSec);
  const insns: Instruction[] = [];
  for (const line of text.split("\n")) {
    const m = line.match(/^([0-9A-Fa-f]{8}):\s+(\S+)\s*(.*?)\s*$/);
    if (m) insns.push({ addr: parseInt(m[1], 16), mnemonic: m[2], operands: m[3] });
  }
  if (insns.length === 0) {
    throw new Error(`disassemble_function: ${toHexAddr(addr)} を逆アセンブルできません: ${text.trim()}`);
  }
  return insns;
};

// addr にある関数を Ghidra でデコンパイルし、C コードを返す。
// 大きい関数だと時間がかかるので、タイムアウトは長めにしておく。
export const decompileFunction = async (addr: number, timeoutSec: number = 60): Promise<string> => {
  return await get("decompile_function", { address: `0x${addr.toString(16).toUpperCase()}` }, timeoutSec);
};

// get_function_pcode の応答 (JSON) の形
export type Varnode = { space: string; offset: string; size: number };
export type PcodeOp = { mnemonic: string; seq: { address: string }; inputs: Varnode[]; output?: Varnode };
export type BasicBlock = { start: { address: string }; stop: { address: string }; pcodes: PcodeOp[] };
export type PcodeResponse = { name: string; address: string; basic_blocks: BasicBlock[]; high_pcodes?: PcodeOp[] };

// addr にある関数の P-code を取得し、応答の JSON 文字列をそのまま返す (PcodeResponse として解析できる)。
// granularity は 'basic'(基本ブロックのみ) または 'high'(HighFunction の op 列 high_pcodes も付く)。
export const getFunctionPcode = async (addr: number, granularity: "basic" | "high" = "basic", timeoutSec: number = 60): Promise<string> => {
  return await get("get_function_pcode", { function_address: `0x${addr.toString(16).toUpperCase()}`, granularity }, timeoutSec);
};
