const GBAGFX = "./tools/gbagfx/gbagfx";

export const gbagfx = (...opts: string[]) => {
  return Deno.spawnAndWaitSync(GBAGFX, opts); // $ gbagfx xxx.4bpp xxx.png -width 6 -palette xxx.gbapal
};
