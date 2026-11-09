	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x30]
	ldr r1, _08194570 @ =0x00000F2C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _08194574 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, r7, #0
	bl Serpent_InitAnims
	ldr r3, _08194578 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08194584
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0819457C @ =0x0000D636
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _08194580 @ =0x0000C102
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _08194574 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x8c]
	cmp r1, #0x11
	beq _08194560
	cmp r1, #0x17
	bne _08194564
_08194560:
	movs r0, #1
	strb r0, [r5, #7]
_08194564:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081945EC
	.align 2, 0
_08194570: .4byte 0x00000F2C
_08194574: .4byte 0x000001DF
_08194578: .4byte 0x0000025D
_0819457C: .4byte 0x0000D636
_08194580: .4byte 0x0000C102
_08194584:
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
	ldr r2, _08194668 @ =0x05000002
	bl CpuSet
	ldr r0, _0819466C @ =0x0000CB05
	ldr r1, _08194670 @ =0x0000D636
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
	ldr r0, _08194674 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08194678 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x8c]
_081945EC:
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
	ldr r5, _0819467C @ =0x0000046F
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
	ldr r1, _08194680 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _08194668 @ =0x05000002
	bl CpuSet
	ldr r3, _08194684 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x5c]
	mov r3, r8
	str r3, [sp, #0x60]
	str r6, [sp, #0x1b0]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _08194658
	b _081947B8
_08194658:
	bl VM_GetPC
	cmp r0, #0
	beq _08194688
	bl VM_GetValue
	adds r1, r0, #0
	b _0819468A
	.align 2, 0
_08194668: .4byte 0x05000002
_0819466C: .4byte 0x0000CB05
_08194670: .4byte 0x0000D636
_08194674: .4byte 0x000004B7
_08194678: .4byte 0x000001DF
_0819467C: .4byte 0x0000046F
_08194680: .4byte 0x00000474
_08194684: .4byte 0x000004B6
_08194688:
	movs r1, #0
_0819468A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081946B0 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x114]
	str r4, [sp, #0x118]
	cmp r0, #0
	beq _081946B4
	bl VM_GetValue
	adds r1, r0, #0
	b _081946B6
	.align 2, 0
_081946B0: .4byte 0x00000251
_081946B4:
	movs r1, #0
_081946B6:
	ldr r2, _081946EC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081946F0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x114]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x120]
	cmp r0, #0
	beq _081946F4
	bl VM_GetValue
	b _081946F8
	.align 2, 0
_081946EC: .4byte 0x00000252
_081946F0: .4byte 0x000004B4
_081946F4:
	ldr r4, [sp, #0x114]
	ldrb r0, [r4]
_081946F8:
	strb r0, [r6]
	ldr r5, [sp, #0x114]
	ldrb r1, [r5]
	ldr r6, [sp, #0x120]
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
	blt _08194730
	cmp r1, #0
	blt _08194730
	ldr r0, _08194734 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08194730
	ldr r0, _08194738 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819473C
_08194730:
	movs r1, #0
	b _0819474A
	.align 2, 0
_08194734: .4byte 0x030046A8
_08194738: .4byte 0x030046AC
_0819473C:
	ldr r0, _08194764 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0819474A:
	ldr r2, _08194768 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0819476C
	adds r0, #4
	b _08194778
	.align 2, 0
_08194764: .4byte 0x030046A4
_08194768: .4byte 0x00000256
_0819476C:
	ldr r0, _0819478C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08194778:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08194790
	cmp r2, #2
	beq _08194794
	b _08194798
	.align 2, 0
_0819478C: .4byte 0x030046A4
_08194790:
	ldrb r0, [r4, #4]
	b _08194796
_08194794:
	ldrb r0, [r4]
_08194796:
	subs r1, r1, r0
_08194798:
	ldr r3, _081947B0 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081947B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _081947F8
	.align 2, 0
_081947B0: .4byte 0x00000472
_081947B4: .4byte 0x0000FFFF
_081947B8:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0819481C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08194820 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08194824 @ =0x000004B4
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
	str r5, [sp, #0x114]
	str r4, [sp, #0x118]
	str r3, [sp, #0x120]
_081947F8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08194842
	bl VM_GetPC
	cmp r0, #0
	beq _08194828
	bl VM_GetValue
	adds r4, r0, #0
	b _0819482A
	.align 2, 0
_0819481C: .4byte 0x00000251
_08194820: .4byte 0x00000252
_08194824: .4byte 0x000004B4
_08194828:
	movs r4, #0x30
_0819482A:
	bl VM_GetPC
	cmp r0, #0
	beq _0819483C
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0819483E
_0819483C:
	movs r5, #0x40
_0819483E:
	mov r8, r4
	b _08194848
_08194842:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08194848:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08194880
	bl VM_GetPC
	cmp r0, #0
	beq _08194862
	bl VM_GetValue
	adds r6, r0, #0
	b _08194864
_08194862:
	movs r6, #0
_08194864:
	bl VM_GetPC
	cmp r0, #0
	beq _08194874
	bl VM_GetValue
	adds r1, r0, #0
	b _08194876
_08194874:
	movs r1, #0
_08194876:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0819488A
_08194880:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0819488A:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _08194B1C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x134]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x68]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x124]
	lsls r4, r4, #0x10
	str r4, [sp, #0x88]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x94]
	lsls r6, r6, #0x10
	str r6, [sp, #0x98]
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	ldr r4, _08194B20 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x130]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x84]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x18c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x190]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x194]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x188]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x44]
	ldr r1, _08194B24 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x1b4]
	ldr r2, _08194B28 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r3, _08194B2C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _08194B30 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x58]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf8]
	ldr r4, _08194B34 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _08194B38 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x128]
	ldr r1, _08194B3C @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _08194B40 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08194B44 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _08194B48 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08194B4C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _08194B50 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xe0]
	ldr r4, _08194B54 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _08194B58 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	ldr r2, _08194B5C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x164]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	ldr r4, _08194B60 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _08194B64 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x110]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08194B68 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x100]
	ldr r6, _08194B6C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x180]
	ldr r1, _08194B70 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	ldr r4, _08194B74 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xec]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _08194B78 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _08194B7C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _08194B80 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08194B84 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _08194B88 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _08194B8C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _08194B90 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08194B94 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	ldr r5, _08194B98 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	ldr r6, _08194B9C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x1a4]
	ldr r1, _08194BA0 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x78]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x80]
	ldr r6, _08194BA4 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _08194BA8 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xac]
	ldr r5, _08194BAC @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _08194BB0 @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _08194BB4 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _08194BB8 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	ldr r4, _08194BBC @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	cmp r0, #0
	bne _08194AEC
	b _08194C18
_08194AEC:
	movs r5, #0
	mov sl, r5
	movs r6, #0x8d
	lsls r6, r6, #2
	adds r6, r6, r7
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r7, r2
_08194B0C:
	bl VM_GetPC
	cmp r0, #0
	beq _08194BC0
	bl VM_GetValue
	b _08194BC2
	.align 2, 0
_08194B1C: .4byte 0x0000025D
_08194B20: .4byte 0x0000025A
_08194B24: .4byte 0x0000047A
_08194B28: .4byte 0x0000047C
_08194B2C: .4byte 0x0000047E
_08194B30: .4byte 0x000004A4
_08194B34: .4byte 0x000005A4
_08194B38: .4byte 0x000005C4
_08194B3C: .4byte 0x000005CC
_08194B40: .4byte 0x000005D4
_08194B44: .4byte 0x000005DC
_08194B48: .4byte 0x00000584
_08194B4C: .4byte 0x00000604
_08194B50: .4byte 0x0000021D
_08194B54: .4byte 0x0000060C
_08194B58: .4byte 0x000005E4
_08194B5C: .4byte 0x000005FC
_08194B60: .4byte 0x00000614
_08194B64: .4byte 0x000005BC
_08194B68: .4byte 0x000005EC
_08194B6C: .4byte 0x00000624
_08194B70: .4byte 0x0000058C
_08194B74: .4byte 0x00000594
_08194B78: .4byte 0x0000059C
_08194B7C: .4byte 0x000005B4
_08194B80: .4byte 0x00000543
_08194B84: .4byte 0x00000496
_08194B88: .4byte 0x00000469
_08194B8C: .4byte 0x0000046A
_08194B90: .4byte 0x00000484
_08194B94: .4byte 0x0000046C
_08194B98: .4byte 0x0000046D
_08194B9C: .4byte 0x0000046B
_08194BA0: .4byte 0x00000553
_08194BA4: .4byte 0x00000572
_08194BA8: .4byte 0x0000055C
_08194BAC: .4byte 0x00000564
_08194BB0: .4byte 0x00000565
_08194BB4: .4byte 0x00000566
_08194BB8: .4byte 0x00000567
_08194BBC: .4byte 0x0000056C
_08194BC0:
	movs r0, #0x18
_08194BC2:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08194BD4
	bl VM_GetValue
	b _08194BD6
_08194BD4:
	movs r0, #0x18
_08194BD6:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08194BE8
	bl VM_GetValue
	b _08194BEA
_08194BE8:
	movs r0, #0
_08194BEA:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08194BFC
	bl VM_GetValue
	b _08194BFE
_08194BFC:
	movs r0, #0
_08194BFE:
	strh r0, [r6]
	movs r3, #2
	add sb, r3
	movs r6, #4
	add r8, r6
	adds r5, #2
	adds r4, #2
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _08194C18
	b _08194B0C
_08194C18:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08194C64
	bl VM_GetPC
	cmp r0, #0
	beq _08194C32
	bl VM_GetValue
	adds r4, r0, #0
	b _08194C36
_08194C32:
	movs r4, #0x96
	lsls r4, r4, #1
_08194C36:
	bl VM_GetPC
	cmp r0, #0
	beq _08194C46
	bl VM_GetValue
	adds r6, r0, #0
	b _08194C4A
_08194C46:
	movs r6, #0x96
	lsls r6, r6, #1
_08194C4A:
	bl VM_GetPC
	cmp r0, #0
	beq _08194C58
	bl VM_GetValue
	b _08194C5E
_08194C58:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_08194C5E:
	ldr r3, [sp, #0x10c]
	strh r0, [r3]
	b _08194C6C
_08194C64:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x10c]
	strh r6, [r5]
_08194C6C:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08194C84
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x60]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08194C84:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x68]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x64]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08194D54
	bl VM_GetPC
	cmp r0, #0
	beq _08194CB4
	bl VM_GetValue
	b _08194CB6
_08194CB4:
	movs r0, #0
_08194CB6:
	ldr r1, [sp, #0x124]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08194CC4
	asrs r1, r0, #1
	b _08194CCA
_08194CC4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08194CCA:
	ldr r2, _08194CE0 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08194CE4
	bl VM_GetValue
	b _08194CE6
	.align 2, 0
_08194CE0: .4byte 0x00000546
_08194CE4:
	movs r0, #0
_08194CE6:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194CFC
	bl VM_GetValue
	b _08194CFE
_08194CFC:
	movs r0, #0
_08194CFE:
	ldr r5, _08194D14 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D18
	bl VM_GetValue
	adds r1, r0, #0
	b _08194D1A
	.align 2, 0
_08194D14: .4byte 0x00000187
_08194D18:
	movs r1, #0
_08194D1A:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D30
	bl VM_GetValue
	b _08194D32
_08194D30:
	movs r0, #0
_08194D32:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D4A
	bl VM_GetValue
	adds r1, r0, #0
	b _08194D4C
_08194D4A:
	movs r1, #0
_08194D4C:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08194D54:
	ldr r0, [sp, #0x124]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0x88]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x94]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x98]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x90]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08194DB6
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08194D9C
	bl VM_GetValue
	b _08194D9E
_08194D9C:
	movs r0, #0
_08194D9E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08194DAE
	bl VM_GetValue
	b _08194DB0
_08194DAE:
	movs r0, #0
_08194DB0:
	ldr r2, _08194E18 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08194DB6:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08194DDA
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08194DDA:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08194DF2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08194DF2:
	ldr r6, [sp, #0x84]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x34]
	add r2, sp, #0x28
	movs r3, #0
	bl Mover_Init
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x1b0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08194E1C
	movs r0, #1
	b _08194E1E
	.align 2, 0
_08194E18: .4byte 0x00000189
_08194E1C:
	movs r0, #0
_08194E1E:
	cmp r0, #0
	beq _08194E2E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08194E58 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x34]
	bl CWolfTargetManager_Register
_08194E2E:
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08194E3A
	ldr r1, [r7, #0x44]
_08194E3A:
	ldr r0, [sp, #0x34]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0x8c]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08194E5C
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x18c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _08194E68
	.align 2, 0
_08194E58: .4byte Enemy_OnCWolfMessage
_08194E5C:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x18c]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_08194E68:
	ldr r5, [sp, #0x8c]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08194EB6
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08194EB6
	cmp r0, #0x16
	beq _08194EB6
	cmp r0, #0x14
	beq _08194EB6
	cmp r0, #9
	beq _08194EB6
	cmp r0, #0x19
	beq _08194EB6
	cmp r0, #0x1a
	beq _08194EB6
	cmp r0, #0xd
	beq _08194EB6
	cmp r0, #0x1b
	beq _08194EB6
	cmp r0, #0x1f
	beq _08194EB6
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x114]
	ldrb r2, [r6]
	ldr r0, [sp, #0x118]
	ldrb r3, [r0]
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl Mover_SetPath
_08194EB6:
	movs r1, #8
	ldr r5, [sp, #0x1b0]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08194EC6
	movs r0, #1
	b _08194EC8
_08194EC6:
	movs r0, #0
_08194EC8:
	cmp r0, #0
	beq _08194ED6
	ldr r6, [sp, #0xa4]
	ldr r0, [r6]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	b _08194EE8
_08194ED6:
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa0]
	str r0, [r3]
_08194EE8:
	ldrh r0, [r7]
	ldr r4, [sp, #0x190]
	strh r0, [r4]
	ldr r5, [sp, #0x188]
	ldr r6, [sp, #0x194]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _08194F12
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
_08194F12:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08195004
	bl VM_GetPC
	cmp r0, #0
	beq _08194F2A
	bl VM_GetValue
	b _08194F2C
_08194F2A:
	movs r0, #0
_08194F2C:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08194F3C
	bl VM_GetValue
	b _08194F3E
_08194F3C:
	movs r0, #0
_08194F3E:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08194F4E
	bl VM_GetValue
	b _08194F50
_08194F4E:
	movs r0, #0
_08194F50:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x188]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08194F78
	cmp r1, #0
	blt _08194F78
	ldr r0, _08194F7C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08194F78
	ldr r0, _08194F80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08194F84
_08194F78:
	movs r1, #0
	b _08194F92
	.align 2, 0
_08194F7C: .4byte 0x030046A8
_08194F80: .4byte 0x030046AC
_08194F84:
	ldr r0, _08194FAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08194F92:
	ldr r4, _08194FB0 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x188]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08194FB4
	adds r0, #4
	b _08194FC0
	.align 2, 0
_08194FAC: .4byte 0x030046A4
_08194FB0: .4byte 0x00000256
_08194FB4:
	ldr r0, _08194FD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08194FC0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08194FD8
	cmp r3, #2
	beq _08194FDC
	b _08194FE0
	.align 2, 0
_08194FD4: .4byte 0x030046A4
_08194FD8:
	ldrb r0, [r5, #4]
	b _08194FDE
_08194FDC:
	ldrb r0, [r5]
_08194FDE:
	subs r2, r2, r0
_08194FE0:
	ldr r5, _08195020 @ =0x00000472
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
	ldr r1, _08195024 @ =0x00000F84
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08195004:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08195052
	bl VM_GetPC
	cmp r0, #0
	beq _08195028
	bl VM_GetValue
	adds r1, r0, #0
	b _0819502A
	.align 2, 0
_08195020: .4byte 0x00000472
_08195024: .4byte 0x00000F84
_08195028:
	movs r1, #0x2c
_0819502A:
	ldr r2, [sp, #0x30]
	ldr r3, _08195044 @ =0x00000ED2
	adds r0, r2, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08195048
	bl VM_GetValue
	adds r1, r0, #0
	b _0819504A
	.align 2, 0
_08195044: .4byte 0x00000ED2
_08195048:
	movs r1, #0x2c
_0819504A:
	ldr r4, [sp, #0x30]
	ldr r5, _081950C0 @ =0x00000ED3
	adds r0, r4, r5
	strb r1, [r0]
_08195052:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r6, [sp, #0x30]
	ldr r2, _081950C4 @ =0x00000EC8
	adds r1, r6, r2
	movs r3, #0
	movs r2, #0
	strh r0, [r1]
	movs r4, #0xed
	lsls r4, r4, #4
	adds r0, r6, r4
	strh r2, [r0]
	ldr r5, _081950C8 @ =0x00000F43
	adds r0, r6, r5
	strb r3, [r0]
	ldr r0, _081950CC @ =0x00000E42
	adds r1, r6, r0
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819208c
	ldr r4, _081950D0 @ =0x000001A3
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x44]
	strh r0, [r1]
	ldr r2, [sp, #0x1b4]
	strh r4, [r2]
	ldr r3, [sp, #0x3c]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x40]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0x134]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081950D4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081950E0
	.align 2, 0
_081950C0: .4byte 0x00000ED3
_081950C4: .4byte 0x00000EC8
_081950C8: .4byte 0x00000F43
_081950CC: .4byte 0x00000E42
_081950D0: .4byte 0x000001A3
_081950D4:
	ldr r2, [r7, #0x44]
	ldr r0, _08195118 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081950E0:
	ldr r1, [sp, #0x134]
	ldrb r0, [r1]
	cmp r0, #1
	bne _08195130
	ldr r2, [sp, #0x8c]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0819511C
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
	b _08195126
	.align 2, 0
_08195118: .4byte 0x03003584
_0819511C:
	ldr r3, [sp, #0x8c]
	ldrb r0, [r3]
	bl Enemy_CountByKind
	adds r4, r0, #1
_08195126:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08195130:
	adds r0, r7, #0
	bl FUN_08192bf4
	adds r0, r7, #0
	bl Serpent_InitHitboxes
	adds r0, r7, #0
	bl FUN_0818f994
	movs r5, #0xf5
	lsls r5, r5, #4
	ldr r4, [sp, #0x30]
	adds r5, r4, r5
	str r5, [sp, #0x1c0]
	ldr r6, _08195338 @ =0x00000F74
	adds r4, r4, r6
	mov r8, r4
	ldr r0, _0819533C @ =FUN_08194264
	mov sb, r0
	ldr r1, _08195340 @ =Serpent_GetMoveSpeed
	mov sl, r1
	ldr r2, _08195344 @ =FUN_08189608
	mov ip, r2
	movs r5, #0
	ldr r3, _08195348 @ =Serpent_StateDamaged
	ldr r4, _0819534C @ =Serpent_StateDying
	ldr r2, _08195350 @ =FUN_080f62b0
	ldr r6, _08195354 @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1c0]
	ldr r1, [sp, #0x54]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0x58]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0xd4]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0xdc]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0xe8]
	str r6, [r0]
	ldr r1, _08195358 @ =FUN_08189104
	ldr r6, [sp, #0xf8]
	str r1, [r6]
	ldr r0, _0819535C @ =FUN_081894fc
	ldr r1, [sp, #0xfc]
	str r0, [r1]
	ldr r6, _08195360 @ =FUN_0818960c
	ldr r0, [sp, #0x11c]
	str r6, [r0]
	ldr r1, [sp, #0x128]
	str r2, [r1]
	ldr r2, [sp, #0x138]
	str r3, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	ldr r0, _08195364 @ =FUN_080f44f4
	ldr r4, [sp, #0x140]
	str r0, [r4]
	ldr r0, _08195368 @ =FUN_080f410c
	ldr r6, [sp, #0x148]
	str r0, [r6]
	ldr r0, [sp, #0x12c]
	str r5, [r0]
	ldr r1, _0819536C @ =FUN_08189610
	ldr r2, [sp, #0xd8]
	str r1, [r2]
	ldr r3, [sp, #0x1b8]
	ldr r4, [sp, #0x16c]
	str r3, [r4]
	ldr r0, _08195370 @ =FUN_080f0430
	ldr r6, [sp, #0x170]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r0, _08195374 @ =0x085AD470
	ldr r2, [sp, #0x174]
	str r0, [r2]
	ldr r0, _08195378 @ =FUN_080e73c8
	ldr r3, [sp, #0x15c]
	str r0, [r3]
	ldr r4, [sp, #0x150]
	str r5, [r4]
	ldr r6, [sp, #0x160]
	str r5, [r6]
	ldr r0, [sp, #0x164]
	str r5, [r0]
	ldr r1, [sp, #0x168]
	str r5, [r1]
	ldr r2, [sp, #0x178]
	str r5, [r2]
	ldr r0, _0819537C @ =FUN_080f0320
	ldr r3, [sp, #0x17c]
	str r0, [r3]
	ldr r0, _08195380 @ =Enemy_080eff14
	ldr r4, [sp, #0x110]
	str r0, [r4]
	ldr r0, _08195384 @ =FUN_080e72b0
	ldr r6, [sp, #0x154]
	str r0, [r6]
	ldr r0, _08195388 @ =FUN_0818afc0
	ldr r1, [sp, #0x14c]
	str r0, [r1]
	ldr r0, _0819538C @ =Enemy_StateBlownAway
	ldr r2, [sp, #0x158]
	str r0, [r2]
	ldr r0, _08195390 @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x144]
	str r0, [r3]
	ldr r4, [sp, #0x100]
	str r5, [r4]
	ldr r0, _08195394 @ =FUN_080f6e64
	ldr r6, [sp, #0x180]
	str r0, [r6]
	ldr r0, _08195398 @ =Enemy_OnDamaged
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	ldr r0, _0819539C @ =FUN_080f84d4
	ldr r2, [sp, #0x184]
	str r0, [r2]
	ldr r0, _081953A0 @ =FUN_080f624c
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r0, _081953A4 @ =FUN_080f56ec
	ldr r4, [sp, #0xec]
	str r0, [r4]
	ldr r0, _081953A8 @ =FUN_080f5b34
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, _081953AC @ =FUN_080f5fac
	ldr r1, [sp, #0xf4]
	str r0, [r1]
	ldr r2, [sp, #0x104]
	str r5, [r2]
	movs r0, #0x28
	ldr r3, [sp, #0x7c]
	strb r0, [r3]
	ldr r4, _081953B0 @ =0x0000060C
	adds r1, r7, r4
	ldr r0, _081953B4 @ =0x085ADD74
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081953B8 @ =Serpent_OnReset
	str r0, [r1]
	ldr r1, _081953BC @ =0x000005FC
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081953C0 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081953C4 @ =FUN_08192124
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081953C8 @ =FUN_0819218c
	str r0, [r1]
	subs r4, #4
	adds r1, r7, r4
	ldr r0, _081953CC @ =FUN_08192190
	str r0, [r1]
	subs r6, #0x6c
	adds r1, r7, r6
	ldr r0, _081953D0 @ =FUN_08194240
	str r0, [r1]
	ldr r0, _081953D4 @ =0x000005B4
	adds r1, r7, r0
	ldr r0, _081953D8 @ =FUN_08190824
	str r0, [r1]
	ldr r1, _081953DC @ =0x00100200
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081953E0 @ =0x02000008
	ldr r3, [sp, #0x60]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0xc0
	ldr r4, [sp, #0x1b0]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_InitShadowAndEmitter
	movs r6, #0xaa
	lsls r6, r6, #2
	adds r4, r7, r6
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x188]
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r2, _081953E4 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081953E8 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl AuxShadow_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r4, #0
	bl AuxShadow_Hide
	ldr r3, _081953EC @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x6c]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081953FA
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08195328:
	bl VM_GetPC
	cmp r0, #0
	beq _081953F0
	bl VM_GetValue
	b _081953F2
	.align 2, 0
_08195338: .4byte 0x00000F74
_0819533C: .4byte FUN_08194264
_08195340: .4byte Serpent_GetMoveSpeed
_08195344: .4byte FUN_08189608
_08195348: .4byte Serpent_StateDamaged
_0819534C: .4byte Serpent_StateDying
_08195350: .4byte FUN_080f62b0
_08195354: .4byte FUN_080f62ac
_08195358: .4byte FUN_08189104
_0819535C: .4byte FUN_081894fc
_08195360: .4byte FUN_0818960c
_08195364: .4byte FUN_080f44f4
_08195368: .4byte FUN_080f410c
_0819536C: .4byte FUN_08189610
_08195370: .4byte FUN_080f0430
_08195374: .4byte 0x085AD470
_08195378: .4byte FUN_080e73c8
_0819537C: .4byte FUN_080f0320
_08195380: .4byte Enemy_080eff14
_08195384: .4byte FUN_080e72b0
_08195388: .4byte FUN_0818afc0
_0819538C: .4byte Enemy_StateBlownAway
_08195390: .4byte Enemy_StateFallDeath
_08195394: .4byte FUN_080f6e64
_08195398: .4byte Enemy_OnDamaged
_0819539C: .4byte FUN_080f84d4
_081953A0: .4byte FUN_080f624c
_081953A4: .4byte FUN_080f56ec
_081953A8: .4byte FUN_080f5b34
_081953AC: .4byte FUN_080f5fac
_081953B0: .4byte 0x0000060C
_081953B4: .4byte 0x085ADD74
_081953B8: .4byte Serpent_OnReset
_081953BC: .4byte 0x000005FC
_081953C0: .4byte 0x000005AC
_081953C4: .4byte FUN_08192124
_081953C8: .4byte FUN_0819218c
_081953CC: .4byte FUN_08192190
_081953D0: .4byte FUN_08194240
_081953D4: .4byte 0x000005B4
_081953D8: .4byte FUN_08190824
_081953DC: .4byte 0x00100200
_081953E0: .4byte 0x02000008
_081953E4: .4byte 0x0000044C
_081953E8: .4byte 0x00001C1B
_081953EC: .4byte 0x0000044D
_081953F0:
	movs r0, #0
_081953F2:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08195328
_081953FA:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x70]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x50]
	strh r0, [r3]
	cmp r2, #0
	beq _08195432
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x5c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08195432
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08195432:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x1b0]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08195444
	movs r0, #1
	b _08195446
_08195444:
	movs r0, #0
_08195446:
	cmp r0, #0
	beq _08195458
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08195458:
	cmp r2, #1
	beq _0819548C
	movs r0, #0
	ldr r1, [sp, #0x198]
	strb r0, [r1]
	ldr r2, [sp, #0x19c]
	strb r0, [r2]
	ldr r3, [sp, #0x1a0]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x1a8]
	strb r1, [r5]
	ldr r6, [sp, #0xfc]
	ldr r2, [r6]
	ldr r3, [sp, #0x1ac]
	strb r1, [r3]
	ldr r4, [sp, #0x1a4]
	strb r0, [r4]
	ldr r5, [sp, #0x9c]
	strb r0, [r5]
	ldr r6, [sp, #0xd0]
	str r2, [r6]
	ldr r1, [sp, #0x78]
	strh r0, [r1]
_0819548C:
	movs r1, #2
	ldr r2, [sp, #0x1b0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819549C
	movs r0, #1
	b _0819549E
_0819549C:
	movs r0, #0
_0819549E:
	cmp r0, #0
	beq _081954B8
	ldr r0, _081954B4 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x4c]
	strh r0, [r4]
	b _081954C2
	.align 2, 0
_081954B4: .4byte 0x030046A0
_081954B8:
	ldr r0, [sp, #0x188]
	bl GetZoneAt
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
_081954C2:
	movs r1, #0x40
	ldr r6, [sp, #0x1b0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081954D2
	movs r0, #1
	b _081954D4
_081954D2:
	movs r0, #0
_081954D4:
	cmp r0, #0
	beq _081954E4
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08195508 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081954E4:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _08195516
	ldr r0, _0819550C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x4c]
	ldrh r2, [r2]
	cmp r0, r2
	bne _08195510
	movs r0, #1
	b _08195512
	.align 2, 0
_08195508: .4byte 0xFFFFFEFF
_0819550C: .4byte 0x030046A0
_08195510:
	movs r0, #0
_08195512:
	cmp r0, #0
	bne _0819551E
_08195516:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0819551E:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08195606
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
	beq _08195560
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08195568
_08195560:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08195568:
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
	beq _0819558C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08195594
_0819558C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08195594:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _081955CC @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _08195610
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081955D0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081955C4
	ldrb r0, [r4, #5]
_081955C4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081955E0
	.align 2, 0
_081955CC: .4byte 0x0000FFFF
_081955D0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081955E0
	strh r1, [r4, #8]
_081955E0:
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
	bne _08195610
	movs r0, #1
	strb r0, [r4, #7]
	b _08195610
_08195606:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08195610:
	movs r0, #0
	ldr r3, [sp, #0x80]
	str r0, [r3]
	ldr r0, _08195628 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0819562C
	movs r0, #1
	b _0819562E
	.align 2, 0
_08195628: .4byte 0x030047A4
_0819562C:
	movs r0, #0
_0819562E:
	cmp r0, #0
	bne _0819566E
	ldr r4, [sp, #0x8c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08195656
	adds r0, r1, #0
	cmp r0, #7
	beq _08195656
	cmp r0, #6
	beq _08195656
	cmp r0, #0x15
	beq _08195656
	cmp r0, #0x14
	beq _08195656
	cmp r0, #0x17
	bne _0819566E
_08195656:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x1b0]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0819566E:
	adds r0, r7, #0
	bl FUN_0818e6fc
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x198]
	strb r2, [r6]
	ldr r1, [sp, #0x19c]
	strb r2, [r1]
	ldr r3, [sp, #0x1a0]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x1a8]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x1ac]
	strb r1, [r3]
	ldr r4, [sp, #0x1a4]
	strb r2, [r4]
	ldr r5, [sp, #0x9c]
	strb r1, [r5]
	ldr r6, [sp, #0xd0]
	str r0, [r6]
	ldr r0, [sp, #0x78]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_0818e2a4
	adds r0, r7, #0
	bl FUN_081941bc
	ldr r1, _0819575C @ =0x0000D636
	ldr r2, _08195760 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_0818ee98
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x188]
	bl FUN_0819014c
	adds r0, r7, #0
	bl FUN_08190fb8
	adds r0, r7, #0
	bl FUN_0818e6fc
	adds r0, r7, #0
	bl FUN_081939c0
	ldr r1, [sp, #0x1b0]
	ldrh r0, [r1]
	ldr r2, [sp, #0xcc]
	strh r0, [r2]
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ldr r4, [sp, #0xc8]
	strh r0, [r4]
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	ldr r6, [sp, #0xa8]
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldr r0, [r1]
	ldr r2, [sp, #0xac]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xb0]
	strb r0, [r3]
	ldr r4, [sp, #0x198]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb4]
	strb r0, [r5]
	ldr r6, [sp, #0x19c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xb8]
	strb r0, [r1]
	ldr r2, [sp, #0x1a0]
	ldrb r0, [r2]
	ldr r3, [sp, #0xbc]
	strb r0, [r3]
	ldr r4, [sp, #0xd0]
	ldr r0, [r4]
	ldr r5, [sp, #0xc0]
	str r0, [r5]
	ldr r6, [sp, #0x9c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc4]
	strb r0, [r1]
	ldr r2, _08195764 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08195768 @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0819576C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08195770 @ =Serpent_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08195774 @ =Serpent_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08195778
	movs r0, #0
	b _0819577C
	.align 2, 0
_0819575C: .4byte 0x0000D636
_08195760: .4byte 0x0000C102
_08195764: .4byte 0x0000057C
_08195768: .4byte Enemy_DispatchMsg
_0819576C: .4byte 0x0000061C
_08195770: .4byte Serpent_Update
_08195774: .4byte Serpent_Destroy
_08195778:
	movs r0, #1
	rsbs r0, r0, #0
_0819577C:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
