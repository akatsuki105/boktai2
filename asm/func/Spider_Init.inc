	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1bc
	adds r7, r0, #0
	str r7, [sp, #0x30]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	mov r3, r8
	strh r3, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r4, _081311EC @ =0x000001DF
	adds r0, r7, r4
	movs r5, #2
	mov sb, r5
	mov r6, sb
	strb r6, [r0]
	adds r0, r7, #0
	bl Spider_InitAnims
	ldr r1, _081311F0 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081311FC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081311F4 @ =0x0000528F
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081311F8 @ =0x0000B6EE
	bl EnemyAuxSprite_LoadAnim
	ldr r2, _081311EC @ =0x000001DF
	adds r0, r7, r2
	ldrb r1, [r0]
	str r0, [sp, #0xb8]
	cmp r1, #0x11
	beq _081311DC
	cmp r1, #0x17
	bne _081311E0
_081311DC:
	movs r0, #1
	strb r0, [r5, #7]
_081311E0:
	movs r3, #0xef
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	b _08131266
	.align 2, 0
_081311EC: .4byte 0x000001DF
_081311F0: .4byte 0x0000025D
_081311F4: .4byte 0x0000528F
_081311F8: .4byte 0x0000B6EE
_081311FC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x20
	mov sl, r5
	mov r6, r8
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, sl
	ldr r2, _081312E4 @ =0x05000002
	bl CpuSet
	ldr r0, _081312E8 @ =0x0000CB05
	ldr r1, _081312EC @ =0x0000528F
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x20
	mov r6, sb
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r2, _081312F0 @ =0x000004B7
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _081312F4 @ =0x000001DF
	adds r3, r7, r3
	str r3, [sp, #0xb8]
_08131266:
	str r7, [sp, #0x38]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	movs r4, #0
	mov r5, sb
	str r4, [r5]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	str r4, [r6]
	ldr r1, _081312F8 @ =0x0000046F
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	mov sl, r3
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, _081312FC @ =0x00000474
	adds r6, r7, r5
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _081312E4 @ =0x05000002
	bl CpuSet
	ldr r0, _08131300 @ =0x000004B6
	adds r2, r7, r0
	mov r1, sl
	strb r1, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b8]
	bl VM_SeekToNamedArg
	mov r3, sb
	str r3, [sp, #0x84]
	mov r4, r8
	str r4, [sp, #0x8c]
	str r6, [sp, #0x68]
	ldr r2, [sp, #0x1b8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081312D4
	b _08131434
_081312D4:
	bl VM_GetPC
	cmp r0, #0
	beq _08131304
	bl VM_GetValue
	adds r1, r0, #0
	b _08131306
	.align 2, 0
_081312E4: .4byte 0x05000002
_081312E8: .4byte 0x0000CB05
_081312EC: .4byte 0x0000528F
_081312F0: .4byte 0x000004B7
_081312F4: .4byte 0x000001DF
_081312F8: .4byte 0x0000046F
_081312FC: .4byte 0x00000474
_08131300: .4byte 0x000004B6
_08131304:
	movs r1, #0
_08131306:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0813132C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x10c]
	str r4, [sp, #0x110]
	cmp r0, #0
	beq _08131330
	bl VM_GetValue
	adds r1, r0, #0
	b _08131332
	.align 2, 0
_0813132C: .4byte 0x00000251
_08131330:
	movs r1, #0
_08131332:
	ldr r2, _08131368 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813136C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x10c]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x114]
	cmp r0, #0
	beq _08131370
	bl VM_GetValue
	b _08131374
	.align 2, 0
_08131368: .4byte 0x00000252
_0813136C: .4byte 0x000004B4
_08131370:
	ldr r4, [sp, #0x10c]
	ldrb r0, [r4]
_08131374:
	strb r0, [r6]
	ldr r5, [sp, #0x10c]
	ldrb r1, [r5]
	ldr r6, [sp, #0x114]
	ldrb r2, [r6]
	add r0, sp, #0x28
	bl Map_GetPathNodePos
	add r0, sp, #0x28
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081313AC
	cmp r1, #0
	blt _081313AC
	ldr r0, _081313B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081313AC
	ldr r0, _081313B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081313B8
_081313AC:
	movs r1, #0
	b _081313C6
	.align 2, 0
_081313B0: .4byte 0x030046A8
_081313B4: .4byte 0x030046AC
_081313B8:
	ldr r0, _081313E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081313C6:
	ldr r2, _081313E4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081313E8
	adds r0, #4
	b _081313F4
	.align 2, 0
_081313E0: .4byte 0x030046A4
_081313E4: .4byte 0x00000256
_081313E8:
	ldr r0, _08131408 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081313F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813140C
	cmp r2, #2
	beq _08131410
	b _08131414
	.align 2, 0
_08131408: .4byte 0x030046A4
_0813140C:
	ldrb r0, [r4, #4]
	b _08131412
_08131410:
	ldrb r0, [r4]
_08131412:
	subs r1, r1, r0
_08131414:
	ldr r3, _0813142C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08131430 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x3c]
	b _08131474
	.align 2, 0
_0813142C: .4byte 0x00000472
_08131430: .4byte 0x0000FFFF
_08131434:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08131498 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813149C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081314A0 @ =0x000004B4
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
	str r0, [sp, #0x3c]
	str r5, [sp, #0x10c]
	str r4, [sp, #0x110]
	str r3, [sp, #0x114]
_08131474:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081314BE
	bl VM_GetPC
	cmp r0, #0
	beq _081314A4
	bl VM_GetValue
	adds r4, r0, #0
	b _081314A6
	.align 2, 0
_08131498: .4byte 0x00000251
_0813149C: .4byte 0x00000252
_081314A0: .4byte 0x000004B4
_081314A4:
	movs r4, #0x30
_081314A6:
	bl VM_GetPC
	cmp r0, #0
	beq _081314B8
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081314BA
_081314B8:
	movs r5, #0x40
_081314BA:
	mov r8, r4
	b _081314C4
_081314BE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081314C4:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081314FC
	bl VM_GetPC
	cmp r0, #0
	beq _081314DE
	bl VM_GetValue
	adds r6, r0, #0
	b _081314E0
_081314DE:
	movs r6, #0
_081314E0:
	bl VM_GetPC
	cmp r0, #0
	beq _081314F0
	bl VM_GetValue
	adds r1, r0, #0
	b _081314F2
_081314F0:
	movs r1, #0
_081314F2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08131506
_081314FC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08131506:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0813178C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x104]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x94]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x118]
	lsls r4, r4, #0x10
	str r4, [sp, #0xb4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xc0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xc4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xbc]
	ldr r4, _08131790 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x120]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xb0]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x48]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x4c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x50]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x44]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _08131794 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _08131798 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _0813179C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _081317A0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x88]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x11c]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x144]
	ldr r4, _081317A4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _081317A8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	ldr r1, _081317AC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	ldr r3, _081317B0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _081317B4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _081317B8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x124]
	ldr r1, _081317BC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _081317C0 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	ldr r4, _081317C4 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _081317C8 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x180]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x190]
	ldr r2, _081317CC @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x198]
	ldr r4, _081317D0 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	ldr r6, _081317D4 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x184]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x17c]
	ldr r3, _081317D8 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x188]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	ldr r6, _081317DC @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x1b0]
	ldr r1, _081317E0 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x130]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x40]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x154]
	ldr r4, _081317E4 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x138]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081317E8 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _081317EC @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x150]
	ldr r2, _081317F0 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	ldr r5, _081317F4 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081317F8 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081317FC @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r3, _08131800 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _08131804 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08131808 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x108]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	ldr r4, _0813180C @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	ldr r1, _08131810 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _08131814 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	ldr r4, _08131818 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	ldr r5, _0813181C @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xec]
	ldr r6, _08131820 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xf0]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	ldr r2, _08131824 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	cmp r0, #0
	bne _0813175C
	b _08131880
_0813175C:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_0813177C:
	bl VM_GetPC
	cmp r0, #0
	beq _08131828
	bl VM_GetValue
	b _0813182A
	.align 2, 0
_0813178C: .4byte 0x0000025D
_08131790: .4byte 0x0000025A
_08131794: .4byte 0x0000047A
_08131798: .4byte 0x0000047C
_0813179C: .4byte 0x0000047E
_081317A0: .4byte 0x000004A4
_081317A4: .4byte 0x000005A4
_081317A8: .4byte 0x000005C4
_081317AC: .4byte 0x000005CC
_081317B0: .4byte 0x000005D4
_081317B4: .4byte 0x000005DC
_081317B8: .4byte 0x00000584
_081317BC: .4byte 0x00000604
_081317C0: .4byte 0x0000021D
_081317C4: .4byte 0x0000060C
_081317C8: .4byte 0x000005E4
_081317CC: .4byte 0x000005FC
_081317D0: .4byte 0x00000614
_081317D4: .4byte 0x000005BC
_081317D8: .4byte 0x000005EC
_081317DC: .4byte 0x00000624
_081317E0: .4byte 0x0000058C
_081317E4: .4byte 0x00000594
_081317E8: .4byte 0x0000059C
_081317EC: .4byte 0x000005B4
_081317F0: .4byte 0x00000543
_081317F4: .4byte 0x00000496
_081317F8: .4byte 0x00000469
_081317FC: .4byte 0x0000046A
_08131800: .4byte 0x0000046D
_08131804: .4byte 0x0000046B
_08131808: .4byte 0x00000553
_0813180C: .4byte 0x00000572
_08131810: .4byte 0x0000055C
_08131814: .4byte 0x00000564
_08131818: .4byte 0x00000565
_0813181C: .4byte 0x00000566
_08131820: .4byte 0x00000567
_08131824: .4byte 0x0000056C
_08131828:
	movs r0, #0x18
_0813182A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0813183C
	bl VM_GetValue
	b _0813183E
_0813183C:
	movs r0, #0x18
_0813183E:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08131850
	bl VM_GetValue
	b _08131852
_08131850:
	movs r0, #0
_08131852:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08131864
	bl VM_GetValue
	b _08131866
_08131864:
	movs r0, #0
_08131866:
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
	bgt _08131880
	b _0813177C
_08131880:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081318CC
	bl VM_GetPC
	cmp r0, #0
	beq _0813189A
	bl VM_GetValue
	adds r4, r0, #0
	b _0813189E
_0813189A:
	movs r4, #0x96
	lsls r4, r4, #1
_0813189E:
	bl VM_GetPC
	cmp r0, #0
	beq _081318AE
	bl VM_GetValue
	adds r6, r0, #0
	b _081318B2
_081318AE:
	movs r6, #0x96
	lsls r6, r6, #1
_081318B2:
	bl VM_GetPC
	cmp r0, #0
	beq _081318C0
	bl VM_GetValue
	b _081318C6
_081318C0:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081318C6:
	ldr r2, [sp, #0x104]
	strh r0, [r2]
	b _081318D4
_081318CC:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x104]
	strh r6, [r3]
_081318D4:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081318EC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081318EC:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x98]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x94]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081319BC
	bl VM_GetPC
	cmp r0, #0
	beq _0813191C
	bl VM_GetValue
	b _0813191E
_0813191C:
	movs r0, #0
_0813191E:
	ldr r3, [sp, #0x118]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _0813192C
	asrs r1, r0, #1
	b _08131932
_0813192C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08131932:
	ldr r5, _08131948 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813194C
	bl VM_GetValue
	b _0813194E
	.align 2, 0
_08131948: .4byte 0x00000546
_0813194C:
	movs r0, #0
_0813194E:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08131964
	bl VM_GetValue
	b _08131966
_08131964:
	movs r0, #0
_08131966:
	ldr r3, _0813197C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08131980
	bl VM_GetValue
	adds r1, r0, #0
	b _08131982
	.align 2, 0
_0813197C: .4byte 0x00000187
_08131980:
	movs r1, #0
_08131982:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08131998
	bl VM_GetValue
	b _0813199A
_08131998:
	movs r0, #0
_0813199A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081319B2
	bl VM_GetValue
	adds r1, r0, #0
	b _081319B4
_081319B2:
	movs r1, #0
_081319B4:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081319BC:
	ldr r5, [sp, #0x118]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0xb4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xc0]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xc4]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xbc]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08131A1E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08131A04
	bl VM_GetValue
	b _08131A06
_08131A04:
	movs r0, #0
_08131A06:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08131A16
	bl VM_GetValue
	b _08131A18
_08131A16:
	movs r0, #0
_08131A18:
	ldr r6, _08131A80 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08131A1E:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x120]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08131A42
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08131A42:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08131A5A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x8c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08131A5A:
	ldr r4, [sp, #0xb0]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x38]
	add r2, sp, #0x28
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x68]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08131A84
	movs r0, #1
	b _08131A86
	.align 2, 0
_08131A80: .4byte 0x00000189
_08131A84:
	movs r0, #0
_08131A86:
	cmp r0, #0
	beq _08131A96
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08131AC0 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x38]
	bl CWolfTargetManager_Register
_08131A96:
	ldr r6, [sp, #0x128]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08131AA2
	ldr r1, [r7, #0x44]
_08131AA2:
	ldr r0, [sp, #0x38]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08131AC4
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08131AD0
	.align 2, 0
_08131AC0: .4byte Enemy_OnCWolfMessage
_08131AC4:
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08131AD0:
	ldr r2, [sp, #0xb8]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08131B1E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08131B1E
	cmp r0, #0x16
	beq _08131B1E
	cmp r0, #0x14
	beq _08131B1E
	cmp r0, #9
	beq _08131B1E
	cmp r0, #0x19
	beq _08131B1E
	cmp r0, #0x1a
	beq _08131B1E
	cmp r0, #0xd
	beq _08131B1E
	cmp r0, #0x1b
	beq _08131B1E
	cmp r0, #0x1f
	beq _08131B1E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x10c]
	ldrb r2, [r3]
	ldr r4, [sp, #0x110]
	ldrb r3, [r4]
	ldr r5, [sp, #0x114]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	bl Mover_SetPath
_08131B1E:
	movs r1, #8
	ldr r6, [sp, #0x68]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08131B2E
	movs r0, #1
	b _08131B30
_08131B2E:
	movs r0, #0
_08131B30:
	cmp r0, #0
	beq _08131B3E
	ldr r1, [sp, #0xcc]
	ldr r0, [r1]
	ldr r2, [sp, #0xc8]
	str r0, [r2]
	b _08131B50
_08131B3E:
	ldr r3, [sp, #0xcc]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xc8]
	str r0, [r4]
_08131B50:
	ldrh r0, [r7]
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
	ldr r6, [sp, #0x44]
	ldr r0, [sp, #0x50]
	str r6, [r0]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _08131B7A
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
	ldr r2, [sp, #0x38]
	strb r0, [r2, #5]
_08131B7A:
	movs r4, #0x8f
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x78]
	strh r0, [r3]
	ldr r6, [sp, #0x6c]
	strh r4, [r6]
	ldr r0, [sp, #0x70]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0x8f
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x128]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08131BB4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08131BC0
_08131BB4:
	ldr r2, [r7, #0x44]
	ldr r0, _08131BF8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08131BC0:
	ldr r3, [sp, #0x128]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08131C10
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08131BFC
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
	b _08131C06
	.align 2, 0
_08131BF8: .4byte 0x03003584
_08131BFC:
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08131C06:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08131C10:
	adds r0, r7, #0
	bl Spider_InitHitboxes
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x34]
	movs r0, #0x54
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08131C3C
	ldr r6, [sp, #0x30]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2]
_08131C3C:
	ldr r1, [sp, #0x30]
	ldr r2, _08131D98 @ =0x00000664
	adds r0, r1, r2
	movs r3, #0xd1
	lsls r3, r3, #3
	adds r1, r1, r3
	mov r8, r1
	ldr r4, _08131D9C @ =FUN_081310b8
	mov sb, r4
	ldr r5, _08131DA0 @ =Spider_GetMoveSpeed
	mov sl, r5
	ldr r6, _08131DA4 @ =Spider_StateTurn
	mov ip, r6
	movs r4, #0
	ldr r5, _08131DA8 @ =Spider_StateDamaged
	ldr r3, _08131DAC @ =FUN_080f62b0
	ldr r1, _08131DB0 @ =FUN_080f62ac
	str r1, [sp, #0x1b4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x84]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x90]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x12c]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x134]
	str r2, [r6]
	ldr r1, _08131DB4 @ =FUN_0812ea6c
	ldr r2, [sp, #0x144]
	str r1, [r2]
	ldr r6, _08131DB8 @ =FUN_0812ea90
	ldr r1, [sp, #0x148]
	str r6, [r1]
	ldr r2, _08131DBC @ =FUN_0812f1b4
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r1, [sp, #0x160]
	str r3, [r1]
	ldr r2, [sp, #0x168]
	str r5, [r2]
	ldr r3, _08131DC0 @ =Spider_StateDying
	ldr r5, [sp, #0x16c]
	str r3, [r5]
	ldr r1, _08131DC4 @ =FUN_080f44f4
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r1, _08131DC8 @ =FUN_080f410c
	ldr r2, [sp, #0x178]
	str r1, [r2]
	ldr r3, [sp, #0x164]
	str r4, [r3]
	ldr r5, _08131DCC @ =FUN_0812f1b8
	ldr r6, [sp, #0x124]
	str r5, [r6]
	ldr r1, [sp, #0x1b4]
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _08131DD0 @ =FUN_080f0430
	ldr r3, [sp, #0x1a0]
	str r1, [r3]
	movs r6, #1
	ldr r5, [sp, #0xd4]
	strb r6, [r5]
	ldr r1, _08131DD4 @ =0x085AD470
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _08131DD8 @ =FUN_080e73c8
	ldr r3, [sp, #0x18c]
	str r1, [r3]
	ldr r5, [sp, #0x180]
	str r4, [r5]
	ldr r6, [sp, #0x190]
	str r4, [r6]
	ldr r1, [sp, #0x194]
	str r4, [r1]
	ldr r2, [sp, #0x198]
	str r4, [r2]
	ldr r3, [sp, #0x1a8]
	str r4, [r3]
	ldr r1, _08131DDC @ =FUN_080f0320
	ldr r5, [sp, #0x1ac]
	str r1, [r5]
	ldr r1, _08131DE0 @ =Enemy_080eff14
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, _08131DE4 @ =FUN_080e72b0
	ldr r2, [sp, #0x184]
	str r1, [r2]
	ldr r3, [sp, #0x17c]
	str r4, [r3]
	ldr r1, _08131DE8 @ =Enemy_StateBlownAway
	ldr r5, [sp, #0x188]
	str r1, [r5]
	ldr r1, _08131DEC @ =Enemy_StateFallDeath
	ldr r6, [sp, #0x174]
	str r1, [r6]
	ldr r1, [sp, #0x14c]
	str r4, [r1]
	ldr r1, _08131DF0 @ =FUN_080f6e64
	ldr r2, [sp, #0x1b0]
	str r1, [r2]
	ldr r1, _08131DF4 @ =Enemy_OnDamaged
	ldr r3, [sp, #0x130]
	str r1, [r3]
	ldr r1, _08131DF8 @ =FUN_080f84d4
	ldr r5, [sp, #0x40]
	str r1, [r5]
	ldr r1, _08131DFC @ =FUN_080f624c
	ldr r6, [sp, #0x154]
	str r1, [r6]
	ldr r1, _08131E00 @ =FUN_080f56ec
	ldr r2, [sp, #0x138]
	str r1, [r2]
	ldr r1, _08131E04 @ =FUN_080f5b34
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r1, _08131E08 @ =FUN_080f5fac
	ldr r5, [sp, #0x140]
	str r1, [r5]
	ldr r6, [sp, #0x150]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xd0]
	strb r1, [r2]
	ldr r1, [sp, #0x44]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	ldr r3, _08131E0C @ =0x0000060C
	adds r1, r7, r3
	ldr r0, _08131E10 @ =0x085AD710
	str r0, [r1]
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08131E14 @ =Spider_OnReset
	str r0, [r1]
	ldr r6, _08131E18 @ =0x000005AC
	adds r0, r7, r6
	str r4, [r0]
	movs r1, #0xb6
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08131E1C @ =FUN_0812f358
	str r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08131E24
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08131E20 @ =FUN_08130d34
	b _08131E2C
	.align 2, 0
_08131D98: .4byte 0x00000664
_08131D9C: .4byte FUN_081310b8
_08131DA0: .4byte Spider_GetMoveSpeed
_08131DA4: .4byte Spider_StateTurn
_08131DA8: .4byte Spider_StateDamaged
_08131DAC: .4byte FUN_080f62b0
_08131DB0: .4byte FUN_080f62ac
_08131DB4: .4byte FUN_0812ea6c
_08131DB8: .4byte FUN_0812ea90
_08131DBC: .4byte FUN_0812f1b4
_08131DC0: .4byte Spider_StateDying
_08131DC4: .4byte FUN_080f44f4
_08131DC8: .4byte FUN_080f410c
_08131DCC: .4byte FUN_0812f1b8
_08131DD0: .4byte FUN_080f0430
_08131DD4: .4byte 0x085AD470
_08131DD8: .4byte FUN_080e73c8
_08131DDC: .4byte FUN_080f0320
_08131DE0: .4byte Enemy_080eff14
_08131DE4: .4byte FUN_080e72b0
_08131DE8: .4byte Enemy_StateBlownAway
_08131DEC: .4byte Enemy_StateFallDeath
_08131DF0: .4byte FUN_080f6e64
_08131DF4: .4byte Enemy_OnDamaged
_08131DF8: .4byte FUN_080f84d4
_08131DFC: .4byte FUN_080f624c
_08131E00: .4byte FUN_080f56ec
_08131E04: .4byte FUN_080f5b34
_08131E08: .4byte FUN_080f5fac
_08131E0C: .4byte 0x0000060C
_08131E10: .4byte 0x085AD710
_08131E14: .4byte Spider_OnReset
_08131E18: .4byte 0x000005AC
_08131E1C: .4byte FUN_0812f358
_08131E20: .4byte FUN_08130d34
_08131E24:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08131E70 @ =FUN_08130ac4
_08131E2C:
	str r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #0xf
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #8
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x9c]
	strh r0, [r3]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08131E7E
	movs r4, #0xce
	lsls r4, r4, #1
	adds r5, r7, r4
	movs r4, #4
_08131E62:
	bl VM_GetPC
	cmp r0, #0
	beq _08131E74
	bl VM_GetValue
	b _08131E76
	.align 2, 0
_08131E70: .4byte FUN_08130ac4
_08131E74:
	movs r0, #0
_08131E76:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08131E62
_08131E7E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0xa0]
	strh r0, [r5]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r6, [sp, #0x80]
	strh r0, [r6]
	cmp r2, #0
	beq _08131EB6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r3, [sp, #0x84]
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	cmp r2, #2
	bne _08131EB6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r3]
_08131EB6:
	movs r2, #0
	movs r1, #4
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08131EC8
	movs r0, #1
	b _08131ECA
_08131EC8:
	movs r0, #0
_08131ECA:
	cmp r0, #0
	beq _08131EDC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r2, #1
_08131EDC:
	cmp r2, #1
	beq _08131F14
	movs r1, #0
	ldr r6, [sp, #0x54]
	strb r1, [r6]
	ldr r0, [sp, #0x58]
	strb r1, [r0]
	ldr r2, [sp, #0x5c]
	strb r1, [r2]
	ldr r3, _08131F24 @ =0x00000484
	adds r0, r7, r3
	str r1, [r0]
	ldr r4, _08131F28 @ =0x0000046C
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, [sp, #0x148]
	ldr r0, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r2, [sp, #0x60]
	strb r1, [r2]
	ldr r3, [sp, #0xd8]
	strb r1, [r3]
	ldr r4, [sp, #0x108]
	str r0, [r4]
	ldr r5, [sp, #0xa8]
	strh r1, [r5]
_08131F14:
	movs r1, #2
	ldr r6, [sp, #0x68]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08131F2C
	movs r0, #1
	b _08131F2E
	.align 2, 0
_08131F24: .4byte 0x00000484
_08131F28: .4byte 0x0000046C
_08131F2C:
	movs r0, #0
_08131F2E:
	cmp r0, #0
	beq _08131F48
	ldr r0, _08131F44 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x7c]
	strh r0, [r2]
	b _08131F52
	.align 2, 0
_08131F44: .4byte 0x030046A0
_08131F48:
	ldr r0, [sp, #0x44]
	bl GetZoneAt
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
_08131F52:
	movs r1, #0x40
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08131F62
	movs r0, #1
	b _08131F64
_08131F62:
	movs r0, #0
_08131F64:
	cmp r0, #0
	beq _08131F74
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08131F98 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08131F74:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08131FA6
	ldr r0, _08131F9C @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x7c]
	ldrh r6, [r6]
	cmp r0, r6
	bne _08131FA0
	movs r0, #1
	b _08131FA2
	.align 2, 0
_08131F98: .4byte 0xFFFFFEFF
_08131F9C: .4byte 0x030046A0
_08131FA0:
	movs r0, #0
_08131FA2:
	cmp r0, #0
	bne _08131FAE
_08131FA6:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_08131FAE:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, [sp, #0x128]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08132096
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
	beq _08131FF0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08131FF8
_08131FF0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08131FF8:
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
	beq _0813201C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08132024
_0813201C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08132024:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0813205C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081320A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08132060
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08132054
	ldrb r0, [r4, #5]
_08132054:
	subs r0, #1
	strh r0, [r4, #8]
	b _08132070
	.align 2, 0
_0813205C: .4byte 0x0000FFFF
_08132060:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _08132070
	strh r1, [r4, #8]
_08132070:
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
	bne _081320A0
	movs r0, #1
	strb r0, [r4, #7]
	b _081320A0
_08132096:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081320A0:
	movs r0, #0
	ldr r1, [sp, #0xac]
	str r0, [r1]
	ldr r0, _081320B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081320BC
	movs r0, #1
	b _081320BE
	.align 2, 0
_081320B8: .4byte 0x030047A4
_081320BC:
	movs r0, #0
_081320BE:
	cmp r0, #0
	bne _081320FE
	ldr r2, [sp, #0xb8]
	ldrb r1, [r2]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081320E6
	adds r0, r1, #0
	cmp r0, #7
	beq _081320E6
	cmp r0, #6
	beq _081320E6
	cmp r0, #0x15
	beq _081320E6
	cmp r0, #0x14
	beq _081320E6
	cmp r0, #0x17
	bne _081320FE
_081320E6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, [sp, #0x68]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
_081320FE:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_081300d0
	ldr r4, [sp, #0x34]
	cmp r4, #0
	beq _081321B8
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r4, #0
	movs r2, #0
	mov r6, sp
	ldrh r6, [r6, #0x34]
	strh r6, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081321A4 @ =FUN_0812edf8
	movs r0, #0x22
	movs r5, #1
	ldr r3, [sp, #0x64]
	strb r5, [r3]
	ldr r6, [sp, #0x60]
	strb r4, [r6]
	ldr r3, [sp, #0xd8]
	strb r0, [r3]
	ldr r6, [sp, #0x108]
	str r1, [r6]
	ldr r0, [sp, #0xa8]
	strh r2, [r0]
	movs r0, #3
	ldr r1, [sp, #0x54]
	strb r0, [r1]
	ldr r3, [sp, #0x58]
	strb r4, [r3]
	ldr r6, [sp, #0x5c]
	strb r4, [r6]
	ldr r1, _081321A8 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r3, _081321AC @ =0x0000046C
	adds r0, r7, r3
	strb r5, [r0]
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #0x60
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	movs r1, #0xa0
	lsls r1, r1, #4
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r1, [sp, #0x44]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	ldr r6, _081321B0 @ =0x0000044C
	adds r1, r7, r6
	strb r0, [r1]
	ldr r1, _081321B4 @ =0x0000044D
	adds r0, r7, r1
	strb r5, [r0]
	ldr r3, [sp, #0x30]
	movs r4, #0xcc
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	b _0813221A
	.align 2, 0
_081321A4: .4byte FUN_0812edf8
_081321A8: .4byte 0x00000484
_081321AC: .4byte 0x0000046C
_081321B0: .4byte 0x0000044C
_081321B4: .4byte 0x0000044D
_081321B8:
	ldr r1, _081322A0 @ =FUN_080e68d8
	movs r0, #0xe
	movs r3, #1
	ldr r5, [sp, #0x64]
	strb r3, [r5]
	add r6, sp, #0x34
	ldrb r2, [r6]
	ldr r6, [sp, #0x60]
	strb r2, [r6]
	ldr r2, [sp, #0xd8]
	strb r0, [r2]
	ldr r4, [sp, #0x108]
	str r1, [r4]
	movs r5, #0
	mov r6, sp
	ldrh r0, [r6, #0x34]
	ldr r6, [sp, #0xa8]
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #7
	mov r8, r2
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081322A4 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r4, _081322A8 @ =0x00000552
	adds r0, r7, r4
	mov r5, r8
	strb r5, [r0]
	ldr r6, _081322AC @ =0x0000044C
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _081322B0 @ =0x0000044D
	adds r0, r7, r1
	strb r3, [r0]
_0813221A:
	ldr r2, [sp, #0x30]
	ldr r3, _081322B4 @ =0x00000662
	adds r1, r2, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ldr r5, [sp, #0x100]
	strh r0, [r5]
	ldr r6, [sp, #0xa4]
	ldrh r0, [r6]
	ldr r1, [sp, #0xfc]
	strh r0, [r1]
	ldr r2, [sp, #0x84]
	ldr r0, [r2]
	ldr r3, [sp, #0xdc]
	str r0, [r3]
	ldr r4, [sp, #0x8c]
	ldr r0, [r4]
	ldr r5, [sp, #0xe0]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r2, [sp, #0xe8]
	strb r0, [r2]
	ldr r3, [sp, #0x58]
	ldrb r0, [r3]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x5c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x108]
	ldr r0, [r1]
	ldr r2, [sp, #0xf4]
	str r0, [r2]
	ldr r3, [sp, #0xd8]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf8]
	strb r0, [r4]
	ldr r5, _081322B8 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081322BC @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r6, _081322C0 @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081322C4 @ =Spider_Update
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081322C8 @ =Spider_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081322CC
	movs r0, #0
	b _081322D0
	.align 2, 0
_081322A0: .4byte FUN_080e68d8
_081322A4: .4byte 0x00000551
_081322A8: .4byte 0x00000552
_081322AC: .4byte 0x0000044C
_081322B0: .4byte 0x0000044D
_081322B4: .4byte 0x00000662
_081322B8: .4byte 0x0000057C
_081322BC: .4byte Enemy_DispatchMsg
_081322C0: .4byte 0x0000061C
_081322C4: .4byte Spider_Update
_081322C8: .4byte Spider_Destroy
_081322CC:
	movs r0, #1
	rsbs r0, r0, #0
_081322D0:
	add sp, #0x1bc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
