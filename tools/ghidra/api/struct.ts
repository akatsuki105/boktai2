import { get, post } from "./http.ts";

export type StructField = { offset: number; size: number; type: string; name: string };
export type StructLayout = { size: number; fields: StructField[] };

// 構造体のサイズとフィールドの一覧を返す (get_struct_layout)。構造体が見つからなければ例外を投げる。
// ビットフィールドは同じオフセットに複数並ぶ。名前のないフィールドは name が空文字列になる。
export const getStructLayout = async (structName: string, timeoutSec: number = 60): Promise<StructLayout> => {
  const text = await get("get_struct_layout", { struct_name: structName }, timeoutSec);
  const size = text.match(/^Size: (\d+)/m)?.[1];
  if (!size) {
    throw new Error(`get_struct_layout: 構造体 '${structName}' のレイアウトを取得できません: ${text.trim()}`);
  }
  const fields: StructField[] = [];
  for (const line of text.split("\n")) {
    const m = line.match(/^\s*(\d+)\s*\|\s*(\d+)\s*\|\s*(.+?)\s*\|\s*(\S*)\s*$/);
    if (m) fields.push({ offset: Number(m[1]), size: Number(m[2]), type: m[3], name: m[4] });
  }
  return { size: Number(size), fields };
};

// 構造体のフィールドの名前や型を変える (modify_struct_field)。サーバーの応答をそのまま返す。
// field はフィールド名、名前のないフィールドなら "offset:N" (N は10進数のオフセット)。
// 応答の形式が決まっていないので成否は判定しない。結果は getStructLayout で読み直して確かめること。
export const modifyStructField = async (
  structName: string,
  field: string,
  change: { newName?: string; newType?: string },
  timeoutSec: number = 60,
): Promise<string> => {
  return await post("modify_struct_field", {
    struct_name: structName,
    field_name: field,
    new_name: change.newName ?? "",
    new_type: change.newType ?? "",
  }, timeoutSec);
};
