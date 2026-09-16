import { bgr888, getBGR888, rgb555 } from "../common/color.ts";

export const fmtJascPlttBGR888 = (colors: bgr888[] | Uint32Array): string => {
  if (colors instanceof Uint32Array) colors = Array.from(colors);
  const length = colors.length;
  const header = ["JASC-PAL", "0100", `${length}`].join("\n");
  const result: string[] = [];
  for (let i = 0; i < length; i++) {
    const bgr888 = colors[i];
    const r = bgr888 & 0xFF;
    const g = (bgr888 >> 8) & 0xFF;
    const b = (bgr888 >> 16) & 0xFF;
    result.push(`${r} ${g} ${b}`);
  }
  return [header, ...result].join("\n");
};

export const fmtJascPlttRGB555 = (colors: rgb555[] | Uint16Array | Uint8Array): string => {
  if (colors instanceof Uint8Array) colors = new Uint16Array(colors.buffer);
  if (colors instanceof Uint16Array) colors = Array.from(colors);
  return fmtJascPlttBGR888(colors.map(getBGR888));
};
