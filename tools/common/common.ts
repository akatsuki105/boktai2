export const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};
