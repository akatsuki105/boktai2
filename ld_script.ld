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

gSubroutineTable = 0x085A9208;

gCtrlHandlers2_ROM = 0x08DBD758;

gPlayerAttackUpdates = 0x085abab8;

gAnimDirectory = 0x085b0df0;
gTilemapDirectory = 0x085b26e4;
gCollisionMapsDirectory = 0x087b260c;
gPlttDirectory = 0x087fa08c;

gParticleFile0 = 0x08A20138;
gSpriteSetFile25 = 0x08C5A80C;

SECTIONS {
	. = 0x2000000;
	ewram (NOLOAD) :
	ALIGN(4)
    {
      gHeap = .;
      . = 0x20400;
      src/main.o(ewram_data);
      src/ewram.o(ewram_data);
    } >ewram = 0x00

	. = 0x3000000;
    iwram (NOLOAD) :
    ALIGN(4)
    {
      src/iwram1.o(iwram_data);
      src/sound.o(iwram_data);
      src/solar_sensor.o(iwram_data);
      src/lib/libagbrtc.o(.bss);
      *libgcc.a:dp-bit.o(.bss);
      *libgcc.a:fp-bit.o(.bss);
      *libc.a:syscalls.o(.bss);
      src/lib/m4a.o(.bss.code);
      src/iwram2.o(iwram_data);
      src/sound.o(COMMON);
      src/solar_sensor.o(COMMON);
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
			src/entity_4ae5.o (.text);
			src/entity_6978.o (.text);
			src/entity_e28b.o (.text);
			src/entity_d9ae.o (.text);
			src/code_080026fc.o (.text);
			src/entity_83b2.o (.text);
			src/code_08009a58.o (.text);
			src/password.o (.text);
			src/code_08013288.o (.text);
			src/code_08013634.o (.text);
			src/code_08013c94.o (.text);
			src/boss.o (.text);
			src/boss/duneyrr.o (.text);
			src/boss/entity_ba4b.o (.text);
			src/boss/durathror.o (.text);
			src/code_0803c1bc.o (.text);
			src/crossover_lobby.o (.text);
			src/code_0804f820.o (.text);
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
			src/player_0807f640.o (.text);
			src/code_080801f4.o (.text);
			src/item_08091774.o (.text);
			src/code_080917e4.o (.text);
			src/level_upper.o (.text);
			src/code_080a8804.o (.text);
			src/code_080aad30.o (.text);
			src/code_080aafdc.o (.text);
			src/entity_e9d3.o (.text);
			src/code_080b5ab0.o (.text);
			src/entity_d3a9.o (.text);
			src/code_080c0d6c.o (.text);
			src/code_080c5058.o (.text);
			src/entity_080ddf88.o (.text);
			src/enemy/boku.o (.text);
			src/enemy/skeleton.o (.text);
			src/enemy/golem.o (.text);
			src/enemy/mummy.o (.text);
			src/enemy/spider.o (.text);
			src/enemy/centipede.o (.text);
			src/enemy/curoro.o (.text);
			src/enemy/bat.o (.text);
			src/enemy/crow.o (.text);
			src/enemy/mimic.o (.text);
			src/enemy/dog.o (.text);
			src/enemy/cockatrice.o (.text);
			src/enemy/slime.o (.text);
			src/enemy/bee.o (.text);
			src/enemy/ghost.o (.text);
			src/enemy/sandworm.o (.text);
			src/enemy/cheye.o (.text);
			src/enemy/octopus.o (.text);
			src/enemy/serpent.o (.text);
			src/enemy/ax.o (.text);
			src/enemy/root_of_darkness.o (.text);
			src/enemy/unk_flame_snake.o (.text);
			src/enemy/boku_link.o (.text);
			src/enemy/golem_link.o (.text);
			src/enemy/dog_link.o (.text);
			src/code_081cc550.o (.text);
			src/code_081eafbc.o (.text);
			src/boss/dvalinn.o (.text);
			src/code_08200ab4.o (.text);
			src/enemy_dex.o (.text);
			src/entity_c946.o (.text);
			src/weapon_dex.o (.text);
			src/album_menu.o (.text);
			src/entity_4ddf.o (.text);
			src/intro.o (.text);
			src/code_08213880.o (.text);
			src/entity_0fc5.o (.text);
			src/code_0821b21c.o (.text);
			src/entity_0821b7fc.o (.text);
			src/code_0821b860.o (.text);
			src/entity_83e5.o (.text);
			src/entity_8aab.o (.text);
			src/system.o (.text);
			src/video.o (.text);
			src/code_0822f204.o (.text);
			src/sprite_0822f284.o (.text);
			src/code_0822f650.o (.text);
			src/code_0823071c.o (.text);
			src/malloc.o (.text);
			src/entity.o (.text);
			src/code_08230d30.o (.text);
			src/file.o (.text);
			src/vm.o (.text);
			src/vm_ctrl1.o (.text);
			src/vm_expr.o (.text);
			src/code_082326a0.o (.text);
			src/code_082324dc.o (.text);
			src/lib/linkManager.o (.text);
			src/code_0823a6c0.o (.text);
			src/vm_ctrl2.o (.text);
			src/vm_subroutine.o (.text);
			src/entity_b8b9.o (.text);
			src/code_0823b540.o (.text);
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
			src/solar_sensor.o (.text);
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
    src/system.o (.rodata);
    src/lib/m4a_tables.o (.rodata);
    src/sound.o (.rodata);
    src/lib/librfu_rfu.o (.rodata);
    src/lib/librfu_sio32id.o (.rodata);
    src/lib/agb_eeprom_data.o (.rodata);
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
    *libc.a:impure.o(.rodata);
    *libc.a:syscalls.o(.rodata);
    src/data3.o (.rodata);
    src/entity_4ae5.o (.rodata);
    src/entity_d9ae.o (.rodata);
    src/entity_2d2b.o (.rodata);
    src/entity_5da5.o (.rodata);
    src/entity_83b2.o (.rodata);
    src/data3b.o (.rodata);
    src/entity_c946.o (.rodata);
    src/weapon_dex.o (.rodata);
    src/album_menu.o (.rodata);
    src/data3d.o (.rodata);
    src/entity_0fc5.o (.rodata);
    src/entity_0623.o (.rodata);
    src/entity_83e5.o (.rodata);
    src/entity_8aab.o (.rodata);
    src/video.o (.rodata);
    src/entity.o (.rodata);
    src/vm.o (.rodata);
    src/vm_ctrl1.o (.rodata);
    src/data3c.o (.rodata);
    src/file.o (.rodata);
    src/data/tilesets.o (.rodata);
    src/data/fonts.o (.rodata);
    src/data/sprites.o (.rodata);
    src/data/scripts.o (.rodata);
    src/data/item.o (.rodata);
    src/data4.o (.rodata);

    /* ????????????? */
    *libc.a:impure.o(.data);
	} >rom = 0x00

    /* Discard everything not specifically mentioned above. */
	/DISCARD/ :
    {
        *(*);
    }
}
