# gbagfx に追加でオプションを渡す場合は target-specific variables で個別に記述する
GFX_OPTS :=

data/font_narrow.4bpp: GFX_OPTS := -mheight 2
data/font_wide.4bpp: GFX_OPTS := -num_tiles 6148 -mwidth 2 -mheight 2

# 汎用ルール, scaninc がソースファイルから依存関係を自動で生成するため、このルール定義だけでよい
%.1bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.4bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.8bpp:   %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.pal              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.gbapal: %.png              ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.rl:     %                  ; @$(GBAGFX) $< $@ $(GFX_OPTS)
%.lz:     %.lz.4bpp          ; @$(GBAGFX) $< $@ $(GFX_OPTS)

.PHONY: clean-graphics
clean-graphics:
	rm -f data/font_narrow.4bpp data/font_wide.4bpp

RULES_NO_SCAN += clean-graphics
