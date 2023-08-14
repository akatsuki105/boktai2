clean-src: clean-libs
	@rm -f src/*.[o.s]

clean-libs: 
	@rm -f src/libs/*.o
	@rm -f src/libs/agb_eeprom.s
