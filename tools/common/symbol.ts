const SYM_PATH = "boktai2.sym";

type SymbolEntry = {
  offset: number;
  name: string;
  type: string;
};

export const parseSymbolFile = (): SymbolEntry[] => {
  const symFileContent = Deno.readTextFileSync(SYM_PATH);
  const lines = symFileContent.split("\n");
  const symbolEntries: SymbolEntry[] = Array<SymbolEntry>(lines.length).fill({ offset: 0, name: "", type: "" });

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
