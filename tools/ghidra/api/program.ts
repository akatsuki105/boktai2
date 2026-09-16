import { post } from "./http.ts";

// 開いているプログラムを保存する (save_program)。失敗したら例外を投げる。
export const saveProgram = async (timeoutSec: number = 60): Promise<void> => {
  const text = await post("save_program", {}, timeoutSec);
  let json: Record<string, unknown>;
  try {
    json = JSON.parse(text);
  } catch {
    throw new Error(`save_program: JSON ではない応答が返りました: ${text.trim()}`);
  }
  if (json.success !== true) {
    throw new Error(`save_program: 保存に失敗しました: ${text.trim()}`);
  }
};
