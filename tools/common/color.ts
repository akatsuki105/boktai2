export type rgb555 = number;
export type bgr888 = number;

export const color8 = (c5: number): number => (Math.floor((c5 * 255) / 31));

export const getBGR888 = (rgb555: rgb555): bgr888 => {
  if (rgb555 & (1 << 15)) {
    console.warn(`Warning: bit15 is set for color value 0x${rgb555.toString(16)}`);
  }
  const val = rgb555 & 0xFFFF;
  const r5 = (val >> 0) & 0x1F;
  const g5 = (val >> 5) & 0x1F;
  const b5 = (val >> 10) & 0x1F;
  return (color8(b5) << 16) | (color8(g5) << 8) | color8(r5);
};
