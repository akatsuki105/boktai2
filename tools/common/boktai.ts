import * as gba from "./gba/gba.ts";

export type gameid = "U32J" | "U32J_rev1";

export type Region = "J"; // J: Japanese, TODO: support USA version

type GameMeta = {
  id: gameid;
  supported: boolean;
  seriesNumber: number; // 1, 2, 3
  region: Region; // J: Japanese
};

const GAME_META = {
  "U32J": {
    id: "U32J",
    supported: true,
    seriesNumber: 2,
    region: "J",
  },
  "U32J_rev1": {
    id: "U32J_rev1",
    supported: true,
    seriesNumber: 2,
    region: "J",
  },
} as Record<gameid, GameMeta>;

export const getGameMeta = (rom: DataView): GameMeta => {
  const gameID = gba.getGameID(rom);
  // check gameID satisfies the type gameid
  if (!Object.keys(GAME_META).includes(gameID)) {
    throw new Error(`Unsupported gameID: ${gameID}`);
  }
  return GAME_META[gameID as gameid];
};

// key: (OAM1.14-15 << 2) | (OAM0.14-15); (size << 2) | shape
export const SpriteSize: Record<number, [width: number, height: number]> = {
  0: [8, 8],
  4: [16, 16],
  8: [32, 32],
  12: [64, 64],
  1: [16, 8],
  5: [32, 8],
  9: [32, 16],
  13: [64, 32],
  2: [8, 16],
  6: [8, 32],
  10: [16, 32],
  14: [32, 64],
};
