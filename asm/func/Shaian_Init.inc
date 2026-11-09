	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c0
	adds r7, r0, #0
	str r7, [sp, #0x30]
	str r7, [sp, #0x34]
	ldr r1, _08183564 @ =0x00000898
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #1
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _08183568 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1b
	strb r0, [r1]
	adds r0, r7, #0
	bl Shaian_InitAnims
	ldr r3, _0818356C @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08183574
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08183570 @ =0x0000D3EA
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _08183568 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xb0]
	cmp r1, #0x11
	beq _08183552
	cmp r1, #0x17
	bne _08183556
_08183552:
	movs r0, #1
	strb r0, [r5, #7]
_08183556:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081835DC
	.align 2, 0
_08183564: .4byte 0x00000898
_08183568: .4byte 0x000001DF
_0818356C: .4byte 0x0000025D
_08183570: .4byte 0x0000D3EA
_08183574:
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
	ldr r2, _08183658 @ =0x05000002
	bl CpuSet
	ldr r0, _0818365C @ =0x0000CB05
	ldr r1, _08183660 @ =0x0000D3EA
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
	ldr r0, _08183664 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08183668 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xb0]
_081835DC:
	str r7, [sp, #0x38]
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
	ldr r5, _0818366C @ =0x0000046F
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
	ldr r1, _08183670 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _08183658 @ =0x05000002
	bl CpuSet
	ldr r3, _08183674 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b8]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x74]
	str r6, [sp, #0x54]
	ldr r2, [sp, #0x1b8]
	adds r6, r2, #0
	cmp r0, #0
	bne _08183648
	b _081837A8
_08183648:
	bl VM_GetPC
	cmp r0, #0
	beq _08183678
	bl VM_GetValue
	adds r1, r0, #0
	b _0818367A
	.align 2, 0
_08183658: .4byte 0x05000002
_0818365C: .4byte 0x0000CB05
_08183660: .4byte 0x0000D3EA
_08183664: .4byte 0x000004B7
_08183668: .4byte 0x000001DF
_0818366C: .4byte 0x0000046F
_08183670: .4byte 0x00000474
_08183674: .4byte 0x000004B6
_08183678:
	movs r1, #0
_0818367A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081836A0 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xd0]
	str r4, [sp, #0xd4]
	cmp r0, #0
	beq _081836A4
	bl VM_GetValue
	adds r1, r0, #0
	b _081836A6
	.align 2, 0
_081836A0: .4byte 0x00000251
_081836A4:
	movs r1, #0
_081836A6:
	ldr r2, _081836DC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081836E0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xd0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd8]
	cmp r0, #0
	beq _081836E4
	bl VM_GetValue
	b _081836E8
	.align 2, 0
_081836DC: .4byte 0x00000252
_081836E0: .4byte 0x000004B4
_081836E4:
	ldr r4, [sp, #0xd0]
	ldrb r0, [r4]
_081836E8:
	strb r0, [r6]
	ldr r5, [sp, #0xd0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd8]
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
	blt _08183720
	cmp r1, #0
	blt _08183720
	ldr r0, _08183724 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08183720
	ldr r0, _08183728 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818372C
_08183720:
	movs r1, #0
	b _0818373A
	.align 2, 0
_08183724: .4byte 0x030046A8
_08183728: .4byte 0x030046AC
_0818372C:
	ldr r0, _08183754 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0818373A:
	ldr r2, _08183758 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818375C
	adds r0, #4
	b _08183768
	.align 2, 0
_08183754: .4byte 0x030046A4
_08183758: .4byte 0x00000256
_0818375C:
	ldr r0, _0818377C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08183768:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08183780
	cmp r2, #2
	beq _08183784
	b _08183788
	.align 2, 0
_0818377C: .4byte 0x030046A4
_08183780:
	ldrb r0, [r4, #4]
	b _08183786
_08183784:
	ldrb r0, [r4]
_08183786:
	subs r1, r1, r0
_08183788:
	ldr r3, _081837A0 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081837A4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x3c]
	b _081837E8
	.align 2, 0
_081837A0: .4byte 0x00000472
_081837A4: .4byte 0x0000FFFF
_081837A8:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0818380C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08183810 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08183814 @ =0x000004B4
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
	str r5, [sp, #0xd0]
	str r4, [sp, #0xd4]
	str r3, [sp, #0xd8]
_081837E8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08183832
	bl VM_GetPC
	cmp r0, #0
	beq _08183818
	bl VM_GetValue
	adds r4, r0, #0
	b _0818381A
	.align 2, 0
_0818380C: .4byte 0x00000251
_08183810: .4byte 0x00000252
_08183814: .4byte 0x000004B4
_08183818:
	movs r4, #0x30
_0818381A:
	bl VM_GetPC
	cmp r0, #0
	beq _0818382C
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0818382E
_0818382C:
	movs r5, #0x40
_0818382E:
	mov r8, r4
	b _08183838
_08183832:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08183838:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08183870
	bl VM_GetPC
	cmp r0, #0
	beq _08183852
	bl VM_GetValue
	adds r6, r0, #0
	b _08183854
_08183852:
	movs r6, #0
_08183854:
	bl VM_GetPC
	cmp r0, #0
	beq _08183864
	bl VM_GetValue
	adds r1, r0, #0
	b _08183866
_08183864:
	movs r1, #0
_08183866:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0818387A
_08183870:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0818387A:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08183B00 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	lsls r4, r4, #0x10
	str r4, [sp, #0xa4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xac]
	lsls r6, r6, #0x10
	str r6, [sp, #0xb4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xa8]
	ldr r4, _08183B04 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x1b0]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x40]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x44]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x19c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r1, _08183B08 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x60]
	ldr r2, _08183B0C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r3, _08183B10 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x68]
	ldr r4, _08183B14 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _08183B18 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x94]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x124]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _08183B1C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x138]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	ldr r2, _08183B20 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _08183B24 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08183B28 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _08183B2C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x168]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	ldr r2, _08183B30 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x118]
	ldr r3, _08183B34 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x18c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x190]
	ldr r5, _08183B38 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08183B3C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x194]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	ldr r2, _08183B40 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x170]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x180]
	ldr r4, _08183B44 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _08183B48 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _08183B4C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x148]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x174]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x16c]
	ldr r5, _08183B50 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x178]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _08183B54 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a8]
	ldr r3, _08183B58 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x120]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1ac]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08183B5C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	ldr r2, _08183B60 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x130]
	ldr r3, _08183B64 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08183B68 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	ldr r5, [sp, #0x34]
	adds r5, #8
	str r5, [sp, #0x1a0]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _08183B6C @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08183B70 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _08183B74 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _08183B78 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	ldr r4, _08183B7C @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x98]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x108]
	ldr r1, _08183B80 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xe0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r3, _08183B84 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xf0]
	ldr r4, _08183B88 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xf4]
	ldr r5, _08183B8C @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xf8]
	ldr r6, _08183B90 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _08183B94 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0x104]
	cmp r0, #0
	bne _08183AD0
	b _08183BF0
_08183AD0:
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
_08183AF0:
	bl VM_GetPC
	cmp r0, #0
	beq _08183B98
	bl VM_GetValue
	b _08183B9A
	.align 2, 0
_08183B00: .4byte 0x0000025D
_08183B04: .4byte 0x0000025A
_08183B08: .4byte 0x0000047A
_08183B0C: .4byte 0x0000047C
_08183B10: .4byte 0x0000047E
_08183B14: .4byte 0x00000476
_08183B18: .4byte 0x000004A4
_08183B1C: .4byte 0x000005A4
_08183B20: .4byte 0x000005C4
_08183B24: .4byte 0x000005CC
_08183B28: .4byte 0x000005D4
_08183B2C: .4byte 0x000005DC
_08183B30: .4byte 0x00000584
_08183B34: .4byte 0x00000604
_08183B38: .4byte 0x0000021D
_08183B3C: .4byte 0x0000060C
_08183B40: .4byte 0x000005E4
_08183B44: .4byte 0x000005FC
_08183B48: .4byte 0x00000614
_08183B4C: .4byte 0x000005BC
_08183B50: .4byte 0x000005EC
_08183B54: .4byte 0x00000624
_08183B58: .4byte 0x0000058C
_08183B5C: .4byte 0x00000594
_08183B60: .4byte 0x0000059C
_08183B64: .4byte 0x000005B4
_08183B68: .4byte 0x00000543
_08183B6C: .4byte 0x00000496
_08183B70: .4byte 0x00000469
_08183B74: .4byte 0x0000046A
_08183B78: .4byte 0x00000553
_08183B7C: .4byte 0x00000572
_08183B80: .4byte 0x0000055C
_08183B84: .4byte 0x00000564
_08183B88: .4byte 0x00000565
_08183B8C: .4byte 0x00000566
_08183B90: .4byte 0x00000567
_08183B94: .4byte 0x0000056C
_08183B98:
	movs r0, #0x18
_08183B9A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08183BAC
	bl VM_GetValue
	b _08183BAE
_08183BAC:
	movs r0, #0x18
_08183BAE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08183BC0
	bl VM_GetValue
	b _08183BC2
_08183BC0:
	movs r0, #0
_08183BC2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08183BD4
	bl VM_GetValue
	b _08183BD6
_08183BD4:
	movs r0, #0
_08183BD6:
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
	bgt _08183BF0
	b _08183AF0
_08183BF0:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08183C3C
	bl VM_GetPC
	cmp r0, #0
	beq _08183C0A
	bl VM_GetValue
	adds r4, r0, #0
	b _08183C0E
_08183C0A:
	movs r4, #0x96
	lsls r4, r4, #1
_08183C0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08183C1E
	bl VM_GetValue
	adds r6, r0, #0
	b _08183C22
_08183C1E:
	movs r6, #0x96
	lsls r6, r6, #1
_08183C22:
	bl VM_GetPC
	cmp r0, #0
	beq _08183C30
	bl VM_GetValue
	b _08183C36
_08183C30:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08183C36:
	ldr r2, [sp, #0xc8]
	strh r0, [r2]
	b _08183C44
_08183C3C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc8]
	strh r6, [r3]
_08183C44:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08183C5C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08183C5C:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08183D2C
	bl VM_GetPC
	cmp r0, #0
	beq _08183C8C
	bl VM_GetValue
	b _08183C8E
_08183C8C:
	movs r0, #0
_08183C8E:
	ldr r3, [sp, #0xdc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08183C9C
	asrs r1, r0, #1
	b _08183CA2
_08183C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08183CA2:
	ldr r5, _08183CB8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CBC
	bl VM_GetValue
	b _08183CBE
	.align 2, 0
_08183CB8: .4byte 0x00000546
_08183CBC:
	movs r0, #0
_08183CBE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CD4
	bl VM_GetValue
	b _08183CD6
_08183CD4:
	movs r0, #0
_08183CD6:
	ldr r3, _08183CEC @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183CF0
	bl VM_GetValue
	adds r1, r0, #0
	b _08183CF2
	.align 2, 0
_08183CEC: .4byte 0x00000187
_08183CF0:
	movs r1, #0
_08183CF2:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D08
	bl VM_GetValue
	b _08183D0A
_08183D08:
	movs r0, #0
_08183D0A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D22
	bl VM_GetValue
	adds r1, r0, #0
	b _08183D24
_08183D22:
	movs r1, #0
_08183D24:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08183D2C:
	ldr r5, [sp, #0xdc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r6, [sp, #0xa4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xac]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xb4]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xa8]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08183D8E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08183D74
	bl VM_GetValue
	b _08183D76
_08183D74:
	movs r0, #0
_08183D76:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08183D86
	bl VM_GetValue
	b _08183D88
_08183D86:
	movs r0, #0
_08183D88:
	ldr r6, _08183DF0 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08183D8E:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08183DB2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08183DB2:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08183DCA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x74]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08183DCA:
	ldr r4, [sp, #0x9c]
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
	ldr r5, [sp, #0x54]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08183DF4
	movs r0, #1
	b _08183DF6
	.align 2, 0
_08183DF0: .4byte 0x00000189
_08183DF4:
	movs r0, #0
_08183DF6:
	cmp r0, #0
	beq _08183E06
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08183E30 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x38]
	bl CWolfTargetManager_Register
_08183E06:
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08183E12
	ldr r1, [r7, #0x44]
_08183E12:
	ldr r0, [sp, #0x38]
	bl Mover_SetAuxSprite
	ldr r1, [sp, #0xb0]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08183E34
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x1b0]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08183E40
	.align 2, 0
_08183E30: .4byte Enemy_OnCWolfMessage
_08183E34:
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x1b0]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08183E40:
	ldr r2, [sp, #0xb0]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08183E8E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08183E8E
	cmp r0, #0x16
	beq _08183E8E
	cmp r0, #0x14
	beq _08183E8E
	cmp r0, #9
	beq _08183E8E
	cmp r0, #0x19
	beq _08183E8E
	cmp r0, #0x1a
	beq _08183E8E
	cmp r0, #0xd
	beq _08183E8E
	cmp r0, #0x1b
	beq _08183E8E
	cmp r0, #0x1f
	beq _08183E8E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xd0]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd4]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	bl Mover_SetPath
_08183E8E:
	movs r1, #8
	ldr r6, [sp, #0x54]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08183E9E
	movs r0, #1
	b _08183EA0
_08183E9E:
	movs r0, #0
_08183EA0:
	cmp r0, #0
	beq _08183EAE
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	b _08183EC0
_08183EAE:
	ldr r3, [sp, #0xbc]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb8]
	str r0, [r4]
_08183EC0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldr r6, [sp, #0x19c]
	ldr r0, [sp, #0x44]
	str r6, [r0]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _08183EEA
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
_08183EEA:
	adds r0, r7, #0
	bl FUN_0817c44c
	adds r0, r7, #0
	bl FUN_0817ded0
	ldr r4, _08183F30 @ =0x00000272
	ldr r5, _08183F34 @ =0x00000276
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x70]
	strh r0, [r3]
	ldr r6, [sp, #0x60]
	strh r4, [r6]
	ldr r0, [sp, #0x64]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x68]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xec]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08183F38
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08183F44
	.align 2, 0
_08183F30: .4byte 0x00000272
_08183F34: .4byte 0x00000276
_08183F38:
	ldr r2, [r7, #0x44]
	ldr r0, _08183F7C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08183F44:
	ldr r3, [sp, #0xec]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08183F94
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08183F80
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
	b _08183F8A
	.align 2, 0
_08183F7C: .4byte 0x03003584
_08183F80:
	ldr r5, [sp, #0xb0]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08183F8A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08183F94:
	movs r4, #0
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ldr r1, [sp, #0x58]
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #2
	ldr r2, [sp, #0x5c]
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_0817d6d4
	adds r0, r7, #0
	bl Shaian_InitHitboxes
	ldr r3, [sp, #0x30]
	ldr r5, _081841A4 @ =0x000008B8
	adds r0, r3, r5
	ldr r6, _081841A8 @ =0x000008DC
	adds r5, r3, r6
	ldr r1, _081841AC @ =FUN_0818337c
	str r1, [sp, #0x1bc]
	ldr r2, _081841B0 @ =Shaian_GetMoveSpeed
	mov r8, r2
	ldr r3, _081841B4 @ =FUN_081804f8
	mov sb, r3
	ldr r6, _081841B8 @ =FUN_0817fab0
	mov sl, r6
	ldr r1, _081841BC @ =FUN_0817fc84
	mov ip, r1
	ldr r3, _081841C0 @ =FUN_080f62b0
	ldr r2, _081841C4 @ =FUN_080f62ac
	str r2, [sp, #0x1b4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x6c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x90]
	str r0, [r1]
	ldr r2, [sp, #0x94]
	str r5, [r2]
	ldr r5, [sp, #0x1bc]
	ldr r6, [sp, #0x114]
	str r5, [r6]
	mov r1, r8
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	mov r5, sb
	ldr r6, [sp, #0x124]
	str r5, [r6]
	mov r1, sl
	ldr r2, [sp, #0x134]
	str r1, [r2]
	mov r5, ip
	ldr r6, [sp, #0x138]
	str r5, [r6]
	ldr r1, [sp, #0x14c]
	str r4, [r1]
	ldr r2, [sp, #0x150]
	str r3, [r2]
	ldr r3, _081841C8 @ =Shaian_StateDamaged
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r6, _081841CC @ =Shaian_StateDying
	ldr r1, [sp, #0x15c]
	str r6, [r1]
	ldr r1, _081841D0 @ =FUN_080f44f4
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r1, _081841D4 @ =FUN_080f410c
	ldr r3, [sp, #0x168]
	str r1, [r3]
	ldr r5, [sp, #0x154]
	str r4, [r5]
	ldr r6, [sp, #0x118]
	str r4, [r6]
	ldr r1, [sp, #0x1b4]
	ldr r2, [sp, #0x18c]
	str r1, [r2]
	ldr r1, _081841D8 @ =FUN_080f0430
	ldr r3, [sp, #0x190]
	str r1, [r3]
	movs r6, #1
	ldr r5, [sp, #0xc0]
	strb r6, [r5]
	ldr r1, _081841DC @ =0x085AD470
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081841E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x17c]
	str r1, [r3]
	ldr r5, [sp, #0x170]
	str r4, [r5]
	ldr r6, [sp, #0x180]
	str r4, [r6]
	ldr r1, [sp, #0x184]
	str r4, [r1]
	ldr r2, [sp, #0x188]
	str r4, [r2]
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081841E4 @ =FUN_080f0320
	ldr r5, [sp, #0x1a4]
	str r1, [r5]
	ldr r1, _081841E8 @ =Enemy_080eff14
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r1, _081841EC @ =FUN_080e72b0
	ldr r2, [sp, #0x174]
	str r1, [r2]
	ldr r3, [sp, #0x16c]
	str r4, [r3]
	ldr r1, _081841F0 @ =Enemy_StateBlownAway
	ldr r5, [sp, #0x178]
	str r1, [r5]
	ldr r1, _081841F4 @ =Enemy_StateFallDeath
	ldr r6, [sp, #0x164]
	str r1, [r6]
	ldr r1, [sp, #0x13c]
	str r4, [r1]
	ldr r1, _081841F8 @ =FUN_080f6e64
	ldr r2, [sp, #0x1a8]
	str r1, [r2]
	ldr r1, _081841FC @ =Enemy_OnDamaged
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r1, _08184200 @ =FUN_080f84d4
	ldr r5, [sp, #0x1ac]
	str r1, [r5]
	ldr r1, _08184204 @ =FUN_080f624c
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _08184208 @ =FUN_080f56ec
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r1, _0818420C @ =FUN_080f5b34
	ldr r3, [sp, #0x12c]
	str r1, [r3]
	ldr r1, _08184210 @ =FUN_080f5fac
	ldr r5, [sp, #0x130]
	str r1, [r5]
	ldr r6, [sp, #0x140]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xc4]
	strb r1, [r2]
	ldr r1, [sp, #0x1a0]
	bl Map_InitNavAgent
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	ldr r5, _08184214 @ =0x000005FC
	adds r0, r7, r5
	str r4, [r0]
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08184218 @ =FUN_0817bb7c
	str r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0818421C @ =FUN_0817c328
	str r0, [r1]
	ldr r2, _08184220 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _08184224 @ =FUN_0817bbe0
	str r0, [r1]
	subs r3, #0x48
	adds r1, r7, r3
	ldr r0, _08184228 @ =FUN_0817bbe4
	str r0, [r1]
	subs r5, #0x70
	adds r1, r7, r5
	ldr r0, _0818422C @ =FUN_08182254
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _08184230 @ =0x00500200
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x81
	lsls r1, r1, #3
	ldr r3, [sp, #0x74]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	ldr r5, [sp, #0x30]
	ldr r6, _08184234 @ =0x0000085C
	adds r1, r5, r6
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	str r2, [r1]
	str r3, [r1, #4]
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r4, [sp, #0x18]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r3, _08184238 @ =0x0000044C
	adds r1, r7, r3
	strb r0, [r1]
	ldr r1, _0818423C @ =0x00001C1B
	adds r0, r5, #0
	movs r2, #6
	bl AuxShadow_SetSprite
	adds r0, r5, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r5, #0
	bl AuxShadow_Show
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r4, [sp, #0x88]
	strh r0, [r4]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0818424A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08184196:
	bl VM_GetPC
	cmp r0, #0
	beq _08184240
	bl VM_GetValue
	b _08184242
	.align 2, 0
_081841A4: .4byte 0x000008B8
_081841A8: .4byte 0x000008DC
_081841AC: .4byte FUN_0818337c
_081841B0: .4byte Shaian_GetMoveSpeed
_081841B4: .4byte FUN_081804f8
_081841B8: .4byte FUN_0817fab0
_081841BC: .4byte FUN_0817fc84
_081841C0: .4byte FUN_080f62b0
_081841C4: .4byte FUN_080f62ac
_081841C8: .4byte Shaian_StateDamaged
_081841CC: .4byte Shaian_StateDying
_081841D0: .4byte FUN_080f44f4
_081841D4: .4byte FUN_080f410c
_081841D8: .4byte FUN_080f0430
_081841DC: .4byte 0x085AD470
_081841E0: .4byte FUN_080e73c8
_081841E4: .4byte FUN_080f0320
_081841E8: .4byte Enemy_080eff14
_081841EC: .4byte FUN_080e72b0
_081841F0: .4byte Enemy_StateBlownAway
_081841F4: .4byte Enemy_StateFallDeath
_081841F8: .4byte FUN_080f6e64
_081841FC: .4byte Enemy_OnDamaged
_08184200: .4byte FUN_080f84d4
_08184204: .4byte FUN_080f624c
_08184208: .4byte FUN_080f56ec
_0818420C: .4byte FUN_080f5b34
_08184210: .4byte FUN_080f5fac
_08184214: .4byte 0x000005FC
_08184218: .4byte FUN_0817bb7c
_0818421C: .4byte FUN_0817c328
_08184220: .4byte 0x000005AC
_08184224: .4byte FUN_0817bbe0
_08184228: .4byte FUN_0817bbe4
_0818422C: .4byte FUN_08182254
_08184230: .4byte 0x00500200
_08184234: .4byte 0x0000085C
_08184238: .4byte 0x0000044C
_0818423C: .4byte 0x00001C1B
_08184240:
	movs r0, #0
_08184242:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08184196
_0818424A:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	cmp r2, #0
	beq _08184282
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x6c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08184282
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08184282:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x54]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08184294
	movs r0, #1
	b _08184296
_08184294:
	movs r0, #0
_08184296:
	cmp r0, #0
	beq _081842A8
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081842A8:
	cmp r2, #1
	beq _081842E8
	movs r1, #0
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	ldr r4, _081842F8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081842FC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x138]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xcc]
	strb r1, [r6]
	ldr r0, [sp, #0x110]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081842E8:
	movs r1, #2
	ldr r3, [sp, #0x54]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08184300
	movs r0, #1
	b _08184302
	.align 2, 0
_081842F8: .4byte 0x00000484
_081842FC: .4byte 0x0000046C
_08184300:
	movs r0, #0
_08184302:
	cmp r0, #0
	beq _0818431C
	ldr r0, _08184318 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	b _08184326
	.align 2, 0
_08184318: .4byte 0x030046A0
_0818431C:
	ldr r0, [sp, #0x19c]
	bl GetZoneAt
	ldr r6, [sp, #0x78]
	strh r0, [r6]
_08184326:
	movs r1, #0x40
	ldr r2, [sp, #0x54]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08184336
	movs r0, #1
	b _08184338
_08184336:
	movs r0, #0
_08184338:
	cmp r0, #0
	beq _08184348
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0818436C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08184348:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0818437A
	ldr r0, _08184370 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x78]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08184374
	movs r0, #1
	b _08184376
	.align 2, 0
_0818436C: .4byte 0xFFFFFEFF
_08184370: .4byte 0x030046A0
_08184374:
	movs r0, #0
_08184376:
	cmp r0, #0
	bne _08184382
_0818437A:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_08184382:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [sp, #0xec]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0818446A
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
	beq _081843C4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081843CC
_081843C4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081843CC:
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
	beq _081843F0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081843F8
_081843F0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081843F8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08184430 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08184474
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08184434
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08184428
	ldrb r0, [r4, #5]
_08184428:
	subs r0, #1
	strh r0, [r4, #8]
	b _08184444
	.align 2, 0
_08184430: .4byte 0x0000FFFF
_08184434:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08184444
	strh r1, [r4, #8]
_08184444:
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
	bne _08184474
	movs r0, #1
	strb r0, [r4, #7]
	b _08184474
_0818446A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08184474:
	movs r0, #0
	ldr r3, [sp, #0xa0]
	str r0, [r3]
	ldr r0, _0818448C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08184490
	movs r0, #1
	b _08184492
	.align 2, 0
_0818448C: .4byte 0x030047A4
_08184490:
	movs r0, #0
_08184492:
	cmp r0, #0
	bne _081844D2
	ldr r4, [sp, #0xb0]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081844BA
	adds r0, r1, #0
	cmp r0, #7
	beq _081844BA
	cmp r0, #6
	beq _081844BA
	cmp r0, #0x15
	beq _081844BA
	cmp r0, #0x14
	beq _081844BA
	cmp r0, #0x17
	bne _081844D2
_081844BA:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x54]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081844D2:
	adds r0, r7, #0
	bl FUN_0817c02c
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_08183368
	adds r0, r7, #0
	bl FUN_08181a78
	adds r0, r7, #0
	bl FUN_08182240
	ldr r6, [sp, #0x54]
	ldrh r0, [r6]
	ldr r1, [sp, #0x10c]
	strh r0, [r1]
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ldr r3, [sp, #0x108]
	strh r0, [r3]
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	ldr r5, [sp, #0xe0]
	str r0, [r5]
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xf0]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf4]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf8]
	strb r0, [r6]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	ldr r2, [sp, #0xfc]
	strb r0, [r2]
	ldr r3, [sp, #0x110]
	ldr r0, [r3]
	ldr r4, [sp, #0x100]
	str r0, [r4]
	ldr r5, [sp, #0xcc]
	ldrb r0, [r5]
	ldr r6, [sp, #0x104]
	strb r0, [r6]
	ldr r0, _08184578 @ =0x00000574
	adds r1, r7, r0
	ldr r2, [sp, #0x30]
	ldr r3, _0818457C @ =0x00000898
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, _08184580 @ =0x0000057C
	adds r1, r7, r4
	ldr r0, _08184584 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r5, _08184588 @ =0x0000061C
	adds r1, r7, r5
	ldr r0, _0818458C @ =Shaian_Update
	str r0, [r1]
	movs r6, #0xc4
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08184590 @ =Shaian_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08184594
	movs r0, #0
	b _08184598
	.align 2, 0
_08184578: .4byte 0x00000574
_0818457C: .4byte 0x00000898
_08184580: .4byte 0x0000057C
_08184584: .4byte Enemy_DispatchMsg
_08184588: .4byte 0x0000061C
_0818458C: .4byte Shaian_Update
_08184590: .4byte Shaian_Destroy
_08184594:
	movs r0, #1
	rsbs r0, r0, #0
_08184598:
	add sp, #0x1c0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
