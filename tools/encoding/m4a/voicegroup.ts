import * as gba from "../../common/gba/gba.ts";
import type { addr } from "../../common/gba/gba.ts";
import { Parser } from "@binary-parser";

export type ToneData = {
  type: number; // タイプ
  key: number; // オリジナルキー
  length: number; // 音の長さ（互換サウンド)
  pan_sweep: number; // パンポット or スイープ（互換サウンド１）
  wav: addr; // 波形データのアドレス
  attack: number; // アタック
  decay: number; // ディケイ
  sustain: number; // サスティン
  release: number; // リリース
};

export const ParseToneData = (data: Uint8Array): ToneData => {
  const parser = new Parser().endianness("little")
    .uint8("type")
    .uint8("key")
    .uint8("length")
    .uint8("pan_sweep")
    .uint32("wav")
    .uint8("attack")
    .uint8("decay")
    .uint8("sustain")
    .uint8("release");
  return parser.parse(data);
};

export const StringifyToneData = (tone: ToneData): string => {
  return `{type: 0x${gba.toHex8(tone.type)}, key: ${tone.key}, length: ${tone.length}, pan_sweep: ${tone.pan_sweep}, wav: (void*)0x${gba.toHex32(tone.wav)}, attack: ${tone.attack}, decay: ${tone.decay}, sustain: ${tone.sustain}, release: ${tone.release}}`;
};

// voicegroup is ToneData array
export const ParseVoicegroup = (rom: DataView, start: addr, count: number): ToneData[] => {
  const offset = (start >= gba.BASE) ? start - gba.BASE : start;

  const voicegroup: ToneData[] = [];
  for (let i = 0; i < count; i++) {
    const data = new Uint8Array(rom.buffer, offset + (i * 12), 12);
    voicegroup.push(ParseToneData(data));
  }
  return voicegroup;
};
