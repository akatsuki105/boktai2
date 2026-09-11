# mid2agb に追加でオプションを渡す場合は target-specific variables で個別に記述する
MID2AGB_FLAGS := 

MIDI_DIR := data/sounds

MIDIS := $(wildcard $(MIDI_DIR)/*.mid)
MIDI_INCS := $(MIDIS:.mid=.inc)

# src/data/songs.s: $(MIDI_INCS)

$(MIDI_INCS): %.inc: %.mid
	$(MID2AGB) $< $@ $(MID2AGB_FLAGS)

.PHONY: clean-midi
clean-midi:
	@rm -f $(MIDI_INCS)
