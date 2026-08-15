OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
MEMORY {
    ewram   : ORIGIN = 0x02000000, LENGTH = 4M - 4k
    iwram   : ORIGIN = 0x03000000, LENGTH = 32k
		rom     : ORIGIN = (0x08000000), LENGTH = 16M
}

gInput = 0x030044E0;
SOUND_INFO_PTR = 0x03007FF0;

gMaxLines = 0;
gNumMusicPlayers = 32;
gSongTable = 0x0825E56C;

gDefaultEntityManager = 0x085B0158;

/* Strong symbols to prevent libc archive from pulling in impure.o / syscalls.o */
_impure_ptr = 0x08DBDDD4;

gSubroutineTable1 = 0x085A9208;

gCtrlHandlers1_ROM = 0x085B01D0;
gCtrlHandlers2_ROM = 0x08DBD758;

gScriptDirectory = 0x08CBF248;

gParticlesDirectory = 0x08A2011C;
gParticleFile0 = 0x08A20138;

gActorSpritesFile0 = 0x08A2291C;
gObjPlttFile0 = 0x08CB9244;

SECTIONS {
	. = 0x2000000;
	ewram (NOLOAD) :
	ALIGN(4)
    {
      gHeap = .;
      . = 0x20400;
      src/ewram.o(ewram_data);
    } >ewram = 0x00

	. = 0x3000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
      src/iwram1.o(iwram_data);
      src/lib/libagbrtc.o(.bss);
      *libgcc.a:dp-bit.o(.bss);
      *libgcc.a:fp-bit.o(.bss);
      *libc.a:syscalls.o(.bss);
      src/lib/m4a.o(.bss.code);
      src/iwram2.o(iwram_data);
      src/lib/librfu_stwi.o(iwram_data);
      . = ALIGN(16);
      src/lib/librfu_rfu.o(iwram_data);
      src/lib/librfu_sio32id.o(iwram_data);
      src/lib/agb_eeprom.o(iwram_data);
      end = .;
      *libc.a:sbrkr.o(COMMON);
    } >iwram = 0x00

    . = 0x8000000;
    .text :
    ALIGN(4)
    {
      src/rom_header.o (.text);
      src/crt0.o (.text);
			src/main.o (.text);
			src/code_08000440.o (.text);
			src/password.o (.text);
			src/code_08013288.o (.text);
			src/code_08013634.o (.text);
			src/code_08013c94.o (.text);
			src/code_08052290.o (.text);
			src/code_08052eb8.o (.text);
			src/code_0805f6d4.o (.text);
			src/code_0805ff04.o (.text);
			src/code_080601f0.o (.text);
			src/code_080604bc.o (.text);
			src/player.o (.text);
			src/player_08065988.o (.text);
			src/player_0807f430.o (.text);
			src/code_0807f430.o (.text);
			src/code_0807f640.o (.text);
			src/item_08091774.o (.text);
			src/code_080917e4.o (.text);
			src/code_080aafdc.o (.text);
			src/code_080c5058.o (.text);
			src/code_080ddf88.o (.text);
			src/code_080ffd28.o (.text);
			src/code_081a4e88.o (.text);
			src/code_081cc550.o (.text);
			src/code_081eafbc.o (.text);
			src/code_0820fb20.o (.text);
			src/code_0821a2bc.o (.text);
			src/code_0821b860.o (.text);
			src/code_0822f204.o (.text);
			src/code_0822f650.o (.text);
			src/code_0823071c.o (.text);
			src/malloc.o (.text);
			src/entity.o (.text);
			src/code_08230d30.o (.text);
			src/code_08230b88.o (.text);
			src/vm.o (.text);
			src/code_082324dc.o (.text);
			src/lib/linkManager.o (.text);
			src/code_0823a6c0.o (.text);
			src/vm_0823b190.o (.text);
			src/code_0823b258.o (.text);
			src/camera.o (.text);
			src/time.o (.text);
			src/sound.o (.text);
			src/code_0823e174.o (.text);
			src/solar.o (.text);
			src/item_082421f0.o (.text);
			src/weapon.o (.text);
			src/armor.o (.text);
			src/equip_magic.o (.text);
			src/code_08243660.o (.text);
    } >rom = 0x00

	lib_text :
	ALIGN(4)
	{
      src/lib/m4a_1.o (.text);
			src/lib/m4a.o (.text);
			src/code_08245c4c.o (.text);
			src/lib/librfu_stwi.o (.text);
      src/lib/librfu_intr.o (.text);
      src/lib/librfu_rfu.o (.text);
      src/lib/librfu_sio32id.o (.text);
			src/code_0824beb8.o (.text);
			src/lib/libagbsyscall.o (.text);
			src/lib/agb_eeprom.o (.text);
			src/lib/libagbrtc.o (.text);
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
			src/lib/math/s_atan.o (.text);
			src/lib/math/s_cos.o (.text);
      src/lib/math/s_fabs.o (.text);
      src/lib/math/s_sin.o (.text);
      src/lib/math/s_tan.o (.text);
      src/lib/math/w_*.o (.text);
      src/lib/math/e_*.o (.text);
      src/lib/math/k_*.o (.text);
      src/lib/math/s_floor.o (.text);
			*libc.a:s_isnan.o(.text);
			src/lib/math/s_matherr.o (.text);
			*libc.a:s_scalbn.o(.text);
			*libc.a:s_copysign.o(.text);
			*libc.a:errno.o(.text);
			*libc.a:exit.o(.text);
			*libc.a:memcpy.o(.text);
			*libc.a:syscalls.o(.text);
			*libc.a:libcfunc.o(.text);
			*libc.a:strlen.o(.text);
			src/lib/ArmCpuFastSet.o (.text);
	} >rom = 0x00

	.rodata :
	ALIGN(4)
	{
    src/data.o (.rodata);
    src/lib/m4a_tables.o (.rodata);
    src/sound.o (.rodata);
    src/lib/librfu_rfu.o (.rodata);
    src/lib/librfu_sio32id.o (.rodata);
    src/data_085a8b30.o (.rodata);
    src/lib/libagbrtc.o (.rodata);
    src/lib/math/s_atan.o (.rodata);
    src/lib/math/s_cos.o (.rodata);
    src/lib/math/s_fabs.o (.rodata);
    src/lib/math/s_sin.o (.rodata);
    src/lib/math/s_tan.o (.rodata);
    src/lib/math/w_acos.o (.rodata);
    src/lib/math/w_asin.o (.rodata);
    src/lib/math/w_fmod.o (.rodata);
    src/lib/math/e_acos.o (.rodata);
    src/lib/math/e_asin.o (.rodata);
    src/lib/math/e_fmod.o (.rodata);
    src/lib/math/e_rem_pio2.o (.rodata);
    src/lib/math/e_sqrt.o (.rodata);
    src/lib/math/k_cos.o (.rodata);
    src/lib/math/k_rem_pio2.o (.rodata);
    src/lib/math/k_sin.o (.rodata);
    src/lib/math/k_tan.o (.rodata);
    src/lib/math/s_floor.o (.rodata);
    src/data_085a90b8.o (.rodata);
    *libc.a:s_scalbn.o(.rodata);
    src/data_085a90dc.o (.rodata);
    *libc.a:syscalls.o(.rodata);
    src/data3.o (.rodata);
    src/data/item.o (.rodata);
    src/data4.o (.rodata);
	} >rom = 0x00

    /* Discard everything not specifically mentioned above. */
	/DISCARD/ :
    {
        *(*);
    }
}
