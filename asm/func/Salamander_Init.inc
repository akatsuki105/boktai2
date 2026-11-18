	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1e0
	adds r7, r0, #0
	str r7, [sp, #0x30]
	movs r1, #0xca
	lsls r1, r1, #4
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _081AD1F4 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1f
	strb r0, [r1]
	adds r0, r7, #0
	bl Salamander_InitAnims
	ldr r3, _081AD1F8 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AD204
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081AD1FC @ =0x0000D636
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _081AD200 @ =0x0000C102
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _081AD1F4 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x60]
	cmp r1, #0x11
	beq _081AD1E2
	cmp r1, #0x17
	bne _081AD1E6
_081AD1E2:
	movs r0, #1
	strb r0, [r5, #7]
_081AD1E6:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081AD26C
	.align 2, 0
_081AD1F4: .4byte 0x000001DF
_081AD1F8: .4byte 0x0000025D
_081AD1FC: .4byte 0x0000D636
_081AD200: .4byte 0x0000C102
_081AD204:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x20
	mov r8, r0
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, r8
	ldr r2, _081AD2E8 @ =0x05000002
	bl CpuSet
	ldr r0, _081AD2EC @ =0x0000CB05
	ldr r1, _081AD2F0 @ =0x0000D636
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
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r0, _081AD2F4 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081AD2F8 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x60]
_081AD26C:
	str r7, [sp, #0x34]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _081AD2FC @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, _081AD300 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _081AD2E8 @ =0x05000002
	bl CpuSet
	ldr r3, _081AD304 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1d8]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x1b0]
	mov r3, r8
	str r3, [sp, #0x1b4]
	str r6, [sp, #0x188]
	ldr r2, [sp, #0x1d8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081AD2D8
	b _081AD438
_081AD2D8:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD308
	bl VM_GetValue
	adds r1, r0, #0
	b _081AD30A
	.align 2, 0
_081AD2E8: .4byte 0x05000002
_081AD2EC: .4byte 0x0000CB05
_081AD2F0: .4byte 0x0000D636
_081AD2F4: .4byte 0x000004B7
_081AD2F8: .4byte 0x000001DF
_081AD2FC: .4byte 0x0000046F
_081AD300: .4byte 0x00000474
_081AD304: .4byte 0x000004B6
_081AD308:
	movs r1, #0
_081AD30A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081AD330 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf4]
	str r4, [sp, #0xf8]
	cmp r0, #0
	beq _081AD334
	bl VM_GetValue
	adds r1, r0, #0
	b _081AD336
	.align 2, 0
_081AD330: .4byte 0x00000251
_081AD334:
	movs r1, #0
_081AD336:
	ldr r2, _081AD36C @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081AD370 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf4]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x100]
	cmp r0, #0
	beq _081AD374
	bl VM_GetValue
	b _081AD378
	.align 2, 0
_081AD36C: .4byte 0x00000252
_081AD370: .4byte 0x000004B4
_081AD374:
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4]
_081AD378:
	strb r0, [r6]
	ldr r5, [sp, #0xf4]
	ldrb r1, [r5]
	ldr r6, [sp, #0x100]
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
	blt _081AD3B0
	cmp r1, #0
	blt _081AD3B0
	ldr r0, _081AD3B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AD3B0
	ldr r0, _081AD3B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AD3BC
_081AD3B0:
	movs r1, #0
	b _081AD3CA
	.align 2, 0
_081AD3B4: .4byte 0x030046A8
_081AD3B8: .4byte 0x030046AC
_081AD3BC:
	ldr r0, _081AD3E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081AD3CA:
	ldr r2, _081AD3E8 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AD3EC
	adds r0, #4
	b _081AD3F8
	.align 2, 0
_081AD3E4: .4byte 0x030046A4
_081AD3E8: .4byte 0x00000256
_081AD3EC:
	ldr r0, _081AD40C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AD3F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AD410
	cmp r2, #2
	beq _081AD414
	b _081AD418
	.align 2, 0
_081AD40C: .4byte 0x030046A4
_081AD410:
	ldrb r0, [r4, #4]
	b _081AD416
_081AD414:
	ldrb r0, [r4]
_081AD416:
	subs r1, r1, r0
_081AD418:
	ldr r3, _081AD430 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081AD434 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _081AD478
	.align 2, 0
_081AD430: .4byte 0x00000472
_081AD434: .4byte 0x0000FFFF
_081AD438:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081AD49C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081AD4A0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081AD4A4 @ =0x000004B4
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
	str r0, [sp, #0x38]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xf8]
	str r3, [sp, #0x100]
_081AD478:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081AD4C2
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4A8
	bl VM_GetValue
	adds r4, r0, #0
	b _081AD4AA
	.align 2, 0
_081AD49C: .4byte 0x00000251
_081AD4A0: .4byte 0x00000252
_081AD4A4: .4byte 0x000004B4
_081AD4A8:
	movs r4, #0x30
_081AD4AA:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4BC
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081AD4BE
_081AD4BC:
	movs r5, #0x40
_081AD4BE:
	mov r8, r4
	b _081AD4C8
_081AD4C2:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081AD4C8:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081AD500
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4E2
	bl VM_GetValue
	adds r6, r0, #0
	b _081AD4E4
_081AD4E2:
	movs r6, #0
_081AD4E4:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4F4
	bl VM_GetValue
	adds r1, r0, #0
	b _081AD4F6
_081AD4F4:
	movs r1, #0
_081AD4F6:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081AD50A
_081AD500:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081AD50A:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _081AD7CC @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x114]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xec]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1bc]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x1b8]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x104]
	lsls r4, r4, #0x10
	str r4, [sp, #0x58]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x68]
	lsls r6, r6, #0x10
	str r6, [sp, #0x70]
	lsls r5, r5, #0x10
	str r5, [sp, #0x64]
	ldr r4, _081AD7D0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x110]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x48]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x160]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x88]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x164]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x168]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x15c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _081AD7D4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _081AD7D8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x190]
	ldr r3, _081AD7DC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x194]
	ldr r4, _081AD7E0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	ldr r4, _081AD7E4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xcc]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe4]
	ldr r6, _081AD7E8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _081AD7EC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x108]
	ldr r3, _081AD7F0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	ldr r4, _081AD7F4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081AD7F8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r1, _081AD7FC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x140]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x144]
	ldr r3, _081AD800 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	ldr r4, _081AD804 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081AD808 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081AD80C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	ldr r4, _081AD810 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _081AD814 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x120]
	ldr r3, _081AD818 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd0]
	ldr r6, _081AD81C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x154]
	ldr r1, _081AD820 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x158]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	ldr r4, _081AD824 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xb8]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _081AD828 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	ldr r1, _081AD82C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _081AD830 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x1cc]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1c0]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x1c4]
	ldr r5, _081AD834 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x1a4]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x170]
	ldr r1, _081AD838 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081AD83C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _081AD840 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	ldr r4, _081AD844 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _081AD848 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x184]
	ldr r6, _081AD84C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _081AD850 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x50]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1d0]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a0]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x16c]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	movs r1, #0xab
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _081AD854 @ =0x00000554
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #0xaa
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081AD858 @ =0x00000551
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081AD85C @ =0x00000552
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	movs r1, #0xca
	lsls r1, r1, #4
	ldr r6, [sp, #0x30]
	adds r1, r6, r1
	str r1, [sp, #0xd4]
	ldr r2, _081AD860 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0x9c]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1c8]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x98]
	ldr r5, _081AD864 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081AD868 @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _081AD86C @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0x80]
	ldr r3, _081AD870 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0x84]
	ldr r4, _081AD874 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	ldr r6, _081AD878 @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0x94]
	cmp r0, #0
	bne _081AD79E
	b _081AD8D4
_081AD79E:
	movs r0, #0
	mov sl, r0
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r4, r7, r6
_081AD7BE:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD87C
	bl VM_GetValue
	b _081AD87E
	.align 2, 0
_081AD7CC: .4byte 0x0000025D
_081AD7D0: .4byte 0x0000025A
_081AD7D4: .4byte 0x0000047A
_081AD7D8: .4byte 0x0000047C
_081AD7DC: .4byte 0x0000047E
_081AD7E0: .4byte 0x000004A4
_081AD7E4: .4byte 0x000005A4
_081AD7E8: .4byte 0x000005C4
_081AD7EC: .4byte 0x000005CC
_081AD7F0: .4byte 0x000005D4
_081AD7F4: .4byte 0x000005DC
_081AD7F8: .4byte 0x00000584
_081AD7FC: .4byte 0x00000604
_081AD800: .4byte 0x0000021D
_081AD804: .4byte 0x0000060C
_081AD808: .4byte 0x000005E4
_081AD80C: .4byte 0x000005FC
_081AD810: .4byte 0x00000614
_081AD814: .4byte 0x000005BC
_081AD818: .4byte 0x000005EC
_081AD81C: .4byte 0x00000624
_081AD820: .4byte 0x0000058C
_081AD824: .4byte 0x00000594
_081AD828: .4byte 0x0000059C
_081AD82C: .4byte 0x000005B4
_081AD830: .4byte 0x00000543
_081AD834: .4byte 0x00000496
_081AD838: .4byte 0x00000469
_081AD83C: .4byte 0x0000046A
_081AD840: .4byte 0x00000484
_081AD844: .4byte 0x0000046C
_081AD848: .4byte 0x0000046D
_081AD84C: .4byte 0x0000046B
_081AD850: .4byte 0x00000553
_081AD854: .4byte 0x00000554
_081AD858: .4byte 0x00000551
_081AD85C: .4byte 0x00000552
_081AD860: .4byte 0x00000572
_081AD864: .4byte 0x0000055C
_081AD868: .4byte 0x00000564
_081AD86C: .4byte 0x00000565
_081AD870: .4byte 0x00000566
_081AD874: .4byte 0x00000567
_081AD878: .4byte 0x0000056C
_081AD87C:
	movs r0, #0x18
_081AD87E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081AD890
	bl VM_GetValue
	b _081AD892
_081AD890:
	movs r0, #0x18
_081AD892:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8A4
	bl VM_GetValue
	b _081AD8A6
_081AD8A4:
	movs r0, #0
_081AD8A6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8B8
	bl VM_GetValue
	b _081AD8BA
_081AD8B8:
	movs r0, #0
_081AD8BA:
	strh r0, [r6]
	movs r0, #2
	add sb, r0
	movs r1, #4
	add r8, r1
	adds r5, #2
	adds r4, #2
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	bgt _081AD8D4
	b _081AD7BE
_081AD8D4:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081AD920
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8EE
	bl VM_GetValue
	adds r4, r0, #0
	b _081AD8F2
_081AD8EE:
	movs r4, #0x96
	lsls r4, r4, #1
_081AD8F2:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD902
	bl VM_GetValue
	adds r6, r0, #0
	b _081AD906
_081AD902:
	movs r6, #0x96
	lsls r6, r6, #1
_081AD906:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD914
	bl VM_GetValue
	b _081AD91A
_081AD914:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_081AD91A:
	ldr r1, [sp, #0xec]
	strh r0, [r1]
	b _081AD928
_081AD920:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xec]
	strh r6, [r2]
_081AD928:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081AD940
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x1b4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081AD940:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x1bc]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x1b8]
	strh r0, [r1]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081ADA10
	bl VM_GetPC
	cmp r0, #0
	beq _081AD970
	bl VM_GetValue
	b _081AD972
_081AD970:
	movs r0, #0
_081AD972:
	ldr r2, [sp, #0x104]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081AD980
	asrs r1, r0, #1
	b _081AD986
_081AD980:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081AD986:
	ldr r3, _081AD99C @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9A0
	bl VM_GetValue
	b _081AD9A2
	.align 2, 0
_081AD99C: .4byte 0x00000546
_081AD9A0:
	movs r0, #0
_081AD9A2:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9B8
	bl VM_GetValue
	b _081AD9BA
_081AD9B8:
	movs r0, #0
_081AD9BA:
	ldr r2, _081AD9D0 @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9D4
	bl VM_GetValue
	adds r1, r0, #0
	b _081AD9D6
	.align 2, 0
_081AD9D0: .4byte 0x00000187
_081AD9D4:
	movs r1, #0
_081AD9D6:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9EC
	bl VM_GetValue
	b _081AD9EE
_081AD9EC:
	movs r0, #0
_081AD9EE:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA06
	bl VM_GetValue
	adds r1, r0, #0
	b _081ADA08
_081ADA06:
	movs r1, #0
_081ADA08:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081ADA10:
	ldr r3, [sp, #0x104]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r4, [sp, #0x58]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0x68]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0x70]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x64]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081ADA72
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA58
	bl VM_GetValue
	b _081ADA5A
_081ADA58:
	movs r0, #0
_081ADA5A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA6A
	bl VM_GetValue
	b _081ADA6C
_081ADA6A:
	movs r0, #0
_081ADA6C:
	ldr r3, _081ADAD4 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081ADA72:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0x110]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081ADA96
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x1b4]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081ADA96:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081ADAAE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x1b4]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081ADAAE:
	ldr r0, [sp, #0x48]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x34]
	add r2, sp, #0x28
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x188]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081ADAD8
	movs r0, #1
	b _081ADADA
	.align 2, 0
_081ADAD4: .4byte 0x00000189
_081ADAD8:
	movs r0, #0
_081ADADA:
	cmp r0, #0
	beq _081ADAEA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081ADB14 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x34]
	bl CWolfTargetManager_Register
_081ADAEA:
	ldr r3, [sp, #0x114]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081ADAF6
	ldr r1, [r7, #0x44]
_081ADAF6:
	ldr r0, [sp, #0x34]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081ADB18
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x160]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _081ADB24
	.align 2, 0
_081ADB14: .4byte Enemy_OnCWolfMessage
_081ADB18:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x160]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_081ADB24:
	ldr r5, [sp, #0x60]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081ADB72
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081ADB72
	cmp r0, #0x16
	beq _081ADB72
	cmp r0, #0x14
	beq _081ADB72
	cmp r0, #9
	beq _081ADB72
	cmp r0, #0x19
	beq _081ADB72
	cmp r0, #0x1a
	beq _081ADB72
	cmp r0, #0xd
	beq _081ADB72
	cmp r0, #0x1b
	beq _081ADB72
	cmp r0, #0x1f
	beq _081ADB72
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf4]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf8]
	ldrb r3, [r0]
	ldr r4, [sp, #0x100]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl Mover_SetPath
_081ADB72:
	movs r1, #8
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081ADB82
	movs r0, #1
	b _081ADB84
_081ADB82:
	movs r0, #0
_081ADB84:
	cmp r0, #0
	beq _081ADB92
	ldr r6, [sp, #0x88]
	ldr r0, [r6]
	ldr r1, [sp, #0x78]
	str r0, [r1]
	b _081ADBA4
_081ADB92:
	ldr r2, [sp, #0x88]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x78]
	str r0, [r3]
_081ADBA4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x164]
	strh r0, [r4]
	ldr r5, [sp, #0x15c]
	ldr r6, [sp, #0x168]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _081ADBCE
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
	ldr r1, [sp, #0x34]
	strb r0, [r1, #5]
_081ADBCE:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081ADCC0
	bl VM_GetPC
	cmp r0, #0
	beq _081ADBE6
	bl VM_GetValue
	b _081ADBE8
_081ADBE6:
	movs r0, #0
_081ADBE8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADBF8
	bl VM_GetValue
	b _081ADBFA
_081ADBF8:
	movs r0, #0
_081ADBFA:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADC0A
	bl VM_GetValue
	b _081ADC0C
_081ADC0A:
	movs r0, #0
_081ADC0C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x15c]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081ADC34
	cmp r1, #0
	blt _081ADC34
	ldr r0, _081ADC38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ADC34
	ldr r0, _081ADC3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ADC40
_081ADC34:
	movs r1, #0
	b _081ADC4E
	.align 2, 0
_081ADC38: .4byte 0x030046A8
_081ADC3C: .4byte 0x030046AC
_081ADC40:
	ldr r0, _081ADC68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081ADC4E:
	ldr r4, _081ADC6C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x15c]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ADC70
	adds r0, #4
	b _081ADC7C
	.align 2, 0
_081ADC68: .4byte 0x030046A4
_081ADC6C: .4byte 0x00000256
_081ADC70:
	ldr r0, _081ADC90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ADC7C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081ADC94
	cmp r3, #2
	beq _081ADC98
	b _081ADC9C
	.align 2, 0
_081ADC90: .4byte 0x030046A4
_081ADC94:
	ldrb r0, [r5, #4]
	b _081ADC9A
_081ADC98:
	ldrb r0, [r5]
_081ADC9A:
	subs r2, r2, r0
_081ADC9C:
	ldr r5, _081ADCDC @ =0x00000472
	adds r1, r7, r5
	strh r2, [r1]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r2
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	ldr r1, _081ADCE0 @ =0x00000CF8
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_081ADCC0:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081ADCF2
	bl VM_GetPC
	cmp r0, #0
	beq _081ADCE4
	bl VM_GetValue
	adds r1, r0, #0
	b _081ADCEA
	.align 2, 0
_081ADCDC: .4byte 0x00000472
_081ADCE0: .4byte 0x00000CF8
_081ADCE4:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r2, #0
_081ADCEA:
	ldr r3, [sp, #0x30]
	ldr r4, _081ADD50 @ =0x00000C4A
	adds r0, r3, r4
	strh r1, [r0]
_081ADCF2:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x30]
	movs r6, #0xc4
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r2, #0
	strh r0, [r1]
	ldr r1, _081ADD54 @ =0x00000C48
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r7, #0
	bl Salamander_ResetRecentTiles
	ldr r4, _081ADD58 @ =0x000001A5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x198]
	strh r0, [r2]
	ldr r3, [sp, #0x18c]
	strh r4, [r3]
	ldr r4, [sp, #0x190]
	strh r5, [r4]
	ldrh r0, [r2]
	adds r5, #0x73
	adds r0, r0, r5
	ldr r6, [sp, #0x194]
	strh r0, [r6]
	ldrh r1, [r3]
	ldrh r0, [r2]
	adds r1, r1, r0
	ldr r2, [sp, #0x114]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081ADD5C
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081ADD68
	.align 2, 0
_081ADD50: .4byte 0x00000C4A
_081ADD54: .4byte 0x00000C48
_081ADD58: .4byte 0x000001A5
_081ADD5C:
	ldr r2, [r7, #0x44]
	ldr r0, _081ADDA0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081ADD68:
	ldr r3, [sp, #0x114]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081ADDB8
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081ADDA4
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
	b _081ADDAE
	.align 2, 0
_081ADDA0: .4byte 0x03003584
_081ADDA4:
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_081ADDAE:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081ADDB8:
	adds r0, r7, #0
	bl Salamander_InitHitboxes
	adds r0, r7, #0
	bl Salamander_InitFollowInterval
	ldr r6, [sp, #0x30]
	ldr r0, _081ADFBC @ =0x00000CC4
	adds r3, r6, r0
	ldr r1, _081ADFC0 @ =0x00000CE8
	adds r4, r6, r1
	ldr r2, _081ADFC4 @ =Salamander_UpdateFrame
	str r2, [sp, #0x1dc]
	ldr r5, _081ADFC8 @ =Salamander_GetMoveSpeed
	mov r8, r5
	ldr r6, _081ADFCC @ =Salamander_StateTurn
	mov sb, r6
	ldr r0, _081ADFD0 @ =Salamander_StateMove
	mov sl, r0
	ldr r1, _081ADFD4 @ =Salamander_StateWait
	mov ip, r1
	movs r5, #0
	ldr r2, _081ADFD8 @ =FUN_080f62b0
	ldr r6, _081ADFDC @ =FUN_080f62ac
	str r6, [sp, #0x1d4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x1b0]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1a8]
	str r3, [r0]
	ldr r1, [sp, #0x1ac]
	str r4, [r1]
	ldr r3, [sp, #0x1dc]
	ldr r4, [sp, #0xa4]
	str r3, [r4]
	mov r6, r8
	ldr r0, [sp, #0xac]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xb4]
	str r1, [r3]
	mov r4, sl
	ldr r6, [sp, #0xc8]
	str r4, [r6]
	mov r0, ip
	ldr r1, [sp, #0xcc]
	str r0, [r1]
	ldr r3, _081ADFE0 @ =Salamander_StateNap
	ldr r4, [sp, #0xe4]
	str r3, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	ldr r0, [sp, #0xfc]
	str r5, [r0]
	ldr r1, _081ADFE4 @ =Salamander_StateDying
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r0, _081ADFE8 @ =FUN_080f44f4
	ldr r3, [sp, #0x10c]
	str r0, [r3]
	ldr r0, _081ADFEC @ =FUN_080f410c
	ldr r4, [sp, #0x11c]
	str r0, [r4]
	ldr r6, [sp, #0xf0]
	str r5, [r6]
	ldr r0, _081ADFF0 @ =Salamander_StateRespawnWait
	ldr r1, [sp, #0xa8]
	str r0, [r1]
	ldr r2, [sp, #0x1d4]
	ldr r3, [sp, #0x140]
	str r2, [r3]
	ldr r0, _081ADFF4 @ =FUN_080f0430
	ldr r4, [sp, #0x144]
	str r0, [r4]
	movs r0, #1
	ldr r6, [sp, #0xbc]
	strb r0, [r6]
	ldr r0, _081ADFF8 @ =0x085AD470
	ldr r1, [sp, #0x148]
	str r0, [r1]
	ldr r0, _081ADFFC @ =FUN_080e73c8
	ldr r2, [sp, #0x130]
	str r0, [r2]
	ldr r3, [sp, #0x124]
	str r5, [r3]
	ldr r4, [sp, #0x134]
	str r5, [r4]
	ldr r6, [sp, #0x138]
	str r5, [r6]
	ldr r0, [sp, #0x13c]
	str r5, [r0]
	ldr r1, [sp, #0x14c]
	str r5, [r1]
	ldr r0, _081AE000 @ =FUN_080f0320
	ldr r2, [sp, #0x150]
	str r0, [r2]
	ldr r0, _081AE004 @ =Enemy_080eff14
	ldr r3, [sp, #0xe0]
	str r0, [r3]
	ldr r0, _081AE008 @ =FUN_080e72b0
	ldr r4, [sp, #0x128]
	str r0, [r4]
	ldr r6, _081AE00C @ =Salamander_ClearStateBegun
	ldr r0, [sp, #0x120]
	str r6, [r0]
	ldr r0, _081AE010 @ =Enemy_StateBlownAway
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _081AE014 @ =Enemy_StateFallDeath
	ldr r2, [sp, #0x118]
	str r0, [r2]
	ldr r3, [sp, #0xd0]
	str r5, [r3]
	ldr r0, _081AE018 @ =FUN_080f6e64
	ldr r4, [sp, #0x154]
	str r0, [r4]
	ldr r0, _081AE01C @ =Enemy_OnDamaged
	ldr r6, [sp, #0xb0]
	str r0, [r6]
	ldr r0, _081AE020 @ =FUN_080f84d4
	ldr r1, [sp, #0x158]
	str r0, [r1]
	ldr r0, _081AE024 @ =FUN_080f624c
	ldr r2, [sp, #0xdc]
	str r0, [r2]
	ldr r0, _081AE028 @ =FUN_080f56ec
	ldr r3, [sp, #0xb8]
	str r0, [r3]
	ldr r0, _081AE02C @ =FUN_080f5b34
	ldr r4, [sp, #0xc0]
	str r0, [r4]
	ldr r0, _081AE030 @ =FUN_080f5fac
	ldr r6, [sp, #0xc4]
	str r0, [r6]
	ldr r0, [sp, #0xd8]
	str r5, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x1cc]
	strb r0, [r1]
	ldr r2, _081AE034 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _081AE038 @ =0x085ADED8
	str r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081AE03C @ =Salamander_OnReset
	str r0, [r1]
	ldr r4, _081AE040 @ =0x000005FC
	adds r0, r7, r4
	str r5, [r0]
	ldr r6, _081AE044 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _081AE048 @ =Salamander_OnAttackRequest
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081AE04C @ =FUN_081ac180
	str r0, [r1]
	subs r2, #4
	adds r1, r7, r2
	ldr r0, _081AE050 @ =Salamander_TryDetectPlayer
	str r0, [r1]
	subs r3, #0x6c
	adds r1, r7, r3
	ldr r0, _081AE054 @ =Salamander_OnDamaged
	str r0, [r1]
	subs r4, #0x48
	adds r1, r7, r4
	ldr r0, _081AE058 @ =Salamander_ScatterSegments
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r5, [r0]
	ldr r1, _081AE05C @ =0x00100200
	ldr r2, [sp, #0x1b0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x1b4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r6, #0x40
	ldr r4, [sp, #0x188]
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r4, r7, r0
	str r6, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x15c]
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r2, _081AE060 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081AE064 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #6
	bl AuxShadow_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r4, #0
	bl AuxShadow_Hide
	ldr r3, _081AE068 @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x1c0]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081AE076
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081ADFAE:
	bl VM_GetPC
	cmp r0, #0
	beq _081AE06C
	bl VM_GetValue
	b _081AE06E
	.align 2, 0
_081ADFBC: .4byte 0x00000CC4
_081ADFC0: .4byte 0x00000CE8
_081ADFC4: .4byte Salamander_UpdateFrame
_081ADFC8: .4byte Salamander_GetMoveSpeed
_081ADFCC: .4byte Salamander_StateTurn
_081ADFD0: .4byte Salamander_StateMove
_081ADFD4: .4byte Salamander_StateWait
_081ADFD8: .4byte FUN_080f62b0
_081ADFDC: .4byte FUN_080f62ac
_081ADFE0: .4byte Salamander_StateNap
_081ADFE4: .4byte Salamander_StateDying
_081ADFE8: .4byte FUN_080f44f4
_081ADFEC: .4byte FUN_080f410c
_081ADFF0: .4byte Salamander_StateRespawnWait
_081ADFF4: .4byte FUN_080f0430
_081ADFF8: .4byte 0x085AD470
_081ADFFC: .4byte FUN_080e73c8
_081AE000: .4byte FUN_080f0320
_081AE004: .4byte Enemy_080eff14
_081AE008: .4byte FUN_080e72b0
_081AE00C: .4byte Salamander_ClearStateBegun
_081AE010: .4byte Enemy_StateBlownAway
_081AE014: .4byte Enemy_StateFallDeath
_081AE018: .4byte FUN_080f6e64
_081AE01C: .4byte Enemy_OnDamaged
_081AE020: .4byte FUN_080f84d4
_081AE024: .4byte FUN_080f624c
_081AE028: .4byte FUN_080f56ec
_081AE02C: .4byte FUN_080f5b34
_081AE030: .4byte FUN_080f5fac
_081AE034: .4byte 0x0000060C
_081AE038: .4byte 0x085ADED8
_081AE03C: .4byte Salamander_OnReset
_081AE040: .4byte 0x000005FC
_081AE044: .4byte 0x000005AC
_081AE048: .4byte Salamander_OnAttackRequest
_081AE04C: .4byte FUN_081ac180
_081AE050: .4byte Salamander_TryDetectPlayer
_081AE054: .4byte Salamander_OnDamaged
_081AE058: .4byte Salamander_ScatterSegments
_081AE05C: .4byte 0x00100200
_081AE060: .4byte 0x0000044C
_081AE064: .4byte 0x00001C1B
_081AE068: .4byte 0x0000044D
_081AE06C:
	movs r0, #0
_081AE06E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081ADFAE
_081AE076:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x1c4]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x1a4]
	strh r0, [r3]
	cmp r2, #0
	beq _081AE0AE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x1b0]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081AE0AE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081AE0AE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081AE0C0
	movs r0, #1
	b _081AE0C2
_081AE0C0:
	movs r0, #0
_081AE0C2:
	cmp r0, #0
	beq _081AE0D4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x1b4]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081AE0D4:
	cmp r2, #1
	beq _081AE108
	movs r0, #0
	ldr r1, [sp, #0x170]
	strb r0, [r1]
	ldr r2, [sp, #0x174]
	strb r0, [r2]
	ldr r3, [sp, #0x178]
	strb r0, [r3]
	ldr r4, [sp, #0x19c]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x180]
	strb r1, [r5]
	ldr r6, [sp, #0xcc]
	ldr r2, [r6]
	ldr r3, [sp, #0x184]
	strb r1, [r3]
	ldr r4, [sp, #0x17c]
	strb r0, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r6, [sp, #0xa0]
	str r2, [r6]
	ldr r1, [sp, #0x1d0]
	strh r0, [r1]
_081AE108:
	movs r1, #2
	ldr r2, [sp, #0x188]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AE118
	movs r0, #1
	b _081AE11A
_081AE118:
	movs r0, #0
_081AE11A:
	cmp r0, #0
	beq _081AE134
	ldr r0, _081AE130 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x1a0]
	strh r0, [r4]
	b _081AE13E
	.align 2, 0
_081AE130: .4byte 0x030046A0
_081AE134:
	ldr r0, [sp, #0x15c]
	bl GetZoneAt
	ldr r5, [sp, #0x1a0]
	strh r0, [r5]
_081AE13E:
	movs r1, #0x40
	ldr r6, [sp, #0x188]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081AE14E
	movs r0, #1
	b _081AE150
_081AE14E:
	movs r0, #0
_081AE150:
	cmp r0, #0
	beq _081AE15E
	ldr r0, _081AE184 @ =0xFFFFFEFF
	ldr r2, [sp, #0x16c]
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_081AE15E:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081AE192
	ldr r0, _081AE188 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x1a0]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081AE18C
	movs r0, #1
	b _081AE18E
	.align 2, 0
_081AE184: .4byte 0xFFFFFEFF
_081AE188: .4byte 0x030046A0
_081AE18C:
	movs r0, #0
_081AE18E:
	cmp r0, #0
	bne _081AE19A
_081AE192:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_081AE19A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0x114]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081AE282
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
	beq _081AE1DC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081AE1E4
_081AE1DC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081AE1E4:
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
	beq _081AE208
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081AE210
_081AE208:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081AE210:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081AE248 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081AE28C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081AE24C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081AE240
	ldrb r0, [r4, #5]
_081AE240:
	subs r0, #1
	strh r0, [r4, #8]
	b _081AE25C
	.align 2, 0
_081AE248: .4byte 0x0000FFFF
_081AE24C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081AE25C
	strh r1, [r4, #8]
_081AE25C:
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
	bne _081AE28C
	movs r0, #1
	strb r0, [r4, #7]
	b _081AE28C
_081AE282:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_081AE28C:
	movs r0, #0
	ldr r3, [sp, #0x3c]
	str r0, [r3]
	ldr r0, _081AE2A4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AE2A8
	movs r0, #1
	b _081AE2AA
	.align 2, 0
_081AE2A4: .4byte 0x030047A4
_081AE2A8:
	movs r0, #0
_081AE2AA:
	cmp r0, #0
	bne _081AE2EA
	ldr r4, [sp, #0x60]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081AE2D2
	adds r0, r1, #0
	cmp r0, #7
	beq _081AE2D2
	cmp r0, #6
	beq _081AE2D2
	cmp r0, #0x15
	beq _081AE2D2
	cmp r0, #0x14
	beq _081AE2D2
	cmp r0, #0x17
	bne _081AE2EA
_081AE2D2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x188]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081AE2EA:
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl Salamander_SetHandlerTable2
	adds r0, r7, #0
	bl Salamander_SetHandlerTable4
	ldr r1, _081AE434 @ =0x0000D636
	ldr r2, _081AE438 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl Salamander_InitSegments
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x15c]
	bl Salamander_SetAllSegmentsPos
	adds r0, r7, #0
	bl Salamander_InitSegmentHitboxes
	adds r0, r7, #0
	bl Salamander_PickNextTile
	ldr r2, _081AE43C @ =Enemy_WaitPendingState
	movs r0, #0xe
	movs r1, #0
	movs r5, #1
	ldr r6, [sp, #0x184]
	strb r5, [r6]
	ldr r3, [sp, #0x17c]
	strb r1, [r3]
	ldr r4, [sp, #0x50]
	strb r0, [r4]
	ldr r6, [sp, #0xa0]
	str r2, [r6]
	movs r4, #0
	ldr r0, [sp, #0x1d0]
	strh r1, [r0]
	movs r0, #3
	ldr r2, [sp, #0x170]
	strb r0, [r2]
	ldr r3, [sp, #0x174]
	strb r4, [r3]
	ldr r6, [sp, #0x178]
	strb r4, [r6]
	ldr r0, [sp, #0x19c]
	str r1, [r0]
	ldr r1, [sp, #0x180]
	strb r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r2, #6
	movs r0, #0x78
	ldr r3, [sp, #0x54]
	str r0, [r3]
	ldr r6, [sp, #0x5c]
	str r1, [r6]
	ldr r0, [sp, #0x40]
	strb r4, [r0]
	ldr r1, [sp, #0x44]
	strb r4, [r1]
	ldr r3, [sp, #0x4c]
	strb r2, [r3]
	ldr r6, _081AE440 @ =0x00000472
	adds r4, r7, r6
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, [sp, #0xd4]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [sp, #0x15c]
	bl Salamander_SpawnExplosion
	ldr r3, _081AE444 @ =0xFFFFFE00
	adds r0, r3, #0
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x15c]
	bl Salamander_SetAllSegmentsPos
	ldr r0, [sp, #0x30]
	bl Salamander_HideLiveSegments
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r4, [sp, #0x16c]
	ldrh r0, [r4, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl Salamander_InitPaletteFade
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ldr r6, [sp, #0x9c]
	strh r0, [r6]
	ldr r1, [sp, #0x1c8]
	ldrh r0, [r1]
	ldr r2, [sp, #0x98]
	strh r0, [r2]
	ldr r3, [sp, #0x1b0]
	ldr r0, [r3]
	ldr r4, [sp, #0x6c]
	str r0, [r4]
	ldr r5, [sp, #0x1b4]
	ldr r0, [r5]
	ldr r6, [sp, #0x74]
	str r0, [r6]
	ldrb r0, [r7, #5]
	ldr r1, [sp, #0x7c]
	strb r0, [r1]
	ldr r2, [sp, #0x170]
	ldrb r0, [r2]
	ldr r3, [sp, #0x80]
	strb r0, [r3]
	ldr r4, [sp, #0x174]
	ldrb r0, [r4]
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x178]
	ldrb r0, [r6]
	ldr r1, [sp, #0x8c]
	strb r0, [r1]
	ldr r2, [sp, #0xa0]
	ldr r0, [r2]
	ldr r3, [sp, #0x90]
	str r0, [r3]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0x94]
	strb r0, [r5]
	ldr r6, _081AE448 @ =0x0000057C
	adds r1, r7, r6
	ldr r0, _081AE44C @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r0, _081AE450 @ =0x0000061C
	adds r1, r7, r0
	ldr r0, _081AE454 @ =Salamander_Update
	str r0, [r1]
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081AE458 @ =Salamander_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AE45C
	movs r0, #0
	b _081AE460
	.align 2, 0
_081AE434: .4byte 0x0000D636
_081AE438: .4byte 0x0000C102
_081AE43C: .4byte Enemy_WaitPendingState
_081AE440: .4byte 0x00000472
_081AE444: .4byte 0xFFFFFE00
_081AE448: .4byte 0x0000057C
_081AE44C: .4byte Enemy_DispatchMsg
_081AE450: .4byte 0x0000061C
_081AE454: .4byte Salamander_Update
_081AE458: .4byte Salamander_Destroy
_081AE45C:
	movs r0, #1
	rsbs r0, r0, #0
_081AE460:
	add sp, #0x1e0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
