import { getRepoRoot } from "../common/common.ts";
import * as path from "@std/path";

const SYM_FILE = "boktai2.sym";

export type Entry = {
  offset: number;
  name: string;
  type: string;
};

// boktai2.sym のパーサ
export const Parse = (symFileContent: string): Entry[] => {
  const lines = symFileContent.split("\n");
  const symbolEntries: Entry[] = Array<Entry>(lines.length).fill({ offset: 0, name: "", type: "" });

  for (const line of lines) {
    const parts = line.trim().split(/\s+/);
    if (parts.length === 3) {
      const [offsetStr, type, name] = parts;
      const offset = parseInt(offsetStr, 16);
      symbolEntries.push({ offset, name, type });
    }
  }

  return symbolEntries;
};

export const ParseFile = (): Entry[] => {
  const sympath = path.join(getRepoRoot(), SYM_FILE);
  const symFileContent = Deno.readTextFileSync(sympath);
  return Parse(symFileContent);
};
