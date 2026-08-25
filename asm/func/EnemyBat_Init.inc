	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _0814161C @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x12
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0814089c
	ldr r3, _08141620 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814162C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08141624 @ =0x0000DA6D
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08141628 @ =0x00005BB7
	bl FUN_080e3804
	ldr r4, _0814161C @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xd0]
	cmp r1, #0x11
	beq _0814160A
	cmp r1, #0x17
	bne _0814160E
_0814160A:
	movs r0, #1
	strb r0, [r5, #7]
_0814160E:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08141694
	.align 2, 0
_0814161C: .4byte 0x000001DF
_08141620: .4byte 0x0000025D
_08141624: .4byte 0x0000DA6D
_08141628: .4byte 0x00005BB7
_0814162C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _08141710 @ =0x05000002
	bl CpuSet
	ldr r0, _08141714 @ =0x0000CB05
	ldr r1, _08141718 @ =0x0000DA6D
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
	bl OpenSpriteSetFile
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
	bl FUN_0822f3fc
	ldr r0, _0814171C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08141720 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xd0]
_08141694:
	str r7, [sp, #0x28]
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
	ldr r5, _08141724 @ =0x0000046F
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
	bl Script_GetKeywordValue
	ldr r1, _08141728 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08141710 @ =0x05000002
	bl CpuSet
	ldr r3, _0814172C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x70]
	str r6, [sp, #0x48]
	ldr r2, [sp, #0x1a0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08141700
	b _08141860
_08141700:
	bl VM_GetPC
	cmp r0, #0
	beq _08141730
	bl Script_GetValue
	adds r1, r0, #0
	b _08141732
	.align 2, 0
_08141710: .4byte 0x05000002
_08141714: .4byte 0x0000CB05
_08141718: .4byte 0x0000DA6D
_0814171C: .4byte 0x000004B7
_08141720: .4byte 0x000001DF
_08141724: .4byte 0x0000046F
_08141728: .4byte 0x00000474
_0814172C: .4byte 0x000004B6
_08141730:
	movs r1, #0
_08141732:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08141758 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x150]
	str r4, [sp, #0x154]
	cmp r0, #0
	beq _0814175C
	bl Script_GetValue
	adds r1, r0, #0
	b _0814175E
	.align 2, 0
_08141758: .4byte 0x00000251
_0814175C:
	movs r1, #0
_0814175E:
	ldr r2, _08141794 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08141798 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x150]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x15c]
	cmp r0, #0
	beq _0814179C
	bl Script_GetValue
	b _081417A0
	.align 2, 0
_08141794: .4byte 0x00000252
_08141798: .4byte 0x000004B4
_0814179C:
	ldr r4, [sp, #0x150]
	ldrb r0, [r4]
_081417A0:
	strb r0, [r6]
	ldr r5, [sp, #0x150]
	ldrb r1, [r5]
	ldr r6, [sp, #0x15c]
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
	blt _081417D8
	cmp r1, #0
	blt _081417D8
	ldr r0, _081417DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081417D8
	ldr r0, _081417E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081417E4
_081417D8:
	movs r1, #0
	b _081417F2
	.align 2, 0
_081417DC: .4byte 0x030046A8
_081417E0: .4byte 0x030046AC
_081417E4:
	ldr r0, _0814180C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081417F2:
	ldr r2, _08141810 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08141814
	adds r0, #4
	b _08141820
	.align 2, 0
_0814180C: .4byte 0x030046A4
_08141810: .4byte 0x00000256
_08141814:
	ldr r0, _08141834 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08141820:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08141838
	cmp r2, #2
	beq _0814183C
	b _08141840
	.align 2, 0
_08141834: .4byte 0x030046A4
_08141838:
	ldrb r0, [r4, #4]
	b _0814183E
_0814183C:
	ldrb r0, [r4]
_0814183E:
	subs r1, r1, r0
_08141840:
	ldr r3, _08141858 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0814185C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081418A0
	.align 2, 0
_08141858: .4byte 0x00000472
_0814185C: .4byte 0x0000FFFF
_08141860:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081418C4 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081418C8 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081418CC @ =0x000004B4
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
	str r5, [sp, #0x150]
	str r4, [sp, #0x154]
	str r3, [sp, #0x15c]
_081418A0:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081418EA
	bl VM_GetPC
	cmp r0, #0
	beq _081418D0
	bl Script_GetValue
	adds r4, r0, #0
	b _081418D2
	.align 2, 0
_081418C4: .4byte 0x00000251
_081418C8: .4byte 0x00000252
_081418CC: .4byte 0x000004B4
_081418D0:
	movs r4, #0x30
_081418D2:
	bl VM_GetPC
	cmp r0, #0
	beq _081418E4
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081418E6
_081418E4:
	movs r5, #0x40
_081418E6:
	mov r8, r4
	b _081418F0
_081418EA:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081418F0:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08141928
	bl VM_GetPC
	cmp r0, #0
	beq _0814190A
	bl Script_GetValue
	adds r6, r0, #0
	b _0814190C
_0814190A:
	movs r6, #0
_0814190C:
	bl VM_GetPC
	cmp r0, #0
	beq _0814191C
	bl Script_GetValue
	adds r1, r0, #0
	b _0814191E
_0814191C:
	movs r1, #0
_0814191E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08141932
_08141928:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08141932:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08141BA4 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x148]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x78]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x160]
	lsls r4, r4, #0x10
	str r4, [sp, #0xc0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xcc]
	lsls r6, r6, #0x10
	str r6, [sp, #0xd4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xc8]
	ldr r4, _08141BA8 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x168]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xb8]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x30]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x34]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x38]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x194]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r1, _08141BAC @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	ldr r2, _08141BB0 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x50]
	ldr r3, _08141BB4 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x54]
	ldr r4, _08141BB8 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x100]
	ldr r4, _08141BBC @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x104]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _08141BC0 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x120]
	ldr r1, _08141BC4 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x12c]
	ldr r3, _08141BC8 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x130]
	ldr r4, _08141BCC @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x138]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _08141BD0 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	ldr r1, _08141BD4 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x178]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x17c]
	ldr r3, _08141BD8 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _08141BDC @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x180]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _08141BE0 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x140]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x164]
	ldr r2, _08141BE4 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x170]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x174]
	ldr r4, _08141BE8 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x188]
	ldr r6, _08141BEC @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x118]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _08141BF0 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x14c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x134]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x108]
	ldr r6, _08141BF4 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	ldr r1, _08141BF8 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x110]
	ldr r4, _08141BFC @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xf4]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf8]
	ldr r6, _08141C00 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	ldr r1, _08141C04 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	ldr r2, _08141C08 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x84]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x80]
	ldr r5, _08141C0C @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	ldr r1, _08141C10 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _08141C14 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _08141C18 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x88]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r1, _08141C1C @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x90]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb0]
	ldr r4, _08141C20 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x94]
	ldr r6, _08141C24 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0x98]
	ldr r1, _08141C28 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	ldr r2, _08141C2C @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r3, _08141C30 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xa8]
	ldr r5, _08141C34 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xac]
	cmp r0, #0
	bne _08141B74
	b _08141C8E
_08141B74:
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
_08141B94:
	bl VM_GetPC
	cmp r0, #0
	beq _08141C38
	bl Script_GetValue
	b _08141C3A
	.align 2, 0
_08141BA4: .4byte 0x0000025D
_08141BA8: .4byte 0x0000025A
_08141BAC: .4byte 0x0000047A
_08141BB0: .4byte 0x0000047C
_08141BB4: .4byte 0x0000047E
_08141BB8: .4byte 0x000004A4
_08141BBC: .4byte 0x000005A4
_08141BC0: .4byte 0x000005C4
_08141BC4: .4byte 0x000005CC
_08141BC8: .4byte 0x000005D4
_08141BCC: .4byte 0x000005DC
_08141BD0: .4byte 0x00000584
_08141BD4: .4byte 0x00000604
_08141BD8: .4byte 0x0000021D
_08141BDC: .4byte 0x0000060C
_08141BE0: .4byte 0x000005E4
_08141BE4: .4byte 0x000005FC
_08141BE8: .4byte 0x00000614
_08141BEC: .4byte 0x000005BC
_08141BF0: .4byte 0x000005EC
_08141BF4: .4byte 0x00000624
_08141BF8: .4byte 0x0000058C
_08141BFC: .4byte 0x00000594
_08141C00: .4byte 0x0000059C
_08141C04: .4byte 0x000005B4
_08141C08: .4byte 0x00000543
_08141C0C: .4byte 0x00000496
_08141C10: .4byte 0x00000469
_08141C14: .4byte 0x0000046A
_08141C18: .4byte 0x00000553
_08141C1C: .4byte 0x00000572
_08141C20: .4byte 0x0000055C
_08141C24: .4byte 0x00000564
_08141C28: .4byte 0x00000565
_08141C2C: .4byte 0x00000566
_08141C30: .4byte 0x00000567
_08141C34: .4byte 0x0000056C
_08141C38:
	movs r0, #0x18
_08141C3A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08141C4C
	bl Script_GetValue
	b _08141C4E
_08141C4C:
	movs r0, #0x18
_08141C4E:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08141C60
	bl Script_GetValue
	b _08141C62
_08141C60:
	movs r0, #0
_08141C62:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08141C74
	bl Script_GetValue
	b _08141C76
_08141C74:
	movs r0, #0
_08141C76:
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
	ble _08141B94
_08141C8E:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _08141CDA
	bl VM_GetPC
	cmp r0, #0
	beq _08141CA8
	bl Script_GetValue
	adds r4, r0, #0
	b _08141CAC
_08141CA8:
	movs r4, #0x96
	lsls r4, r4, #1
_08141CAC:
	bl VM_GetPC
	cmp r0, #0
	beq _08141CBC
	bl Script_GetValue
	adds r6, r0, #0
	b _08141CC0
_08141CBC:
	movs r6, #0x96
	lsls r6, r6, #1
_08141CC0:
	bl VM_GetPC
	cmp r0, #0
	beq _08141CCE
	bl Script_GetValue
	b _08141CD4
_08141CCE:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_08141CD4:
	ldr r5, [sp, #0x148]
	strh r0, [r5]
	b _08141CE2
_08141CDA:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0x148]
	strh r6, [r0]
_08141CE2:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08141CFA
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x70]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08141CFA:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x78]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x74]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08141DC8
	bl VM_GetPC
	cmp r0, #0
	beq _08141D2A
	bl Script_GetValue
	b _08141D2C
_08141D2A:
	movs r0, #0
_08141D2C:
	ldr r1, [sp, #0x160]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08141D3A
	asrs r1, r0, #1
	b _08141D40
_08141D3A:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08141D40:
	ldr r2, _08141D54 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08141D58
	bl Script_GetValue
	b _08141D5A
	.align 2, 0
_08141D54: .4byte 0x00000546
_08141D58:
	movs r0, #0
_08141D5A:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08141D70
	bl Script_GetValue
	b _08141D72
_08141D70:
	movs r0, #0
_08141D72:
	ldr r5, _08141D88 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08141D8C
	bl Script_GetValue
	adds r1, r0, #0
	b _08141D8E
	.align 2, 0
_08141D88: .4byte 0x00000187
_08141D8C:
	movs r1, #0
_08141D8E:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08141DA4
	bl Script_GetValue
	b _08141DA6
_08141DA4:
	movs r0, #0
_08141DA6:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08141DBE
	bl Script_GetValue
	adds r1, r0, #0
	b _08141DC0
_08141DBE:
	movs r1, #0
_08141DC0:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08141DC8:
	ldr r0, [sp, #0x160]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0xc0]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xcc]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xd4]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xc8]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _08141E2A
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08141E10
	bl Script_GetValue
	b _08141E12
_08141E10:
	movs r0, #0
_08141E12:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08141E22
	bl Script_GetValue
	b _08141E24
_08141E22:
	movs r0, #0
_08141E24:
	ldr r2, _08141E8C @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08141E2A:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x168]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08141E4E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x70]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08141E4E:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08141E66
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08141E66:
	ldr r6, [sp, #0xb8]
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
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08141E90
	movs r0, #1
	b _08141E92
	.align 2, 0
_08141E8C: .4byte 0x00000189
_08141E90:
	movs r0, #0
_08141E92:
	cmp r0, #0
	beq _08141EA2
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08141ECC @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08141EA2:
	ldr r3, [sp, #0x16c]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08141EAE
	ldr r1, [r7, #0x44]
_08141EAE:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xd0]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08141ED0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08141EDC
	.align 2, 0
_08141ECC: .4byte FUN_080f48ac
_08141ED0:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08141EDC:
	ldr r5, [sp, #0xd0]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08141F2A
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08141F2A
	cmp r0, #0x16
	beq _08141F2A
	cmp r0, #0x14
	beq _08141F2A
	cmp r0, #9
	beq _08141F2A
	cmp r0, #0x19
	beq _08141F2A
	cmp r0, #0x1a
	beq _08141F2A
	cmp r0, #0xd
	beq _08141F2A
	cmp r0, #0x1b
	beq _08141F2A
	cmp r0, #0x1f
	beq _08141F2A
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x150]
	ldrb r2, [r6]
	ldr r0, [sp, #0x154]
	ldrb r3, [r0]
	ldr r4, [sp, #0x15c]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_08141F2A:
	movs r1, #8
	ldr r5, [sp, #0x48]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08141F3A
	movs r0, #1
	b _08141F3C
_08141F3A:
	movs r0, #0
_08141F3C:
	cmp r0, #0
	beq _08141F4A
	ldr r6, [sp, #0xe8]
	ldr r0, [r6]
	ldr r1, [sp, #0xe0]
	str r0, [r1]
	b _08141F5C
_08141F4A:
	ldr r2, [sp, #0xe8]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xe0]
	str r0, [r3]
_08141F5C:
	ldrh r0, [r7]
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	ldr r5, [sp, #0x194]
	ldr r6, [sp, #0x38]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _08141F86
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
_08141F86:
	movs r0, #0x67
	bl prepare_08231510
	cmp r0, #0
	beq _08141FCE
	bl VM_GetPC
	cmp r0, #0
	beq _08141FA0
	bl Script_GetValue
	adds r1, r0, #0
	b _08141FA2
_08141FA0:
	movs r1, #0
_08141FA2:
	ldr r2, [sp, #0x24]
	ldr r3, _08141FBC @ =0x0000065E
	adds r0, r2, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08141FC0
	bl Script_GetValue
	adds r1, r0, #0
	b _08141FC2
	.align 2, 0
_08141FBC: .4byte 0x0000065E
_08141FC0:
	movs r1, #0
_08141FC2:
	ldr r4, [sp, #0x24]
	movs r5, #0xcc
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r1, [r0]
	b _08141FE2
_08141FCE:
	ldr r6, [sp, #0x24]
	ldr r0, _0814200C @ =0x0000065E
	adds r1, r6, r0
	movs r0, #0x3c
	strb r0, [r1]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
_08141FE2:
	movs r0, #0x45
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08141FF0
	movs r0, #0x40
_08141FF0:
	strb r0, [r7, #5]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	bne _08141FFE
	b _0814213A
_08141FFE:
	bl VM_GetPC
	cmp r0, #0
	beq _08142010
	bl Script_GetValue
	b _08142012
	.align 2, 0
_0814200C: .4byte 0x0000065E
_08142010:
	movs r0, #0
_08142012:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08142022
	bl Script_GetValue
	b _08142024
_08142022:
	movs r0, #0
_08142024:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08142034
	bl Script_GetValue
	b _08142036
_08142034:
	movs r0, #0
_08142036:
	strh r0, [r7, #0xc]
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	ldrb r0, [r7, #5]
	cmp r0, #0
	bne _08142058
	adds r1, r2, #0
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08142054 @ =0xFFFF0000
	ands r0, r2
	adds r2, r0, #0
	orrs r2, r1
	b _08142068
	.align 2, 0
_08142054: .4byte 0xFFFF0000
_08142058:
	adds r1, r3, #0
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0814209C @ =0xFFFF0000
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
_08142068:
	ldr r4, [sp, #0x24]
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r0, r4, r5
	str r2, [r0]
	str r3, [r0, #4]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08142098
	cmp r1, #0
	blt _08142098
	ldr r0, _081420A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08142098
	ldr r0, _081420A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081420A8
_08142098:
	movs r1, #0
	b _081420B6
	.align 2, 0
_0814209C: .4byte 0xFFFF0000
_081420A0: .4byte 0x030046A8
_081420A4: .4byte 0x030046AC
_081420A8:
	ldr r0, _081420D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081420B6:
	ldr r6, _081420DC @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r0, [sp, #0x24]
	movs r1, #0xd7
	lsls r1, r1, #3
	adds r5, r0, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081420E0
	adds r0, #4
	b _081420EC
	.align 2, 0
_081420D8: .4byte 0x030046A4
_081420DC: .4byte 0x00000256
_081420E0:
	ldr r0, _08142100 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081420EC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08142104
	cmp r2, #2
	beq _08142108
	b _0814210C
	.align 2, 0
_08142100: .4byte 0x030046A4
_08142104:
	ldrb r0, [r5, #4]
	b _0814210A
_08142108:
	ldrb r0, [r5]
_0814210A:
	subs r1, r1, r0
_0814210C:
	ldr r3, _0814217C @ =0x00000472
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r1
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r1, r7, r4
	strh r0, [r1]
	ldr r5, [sp, #0x24]
	ldr r6, _08142180 @ =0x0000065C
	adds r1, r5, r6
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r7, #0xa]
	ldrh r1, [r2]
	ldr r3, _08142184 @ =0x00000662
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r4, _08142188 @ =0x0000066E
	adds r0, r5, r4
	strh r1, [r0]
_0814213A:
	ldr r4, _0814218C @ =0x00000262
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	ldr r0, [sp, #0x4c]
	strh r4, [r0]
	ldr r1, [sp, #0x50]
	strh r5, [r1]
	ldrh r0, [r6]
	movs r2, #0x99
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r3, [sp, #0x54]
	strh r0, [r3]
	ldr r4, [sp, #0x4c]
	ldrh r1, [r4]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r5, [sp, #0x16c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08142190
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0814219C
	.align 2, 0
_0814217C: .4byte 0x00000472
_08142180: .4byte 0x0000065C
_08142184: .4byte 0x00000662
_08142188: .4byte 0x0000066E
_0814218C: .4byte 0x00000262
_08142190:
	ldr r2, [r7, #0x44]
	ldr r0, _081421D4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0814219C:
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	cmp r0, #1
	bne _081421EC
	ldr r1, [sp, #0xd0]
	ldrb r0, [r1]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081421D8
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
	b _081421E2
	.align 2, 0
_081421D4: .4byte 0x03003584
_081421D8:
	ldr r2, [sp, #0xd0]
	ldrb r0, [r2]
	bl FUN_080ecf60
	adds r4, r0, #1
_081421E2:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081421EC:
	adds r0, r7, #0
	bl FUN_08140580
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi _081422B0
	ldr r5, [sp, #0x24]
	ldr r6, _08142284 @ =0x00000674
	adds r4, r5, r6
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r1, _08142288 @ =FUN_0814145c
	str r1, [sp, #0x1a4]
	ldr r2, _0814228C @ =FUN_08140614
	mov r8, r2
	movs r2, #0
	ldr r3, _08142290 @ =FUN_0813f180
	mov sb, r3
	ldr r6, _08142294 @ =FUN_0813f2fc
	mov sl, r6
	ldr r0, _08142298 @ =FUN_0813f5fc
	mov ip, r0
	ldr r3, _0814229C @ =FUN_080f62b0
	ldr r1, _081422A0 @ =FUN_080f62ac
	str r1, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x6c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x64]
	str r4, [r0]
	ldr r1, [sp, #0x68]
	str r5, [r1]
	ldr r4, [sp, #0x1a4]
	ldr r5, [sp, #0xd8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	ldr r1, [sp, #0xf0]
	str r2, [r1]
	mov r4, sb
	ldr r5, [sp, #0x100]
	str r4, [r5]
	mov r6, sl
	ldr r0, [sp, #0x104]
	str r6, [r0]
	ldr r1, [sp, #0x11c]
	str r2, [r1]
	ldr r4, [sp, #0x120]
	str r3, [r4]
	mov r5, ip
	ldr r6, [sp, #0x128]
	str r5, [r6]
	ldr r0, _081422A4 @ =FUN_0813f7d4
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _081422A8 @ =FUN_080f44f4
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _081422AC @ =FUN_080f410c
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r5, [sp, #0x124]
	str r2, [r5]
	ldr r6, [sp, #0xdc]
	str r2, [r6]
	ldr r0, [sp, #0x198]
	b _08142332
	.align 2, 0
_08142284: .4byte 0x00000674
_08142288: .4byte FUN_0814145c
_0814228C: .4byte FUN_08140614
_08142290: .4byte FUN_0813f180
_08142294: .4byte FUN_0813f2fc
_08142298: .4byte FUN_0813f5fc
_0814229C: .4byte FUN_080f62b0
_081422A0: .4byte FUN_080f62ac
_081422A4: .4byte FUN_0813f7d4
_081422A8: .4byte FUN_080f44f4
_081422AC: .4byte FUN_080f410c
_081422B0:
	ldr r2, [sp, #0x24]
	ldr r3, _08142440 @ =0x00000674
	adds r4, r2, r3
	movs r6, #0xd3
	lsls r6, r6, #3
	adds r5, r2, r6
	ldr r0, _08142444 @ =FUN_0814145c
	str r0, [sp, #0x1a8]
	ldr r1, _08142448 @ =FUN_08140614
	mov r8, r1
	movs r2, #0
	ldr r3, _0814244C @ =FUN_0813f1f0
	mov sb, r3
	ldr r6, _08142450 @ =FUN_0813f2fc
	mov sl, r6
	ldr r0, _08142454 @ =FUN_0813f5fc
	mov ip, r0
	ldr r3, _08142458 @ =FUN_080f62b0
	ldr r1, _0814245C @ =FUN_080f62ac
	str r1, [sp, #0x19c]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x6c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x64]
	str r4, [r0]
	ldr r1, [sp, #0x68]
	str r5, [r1]
	ldr r4, [sp, #0x1a8]
	ldr r5, [sp, #0xd8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	ldr r1, [sp, #0xf0]
	str r2, [r1]
	mov r4, sb
	ldr r5, [sp, #0x100]
	str r4, [r5]
	mov r6, sl
	ldr r0, [sp, #0x104]
	str r6, [r0]
	ldr r1, [sp, #0x11c]
	str r2, [r1]
	ldr r4, [sp, #0x120]
	str r3, [r4]
	mov r5, ip
	ldr r6, [sp, #0x128]
	str r5, [r6]
	ldr r0, _08142460 @ =FUN_0813f7d4
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _08142464 @ =FUN_080f44f4
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _08142468 @ =FUN_080f410c
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r5, [sp, #0x124]
	str r2, [r5]
	ldr r6, [sp, #0xdc]
	str r2, [r6]
	ldr r0, [sp, #0x19c]
_08142332:
	ldr r1, [sp, #0x178]
	str r0, [r1]
	ldr r0, _0814246C @ =FUN_080f0430
	ldr r3, [sp, #0x17c]
	str r0, [r3]
	movs r5, #1
	ldr r4, [sp, #0x114]
	strb r5, [r4]
	ldr r0, _08142470 @ =0x085AD470
	ldr r6, [sp, #0x180]
	str r0, [r6]
	ldr r0, _08142474 @ =FUN_080e73c8
	ldr r1, [sp, #0x158]
	str r0, [r1]
	ldr r3, [sp, #0x140]
	str r2, [r3]
	ldr r4, [sp, #0x164]
	str r2, [r4]
	ldr r5, [sp, #0x170]
	str r2, [r5]
	ldr r6, [sp, #0x174]
	str r2, [r6]
	ldr r0, [sp, #0x184]
	str r2, [r0]
	ldr r0, _08142478 @ =FUN_080f0320
	ldr r1, [sp, #0x188]
	str r0, [r1]
	ldr r0, _0814247C @ =FUN_080eff14
	ldr r3, [sp, #0x118]
	str r0, [r3]
	ldr r0, _08142480 @ =FUN_080e72b0
	ldr r4, [sp, #0x144]
	str r0, [r4]
	ldr r5, [sp, #0x13c]
	str r2, [r5]
	ldr r0, _08142484 @ =FUN_080f47c8
	ldr r6, [sp, #0x14c]
	str r0, [r6]
	ldr r0, _08142488 @ =FUN_080f54e4
	ldr r1, [sp, #0x134]
	str r0, [r1]
	ldr r3, [sp, #0x108]
	str r2, [r3]
	ldr r0, _0814248C @ =FUN_080f6e64
	ldr r4, [sp, #0x18c]
	str r0, [r4]
	ldr r0, _08142490 @ =FUN_080f64f0
	ldr r5, [sp, #0xec]
	str r0, [r5]
	ldr r0, _08142494 @ =FUN_080f84d4
	ldr r6, [sp, #0x190]
	str r0, [r6]
	ldr r0, _08142498 @ =FUN_080f624c
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r0, _0814249C @ =FUN_080f56ec
	ldr r3, [sp, #0xf4]
	str r0, [r3]
	ldr r0, _081424A0 @ =FUN_080f5b34
	ldr r4, [sp, #0xf8]
	str r0, [r4]
	ldr r0, _081424A4 @ =FUN_080f5fac
	ldr r5, [sp, #0xfc]
	str r0, [r5]
	ldr r6, [sp, #0x10c]
	str r2, [r6]
	movs r0, #0x28
	ldr r1, [sp, #0x84]
	strb r0, [r1]
	ldr r2, _081424A8 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _081424AC @ =0x085AD80C
	str r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081424B0 @ =FUN_08140028
	str r0, [r1]
	ldr r4, _081424B4 @ =0x000005FC
	adds r0, r7, r4
	movs r2, #0
	str r2, [r0]
	ldr r5, _081424B8 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _081424BC @ =FUN_08140d48
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081424C0 @ =FUN_08140cd4
	str r0, [r1]
	ldr r2, _081424C4 @ =0x0000058C
	adds r1, r7, r2
	ldr r0, _081424C8 @ =FUN_080f8400
	str r0, [r1]
	ldr r1, _081424CC @ =0x02100408
	ldr r3, [sp, #0x70]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x60
	ldr r4, [sp, #0x48]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _081424DA
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08142430:
	bl VM_GetPC
	cmp r0, #0
	beq _081424D0
	bl Script_GetValue
	b _081424D2
	.align 2, 0
_08142440: .4byte 0x00000674
_08142444: .4byte FUN_0814145c
_08142448: .4byte FUN_08140614
_0814244C: .4byte FUN_0813f1f0
_08142450: .4byte FUN_0813f2fc
_08142454: .4byte FUN_0813f5fc
_08142458: .4byte FUN_080f62b0
_0814245C: .4byte FUN_080f62ac
_08142460: .4byte FUN_0813f7d4
_08142464: .4byte FUN_080f44f4
_08142468: .4byte FUN_080f410c
_0814246C: .4byte FUN_080f0430
_08142470: .4byte 0x085AD470
_08142474: .4byte FUN_080e73c8
_08142478: .4byte FUN_080f0320
_0814247C: .4byte FUN_080eff14
_08142480: .4byte FUN_080e72b0
_08142484: .4byte FUN_080f47c8
_08142488: .4byte FUN_080f54e4
_0814248C: .4byte FUN_080f6e64
_08142490: .4byte FUN_080f64f0
_08142494: .4byte FUN_080f84d4
_08142498: .4byte FUN_080f624c
_0814249C: .4byte FUN_080f56ec
_081424A0: .4byte FUN_080f5b34
_081424A4: .4byte FUN_080f5fac
_081424A8: .4byte 0x0000060C
_081424AC: .4byte 0x085AD80C
_081424B0: .4byte FUN_08140028
_081424B4: .4byte 0x000005FC
_081424B8: .4byte 0x000005AC
_081424BC: .4byte FUN_08140d48
_081424C0: .4byte FUN_08140cd4
_081424C4: .4byte 0x0000058C
_081424C8: .4byte FUN_080f8400
_081424CC: .4byte 0x02100408
_081424D0:
	movs r0, #0
_081424D2:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08142430
_081424DA:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x80]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x60]
	strh r0, [r3]
	cmp r2, #0
	beq _08142512
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x6c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08142512
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08142512:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x48]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08142524
	movs r0, #1
	b _08142526
_08142524:
	movs r0, #0
_08142526:
	cmp r0, #0
	beq _08142538
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08142538:
	cmp r2, #1
	beq _08142578
	movs r1, #0
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	ldr r4, _08142588 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _0814258C @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x104]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0xc4]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08142578:
	movs r1, #2
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08142590
	movs r0, #1
	b _08142592
	.align 2, 0
_08142588: .4byte 0x00000484
_0814258C: .4byte 0x0000046C
_08142590:
	movs r0, #0
_08142592:
	cmp r0, #0
	beq _081425AC
	ldr r0, _081425A8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x5c]
	strh r0, [r5]
	b _081425B6
	.align 2, 0
_081425A8: .4byte 0x030046A0
_081425AC:
	ldr r0, [sp, #0x194]
	bl FUN_08241574
	ldr r6, [sp, #0x5c]
	strh r0, [r6]
_081425B6:
	movs r1, #0x40
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081425C6
	movs r0, #1
	b _081425C8
_081425C6:
	movs r0, #0
_081425C8:
	cmp r0, #0
	beq _081425D8
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081425FC @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081425D8:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0814260A
	ldr r0, _08142600 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x5c]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08142604
	movs r0, #1
	b _08142606
	.align 2, 0
_081425FC: .4byte 0xFFFFFEFF
_08142600: .4byte 0x030046A0
_08142604:
	movs r0, #0
_08142606:
	cmp r0, #0
	bne _08142612
_0814260A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08142612:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x16c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081426FA
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
	beq _08142654
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0814265C
_08142654:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0814265C:
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
	beq _08142680
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08142688
_08142680:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08142688:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081426C0 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08142704
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081426C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081426B8
	ldrb r0, [r4, #5]
_081426B8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081426D4
	.align 2, 0
_081426C0: .4byte 0x0000FFFF
_081426C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081426D4
	strh r1, [r4, #8]
_081426D4:
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
	bne _08142704
	movs r0, #1
	strb r0, [r4, #7]
	b _08142704
_081426FA:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08142704:
	movs r0, #0
	ldr r3, [sp, #0xbc]
	str r0, [r3]
	ldr r0, _0814271C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08142720
	movs r0, #1
	b _08142722
	.align 2, 0
_0814271C: .4byte 0x030047A4
_08142720:
	movs r0, #0
_08142722:
	cmp r0, #0
	bne _08142762
	ldr r4, [sp, #0xd0]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0814274A
	adds r0, r1, #0
	cmp r0, #7
	beq _0814274A
	cmp r0, #6
	beq _0814274A
	cmp r0, #0x15
	beq _0814274A
	cmp r0, #0x14
	beq _0814274A
	cmp r0, #0x17
	bne _08142762
_0814274A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x48]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08142762:
	adds r0, r7, #0
	bl FUN_080f3680
	adds r0, r7, #0
	bl FUN_08140014
	adds r0, r7, #0
	bl FUN_08141448
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r4, #2
	strh r4, [r0]
	ldr r1, [r7, #0x44]
	movs r0, #1
	strb r0, [r1, #7]
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _08142798
	adds r0, r7, #0
	bl FUN_08140c14
	b _081427B0
_08142798:
	ldr r1, [sp, #0x24]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	orrs r1, r4
	str r1, [r0]
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_080136b4
_081427B0:
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ldr r5, [sp, #0xb4]
	strh r0, [r5]
	ldr r6, [sp, #0x90]
	ldrh r0, [r6]
	ldr r1, [sp, #0xb0]
	strh r0, [r1]
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	ldr r3, [sp, #0x8c]
	str r0, [r3]
	ldr r4, [sp, #0x70]
	ldr r0, [r4]
	ldr r5, [sp, #0x94]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0x98]
	strb r0, [r6]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x9c]
	strb r0, [r2]
	ldr r3, [sp, #0x40]
	ldrb r0, [r3]
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldr r0, [r1]
	ldr r2, [sp, #0xa8]
	str r0, [r2]
	ldr r3, [sp, #0x88]
	ldrb r0, [r3]
	ldr r4, [sp, #0xac]
	strb r0, [r4]
	ldr r5, _08142828 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _0814282C @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _08142830 @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _08142834 @ =FUN_08141490
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _08142838 @ =EnemyBat_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814283C
	movs r0, #0
	b _08142840
	.align 2, 0
_08142828: .4byte 0x0000057C
_0814282C: .4byte FUN_080f09e0
_08142830: .4byte 0x0000061C
_08142834: .4byte FUN_08141490
_08142838: .4byte EnemyBat_Destroy
_0814283C:
	movs r0, #1
	rsbs r0, r0, #0
_08142840:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
