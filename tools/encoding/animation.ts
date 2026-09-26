import { Parser } from "@binary-parser";

export type File = {
  animationCount: number;
  cmdCount: number;
  animations: {
    variantCount: number;
    cmdCount: number;
    cmdIdx: number;
  }[];
  cmds: number[];
};

const parser = new Parser().endianness("little")
  .uint16("animationCount")
  .uint16("cmdCount")
  .array("animations", {
    type: "uint32le",
    length: "animationCount",
  })
  .array("cmds", {
    type: "uint16le",
    length: "cmdCount",
  });

export const Parse = (data: Uint8Array): File => {
  const raw = parser.parse(data);
  const offsetTo1stCmd = 4 + raw.animationCount * 4;

  return {
    animationCount: raw.animationCount,
    cmdCount: raw.cmdCount,
    animations: raw.animations.map((a: number) => ({
      variantCount: a & 0xFF,
      cmdCount: (a >> 8) & 0xFF,
      cmdIdx: (((a >> 16) & 0xFFFF) - offsetTo1stCmd) >> 1,
    })),
    cmds: raw.cmds,
  };
};

export const Stringify = (file: File, indent: string = "  "): string => {
  const lines: string[] = [];
  lines.push(indent + ".set ANIM_COUNT, " + file.animationCount);
  lines.push(indent + `.2byte ANIM_COUNT, ${file.cmdCount} @ animation_count, cmd_count`);
  lines.push(indent + `@ Animations, variant_count, cmd_idx, cmd_count`);
  const startIdx: Set<number> = new Set();
  for (const anim of file.animations) {
    lines.push(indent + indent + `animation ${anim.variantCount}, ${anim.cmdIdx}, ${anim.cmdCount}`);
    startIdx.add(anim.cmdIdx);
  }
  lines.push(indent + `@ animcmd spriteidx, duration`);
  for (let i = 0; i < file.cmds.length; i++) {
    const cmd = file.cmds[i];
    if (startIdx.has(i)) lines.push(indent + indent + `@ cmd_idx ${i}`);
    lines.push(indent + indent + indent + fmtAnimCmd(cmd));
  }
  lines.push(indent + `.4byte 0 @ terminator?`);
  return lines.join("\n");
};

const fmtAnimCmd = (cmd: number): string => {
  const duration = cmd & 0xF;
  const xflip = (cmd >> 4) & 0x1;
  const yflip = (cmd >> 5) & 0x1;
  const poseIdx = (cmd >> 6) & 0x3FF;
  let result = `animcmd ${poseIdx}, ${duration}`;
  if (xflip) result += `, xflip=1`;
  if (yflip) result += `, yflip=1`;
  return result;
};
