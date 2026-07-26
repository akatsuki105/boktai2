OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
MEMORY {
    ewram   : ORIGIN = 0x02000000, LENGTH = 4M - 4k
    iwram   : ORIGIN = 0x03000000, LENGTH = 32k
		rom     : ORIGIN = (0x08000000), LENGTH = 16M
}

gScaleTable = 0x082529b8;
gFreqTable = 0x08252a6c;
gPcmSamplesPerVBlankTable = 0x08252a9c;
gMPlayTable = 0x0825e3ec;
gMaxLines = 0;
gNumMusicPlayers = 32;
gCgbChans = 0x030052a0;
gMPlayMemAccArea = 0x03005760;
gSongTable = 0x0825e56c;
gCgbScaleTable = 0x08252ab4;
gCgbFreqTable = 0x08252b38;
gNoiseTable = 0x08252b50;
gCgb3Vol = 0x08252b8c;
gXcmdTable = 0x08252bd0;

gDefaultEntityManager = 0x085b0158;

/* Strong symbols to prevent libc archive from pulling in impure.o / syscalls.o */
_impure_ptr = 0x08DBDDD4;

gItemDB = 0x08daa8d8;
gWeaponDB = 0x08da9e68;
gArmorDB = 0x08daa7b0;

gEEPROMConfig512 = 0x085a8b3c;
gEEPROMConfig8k = 0x085a8b48;

gUnk085a9208 = 0x085a9208;
gUnk08dbd758 = 0x08dbd758;

rtc_lock = 0x030026CA;

SECTIONS {
	. = 0x2000000;
	ewram (NOLOAD) :
	ALIGN(4)
    {
      src/ewram.o(ewram_data);
    } >ewram = 0x00

	. = 0x3000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
      src/iwram.o(iwram_data);
    } >iwram = 0x00

	/* thenan variables from libgcc dp-bit.o and fp-bit.o (within IWRAM range) */
	.libgcc_bss 0x030026D0 (NOLOAD) :
	{
		*libgcc.a:dp-bit.o(.bss);
		. = ALIGN(8);
		*libgcc.a:fp-bit.o(.bss);
	}

    . = 0x8000000;
    .text :
    ALIGN(4)
    {
      src/rom_header.o (.text);
      src/crt0.o (.text);
			src/main.o (.text);
			src/code_08000440.o (.text);
			src/player.o (.text);
			src/code_08060fa4.o (.text);
			src/player_08065988.o (.text);
			src/code_08065988.o (.text);
			src/player_0807f430.o (.text);
			src/code_0807f430.o (.text);
			src/item_08091774.o (.text);
			src/code_080917e4.o (.text);
			src/entity.o (.text);
			src/code_08230d30.o (.text);
			src/code_08230b88.o (.text);
			src/vm.o (.text);
			src/code_082324dc.o (.text);
			src/code_0823b190.o (.text);
			src/code_0823b258.o (.text);
			src/time.o (.text);
			src/code_0823e174.o (.text);
			src/solar.o (.text);
			src/code_082418f0.o (.text);
			src/item_082421f0.o (.text);
			src/weapon.o (.text);
			src/armor.o (.text);
			src/equip_magic.o (.text);
			src/code_0824347c.o (.text);
    } >rom = 0x00

	lib_text :
	ALIGN(4)
	{
      src/libs/m4a_1.o (.text);
			src/libs/m4a.o (.text);
			src/code_08245c4c.o (.text);
			src/libs/libagbsyscall.o (.text);
			src/libs/agb_eeprom.o (.text);
			src/libs/libagbrtc.o (.text);
			*libgcc.a:*_call_via_rX*.o(.text);
			*libgcc.a:_divsi3.o(.text);
			*libgcc.a:_dvmd_tls.o(.text);
			*libgcc.a:_fixunsdfsi.o(.text);
			*libgcc.a:_udivsi3.o(.text);
			*libgcc.a:_umodsi3.o(.text);
			*libgcc.a:dp-bit.o(.text);
			*libgcc.a:fp-bit.o(.text);
			*libgcc.a:_lshrdi3.o(.text);
			*libgcc.a:_muldi3.o(.text);
			*libgcc.a:_negdi2.o(.text);
			src/libs/fdlibm.o (.text);
			*libc.a:s_isnan.o(.text);
			src/code_082513fc.o (.text);
			*libc.a:s_scalbn.o(.text);
			*libc.a:s_copysign.o(.text);
			*libc.a:errno.o(.text);
			*libc.a:exit.o(.text);
			*libc.a:memcpy.o(.text);
			src/code_08251650.o (.text);
			*libc.a:libcfunc.o(.text);
			*libc.a:strlen.o(.text);
			src/libs/ArmCpuFastSet.o (.text);
	} >rom = 0x00

	.rodata :
	ALIGN(4)
	{
    src/data.o (.rodata);
	} >rom = 0x00

    /* Discard everything not specifically mentioned above. */
	/DISCARD/ :
    {
        *(*);
    }
}
