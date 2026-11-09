	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x30]
	ldr r1, _0817A63C @ =0x00001008
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	ldr r2, _0817A640 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r7, #0
	bl Sandworm_InitAnims
	ldr r3, _0817A644 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817A650
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0817A648 @ =0x0000D636
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0817A64C @ =0x0000C102
	bl EnemyAuxSprite_LoadAnim
	ldr r4, _0817A640 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xb4]
	cmp r1, #0x11
	beq _0817A62C
	cmp r1, #0x17
	bne _0817A630
_0817A62C:
	movs r0, #1
	strb r0, [r5, #7]
_0817A630:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _0817A6B8
	.align 2, 0
_0817A63C: .4byte 0x00001008
_0817A640: .4byte 0x000001DF
_0817A644: .4byte 0x0000025D
_0817A648: .4byte 0x0000D636
_0817A64C: .4byte 0x0000C102
_0817A650:
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
	ldr r2, _0817A734 @ =0x05000002
	bl CpuSet
	ldr r0, _0817A738 @ =0x0000CB05
	ldr r1, _0817A73C @ =0x0000D636
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
	ldr r0, _0817A740 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _0817A744 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xb4]
_0817A6B8:
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
	ldr r5, _0817A748 @ =0x0000046F
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
	ldr r1, _0817A74C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _0817A734 @ =0x05000002
	bl CpuSet
	ldr r3, _0817A750 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl VM_SeekToNamedArg
	mov r1, sb
	str r1, [sp, #0x88]
	mov r3, r8
	str r3, [sp, #0x8c]
	str r6, [sp, #0x60]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _0817A724
	b _0817A884
_0817A724:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A754
	bl VM_GetValue
	adds r1, r0, #0
	b _0817A756
	.align 2, 0
_0817A734: .4byte 0x05000002
_0817A738: .4byte 0x0000CB05
_0817A73C: .4byte 0x0000D636
_0817A740: .4byte 0x000004B7
_0817A744: .4byte 0x000001DF
_0817A748: .4byte 0x0000046F
_0817A74C: .4byte 0x00000474
_0817A750: .4byte 0x000004B6
_0817A754:
	movs r1, #0
_0817A756:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0817A77C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x134]
	str r4, [sp, #0x138]
	cmp r0, #0
	beq _0817A780
	bl VM_GetValue
	adds r1, r0, #0
	b _0817A782
	.align 2, 0
_0817A77C: .4byte 0x00000251
_0817A780:
	movs r1, #0
_0817A782:
	ldr r2, _0817A7B8 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0817A7BC @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x134]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x140]
	cmp r0, #0
	beq _0817A7C0
	bl VM_GetValue
	b _0817A7C4
	.align 2, 0
_0817A7B8: .4byte 0x00000252
_0817A7BC: .4byte 0x000004B4
_0817A7C0:
	ldr r4, [sp, #0x134]
	ldrb r0, [r4]
_0817A7C4:
	strb r0, [r6]
	ldr r5, [sp, #0x134]
	ldrb r1, [r5]
	ldr r6, [sp, #0x140]
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
	blt _0817A7FC
	cmp r1, #0
	blt _0817A7FC
	ldr r0, _0817A800 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817A7FC
	ldr r0, _0817A804 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817A808
_0817A7FC:
	movs r1, #0
	b _0817A816
	.align 2, 0
_0817A800: .4byte 0x030046A8
_0817A804: .4byte 0x030046AC
_0817A808:
	ldr r0, _0817A830 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817A816:
	ldr r2, _0817A834 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817A838
	adds r0, #4
	b _0817A844
	.align 2, 0
_0817A830: .4byte 0x030046A4
_0817A834: .4byte 0x00000256
_0817A838:
	ldr r0, _0817A858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817A844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817A85C
	cmp r2, #2
	beq _0817A860
	b _0817A864
	.align 2, 0
_0817A858: .4byte 0x030046A4
_0817A85C:
	ldrb r0, [r4, #4]
	b _0817A862
_0817A860:
	ldrb r0, [r4]
_0817A862:
	subs r1, r1, r0
_0817A864:
	ldr r3, _0817A87C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0817A880 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _0817A8C4
	.align 2, 0
_0817A87C: .4byte 0x00000472
_0817A880: .4byte 0x0000FFFF
_0817A884:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0817A8E8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0817A8EC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0817A8F0 @ =0x000004B4
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
	str r5, [sp, #0x134]
	str r4, [sp, #0x138]
	str r3, [sp, #0x140]
_0817A8C4:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817A90E
	bl VM_GetPC
	cmp r0, #0
	beq _0817A8F4
	bl VM_GetValue
	adds r4, r0, #0
	b _0817A8F6
	.align 2, 0
_0817A8E8: .4byte 0x00000251
_0817A8EC: .4byte 0x00000252
_0817A8F0: .4byte 0x000004B4
_0817A8F4:
	movs r4, #0x30
_0817A8F6:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A908
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0817A90A
_0817A908:
	movs r5, #0x40
_0817A90A:
	mov r8, r4
	b _0817A914
_0817A90E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0817A914:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817A94C
	bl VM_GetPC
	cmp r0, #0
	beq _0817A92E
	bl VM_GetValue
	adds r6, r0, #0
	b _0817A930
_0817A92E:
	movs r6, #0
_0817A930:
	bl VM_GetPC
	cmp r0, #0
	beq _0817A940
	bl VM_GetValue
	adds r1, r0, #0
	b _0817A942
_0817A940:
	movs r1, #0
_0817A942:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0817A956
_0817A94C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0817A956:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	ldr r1, _0817ABE8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x90]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x144]
	lsls r4, r4, #0x10
	str r4, [sp, #0xb0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xbc]
	lsls r6, r6, #0x10
	str r6, [sp, #0xc4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xb8]
	ldr r4, _0817ABEC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x150]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xac]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x3c]
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
	str r3, [sp, #0x40]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x44]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x1b4]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r1, _0817ABF0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _0817ABF4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r3, _0817ABF8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _0817ABFC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _0817AC00 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x128]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _0817AC04 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	ldr r1, _0817AC08 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x168]
	ldr r3, _0817AC0C @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	ldr r4, _0817AC10 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _0817AC14 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x108]
	ldr r1, _0817AC18 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x198]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x19c]
	ldr r3, _0817AC1C @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x104]
	ldr r4, _0817AC20 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x1a0]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _0817AC24 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _0817AC28 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x194]
	ldr r4, _0817AC2C @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a8]
	ldr r6, _0817AC30 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x14c]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _0817AC34 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0817AC38 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x1ac]
	ldr r1, _0817AC3C @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1b0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _0817AC40 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _0817AC44 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x120]
	ldr r1, _0817AC48 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _0817AC4C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xc0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	ldr r5, _0817AC50 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	ldr r1, _0817AC54 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	ldr r2, _0817AC58 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x50]
	ldr r3, _0817AC5C @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _0817AC60 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x58]
	ldr r5, _0817AC64 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _0817AC68 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _0817AC6C @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x78]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	ldr r6, _0817AC70 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf4]
	ldr r3, _0817AC74 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd8]
	ldr r5, _0817AC78 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xdc]
	ldr r6, _0817AC7C @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	ldr r1, _0817AC80 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	ldr r2, _0817AC84 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xec]
	ldr r4, _0817AC88 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	cmp r0, #0
	bne _0817ABB8
	b _0817ACE4
_0817ABB8:
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
_0817ABD8:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AC8C
	bl VM_GetValue
	b _0817AC8E
	.align 2, 0
_0817ABE8: .4byte 0x0000025D
_0817ABEC: .4byte 0x0000025A
_0817ABF0: .4byte 0x0000047A
_0817ABF4: .4byte 0x0000047C
_0817ABF8: .4byte 0x0000047E
_0817ABFC: .4byte 0x000004A4
_0817AC00: .4byte 0x000005A4
_0817AC04: .4byte 0x000005C4
_0817AC08: .4byte 0x000005CC
_0817AC0C: .4byte 0x000005D4
_0817AC10: .4byte 0x000005DC
_0817AC14: .4byte 0x00000584
_0817AC18: .4byte 0x00000604
_0817AC1C: .4byte 0x0000021D
_0817AC20: .4byte 0x0000060C
_0817AC24: .4byte 0x000005E4
_0817AC28: .4byte 0x000005FC
_0817AC2C: .4byte 0x00000614
_0817AC30: .4byte 0x000005BC
_0817AC34: .4byte 0x000005EC
_0817AC38: .4byte 0x00000624
_0817AC3C: .4byte 0x0000058C
_0817AC40: .4byte 0x00000594
_0817AC44: .4byte 0x0000059C
_0817AC48: .4byte 0x000005B4
_0817AC4C: .4byte 0x00000543
_0817AC50: .4byte 0x00000496
_0817AC54: .4byte 0x00000469
_0817AC58: .4byte 0x0000046A
_0817AC5C: .4byte 0x00000484
_0817AC60: .4byte 0x0000046C
_0817AC64: .4byte 0x0000046D
_0817AC68: .4byte 0x0000046B
_0817AC6C: .4byte 0x00000553
_0817AC70: .4byte 0x00000572
_0817AC74: .4byte 0x0000055C
_0817AC78: .4byte 0x00000564
_0817AC7C: .4byte 0x00000565
_0817AC80: .4byte 0x00000566
_0817AC84: .4byte 0x00000567
_0817AC88: .4byte 0x0000056C
_0817AC8C:
	movs r0, #0x18
_0817AC8E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACA0
	bl VM_GetValue
	b _0817ACA2
_0817ACA0:
	movs r0, #0x18
_0817ACA2:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACB4
	bl VM_GetValue
	b _0817ACB6
_0817ACB4:
	movs r0, #0
_0817ACB6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACC8
	bl VM_GetValue
	b _0817ACCA
_0817ACC8:
	movs r0, #0
_0817ACCA:
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
	bgt _0817ACE4
	b _0817ABD8
_0817ACE4:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817AD30
	bl VM_GetPC
	cmp r0, #0
	beq _0817ACFE
	bl VM_GetValue
	adds r4, r0, #0
	b _0817AD02
_0817ACFE:
	movs r4, #0x96
	lsls r4, r4, #1
_0817AD02:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD12
	bl VM_GetValue
	adds r6, r0, #0
	b _0817AD16
_0817AD12:
	movs r6, #0x96
	lsls r6, r6, #1
_0817AD16:
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD24
	bl VM_GetValue
	b _0817AD2A
_0817AD24:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0817AD2A:
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	b _0817AD38
_0817AD30:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x130]
	strh r6, [r5]
_0817AD38:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0817AD50
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0817AD50:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x94]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817AE20
	bl VM_GetPC
	cmp r0, #0
	beq _0817AD80
	bl VM_GetValue
	b _0817AD82
_0817AD80:
	movs r0, #0
_0817AD82:
	ldr r1, [sp, #0x144]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0817AD90
	asrs r1, r0, #1
	b _0817AD96
_0817AD90:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0817AD96:
	ldr r2, _0817ADAC @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADB0
	bl VM_GetValue
	b _0817ADB2
	.align 2, 0
_0817ADAC: .4byte 0x00000546
_0817ADB0:
	movs r0, #0
_0817ADB2:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADC8
	bl VM_GetValue
	b _0817ADCA
_0817ADC8:
	movs r0, #0
_0817ADCA:
	ldr r5, _0817ADE0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADE4
	bl VM_GetValue
	adds r1, r0, #0
	b _0817ADE6
	.align 2, 0
_0817ADE0: .4byte 0x00000187
_0817ADE4:
	movs r1, #0
_0817ADE6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0817ADFC
	bl VM_GetValue
	b _0817ADFE
_0817ADFC:
	movs r0, #0
_0817ADFE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE16
	bl VM_GetValue
	adds r1, r0, #0
	b _0817AE18
_0817AE16:
	movs r1, #0
_0817AE18:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0817AE20:
	ldr r0, [sp, #0x144]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl Enemy_InitHpAndState
	ldr r1, [sp, #0xb0]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xbc]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xc4]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xb8]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetRanges
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817AE82
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE68
	bl VM_GetValue
	b _0817AE6A
_0817AE68:
	movs r0, #0
_0817AE6A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0817AE7A
	bl VM_GetValue
	b _0817AE7C
_0817AE7A:
	movs r0, #0
_0817AE7C:
	ldr r2, _0817AEE4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0817AE82:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r3, [sp, #0x150]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0817AEA6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x8c]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0817AEA6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0817AEBE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0817AEBE:
	ldr r6, [sp, #0xac]
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
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817AEE8
	movs r0, #1
	b _0817AEEA
	.align 2, 0
_0817AEE4: .4byte 0x00000189
_0817AEE8:
	movs r0, #0
_0817AEEA:
	cmp r0, #0
	beq _0817AEFA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0817AF24 @ =Enemy_OnCWolfMessage
	ldr r1, [sp, #0x34]
	bl CWolfTargetManager_Register
_0817AEFA:
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0817AF06
	ldr r1, [r7, #0x44]
_0817AF06:
	ldr r0, [sp, #0x34]
	bl Mover_SetAuxSprite
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0817AF28
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x3c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl Mover_SetCollision
	b _0817AF34
	.align 2, 0
_0817AF24: .4byte Enemy_OnCWolfMessage
_0817AF28:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x3c]
	movs r2, #0x40
	movs r3, #0x40
	bl Mover_SetCollision
_0817AF34:
	ldr r5, [sp, #0xb4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817AF82
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0817AF82
	cmp r0, #0x16
	beq _0817AF82
	cmp r0, #0x14
	beq _0817AF82
	cmp r0, #9
	beq _0817AF82
	cmp r0, #0x19
	beq _0817AF82
	cmp r0, #0x1a
	beq _0817AF82
	cmp r0, #0xd
	beq _0817AF82
	cmp r0, #0x1b
	beq _0817AF82
	cmp r0, #0x1f
	beq _0817AF82
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x134]
	ldrb r2, [r6]
	ldr r0, [sp, #0x138]
	ldrb r3, [r0]
	ldr r4, [sp, #0x140]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl Mover_SetPath
_0817AF82:
	movs r1, #8
	ldr r5, [sp, #0x60]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817AF92
	movs r0, #1
	b _0817AF94
_0817AF92:
	movs r0, #0
_0817AF94:
	cmp r0, #0
	beq _0817AFA2
	ldr r6, [sp, #0xcc]
	ldr r0, [r6]
	ldr r1, [sp, #0xc8]
	str r0, [r1]
	b _0817AFB4
_0817AFA2:
	ldr r2, [sp, #0xcc]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xc8]
	str r0, [r3]
_0817AFB4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x40]
	strh r0, [r4]
	ldr r5, [sp, #0x1b4]
	ldr r6, [sp, #0x44]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0817AFDE
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
_0817AFDE:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817B0D2
	bl VM_GetPC
	cmp r0, #0
	beq _0817AFF6
	bl VM_GetValue
	b _0817AFF8
_0817AFF6:
	movs r0, #0
_0817AFF8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0817B008
	bl VM_GetValue
	b _0817B00A
_0817B008:
	movs r0, #0
_0817B00A:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0817B01A
	bl VM_GetValue
	b _0817B01C
_0817B01A:
	movs r0, #0
_0817B01C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x1b4]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817B044
	cmp r1, #0
	blt _0817B044
	ldr r0, _0817B048 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817B044
	ldr r0, _0817B04C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817B050
_0817B044:
	movs r1, #0
	b _0817B05E
	.align 2, 0
_0817B048: .4byte 0x030046A8
_0817B04C: .4byte 0x030046AC
_0817B050:
	ldr r0, _0817B078 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0817B05E:
	ldr r4, _0817B07C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x1b4]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817B080
	adds r0, #4
	b _0817B08C
	.align 2, 0
_0817B078: .4byte 0x030046A4
_0817B07C: .4byte 0x00000256
_0817B080:
	ldr r0, _0817B0A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817B08C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817B0A4
	cmp r3, #2
	beq _0817B0A8
	b _0817B0AC
	.align 2, 0
_0817B0A0: .4byte 0x030046A4
_0817B0A4:
	ldrb r0, [r5, #4]
	b _0817B0AA
_0817B0A8:
	ldrb r0, [r5]
_0817B0AA:
	subs r2, r2, r0
_0817B0AC:
	ldr r5, _0817B0EC @ =0x00000472
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
	movs r1, #0x83
	lsls r1, r1, #5
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_0817B0D2:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817B0FE
	bl VM_GetPC
	cmp r0, #0
	beq _0817B0F0
	bl VM_GetValue
	adds r1, r0, #0
	b _0817B0F6
	.align 2, 0
_0817B0EC: .4byte 0x00000472
_0817B0F0:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r2, #0
_0817B0F6:
	ldr r3, [sp, #0x30]
	ldr r4, _0817B15C @ =0x00000FB2
	adds r0, r3, r4
	strh r1, [r0]
_0817B0FE:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x30]
	ldr r6, _0817B160 @ =0x00000FA8
	adds r1, r5, r6
	movs r2, #0
	strh r0, [r1]
	movs r1, #0xfb
	lsls r1, r1, #4
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r7, #0
	bl FUN_081794a8
	movs r4, #0xd1
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	ldr r3, [sp, #0x64]
	strh r4, [r3]
	ldr r4, [sp, #0x68]
	strh r5, [r4]
	ldrh r0, [r2]
	adds r5, #0x70
	adds r0, r0, r5
	ldr r6, [sp, #0x6c]
	strh r0, [r6]
	ldrh r1, [r3]
	ldrh r0, [r2]
	adds r1, r1, r0
	ldr r2, [sp, #0x154]
	ldrb r0, [r2]
	cmp r0, #0
	bne _0817B164
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0817B170
	.align 2, 0
_0817B15C: .4byte 0x00000FB2
_0817B160: .4byte 0x00000FA8
_0817B164:
	ldr r2, [r7, #0x44]
	ldr r0, _0817B1A8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0817B170:
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0817B1C0
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0817B1AC
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
	b _0817B1B6
	.align 2, 0
_0817B1A8: .4byte 0x03003584
_0817B1AC:
	ldr r5, [sp, #0xb4]
	ldrb r0, [r5]
	bl Enemy_CountByKind
	adds r4, r0, #1
_0817B1B6:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0817B1C0:
	adds r0, r7, #0
	bl Sandworm_InitHitboxes
	adds r0, r7, #0
	bl FUN_081778f0
	ldr r0, _0817B3C0 @ =0x0000102C
	ldr r6, [sp, #0x30]
	adds r0, r6, r0
	str r0, [sp, #0x1c0]
	ldr r1, _0817B3C4 @ =0x00001050
	adds r6, r6, r1
	mov r8, r6
	ldr r2, _0817B3C8 @ =FUN_0817a334
	mov sb, r2
	ldr r3, _0817B3CC @ =Sandworm_GetMoveSpeed
	mov sl, r3
	ldr r4, _0817B3D0 @ =FUN_08171294
	mov ip, r4
	movs r5, #0
	ldr r3, _0817B3D4 @ =Sandworm_StateDamaged
	ldr r4, _0817B3D8 @ =Sandworm_StateDying
	ldr r2, _0817B3DC @ =FUN_080f62b0
	ldr r6, _0817B3E0 @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x88]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1c0]
	ldr r1, [sp, #0x80]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0x84]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0x100]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0x10c]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0x114]
	str r6, [r0]
	ldr r1, _0817B3E4 @ =FUN_08170d4c
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r0, _0817B3E8 @ =FUN_08171188
	ldr r1, [sp, #0x128]
	str r0, [r1]
	ldr r6, _0817B3EC @ =FUN_08171298
	ldr r0, [sp, #0x158]
	str r6, [r0]
	ldr r1, [sp, #0x15c]
	str r2, [r1]
	ldr r2, [sp, #0x164]
	str r3, [r2]
	ldr r3, [sp, #0x168]
	str r4, [r3]
	ldr r0, _0817B3F0 @ =FUN_080f44f4
	ldr r4, [sp, #0x16c]
	str r0, [r4]
	ldr r0, _0817B3F4 @ =FUN_080f410c
	ldr r6, [sp, #0x174]
	str r0, [r6]
	ldr r0, [sp, #0x160]
	str r5, [r0]
	ldr r1, _0817B3F8 @ =FUN_081713c4
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r3, [sp, #0x1b8]
	ldr r4, [sp, #0x198]
	str r3, [r4]
	ldr r0, _0817B3FC @ =FUN_080f0430
	ldr r6, [sp, #0x19c]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0x104]
	strb r1, [r0]
	ldr r0, _0817B400 @ =0x085AD470
	ldr r2, [sp, #0x1a0]
	str r0, [r2]
	ldr r0, _0817B404 @ =FUN_080e73c8
	ldr r3, [sp, #0x188]
	str r0, [r3]
	ldr r4, [sp, #0x17c]
	str r5, [r4]
	ldr r6, [sp, #0x18c]
	str r5, [r6]
	ldr r0, [sp, #0x190]
	str r5, [r0]
	ldr r1, [sp, #0x194]
	str r5, [r1]
	ldr r2, [sp, #0x1a4]
	str r5, [r2]
	ldr r0, _0817B408 @ =FUN_080f0320
	ldr r3, [sp, #0x1a8]
	str r0, [r3]
	ldr r0, _0817B40C @ =Enemy_080eff14
	ldr r4, [sp, #0x14c]
	str r0, [r4]
	ldr r0, _0817B410 @ =FUN_080e72b0
	ldr r6, [sp, #0x180]
	str r0, [r6]
	ldr r0, _0817B414 @ =FUN_08172384
	ldr r1, [sp, #0x178]
	str r0, [r1]
	ldr r0, _0817B418 @ =Enemy_StateBlownAway
	ldr r2, [sp, #0x184]
	str r0, [r2]
	ldr r0, _0817B41C @ =Enemy_StateFallDeath
	ldr r3, [sp, #0x170]
	str r0, [r3]
	ldr r4, [sp, #0x12c]
	str r5, [r4]
	ldr r0, _0817B420 @ =FUN_080f6e64
	ldr r6, [sp, #0x1ac]
	str r0, [r6]
	ldr r0, _0817B424 @ =Enemy_OnDamaged
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r0, _0817B428 @ =FUN_080f84d4
	ldr r2, [sp, #0x1b0]
	str r0, [r2]
	ldr r0, _0817B42C @ =FUN_080f624c
	ldr r3, [sp, #0x148]
	str r0, [r3]
	ldr r0, _0817B430 @ =FUN_080f56ec
	ldr r4, [sp, #0x118]
	str r0, [r4]
	ldr r0, _0817B434 @ =FUN_080f5b34
	ldr r6, [sp, #0x11c]
	str r0, [r6]
	ldr r0, _0817B438 @ =FUN_080f5fac
	ldr r1, [sp, #0x120]
	str r0, [r1]
	ldr r2, [sp, #0x13c]
	str r5, [r2]
	movs r0, #0x28
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, _0817B43C @ =0x0000060C
	adds r1, r7, r4
	ldr r0, _0817B440 @ =0x085ADB50
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _0817B444 @ =Sandworm_OnReset
	str r0, [r1]
	ldr r1, _0817B448 @ =0x000005FC
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _0817B44C @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _0817B450 @ =FUN_08179540
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0817B454 @ =FUN_081795a8
	str r0, [r1]
	subs r4, #4
	adds r1, r7, r4
	ldr r0, _0817B458 @ =FUN_081795ac
	str r0, [r1]
	subs r6, #0x6c
	adds r1, r7, r6
	ldr r0, _0817B45C @ =FUN_0817a1f8
	str r0, [r1]
	ldr r0, _0817B460 @ =0x000005B4
	adds r1, r7, r0
	ldr r0, _0817B464 @ =FUN_08178660
	str r0, [r1]
	ldr r1, _0817B468 @ =0x00100200
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0817B46C @ =0x02000008
	ldr r3, [sp, #0x8c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0xc0
	ldr r4, [sp, #0x60]
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
	ldr r1, [sp, #0x1b4]
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r2, _0817B470 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _0817B474 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl AuxShadow_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r4, #0
	bl AuxShadow_Hide
	ldr r3, _0817B478 @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r5, [sp, #0x98]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0817B486
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0817B3B0:
	bl VM_GetPC
	cmp r0, #0
	beq _0817B47C
	bl VM_GetValue
	b _0817B47E
	.align 2, 0
_0817B3C0: .4byte 0x0000102C
_0817B3C4: .4byte 0x00001050
_0817B3C8: .4byte FUN_0817a334
_0817B3CC: .4byte Sandworm_GetMoveSpeed
_0817B3D0: .4byte FUN_08171294
_0817B3D4: .4byte Sandworm_StateDamaged
_0817B3D8: .4byte Sandworm_StateDying
_0817B3DC: .4byte FUN_080f62b0
_0817B3E0: .4byte FUN_080f62ac
_0817B3E4: .4byte FUN_08170d4c
_0817B3E8: .4byte FUN_08171188
_0817B3EC: .4byte FUN_08171298
_0817B3F0: .4byte FUN_080f44f4
_0817B3F4: .4byte FUN_080f410c
_0817B3F8: .4byte FUN_081713c4
_0817B3FC: .4byte FUN_080f0430
_0817B400: .4byte 0x085AD470
_0817B404: .4byte FUN_080e73c8
_0817B408: .4byte FUN_080f0320
_0817B40C: .4byte Enemy_080eff14
_0817B410: .4byte FUN_080e72b0
_0817B414: .4byte FUN_08172384
_0817B418: .4byte Enemy_StateBlownAway
_0817B41C: .4byte Enemy_StateFallDeath
_0817B420: .4byte FUN_080f6e64
_0817B424: .4byte Enemy_OnDamaged
_0817B428: .4byte FUN_080f84d4
_0817B42C: .4byte FUN_080f624c
_0817B430: .4byte FUN_080f56ec
_0817B434: .4byte FUN_080f5b34
_0817B438: .4byte FUN_080f5fac
_0817B43C: .4byte 0x0000060C
_0817B440: .4byte 0x085ADB50
_0817B444: .4byte Sandworm_OnReset
_0817B448: .4byte 0x000005FC
_0817B44C: .4byte 0x000005AC
_0817B450: .4byte FUN_08179540
_0817B454: .4byte FUN_081795a8
_0817B458: .4byte FUN_081795ac
_0817B45C: .4byte FUN_0817a1f8
_0817B460: .4byte 0x000005B4
_0817B464: .4byte FUN_08178660
_0817B468: .4byte 0x00100200
_0817B46C: .4byte 0x02000008
_0817B470: .4byte 0x0000044C
_0817B474: .4byte 0x00001C1B
_0817B478: .4byte 0x0000044D
_0817B47C:
	movs r0, #0
_0817B47E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0817B3B0
_0817B486:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r1, [sp, #0x9c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	cmp r2, #0
	beq _0817B4BE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x88]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0817B4BE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0817B4BE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x60]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817B4D0
	movs r0, #1
	b _0817B4D2
_0817B4D0:
	movs r0, #0
_0817B4D2:
	cmp r0, #0
	beq _0817B4E4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x8c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_0817B4E4:
	cmp r2, #1
	beq _0817B518
	movs r0, #0
	ldr r1, [sp, #0x48]
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r4, [sp, #0x74]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x58]
	strb r1, [r5]
	ldr r6, [sp, #0x128]
	ldr r2, [r6]
	ldr r3, [sp, #0x5c]
	strb r1, [r3]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r5, [sp, #0xd0]
	strb r0, [r5]
	ldr r6, [sp, #0xfc]
	str r2, [r6]
	ldr r1, [sp, #0xa4]
	strh r0, [r1]
_0817B518:
	movs r1, #2
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817B528
	movs r0, #1
	b _0817B52A
_0817B528:
	movs r0, #0
_0817B52A:
	cmp r0, #0
	beq _0817B544
	ldr r0, _0817B540 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	b _0817B54E
	.align 2, 0
_0817B540: .4byte 0x030046A0
_0817B544:
	ldr r0, [sp, #0x1b4]
	bl GetZoneAt
	ldr r5, [sp, #0x78]
	strh r0, [r5]
_0817B54E:
	movs r1, #0x40
	ldr r6, [sp, #0x60]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817B55E
	movs r0, #1
	b _0817B560
_0817B55E:
	movs r0, #0
_0817B560:
	cmp r0, #0
	beq _0817B570
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0817B594 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0817B570:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _0817B5A2
	ldr r0, _0817B598 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x78]
	ldrh r2, [r2]
	cmp r0, r2
	bne _0817B59C
	movs r0, #1
	b _0817B59E
	.align 2, 0
_0817B594: .4byte 0xFFFFFEFF
_0817B598: .4byte 0x030046A0
_0817B59C:
	movs r0, #0
_0817B59E:
	cmp r0, #0
	bne _0817B5AA
_0817B5A2:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_Suspend
_0817B5AA:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, [sp, #0x154]
	ldrb r0, [r3]
	cmp r0, #0
	bne _0817B692
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
	beq _0817B5EC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0817B5F4
_0817B5EC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0817B5F4:
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
	beq _0817B618
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0817B620
_0817B618:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0817B620:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _0817B658 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0817B69C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0817B65C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0817B650
	ldrb r0, [r4, #5]
_0817B650:
	subs r0, #1
	strh r0, [r4, #8]
	b _0817B66C
	.align 2, 0
_0817B658: .4byte 0x0000FFFF
_0817B65C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0817B66C
	strh r1, [r4, #8]
_0817B66C:
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
	bne _0817B69C
	movs r0, #1
	strb r0, [r4, #7]
	b _0817B69C
_0817B692:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_0817B69C:
	movs r0, #0
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _0817B6B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817B6B8
	movs r0, #1
	b _0817B6BA
	.align 2, 0
_0817B6B4: .4byte 0x030047A4
_0817B6B8:
	movs r0, #0
_0817B6BA:
	cmp r0, #0
	bne _0817B6FA
	ldr r4, [sp, #0xb4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817B6E2
	adds r0, r1, #0
	cmp r0, #7
	beq _0817B6E2
	cmp r0, #6
	beq _0817B6E2
	cmp r0, #0x15
	beq _0817B6E2
	cmp r0, #0x14
	beq _0817B6E2
	cmp r0, #0x17
	bne _0817B6FA
_0817B6E2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl MsgQueue_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x60]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0817B6FA:
	adds r0, r7, #0
	bl FUN_08175898
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x48]
	strb r2, [r6]
	ldr r1, [sp, #0x4c]
	strb r2, [r1]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r4, [sp, #0x74]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x58]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x5c]
	strb r1, [r3]
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0xd0]
	strb r1, [r5]
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r0, [sp, #0xa4]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_InitHandlerTables
	adds r0, r7, #0
	bl FUN_08175678
	adds r0, r7, #0
	bl FUN_0817a180
	ldr r1, _0817B7E0 @ =0x0000D636
	ldr r2, _0817B7E4 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_081763a8
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x1b4]
	bl FUN_08177f7c
	adds r0, r7, #0
	bl FUN_08178dc4
	adds r0, r7, #0
	bl FUN_08175898
	ldr r1, [sp, #0x60]
	ldrh r0, [r1]
	ldr r2, [sp, #0xf8]
	strh r0, [r2]
	ldr r3, [sp, #0xa0]
	ldrh r0, [r3]
	ldr r4, [sp, #0xf4]
	strh r0, [r4]
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	ldr r6, [sp, #0xd4]
	str r0, [r6]
	ldr r1, [sp, #0x8c]
	ldr r0, [r1]
	ldr r2, [sp, #0xd8]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xdc]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0xe0]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xe4]
	strb r0, [r1]
	ldr r2, [sp, #0x50]
	ldrb r0, [r2]
	ldr r3, [sp, #0xe8]
	strb r0, [r3]
	ldr r4, [sp, #0xfc]
	ldr r0, [r4]
	ldr r5, [sp, #0xec]
	str r0, [r5]
	ldr r6, [sp, #0xd0]
	ldrb r0, [r6]
	ldr r1, [sp, #0xf0]
	strb r0, [r1]
	ldr r2, _0817B7E8 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0817B7EC @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r3, _0817B7F0 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0817B7F4 @ =Sandworm_Update
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0817B7F8 @ =Sandworm_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817B7FC
	movs r0, #0
	b _0817B800
	.align 2, 0
_0817B7E0: .4byte 0x0000D636
_0817B7E4: .4byte 0x0000C102
_0817B7E8: .4byte 0x0000057C
_0817B7EC: .4byte Enemy_DispatchMsg
_0817B7F0: .4byte 0x0000061C
_0817B7F4: .4byte Sandworm_Update
_0817B7F8: .4byte Sandworm_Destroy
_0817B7FC:
	movs r0, #1
	rsbs r0, r0, #0
_0817B800:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
