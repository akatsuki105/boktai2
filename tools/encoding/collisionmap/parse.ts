export type FileHeader = {
  magic: [number, number, number, number]; // "HP\0\0"
  offsetToTileData: number;
  offsetToZones: number;
  offsetToPaths: number;
  offsetToNavmesh: number;
};
