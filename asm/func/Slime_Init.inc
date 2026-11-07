	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081656D4 @ =0x0000068E
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	adds r0, r7, #0
	bl Slime_InitAnims
	ldr r2, _081656D8 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081656E8
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081656DC @ =0x0000B96C
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081656E0 @ =0x0000A929
	bl EnemyAuxSprite_LoadAnim
	ldr r3, _081656E4 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x48]
	cmp r1, #0x11
	beq _081656C4
	cmp r1, #0x17
	bne _081656C8
_081656C4:
	movs r0, #1
	strb r0, [r5, #7]
_081656C8:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08165750
	.align 2, 0
_081656D4: .4byte 0x0000068E
_081656D8: .4byte 0x0000025D
_081656DC: .4byte 0x0000B96C
_081656E0: .4byte 0x0000A929
_081656E4: .4byte 0x000001DF
_081656E8:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081657D4 @ =0x05000002
	bl CpuSet
	ldr r0, _081657D8 @ =0x0000CB05
	ldr r1, _081657DC @ =0x0000B96C
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r2!, {r3, r6}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r5, r8
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r6, _081657E0 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x48]
_08165750:
	ldr r2, _081657E4 @ =0x000001DF
	adds r1, r7, r2
	movs r4, #0
	movs r0, #0x16
	strb r0, [r1]
	str r7, [sp, #0x28]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	str r4, [r3]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	str r4, [r5]
	ldr r6, _081657E8 @ =0x0000046F
	adds r0, r7, r6
	strb r4, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	mov sl, r2
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, _081657EC @ =0x00000474
	adds r6, r7, r3
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081657D4 @ =0x05000002
	bl CpuSet
	ldr r4, _081657F0 @ =0x000004B6
	adds r2, r7, r4
	mov r0, sl
	strb r0, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x184]
	mov r3, r8
	str r3, [sp, #0x188]
	str r6, [sp, #0x160]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _081657C4
	b _08165924
_081657C4:
	bl VM_GetPC
	cmp r0, #0
	beq _081657F4
	bl VM_GetValue
	adds r1, r0, #0
	b _081657F6
	.align 2, 0
_081657D4: .4byte 0x05000002
_081657D8: .4byte 0x0000CB05
_081657DC: .4byte 0x0000B96C
_081657E0: .4byte 0x000004B7
_081657E4: .4byte 0x000001DF
_081657E8: .4byte 0x0000046F
_081657EC: .4byte 0x00000474
_081657F0: .4byte 0x000004B6
_081657F4:
	movs r1, #0
_081657F6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0816581C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xd8]
	str r4, [sp, #0xdc]
	cmp r0, #0
	beq _08165820
	bl VM_GetValue
	adds r1, r0, #0
	b _08165822
	.align 2, 0
_0816581C: .4byte 0x00000251
_08165820:
	movs r1, #0
_08165822:
	ldr r2, _08165858 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0816585C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xd8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xe0]
	cmp r0, #0
	beq _08165860
	bl VM_GetValue
	b _08165864
	.align 2, 0
_08165858: .4byte 0x00000252
_0816585C: .4byte 0x000004B4
_08165860:
	ldr r4, [sp, #0xd8]
	ldrb r0, [r4]
_08165864:
	strb r0, [r6]
	ldr r5, [sp, #0xd8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xe0]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl Map_GetPathNodePos
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0816589C
	cmp r1, #0
	blt _0816589C
	ldr r0, _081658A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816589C
	ldr r0, _081658A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081658A8
_0816589C:
	movs r1, #0
	b _081658B6
	.align 2, 0
_081658A0: .4byte 0x030046A8
_081658A4: .4byte 0x030046AC
_081658A8:
	ldr r0, _081658D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081658B6:
	ldr r2, _081658D4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081658D8
	adds r0, #4
	b _081658E4
	.align 2, 0
_081658D0: .4byte 0x030046A4
_081658D4: .4byte 0x00000256
_081658D8:
	ldr r0, _081658F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081658E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081658FC
	cmp r2, #2
	beq _08165900
	b _08165904
	.align 2, 0
_081658F8: .4byte 0x030046A4
_081658FC:
	ldrb r0, [r4, #4]
	b _08165902
_08165900:
	ldrb r0, [r4]
_08165902:
	subs r1, r1, r0
_08165904:
	ldr r3, _0816591C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08165920 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08165964
	.align 2, 0
_0816591C: .4byte 0x00000472
_08165920: .4byte 0x0000FFFF
_08165924:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08165988 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0816598C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08165990 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xd8]
	str r4, [sp, #0xdc]
	str r3, [sp, #0xe0]
_08165964:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081659AE
	bl VM_GetPC
	cmp r0, #0
	beq _08165994
	bl VM_GetValue
	adds r4, r0, #0
	b _08165996
	.align 2, 0
_08165988: .4byte 0x00000251
_0816598C: .4byte 0x00000252
_08165990: .4byte 0x000004B4
_08165994:
	movs r4, #0x30
_08165996:
	bl VM_GetPC
	cmp r0, #0
	beq _081659A8
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081659AA
_081659A8:
	movs r5, #0x40
_081659AA:
	mov r8, r4
	b _081659B4
_081659AE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081659B4:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081659EC
	bl VM_GetPC
	cmp r0, #0
	beq _081659CE
	bl VM_GetValue
	adds r6, r0, #0
	b _081659D0
_081659CE:
	movs r6, #0
_081659D0:
	bl VM_GetPC
	cmp r0, #0
	beq _081659E0
	bl VM_GetValue
	adds r1, r0, #0
	b _081659E2
_081659E0:
	movs r1, #0
_081659E2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081659F6
_081659EC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081659F6:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08165C70 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x190]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	lsls r4, r4, #0x10
	str r4, [sp, #0x40]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x50]
	lsls r6, r6, #0x10
	str r6, [sp, #0x54]
	lsls r5, r5, #0x10
	str r5, [sp, #0x4c]
	ldr r4, _08165C74 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x3c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x148]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x60]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x68]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x14c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x150]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x144]
	ldr r1, _08165C78 @ =0x0000068E
	ldr r6, [sp, #0x24]
	adds r1, r6, r1
	str r1, [sp, #0x140]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _08165C7C @ =0x0000047A
	adds r3, r7, r3
	str r3, [sp, #0x164]
	ldr r4, _08165C80 @ =0x0000047C
	adds r4, r7, r4
	str r4, [sp, #0x168]
	ldr r5, _08165C84 @ =0x0000047E
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08165C88 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _08165C8C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _08165C90 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _08165C94 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _08165C98 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0xf4]
	ldr r6, _08165C9C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd4]
	ldr r2, _08165CA0 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x90]
	ldr r3, _08165CA4 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x124]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x128]
	ldr r5, _08165CA8 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	ldr r6, _08165CAC @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x12c]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x114]
	ldr r2, _08165CB0 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x118]
	ldr r4, _08165CB4 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _08165CB8 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _08165CBC @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x104]
	ldr r5, _08165CC0 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x110]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _08165CC4 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x138]
	ldr r3, _08165CC8 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x13c]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08165CCC @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	ldr r2, _08165CD0 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xac]
	ldr r3, _08165CD4 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	ldr r4, _08165CD8 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x194]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _08165CDC @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x178]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x154]
	ldr r3, _08165CE0 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x158]
	ldr r4, _08165CE4 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08165CE8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x44]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _08165CEC @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x30]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	ldr r6, _08165CF0 @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _08165CF4 @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r3, _08165CF8 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _08165CFC @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08165D00 @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _08165D04 @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	cmp r0, #0
	bne _08165C40
	b _08165D60
_08165C40:
	movs r2, #0
	mov sl, r2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_08165C60:
	bl VM_GetPC
	cmp r0, #0
	beq _08165D08
	bl VM_GetValue
	b _08165D0A
	.align 2, 0
_08165C70: .4byte 0x0000025D
_08165C74: .4byte 0x0000025A
_08165C78: .4byte 0x0000068E
_08165C7C: .4byte 0x0000047A
_08165C80: .4byte 0x0000047C
_08165C84: .4byte 0x0000047E
_08165C88: .4byte 0x000004A4
_08165C8C: .4byte 0x000005A4
_08165C90: .4byte 0x000005C4
_08165C94: .4byte 0x000005CC
_08165C98: .4byte 0x000005D4
_08165C9C: .4byte 0x000005DC
_08165CA0: .4byte 0x00000584
_08165CA4: .4byte 0x00000604
_08165CA8: .4byte 0x0000021D
_08165CAC: .4byte 0x0000060C
_08165CB0: .4byte 0x000005E4
_08165CB4: .4byte 0x000005FC
_08165CB8: .4byte 0x00000614
_08165CBC: .4byte 0x000005BC
_08165CC0: .4byte 0x000005EC
_08165CC4: .4byte 0x00000624
_08165CC8: .4byte 0x0000058C
_08165CCC: .4byte 0x00000594
_08165CD0: .4byte 0x0000059C
_08165CD4: .4byte 0x000005B4
_08165CD8: .4byte 0x00000543
_08165CDC: .4byte 0x00000496
_08165CE0: .4byte 0x00000469
_08165CE4: .4byte 0x0000046A
_08165CE8: .4byte 0x00000553
_08165CEC: .4byte 0x00000572
_08165CF0: .4byte 0x0000055C
_08165CF4: .4byte 0x00000564
_08165CF8: .4byte 0x00000565
_08165CFC: .4byte 0x00000566
_08165D00: .4byte 0x00000567
_08165D04: .4byte 0x0000056C
_08165D08:
	movs r0, #0x18
_08165D0A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08165D1C
	bl VM_GetValue
	b _08165D1E
_08165D1C:
	movs r0, #0x18
_08165D1E:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08165D30
	bl VM_GetValue
	b _08165D32
_08165D30:
	movs r0, #0
_08165D32:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08165D44
	bl VM_GetValue
	b _08165D46
_08165D44:
	movs r0, #0
_08165D46:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _08165D60
	b _08165C60
_08165D60:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08165DAC
	bl VM_GetPC
	cmp r0, #0
	beq _08165D7A
	bl VM_GetValue
	adds r4, r0, #0
	b _08165D7E
_08165D7A:
	movs r4, #0x96
	lsls r4, r4, #1
_08165D7E:
	bl VM_GetPC
	cmp r0, #0
	beq _08165D8E
	bl VM_GetValue
	adds r6, r0, #0
	b _08165D92
_08165D8E:
	movs r6, #0x96
	lsls r6, r6, #1
_08165D92:
	bl VM_GetPC
	cmp r0, #0
	beq _08165DA0
	bl VM_GetValue
	b _08165DA6
_08165DA0:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08165DA6:
	ldr r2, [sp, #0xd0]
	strh r0, [r2]
	b _08165DB4
_08165DAC:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xd0]
	strh r6, [r3]
_08165DB4:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08165DCC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x188]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08165DCC:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x190]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x18c]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08165E9C
	bl VM_GetPC
	cmp r0, #0
	beq _08165DFC
	bl VM_GetValue
	b _08165DFE
_08165DFC:
	movs r0, #0
_08165DFE:
	ldr r3, [sp, #0xe8]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08165E0C
	asrs r1, r0, #1
	b _08165E12
_08165E0C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08165E12:
	ldr r5, _08165E28 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E2C
	bl VM_GetValue
	b _08165E2E
	.align 2, 0
_08165E28: .4byte 0x00000546
_08165E2C:
	movs r0, #0
_08165E2E:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E44
	bl VM_GetValue
	b _08165E46
_08165E44:
	movs r0, #0
_08165E46:
	ldr r3, _08165E5C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E60
	bl VM_GetValue
	adds r1, r0, #0
	b _08165E62
	.align 2, 0
_08165E5C: .4byte 0x00000187
_08165E60:
	movs r1, #0
_08165E62:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E78
	bl VM_GetValue
	b _08165E7A
_08165E78:
	movs r0, #0
_08165E7A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08165E92
	bl VM_GetValue
	adds r1, r0, #0
	b _08165E94
_08165E92:
	movs r1, #0
_08165E94:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08165E9C:
	ldr r5, [sp, #0xe8]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0x40]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x50]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x54]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x4c]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08165EFE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08165EE4
	bl VM_GetValue
	b _08165EE6
_08165EE4:
	movs r0, #0
_08165EE6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08165EF6
	bl VM_GetValue
	b _08165EF8
_08165EF6:
	movs r0, #0
_08165EF8:
	ldr r6, _08165F60 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08165EFE:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xf0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08165F22
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x188]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08165F22:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08165F3A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08165F3A:
	ldr r4, [sp, #0x3c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x160]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08165F64
	movs r0, #1
	b _08165F66
	.align 2, 0
_08165F60: .4byte 0x00000189
_08165F64:
	movs r0, #0
_08165F66:
	cmp r0, #0
	beq _08165F76
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08165FA0 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x28]
	bl CWolfTargetManager_Register
_08165F76:
	ldr r6, [sp, #0xf8]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08165F82
	ldr r1, [r7, #0x44]
_08165F82:
	ldr r0, [sp, #0x28]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08165FA4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08165FB0
	.align 2, 0
_08165FA0: .4byte Enemy_OnCWolfMessage
_08165FA4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08165FB0:
	ldr r2, [sp, #0x48]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08165FFE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08165FFE
	cmp r0, #0x16
	beq _08165FFE
	cmp r0, #0x14
	beq _08165FFE
	cmp r0, #9
	beq _08165FFE
	cmp r0, #0x19
	beq _08165FFE
	cmp r0, #0x1a
	beq _08165FFE
	cmp r0, #0xd
	beq _08165FFE
	cmp r0, #0x1b
	beq _08165FFE
	cmp r0, #0x1f
	beq _08165FFE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xd8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xdc]
	ldrb r3, [r4]
	ldr r5, [sp, #0xe0]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl Mover_SetPath
_08165FFE:
	movs r1, #8
	ldr r6, [sp, #0x160]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816600E
	movs r0, #1
	b _08166010
_0816600E:
	movs r0, #0
_08166010:
	cmp r0, #0
	beq _0816601E
	ldr r1, [sp, #0x68]
	ldr r0, [r1]
	ldr r2, [sp, #0x60]
	str r0, [r2]
	b _08166030
_0816601E:
	ldr r3, [sp, #0x68]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x60]
	str r0, [r4]
_08166030:
	ldrh r0, [r7]
	ldr r5, [sp, #0x14c]
	strh r0, [r5]
	ldr r6, [sp, #0x144]
	ldr r0, [sp, #0x150]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0816605A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_0816605A:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _08166066
	b _08166162
_08166066:
	bl VM_GetPC
	cmp r0, #0
	beq _08166074
	bl VM_GetValue
	b _08166076
_08166074:
	movs r0, #0
_08166076:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08166086
	bl VM_GetValue
	b _08166088
_08166086:
	movs r0, #0
_08166088:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08166098
	bl VM_GetValue
	b _0816609A
_08166098:
	movs r0, #0
_0816609A:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x144]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081660C2
	cmp r1, #0
	blt _081660C2
	ldr r0, _081660C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081660C2
	ldr r0, _081660CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081660D0
_081660C2:
	movs r1, #0
	b _081660DE
	.align 2, 0
_081660C8: .4byte 0x030046A8
_081660CC: .4byte 0x030046AC
_081660D0:
	ldr r0, _081660F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081660DE:
	ldr r4, _081660FC @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x144]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08166100
	adds r0, #4
	b _0816610C
	.align 2, 0
_081660F8: .4byte 0x030046A4
_081660FC: .4byte 0x00000256
_08166100:
	ldr r0, _08166120 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816610C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08166124
	cmp r2, #2
	beq _08166128
	b _0816612C
	.align 2, 0
_08166120: .4byte 0x030046A4
_08166124:
	ldrb r0, [r5, #4]
	b _0816612A
_08166128:
	ldrb r0, [r5]
_0816612A:
	subs r1, r1, r0
_0816612C:
	ldr r5, _08166150 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	ldr r2, _08166154 @ =0x0000065C
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, [sp, #0xf8]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08166158
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08166162
	.align 2, 0
_08166150: .4byte 0x00000472
_08166154: .4byte 0x0000065C
_08166158:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08166162:
	movs r0, #0x6a
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08166200
	bl VM_GetPC
	cmp r0, #0
	beq _0816617E
	bl VM_GetValue
	adds r1, r0, #0
	b _08166180
_0816617E:
	movs r1, #0
_08166180:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08166196
	bl VM_GetValue
	b _08166198
_08166196:
	movs r0, #0
_08166198:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081661B0
	bl VM_GetValue
	adds r1, r0, #0
	b _081661B2
_081661B0:
	movs r1, #0
_081661B2:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0x18
	ldr r2, [sp, #0x140]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	cmp r1, #0
	beq _081661F0
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r1, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	blt _081661E4
	asrs r1, r0, #1
	b _081661EA
_081661E4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081661EA:
	ldr r4, _081661FC @ =0x00000546
	adds r0, r7, r4
	strh r1, [r0]
_081661F0:
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #1
	strh r0, [r1]
	b _08166208
	.align 2, 0
_081661FC: .4byte 0x00000546
_08166200:
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
_08166208:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, [sp, #0x24]
	ldr r4, _08166288 @ =0x0000065A
	adds r1, r3, r4
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08166244
	movs r0, #0x10
	ldr r6, [sp, #0x140]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
_08166244:
	adds r0, r7, #0
	bl FUN_081645a4
	movs r4, #0x93
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x170]
	strh r0, [r1]
	ldr r2, [sp, #0x164]
	strh r4, [r2]
	ldr r3, [sp, #0x168]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, #0x93
	ldr r4, [sp, #0x16c]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x170]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xf8]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0816628C
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08166298
	.align 2, 0
_08166288: .4byte 0x0000065A
_0816628C:
	ldr r2, [r7, #0x44]
	ldr r0, _081662D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08166298:
	ldr r1, [sp, #0xf8]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081662E8
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081662D4
	movs r0, #5
	bl Enemy_CountByKind
	adds r4, r0, #1
	movs r0, #6
	bl Enemy_CountByKind
	adds r4, r4, r0
	movs r0, #7
	bl Enemy_CountByKind
	adds r4, r4, r0
	movs r0, #8
	bl Enemy_CountByKind
	adds r4, r4, r0
	b _081662DE
	.align 2, 0
_081662D0: .4byte 0x03003584
_081662D4:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081662DE:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081662E8:
	adds r0, r7, #0
	bl Slime_InitHitboxes
	ldr r4, [sp, #0x24]
	ldr r5, _08166470 @ =0x00000664
	adds r3, r4, r5
	movs r2, #0
	ldr r4, _08166474 @ =FUN_08165508
	ldr r5, _08166478 @ =FUN_081640e4
	ldr r6, _0816647C @ =FUN_08162df4
	mov r8, r6
	ldr r0, _08166480 @ =FUN_08163360
	mov sb, r0
	ldr r1, _08166484 @ =FUN_0816390c
	mov sl, r1
	ldr r6, _08166488 @ =FUN_080f62ac
	mov ip, r6
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x184]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x17c]
	str r3, [r0]
	ldr r1, [sp, #0x180]
	str r2, [r1]
	ldr r3, [sp, #0x8c]
	str r4, [r3]
	ldr r4, [sp, #0x94]
	str r5, [r4]
	ldr r5, [sp, #0x9c]
	str r2, [r5]
	ldr r6, _0816648C @ =FUN_08162cf4
	ldr r0, [sp, #0xb0]
	str r6, [r0]
	mov r1, r8
	ldr r3, [sp, #0xb4]
	str r1, [r3]
	ldr r4, [sp, #0xc8]
	str r2, [r4]
	ldr r5, [sp, #0xcc]
	str r2, [r5]
	mov r6, sb
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sl
	ldr r3, [sp, #0xec]
	str r1, [r3]
	ldr r0, _08166490 @ =FUN_080f44f4
	ldr r4, [sp, #0xf4]
	str r0, [r4]
	ldr r0, _08166494 @ =FUN_080f410c
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r6, [sp, #0xd4]
	str r2, [r6]
	ldr r0, _08166498 @ =FUN_0816335c
	ldr r1, [sp, #0x90]
	str r0, [r1]
	mov r3, ip
	ldr r4, [sp, #0x124]
	str r3, [r4]
	ldr r0, _0816649C @ =FUN_080f0430
	ldr r5, [sp, #0x128]
	str r0, [r5]
	movs r0, #1
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, _081664A0 @ =0x085AD470
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _081664A4 @ =FUN_080e73c8
	ldr r3, [sp, #0x114]
	str r0, [r3]
	ldr r4, [sp, #0x108]
	str r2, [r4]
	ldr r5, [sp, #0x118]
	str r2, [r5]
	ldr r6, [sp, #0x11c]
	str r2, [r6]
	ldr r0, [sp, #0x120]
	str r2, [r0]
	ldr r1, [sp, #0x130]
	str r2, [r1]
	ldr r0, _081664A8 @ =FUN_080f0320
	ldr r3, [sp, #0x134]
	str r0, [r3]
	ldr r0, _081664AC @ =Enemy_080eff14
	ldr r4, [sp, #0xc4]
	str r0, [r4]
	ldr r0, _081664B0 @ =FUN_080e72b0
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r6, [sp, #0x104]
	str r2, [r6]
	ldr r0, _081664B4 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r0, _081664B8 @ =Enemy_StateFallDeath
	ldr r3, [sp, #0xfc]
	str r0, [r3]
	ldr r4, [sp, #0xb8]
	str r2, [r4]
	ldr r0, _081664BC @ =FUN_080f6e64
	ldr r5, [sp, #0x138]
	str r0, [r5]
	ldr r0, _081664C0 @ =Enemy_OnDamaged
	ldr r6, [sp, #0x98]
	str r0, [r6]
	ldr r0, _081664C4 @ =FUN_080f84d4
	ldr r1, [sp, #0x13c]
	str r0, [r1]
	ldr r0, _081664C8 @ =FUN_080f624c
	ldr r3, [sp, #0xc0]
	str r0, [r3]
	ldr r0, _081664CC @ =FUN_080f56ec
	ldr r4, [sp, #0xa0]
	str r0, [r4]
	ldr r0, _081664D0 @ =FUN_080f5b34
	ldr r5, [sp, #0xa8]
	str r0, [r5]
	ldr r0, _081664D4 @ =FUN_080f5fac
	ldr r6, [sp, #0xac]
	str r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081664D8 @ =Slime_OnReset
	str r0, [r1]
	ldr r3, _081664DC @ =0x000005FC
	adds r1, r7, r3
	ldr r0, _081664E0 @ =FUN_0816406c
	str r0, [r1]
	ldr r4, _081664E4 @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _081664E8 @ =FUN_0816446c
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081664EC @ =FUN_08164520
	str r0, [r1]
	ldr r6, _081664F0 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081664F4 @ =FUN_081651dc
	str r0, [r1]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081664F8 @ =FUN_08164388
	str r0, [r1]
	subs r2, #0x44
	adds r1, r7, r2
	ldr r0, _081664FC @ =FUN_08165130
	str r0, [r1]
	movs r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x160]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x194]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0816650A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08166462:
	bl VM_GetPC
	cmp r0, #0
	beq _08166500
	bl VM_GetValue
	b _08166502
	.align 2, 0
_08166470: .4byte 0x00000664
_08166474: .4byte FUN_08165508
_08166478: .4byte FUN_081640e4
_0816647C: .4byte FUN_08162df4
_08166480: .4byte FUN_08163360
_08166484: .4byte FUN_0816390c
_08166488: .4byte FUN_080f62ac
_0816648C: .4byte FUN_08162cf4
_08166490: .4byte FUN_080f44f4
_08166494: .4byte FUN_080f410c
_08166498: .4byte FUN_0816335c
_0816649C: .4byte FUN_080f0430
_081664A0: .4byte 0x085AD470
_081664A4: .4byte FUN_080e73c8
_081664A8: .4byte FUN_080f0320
_081664AC: .4byte Enemy_080eff14
_081664B0: .4byte FUN_080e72b0
_081664B4: .4byte Enemy_StateBlownAway
_081664B8: .4byte Enemy_StateFallDeath
_081664BC: .4byte FUN_080f6e64
_081664C0: .4byte Enemy_OnDamaged
_081664C4: .4byte FUN_080f84d4
_081664C8: .4byte FUN_080f624c
_081664CC: .4byte FUN_080f56ec
_081664D0: .4byte FUN_080f5b34
_081664D4: .4byte FUN_080f5fac
_081664D8: .4byte Slime_OnReset
_081664DC: .4byte 0x000005FC
_081664E0: .4byte FUN_0816406c
_081664E4: .4byte 0x000005AC
_081664E8: .4byte FUN_0816446c
_081664EC: .4byte FUN_08164520
_081664F0: .4byte 0x0000058C
_081664F4: .4byte FUN_081651dc
_081664F8: .4byte FUN_08164388
_081664FC: .4byte FUN_08165130
_08166500:
	movs r0, #0
_08166502:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08166462
_0816650A:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x198]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x178]
	strh r0, [r3]
	cmp r2, #0
	beq _08166542
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x184]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08166542
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08166542:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x160]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08166554
	movs r0, #1
	b _08166556
_08166554:
	movs r0, #0
_08166556:
	cmp r0, #0
	beq _08166568
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x188]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08166568:
	cmp r2, #1
	beq _081665A8
	movs r1, #0
	ldr r0, [sp, #0x154]
	strb r1, [r0]
	ldr r2, [sp, #0x158]
	strb r1, [r2]
	ldr r3, [sp, #0x15c]
	strb r1, [r3]
	ldr r4, _081665B8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081665BC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xb4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x88]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081665A8:
	movs r1, #2
	ldr r3, [sp, #0x160]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081665C0
	movs r0, #1
	b _081665C2
	.align 2, 0
_081665B8: .4byte 0x00000484
_081665BC: .4byte 0x0000046C
_081665C0:
	movs r0, #0
_081665C2:
	cmp r0, #0
	beq _081665DC
	ldr r0, _081665D8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x174]
	strh r0, [r5]
	b _081665E6
	.align 2, 0
_081665D8: .4byte 0x030046A0
_081665DC:
	ldr r0, [sp, #0x144]
	bl GetZoneAt
	ldr r6, [sp, #0x174]
	strh r0, [r6]
_081665E6:
	movs r1, #0x40
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081665F6
	movs r0, #1
	b _081665F8
_081665F6:
	movs r0, #0
_081665F8:
	cmp r0, #0
	beq _08166608
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0816662C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08166608:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0816663A
	ldr r0, _08166630 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x174]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08166634
	movs r0, #1
	b _08166636
	.align 2, 0
_0816662C: .4byte 0xFFFFFEFF
_08166630: .4byte 0x030046A0
_08166634:
	movs r0, #0
_08166636:
	cmp r0, #0
	bne _08166642
_0816663A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_08166642:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xf8]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816672A
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08166684
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816668C
_08166684:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816668C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081666B0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081666B8
_081666B0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081666B8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081666F0 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08166734
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081666F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081666E8
	ldrb r0, [r4, #5]
_081666E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08166704
	.align 2, 0
_081666F0: .4byte 0x0000FFFF
_081666F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08166704
	strh r1, [r4, #8]
_08166704:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08166734
	movs r0, #1
	strb r0, [r4, #7]
	b _08166734
_0816672A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08166734:
	movs r0, #0
	ldr r3, [sp, #0x38]
	str r0, [r3]
	ldr r0, _0816674C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08166750
	movs r0, #1
	b _08166752
	.align 2, 0
_0816674C: .4byte 0x030047A4
_08166750:
	movs r0, #0
_08166752:
	cmp r0, #0
	bne _08166792
	ldr r4, [sp, #0x48]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816677A
	adds r0, r1, #0
	cmp r0, #7
	beq _0816677A
	cmp r0, #6
	beq _0816677A
	cmp r0, #0x15
	beq _0816677A
	cmp r0, #0x14
	beq _0816677A
	cmp r0, #0x17
	bne _08166792
_0816677A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x160]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08166792:
	movs r1, #8
	ldr r6, [sp, #0x140]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081667A2
	movs r0, #1
	b _081667A4
_081667A2:
	movs r0, #0
_081667A4:
	cmp r0, #0
	beq _081667F4
	ldr r3, _08166880 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r2, _08166884 @ =0x0000046D
	adds r0, r7, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08166888 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x88]
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r0, #2
	ldr r3, [sp, #0x154]
	strb r1, [r3]
	ldr r5, [sp, #0x158]
	strb r1, [r5]
	ldr r6, [sp, #0x15c]
	strb r0, [r6]
	ldr r1, _0816688C @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08166890 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081667F4:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_08163eac
	adds r0, r7, #0
	bl FUN_08163bac
	ldr r4, [sp, #0x160]
	ldrh r0, [r4]
	ldr r5, [sp, #0x84]
	strh r0, [r5]
	ldr r6, [sp, #0x30]
	ldrh r0, [r6]
	ldr r1, [sp, #0x80]
	strh r0, [r1]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	ldr r3, [sp, #0x58]
	str r0, [r3]
	ldr r4, [sp, #0x188]
	ldr r0, [r4]
	ldr r5, [sp, #0x5c]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	ldr r1, [sp, #0x154]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, [sp, #0x158]
	ldrb r0, [r3]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r5, [sp, #0x15c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r1, [sp, #0x88]
	ldr r0, [r1]
	ldr r2, [sp, #0x78]
	str r0, [r2]
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r5, _08166894 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _08166898 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r6, _0816689C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081668A0 @ =Slime_Update
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081668A4 @ =Slime_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081668A8
	movs r0, #0
	b _081668AC
	.align 2, 0
_08166880: .4byte Enemy_ClearStateBegun
_08166884: .4byte 0x0000046D
_08166888: .4byte 0x0000046B
_0816688C: .4byte 0x00000484
_08166890: .4byte 0x0000046C
_08166894: .4byte 0x0000057C
_08166898: .4byte Enemy_DispatchMsg
_0816689C: .4byte 0x0000061C
_081668A0: .4byte Slime_Update
_081668A4: .4byte Slime_Destroy
_081668A8:
	movs r0, #1
	rsbs r0, r0, #0
_081668AC:
	add sp, #0x1a0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
