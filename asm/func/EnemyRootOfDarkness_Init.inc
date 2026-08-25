	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x19c
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_081a4ea0
	ldr r2, _081A5618 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A5628
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081A561C @ =0x0000D638
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081A5620 @ =0x000099DD
	bl FUN_080e3804
	ldr r3, _081A5624 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0xa8]
	cmp r1, #0x11
	beq _081A5606
	cmp r1, #0x17
	bne _081A560A
_081A5606:
	movs r0, #1
	strb r0, [r5, #7]
_081A560A:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081A5690
	.align 2, 0
_081A5618: .4byte 0x0000025D
_081A561C: .4byte 0x0000D638
_081A5620: .4byte 0x000099DD
_081A5624: .4byte 0x000001DF
_081A5628:
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
	ldr r2, _081A570C @ =0x05000002
	bl CpuSet
	ldr r0, _081A5710 @ =0x0000CB05
	ldr r1, _081A5714 @ =0x0000D638
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
	bl OpenSpriteSetFile
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
	bl FUN_0822f3fc
	ldr r6, _081A5718 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0xa8]
_081A5690:
	str r7, [sp, #0x28]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r4, #0
	str r4, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	str r4, [r2]
	ldr r3, _081A571C @ =0x0000046F
	adds r0, r7, r3
	strb r4, [r0]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r6, #0
	mov sl, r6
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _081A5720 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081A570C @ =0x05000002
	bl CpuSet
	ldr r3, _081A5724 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x198]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x74]
	str r6, [sp, #0x50]
	ldr r2, [sp, #0x198]
	adds r6, r2, #0
	cmp r0, #0
	bne _081A56FC
	b _081A5858
_081A56FC:
	bl VM_GetPC
	cmp r0, #0
	beq _081A5728
	bl Script_GetValue
	adds r1, r0, #0
	b _081A572A
	.align 2, 0
_081A570C: .4byte 0x05000002
_081A5710: .4byte 0x0000CB05
_081A5714: .4byte 0x0000D638
_081A5718: .4byte 0x000004B7
_081A571C: .4byte 0x0000046F
_081A5720: .4byte 0x00000474
_081A5724: .4byte 0x000004B6
_081A5728:
	movs r1, #0
_081A572A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081A5750 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _081A5754
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5756
	.align 2, 0
_081A5750: .4byte 0x00000251
_081A5754:
	movs r1, #0
_081A5756:
	ldr r2, _081A578C @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081A5790 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xf8]
	cmp r0, #0
	beq _081A5794
	bl Script_GetValue
	b _081A5798
	.align 2, 0
_081A578C: .4byte 0x00000252
_081A5790: .4byte 0x000004B4
_081A5794:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4]
_081A5798:
	strb r0, [r6]
	ldr r5, [sp, #0xf0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xf8]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081A57D0
	cmp r1, #0
	blt _081A57D0
	ldr r0, _081A57D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A57D0
	ldr r0, _081A57D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A57DC
_081A57D0:
	movs r1, #0
	b _081A57EA
	.align 2, 0
_081A57D4: .4byte 0x030046A8
_081A57D8: .4byte 0x030046AC
_081A57DC:
	ldr r0, _081A5804 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081A57EA:
	ldr r2, _081A5808 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A580C
	adds r0, #4
	b _081A5818
	.align 2, 0
_081A5804: .4byte 0x030046A4
_081A5808: .4byte 0x00000256
_081A580C:
	ldr r0, _081A582C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A5818:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A5830
	cmp r2, #2
	beq _081A5834
	b _081A5838
	.align 2, 0
_081A582C: .4byte 0x030046A4
_081A5830:
	ldrb r0, [r4, #4]
	b _081A5836
_081A5834:
	ldrb r0, [r4]
_081A5836:
	subs r1, r1, r0
_081A5838:
	ldr r3, _081A5850 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081A5854 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081A5898
	.align 2, 0
_081A5850: .4byte 0x00000472
_081A5854: .4byte 0x0000FFFF
_081A5858:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081A58BC @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081A58C0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081A58C4 @ =0x000004B4
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
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r3, [sp, #0xf8]
_081A5898:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081A58E2
	bl VM_GetPC
	cmp r0, #0
	beq _081A58C8
	bl Script_GetValue
	adds r4, r0, #0
	b _081A58CA
	.align 2, 0
_081A58BC: .4byte 0x00000251
_081A58C0: .4byte 0x00000252
_081A58C4: .4byte 0x000004B4
_081A58C8:
	movs r4, #0x30
_081A58CA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A58DC
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081A58DE
_081A58DC:
	movs r5, #0x40
_081A58DE:
	mov r8, r4
	b _081A58E8
_081A58E2:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081A58E8:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081A5920
	bl VM_GetPC
	cmp r0, #0
	beq _081A5902
	bl Script_GetValue
	adds r6, r0, #0
	b _081A5904
_081A5902:
	movs r6, #0
_081A5904:
	bl VM_GetPC
	cmp r0, #0
	beq _081A5914
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5916
_081A5914:
	movs r1, #0
_081A5916:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081A592A
_081A5920:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081A592A:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _081A5B9C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x80]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x94]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x9c]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa0]
	lsls r5, r5, #0x10
	str r5, [sp, #0x98]
	ldr r4, _081A5BA0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x104]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x38]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x3c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x40]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x34]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	ldr r1, _081A5BA4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r2, _081A5BA8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r3, _081A5BAC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	ldr r4, _081A5BB0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x70]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x78]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x118]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x128]
	ldr r4, _081A5BB4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x140]
	ldr r6, _081A5BB8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x144]
	ldr r1, _081A5BBC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _081A5BC0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x154]
	ldr r4, _081A5BC4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	ldr r6, _081A5BC8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x108]
	ldr r1, _081A5BCC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	ldr r3, _081A5BD0 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _081A5BD4 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x170]
	ldr r6, _081A5BD8 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081A5BDC @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x178]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _081A5BE0 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x18c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x190]
	ldr r6, _081A5BE4 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x160]
	ldr r3, _081A5BE8 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081A5BEC @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x194]
	ldr r1, _081A5BF0 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x114]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x30]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x138]
	ldr r4, _081A5BF4 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081A5BF8 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x124]
	ldr r1, _081A5BFC @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081A5C00 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x88]
	ldr r5, _081A5C04 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x44]
	ldr r1, _081A5C08 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _081A5C0C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r3, _081A5C10 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xec]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _081A5C14 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe0]
	ldr r4, _081A5C18 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xc0]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc4]
	ldr r6, _081A5C1C @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xc8]
	ldr r1, _081A5C20 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xcc]
	ldr r2, _081A5C24 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	ldr r3, _081A5C28 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd8]
	ldr r5, _081A5C2C @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xdc]
	cmp r0, #0
	bne _081A5B6C
	b _081A5C86
_081A5B6C:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_081A5B8C:
	bl VM_GetPC
	cmp r0, #0
	beq _081A5C30
	bl Script_GetValue
	b _081A5C32
	.align 2, 0
_081A5B9C: .4byte 0x0000025D
_081A5BA0: .4byte 0x0000025A
_081A5BA4: .4byte 0x0000047A
_081A5BA8: .4byte 0x0000047C
_081A5BAC: .4byte 0x0000047E
_081A5BB0: .4byte 0x000004A4
_081A5BB4: .4byte 0x000005A4
_081A5BB8: .4byte 0x000005C4
_081A5BBC: .4byte 0x000005CC
_081A5BC0: .4byte 0x000005D4
_081A5BC4: .4byte 0x000005DC
_081A5BC8: .4byte 0x00000584
_081A5BCC: .4byte 0x00000604
_081A5BD0: .4byte 0x0000021D
_081A5BD4: .4byte 0x0000060C
_081A5BD8: .4byte 0x000005E4
_081A5BDC: .4byte 0x000005FC
_081A5BE0: .4byte 0x00000614
_081A5BE4: .4byte 0x000005BC
_081A5BE8: .4byte 0x000005EC
_081A5BEC: .4byte 0x00000624
_081A5BF0: .4byte 0x0000058C
_081A5BF4: .4byte 0x00000594
_081A5BF8: .4byte 0x0000059C
_081A5BFC: .4byte 0x000005B4
_081A5C00: .4byte 0x00000543
_081A5C04: .4byte 0x00000496
_081A5C08: .4byte 0x00000469
_081A5C0C: .4byte 0x0000046A
_081A5C10: .4byte 0x00000553
_081A5C14: .4byte 0x00000572
_081A5C18: .4byte 0x0000055C
_081A5C1C: .4byte 0x00000564
_081A5C20: .4byte 0x00000565
_081A5C24: .4byte 0x00000566
_081A5C28: .4byte 0x00000567
_081A5C2C: .4byte 0x0000056C
_081A5C30:
	movs r0, #0x18
_081A5C32:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081A5C44
	bl Script_GetValue
	b _081A5C46
_081A5C44:
	movs r0, #0x18
_081A5C46:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081A5C58
	bl Script_GetValue
	b _081A5C5A
_081A5C58:
	movs r0, #0
_081A5C5A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081A5C6C
	bl Script_GetValue
	b _081A5C6E
_081A5C6C:
	movs r0, #0
_081A5C6E:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _081A5B8C
_081A5C86:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081A5CD2
	bl VM_GetPC
	cmp r0, #0
	beq _081A5CA0
	bl Script_GetValue
	adds r4, r0, #0
	b _081A5CA4
_081A5CA0:
	movs r4, #0x96
	lsls r4, r4, #1
_081A5CA4:
	bl VM_GetPC
	cmp r0, #0
	beq _081A5CB4
	bl Script_GetValue
	adds r6, r0, #0
	b _081A5CB8
_081A5CB4:
	movs r6, #0x96
	lsls r6, r6, #1
_081A5CB8:
	bl VM_GetPC
	cmp r0, #0
	beq _081A5CC6
	bl Script_GetValue
	b _081A5CCC
_081A5CC6:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_081A5CCC:
	ldr r5, [sp, #0xe8]
	strh r0, [r5]
	b _081A5CDA
_081A5CD2:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0xe8]
	strh r6, [r0]
_081A5CDA:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081A5CF2
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081A5CF2:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x80]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081A5DC0
	bl VM_GetPC
	cmp r0, #0
	beq _081A5D22
	bl Script_GetValue
	b _081A5D24
_081A5D22:
	movs r0, #0
_081A5D24:
	ldr r1, [sp, #0xfc]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _081A5D32
	asrs r1, r0, #1
	b _081A5D38
_081A5D32:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081A5D38:
	ldr r2, _081A5D4C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5D50
	bl Script_GetValue
	b _081A5D52
	.align 2, 0
_081A5D4C: .4byte 0x00000546
_081A5D50:
	movs r0, #0
_081A5D52:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5D68
	bl Script_GetValue
	b _081A5D6A
_081A5D68:
	movs r0, #0
_081A5D6A:
	ldr r5, _081A5D80 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5D84
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5D86
	.align 2, 0
_081A5D80: .4byte 0x00000187
_081A5D84:
	movs r1, #0
_081A5D86:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5D9C
	bl Script_GetValue
	b _081A5D9E
_081A5D9C:
	movs r0, #0
_081A5D9E:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5DB6
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5DB8
_081A5DB6:
	movs r1, #0
_081A5DB8:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_081A5DC0:
	ldr r0, [sp, #0xfc]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x94]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x9c]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xa0]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x98]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081A5E22
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081A5E08
	bl Script_GetValue
	b _081A5E0A
_081A5E08:
	movs r0, #0
_081A5E0A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5E1A
	bl Script_GetValue
	b _081A5E1C
_081A5E1A:
	movs r0, #0
_081A5E1C:
	ldr r2, _081A5E84 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_081A5E22:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x104]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081A5E46
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x74]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_081A5E46:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081A5E5E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081A5E5E:
	ldr r6, [sp, #0x90]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A5E88
	movs r0, #1
	b _081A5E8A
	.align 2, 0
_081A5E84: .4byte 0x00000189
_081A5E88:
	movs r0, #0
_081A5E8A:
	cmp r0, #0
	beq _081A5E9A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081A5EC4 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081A5E9A:
	ldr r3, [sp, #0x10c]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081A5EA6
	ldr r1, [r7, #0x44]
_081A5EA6:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081A5EC8
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x38]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081A5ED4
	.align 2, 0
_081A5EC4: .4byte FUN_080f48ac
_081A5EC8:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x38]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081A5ED4:
	ldr r5, [sp, #0xa8]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A5F22
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081A5F22
	cmp r0, #0x16
	beq _081A5F22
	cmp r0, #0x14
	beq _081A5F22
	cmp r0, #9
	beq _081A5F22
	cmp r0, #0x19
	beq _081A5F22
	cmp r0, #0x1a
	beq _081A5F22
	cmp r0, #0xd
	beq _081A5F22
	cmp r0, #0x1b
	beq _081A5F22
	cmp r0, #0x1f
	beq _081A5F22
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xf8]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081A5F22:
	movs r1, #8
	ldr r5, [sp, #0x50]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A5F32
	movs r0, #1
	b _081A5F34
_081A5F32:
	movs r0, #0
_081A5F34:
	cmp r0, #0
	beq _081A5F42
	ldr r6, [sp, #0xb0]
	ldr r0, [r6]
	ldr r1, [sp, #0xac]
	str r0, [r1]
	b _081A5F54
_081A5F42:
	ldr r2, [sp, #0xb0]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xac]
	str r0, [r3]
_081A5F54:
	ldrh r0, [r7]
	ldr r4, [sp, #0x3c]
	strh r0, [r4]
	ldr r5, [sp, #0x34]
	ldr r6, [sp, #0x40]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081A5F7E
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
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_081A5F7E:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _081A5FE2
	bl VM_GetPC
	cmp r0, #0
	beq _081A5F98
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5F9A
_081A5F98:
	movs r1, #0
_081A5F9A:
	ldr r2, [sp, #0x24]
	ldr r3, _081A5FB4 @ =0x0000066A
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5FB8
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5FBA
	.align 2, 0
_081A5FB4: .4byte 0x0000066A
_081A5FB8:
	movs r1, #0
_081A5FBA:
	ldr r4, [sp, #0x24]
	ldr r5, _081A5FD4 @ =0x00000672
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A5FD8
	bl Script_GetValue
	adds r1, r0, #0
	b _081A5FDA
	.align 2, 0
_081A5FD4: .4byte 0x00000672
_081A5FD8:
	movs r1, #0
_081A5FDA:
	ldr r6, [sp, #0x24]
	ldr r2, _081A6014 @ =0x00000671
	adds r0, r6, r2
	strb r1, [r0]
_081A5FE2:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x24]
	ldr r4, _081A6018 @ =0x0000066C
	adds r1, r3, r4
	strh r0, [r1]
	ldrh r0, [r7, #8]
	adds r0, #0x20
	strh r0, [r7, #8]
	ldrh r0, [r7, #0xc]
	adds r0, #0x20
	strh r0, [r7, #0xc]
	ldr r5, [sp, #0x10c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A601C
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081A6026
	.align 2, 0
_081A6014: .4byte 0x00000671
_081A6018: .4byte 0x0000066C
_081A601C:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081A6026:
	movs r4, #0xdc
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x60]
	strh r0, [r6]
	ldr r0, [sp, #0x54]
	strh r4, [r0]
	ldr r1, [sp, #0x58]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, #0xdc
	ldr r2, [sp, #0x5c]
	strh r0, [r2]
	ldr r3, [sp, #0x54]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x10c]
	ldrb r0, [r4]
	cmp r0, #0
	bne _081A6062
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081A606E
_081A6062:
	ldr r2, [r7, #0x44]
	ldr r0, _081A60A8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081A606E:
	ldr r5, [sp, #0x10c]
	ldrb r0, [r5]
	cmp r0, #1
	bne _081A60C0
	ldr r6, [sp, #0xa8]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081A60AC
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081A60B6
	.align 2, 0
_081A60A8: .4byte 0x03003584
_081A60AC:
	ldr r1, [sp, #0xa8]
	ldrb r0, [r1]
	bl FUN_080ecf60
	adds r4, r0, #1
_081A60B6:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081A60C0:
	adds r0, r7, #0
	bl FUN_081a5060
	ldr r2, [sp, #0x24]
	ldr r4, _081A6258 @ =0x00000674
	adds r3, r2, r4
	movs r5, #0xd3
	lsls r5, r5, #3
	adds r4, r2, r5
	ldr r5, _081A625C @ =FUN_081a546c
	movs r1, #0
	ldr r6, _081A6260 @ =FUN_081a3360
	mov sb, r6
	ldr r0, _081A6264 @ =FUN_081a3fc8
	mov ip, r0
	ldr r2, _081A6268 @ =FUN_080f62ac
	mov r8, r2
	movs r6, #1
	mov sl, r6
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x6c]
	ldr r0, [r6]
	orrs r0, r2
	str r0, [r6]
	ldr r0, [sp, #0x70]
	str r3, [r0]
	ldr r2, [sp, #0x78]
	str r4, [r2]
	ldr r3, [sp, #0x100]
	str r5, [r3]
	ldr r4, [sp, #0x110]
	str r1, [r4]
	ldr r5, [sp, #0x118]
	str r1, [r5]
	ldr r6, [sp, #0x128]
	str r1, [r6]
	ldr r0, [sp, #0x12c]
	str r1, [r0]
	ldr r2, [sp, #0x140]
	str r1, [r2]
	ldr r3, [sp, #0x144]
	str r1, [r3]
	ldr r4, [sp, #0x14c]
	str r1, [r4]
	mov r5, ip
	ldr r6, [sp, #0x150]
	str r5, [r6]
	ldr r0, _081A626C @ =FUN_080f44f4
	ldr r2, [sp, #0x154]
	str r0, [r2]
	ldr r0, _081A6270 @ =FUN_080f410c
	ldr r3, [sp, #0x15c]
	str r0, [r3]
	ldr r4, [sp, #0x148]
	str r1, [r4]
	mov r5, sb
	ldr r6, [sp, #0x108]
	str r5, [r6]
	mov r0, r8
	ldr r2, [sp, #0x180]
	str r0, [r2]
	ldr r0, _081A6274 @ =FUN_080f0430
	ldr r3, [sp, #0x184]
	str r0, [r3]
	mov r5, sl
	ldr r4, [sp, #0xb8]
	strb r5, [r4]
	ldr r0, _081A6278 @ =0x085AD470
	ldr r6, [sp, #0x188]
	str r0, [r6]
	ldr r0, _081A627C @ =FUN_080e73c8
	ldr r2, [sp, #0x170]
	str r0, [r2]
	ldr r3, [sp, #0x164]
	str r1, [r3]
	ldr r4, [sp, #0x174]
	str r1, [r4]
	ldr r5, [sp, #0x178]
	str r1, [r5]
	ldr r6, [sp, #0x17c]
	str r1, [r6]
	ldr r0, [sp, #0x18c]
	str r1, [r0]
	ldr r0, _081A6280 @ =FUN_080f0320
	ldr r2, [sp, #0x190]
	str r0, [r2]
	ldr r0, _081A6284 @ =FUN_080eff14
	ldr r3, [sp, #0x13c]
	str r0, [r3]
	ldr r0, _081A6288 @ =FUN_080e72b0
	ldr r4, [sp, #0x168]
	str r0, [r4]
	ldr r5, [sp, #0x160]
	str r1, [r5]
	ldr r0, _081A628C @ =FUN_080f47c8
	ldr r6, [sp, #0x16c]
	str r0, [r6]
	ldr r0, _081A6290 @ =FUN_080f54e4
	ldr r2, [sp, #0x158]
	str r0, [r2]
	ldr r3, [sp, #0x130]
	str r1, [r3]
	ldr r0, _081A6294 @ =FUN_080f6e64
	ldr r4, [sp, #0x194]
	str r0, [r4]
	ldr r0, _081A6298 @ =FUN_080f64f0
	ldr r5, [sp, #0x114]
	str r0, [r5]
	ldr r0, _081A629C @ =FUN_080f84d4
	ldr r6, [sp, #0x30]
	str r0, [r6]
	ldr r0, _081A62A0 @ =FUN_080f624c
	ldr r2, [sp, #0x138]
	str r0, [r2]
	ldr r0, _081A62A4 @ =FUN_080f56ec
	ldr r3, [sp, #0x11c]
	str r0, [r3]
	ldr r0, _081A62A8 @ =FUN_080f5b34
	ldr r4, [sp, #0x120]
	str r0, [r4]
	ldr r0, _081A62AC @ =FUN_080f5fac
	ldr r5, [sp, #0x124]
	str r0, [r5]
	ldr r6, [sp, #0x134]
	str r1, [r6]
	movs r0, #0x28
	ldr r2, [sp, #0xb4]
	strb r0, [r2]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _081A62B0 @ =FUN_081a4f2c
	str r0, [r2]
	ldr r4, _081A62B4 @ =0x000005AC
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	ldr r6, _081A62B8 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081A62BC @ =FUN_081a4c3c
	str r0, [r1]
	ldr r0, _081A62C0 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080e5dd4
	movs r1, #0x80
	lsls r1, r1, #2
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
	movs r0, #0xc0
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x45
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081A622A
	movs r1, #0x80
	lsls r1, r1, #0x12
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081A622A:
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x84]
	strh r0, [r6]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _081A62CE
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_081A6248:
	bl VM_GetPC
	cmp r0, #0
	beq _081A62C4
	bl Script_GetValue
	b _081A62C6
	.align 2, 0
_081A6258: .4byte 0x00000674
_081A625C: .4byte FUN_081a546c
_081A6260: .4byte FUN_081a3360
_081A6264: .4byte FUN_081a3fc8
_081A6268: .4byte FUN_080f62ac
_081A626C: .4byte FUN_080f44f4
_081A6270: .4byte FUN_080f410c
_081A6274: .4byte FUN_080f0430
_081A6278: .4byte 0x085AD470
_081A627C: .4byte FUN_080e73c8
_081A6280: .4byte FUN_080f0320
_081A6284: .4byte FUN_080eff14
_081A6288: .4byte FUN_080e72b0
_081A628C: .4byte FUN_080f47c8
_081A6290: .4byte FUN_080f54e4
_081A6294: .4byte FUN_080f6e64
_081A6298: .4byte FUN_080f64f0
_081A629C: .4byte FUN_080f84d4
_081A62A0: .4byte FUN_080f624c
_081A62A4: .4byte FUN_080f56ec
_081A62A8: .4byte FUN_080f5b34
_081A62AC: .4byte FUN_080f5fac
_081A62B0: .4byte FUN_081a4f2c
_081A62B4: .4byte 0x000005AC
_081A62B8: .4byte 0x0000058C
_081A62BC: .4byte FUN_081a4c3c
_081A62C0: .4byte 0x000001DF
_081A62C4:
	movs r0, #0
_081A62C6:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081A6248
_081A62CE:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x88]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x68]
	strh r0, [r3]
	cmp r2, #0
	beq _081A6306
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x6c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081A6306
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081A6306:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x50]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A6318
	movs r0, #1
	b _081A631A
_081A6318:
	movs r0, #0
_081A631A:
	cmp r0, #0
	beq _081A632C
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081A632C:
	cmp r2, #1
	beq _081A636C
	movs r1, #0
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r2, [sp, #0x48]
	strb r1, [r2]
	ldr r3, [sp, #0x4c]
	strb r1, [r3]
	ldr r4, _081A637C @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081A6380 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x12c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xec]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081A636C:
	movs r1, #2
	ldr r3, [sp, #0x50]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081A6384
	movs r0, #1
	b _081A6386
	.align 2, 0
_081A637C: .4byte 0x00000484
_081A6380: .4byte 0x0000046C
_081A6384:
	movs r0, #0
_081A6386:
	cmp r0, #0
	beq _081A63A0
	ldr r0, _081A639C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x64]
	strh r0, [r5]
	b _081A63AA
	.align 2, 0
_081A639C: .4byte 0x030046A0
_081A63A0:
	ldr r0, [sp, #0x34]
	bl FUN_08241574
	ldr r6, [sp, #0x64]
	strh r0, [r6]
_081A63AA:
	movs r1, #0x40
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A63BA
	movs r0, #1
	b _081A63BC
_081A63BA:
	movs r0, #0
_081A63BC:
	cmp r0, #0
	beq _081A63CC
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081A63F0 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081A63CC:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081A63FE
	ldr r0, _081A63F4 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x64]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081A63F8
	movs r0, #1
	b _081A63FA
	.align 2, 0
_081A63F0: .4byte 0xFFFFFEFF
_081A63F4: .4byte 0x030046A0
_081A63F8:
	movs r0, #0
_081A63FA:
	cmp r0, #0
	bne _081A6406
_081A63FE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081A6406:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x10c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A64EE
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
	beq _081A6448
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081A6450
_081A6448:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A6450:
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
	beq _081A6474
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081A647C
_081A6474:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081A647C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081A64B4 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081A64F8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081A64B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081A64AC
	ldrb r0, [r4, #5]
_081A64AC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081A64C8
	.align 2, 0
_081A64B4: .4byte 0x0000FFFF
_081A64B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081A64C8
	strh r1, [r4, #8]
_081A64C8:
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
	bne _081A64F8
	movs r0, #1
	strb r0, [r4, #7]
	b _081A64F8
_081A64EE:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081A64F8:
	movs r0, #0
	ldr r3, [sp, #0xa4]
	str r0, [r3]
	ldr r0, _081A6510 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A6514
	movs r0, #1
	b _081A6516
	.align 2, 0
_081A6510: .4byte 0x030047A4
_081A6514:
	movs r0, #0
_081A6516:
	cmp r0, #0
	bne _081A6556
	ldr r4, [sp, #0xa8]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A653E
	adds r0, r1, #0
	cmp r0, #7
	beq _081A653E
	cmp r0, #6
	beq _081A653E
	cmp r0, #0x15
	beq _081A653E
	cmp r0, #0x14
	beq _081A653E
	cmp r0, #0x17
	bne _081A6556
_081A653E:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081A6556:
	adds r0, r7, #0
	bl FUN_080f3680
	adds r0, r7, #0
	bl FUN_081a4c08
	adds r0, r7, #0
	bl FUN_081a50e4
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _081A6580 @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _081A6584 @ =0x00000934
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A6588
	movs r0, #1
	b _081A658A
	.align 2, 0
_081A6580: .4byte 0x030046A0
_081A6584: .4byte 0x00000934
_081A6588:
	movs r0, #0
_081A658A:
	cmp r0, #0
	beq _081A65EC
	movs r2, #1
	movs r1, #0
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, [sp, #0x4c]
	strb r2, [r4]
	ldr r5, _081A666C @ =0x00000484
	adds r0, r7, r5
	str r1, [r0]
	ldr r6, _081A6670 @ =0x0000046C
	adds r0, r7, r6
	strb r2, [r0]
	ldr r4, _081A6674 @ =FUN_081a32d0
	movs r3, #0x29
	subs r5, #0x17
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #1
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xbc]
	strb r3, [r0]
	ldr r2, [sp, #0xec]
	str r4, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #8
	orrs r0, r1
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2, #6]
	ldr r0, _081A6678 @ =0xFFFFF7FF
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, [sp, #0x34]
	bl FUN_0803712c
_081A65EC:
	ldr r5, _081A667C @ =0x0000060C
	adds r1, r7, r5
	ldr r0, _081A6680 @ =0x085ADE8C
	str r0, [r1]
	ldr r6, [sp, #0x50]
	ldrh r0, [r6]
	ldr r1, [sp, #0xe4]
	strh r0, [r1]
	ldr r2, [sp, #0x8c]
	ldrh r0, [r2]
	ldr r3, [sp, #0xe0]
	strh r0, [r3]
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	ldr r5, [sp, #0xc0]
	str r0, [r5]
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	ldr r1, [sp, #0xc4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xc8]
	strb r0, [r2]
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
	ldr r4, [sp, #0xcc]
	strb r0, [r4]
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	ldr r6, [sp, #0xd0]
	strb r0, [r6]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	ldr r2, [sp, #0xd4]
	strb r0, [r2]
	ldr r3, [sp, #0xec]
	ldr r0, [r3]
	ldr r4, [sp, #0xd8]
	str r0, [r4]
	ldr r5, [sp, #0xbc]
	ldrb r0, [r5]
	ldr r6, [sp, #0xdc]
	strb r0, [r6]
	ldr r0, _081A6684 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _081A6688 @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _081A668C @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081A6690 @ =FUN_081a54a8
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081A6694 @ =FUN_081a54b4
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A6698
	movs r0, #0
	b _081A669C
	.align 2, 0
_081A666C: .4byte 0x00000484
_081A6670: .4byte 0x0000046C
_081A6674: .4byte FUN_081a32d0
_081A6678: .4byte 0xFFFFF7FF
_081A667C: .4byte 0x0000060C
_081A6680: .4byte 0x085ADE8C
_081A6684: .4byte 0x0000057C
_081A6688: .4byte FUN_080f09e0
_081A668C: .4byte 0x0000061C
_081A6690: .4byte FUN_081a54a8
_081A6694: .4byte FUN_081a54b4
_081A6698:
	movs r0, #1
	rsbs r0, r0, #0
_081A669C:
	add sp, #0x19c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
