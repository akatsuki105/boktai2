	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _081CE818 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	bl 0x081c6410 @ TODO: Replace by FUN_081c6410
	ldr r3, _081CE81C @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CE828
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081CE820 @ =0x0000D635
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081CE824 @ =0x0000F6E7
	bl FUN_080e3804
	ldr r4, _081CE818 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xa4]
	cmp r1, #0x11
	beq _081CE806
	cmp r1, #0x17
	bne _081CE80A
_081CE806:
	movs r0, #1
	strb r0, [r5, #7]
_081CE80A:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081CE890
	.align 2, 0
_081CE818: .4byte 0x000001DF
_081CE81C: .4byte 0x0000025D
_081CE820: .4byte 0x0000D635
_081CE824: .4byte 0x0000F6E7
_081CE828:
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
	ldr r2, _081CE90C @ =0x05000002
	bl CpuSet
	ldr r0, _081CE910 @ =0x0000CB05
	ldr r1, _081CE914 @ =0x0000D635
	bl FUN_082310cc
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl FUN_0822f284
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
	ldr r0, _081CE918 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081CE91C @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xa4]
_081CE890:
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
	ldr r5, _081CE920 @ =0x0000046F
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
	bl FUN_0823174c
	ldr r1, _081CE924 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081CE90C @ =0x05000002
	bl CpuSet
	ldr r3, _081CE928 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x68]
	mov r3, r8
	str r3, [sp, #0x70]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1a0]
	adds r6, r2, #0
	cmp r0, #0
	bne _081CE8FC
	b _081CEA5C
_081CE8FC:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CE92C
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CE92E
	.align 2, 0
_081CE90C: .4byte 0x05000002
_081CE910: .4byte 0x0000CB05
_081CE914: .4byte 0x0000D635
_081CE918: .4byte 0x000004B7
_081CE91C: .4byte 0x000001DF
_081CE920: .4byte 0x0000046F
_081CE924: .4byte 0x00000474
_081CE928: .4byte 0x000004B6
_081CE92C:
	movs r1, #0
_081CE92E:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081CE954 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl FUN_082316bc
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _081CE958
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CE95A
	.align 2, 0
_081CE954: .4byte 0x00000251
_081CE958:
	movs r1, #0
_081CE95A:
	ldr r2, _081CE990 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081CE994 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl FUN_082316bc
	str r4, [sp, #0xf8]
	cmp r0, #0
	beq _081CE998
	bl fetch_082316e4
	b _081CE99C
	.align 2, 0
_081CE990: .4byte 0x00000252
_081CE994: .4byte 0x000004B4
_081CE998:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4]
_081CE99C:
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
	blt _081CE9D4
	cmp r1, #0
	blt _081CE9D4
	ldr r0, _081CE9D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE9D4
	ldr r0, _081CE9DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE9E0
_081CE9D4:
	movs r1, #0
	b _081CE9EE
	.align 2, 0
_081CE9D8: .4byte 0x030046A8
_081CE9DC: .4byte 0x030046AC
_081CE9E0:
	ldr r0, _081CEA08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081CE9EE:
	ldr r2, _081CEA0C @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CEA10
	adds r0, #4
	b _081CEA1C
	.align 2, 0
_081CEA08: .4byte 0x030046A4
_081CEA0C: .4byte 0x00000256
_081CEA10:
	ldr r0, _081CEA30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CEA1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CEA34
	cmp r2, #2
	beq _081CEA38
	b _081CEA3C
	.align 2, 0
_081CEA30: .4byte 0x030046A4
_081CEA34:
	ldrb r0, [r4, #4]
	b _081CEA3A
_081CEA38:
	ldrb r0, [r4]
_081CEA3A:
	subs r1, r1, r0
_081CEA3C:
	ldr r3, _081CEA54 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081CEA58 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081CEA9C
	.align 2, 0
_081CEA54: .4byte 0x00000472
_081CEA58: .4byte 0x0000FFFF
_081CEA5C:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081CEAC0 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081CEAC4 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081CEAC8 @ =0x000004B4
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
_081CEA9C:
	movs r0, #0x4e
	movs r1, #0
	bl FUN_0823174c
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081CEAE6
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEACC
	bl fetch_082316e4
	adds r4, r0, #0
	b _081CEACE
	.align 2, 0
_081CEAC0: .4byte 0x00000251
_081CEAC4: .4byte 0x00000252
_081CEAC8: .4byte 0x000004B4
_081CEACC:
	movs r4, #0x30
_081CEACE:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEAE0
	bl fetch_082316e4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081CEAE2
_081CEAE0:
	movs r5, #0x40
_081CEAE2:
	mov r8, r4
	b _081CEAEC
_081CEAE6:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081CEAEC:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081CEB24
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEB06
	bl fetch_082316e4
	adds r6, r0, #0
	b _081CEB08
_081CEB06:
	movs r6, #0
_081CEB08:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEB18
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CEB1A
_081CEB18:
	movs r1, #0
_081CEB1A:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081CEB2E
_081CEB24:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081CEB2E:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _081CEDA8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x98]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa8]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _081CEDAC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x108]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
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
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _081CEDB0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _081CEDB4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _081CEDB8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _081CEDBC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x6c]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x74]
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
	ldr r4, _081CEDC0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x140]
	ldr r6, _081CEDC4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x144]
	ldr r1, _081CEDC8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _081CEDCC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x154]
	ldr r4, _081CEDD0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	ldr r6, _081CEDD4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _081CEDD8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	ldr r3, _081CEDDC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _081CEDE0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x170]
	ldr r6, _081CEDE4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081CEDE8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x178]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _081CEDEC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x18c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x190]
	ldr r6, _081CEDF0 @ =0x000005BC
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
	ldr r3, _081CEDF4 @ =0x000005EC
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
	ldr r6, _081CEDF8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x194]
	ldr r1, _081CEDFC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x114]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x138]
	ldr r4, _081CEE00 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081CEE04 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x124]
	ldr r1, _081CEE08 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081CEE0C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x80]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x84]
	ldr r5, _081CEE10 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _081CEE14 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _081CEE18 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _081CEE1C @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xec]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _081CEE20 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x88]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	ldr r5, _081CEE24 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	ldr r1, _081CEE28 @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _081CEE2C @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _081CEE30 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0xd0]
	ldr r4, _081CEE34 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	ldr r6, _081CEE38 @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	cmp r0, #0
	bne _081CED78
	b _081CEE92
_081CED78:
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
_081CED98:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEE3C
	bl fetch_082316e4
	b _081CEE3E
	.align 2, 0
_081CEDA8: .4byte 0x0000025D
_081CEDAC: .4byte 0x0000025A
_081CEDB0: .4byte 0x0000047A
_081CEDB4: .4byte 0x0000047C
_081CEDB8: .4byte 0x0000047E
_081CEDBC: .4byte 0x000004A4
_081CEDC0: .4byte 0x000005A4
_081CEDC4: .4byte 0x000005C4
_081CEDC8: .4byte 0x000005CC
_081CEDCC: .4byte 0x000005D4
_081CEDD0: .4byte 0x000005DC
_081CEDD4: .4byte 0x00000584
_081CEDD8: .4byte 0x00000604
_081CEDDC: .4byte 0x0000021D
_081CEDE0: .4byte 0x0000060C
_081CEDE4: .4byte 0x000005E4
_081CEDE8: .4byte 0x000005FC
_081CEDEC: .4byte 0x00000614
_081CEDF0: .4byte 0x000005BC
_081CEDF4: .4byte 0x000005EC
_081CEDF8: .4byte 0x00000624
_081CEDFC: .4byte 0x0000058C
_081CEE00: .4byte 0x00000594
_081CEE04: .4byte 0x0000059C
_081CEE08: .4byte 0x000005B4
_081CEE0C: .4byte 0x00000543
_081CEE10: .4byte 0x00000496
_081CEE14: .4byte 0x00000469
_081CEE18: .4byte 0x0000046A
_081CEE1C: .4byte 0x00000553
_081CEE20: .4byte 0x00000572
_081CEE24: .4byte 0x0000055C
_081CEE28: .4byte 0x00000564
_081CEE2C: .4byte 0x00000565
_081CEE30: .4byte 0x00000566
_081CEE34: .4byte 0x00000567
_081CEE38: .4byte 0x0000056C
_081CEE3C:
	movs r0, #0x18
_081CEE3E:
	strh r0, [r4]
	adds r6, r5, #0
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEE50
	bl fetch_082316e4
	b _081CEE52
_081CEE50:
	movs r0, #0x18
_081CEE52:
	strh r0, [r6]
	mov r6, r8
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEE64
	bl fetch_082316e4
	b _081CEE66
_081CEE64:
	movs r0, #0
_081CEE66:
	str r0, [r6]
	mov r6, sb
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEE78
	bl fetch_082316e4
	b _081CEE7A
_081CEE78:
	movs r0, #0
_081CEE7A:
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
	ble _081CED98
_081CEE92:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081CEEDE
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEEAC
	bl fetch_082316e4
	adds r4, r0, #0
	b _081CEEB0
_081CEEAC:
	movs r4, #0x96
	lsls r4, r4, #1
_081CEEB0:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEEC0
	bl fetch_082316e4
	adds r6, r0, #0
	b _081CEEC4
_081CEEC0:
	movs r6, #0x96
	lsls r6, r6, #1
_081CEEC4:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEED2
	bl fetch_082316e4
	b _081CEED8
_081CEED2:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_081CEED8:
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	b _081CEEE6
_081CEEDE:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xe8]
	strh r6, [r2]
_081CEEE6:
	movs r0, #0x62
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _081CEEFE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x70]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081CEEFE:
	movs r0, #0x46
	movs r1, #0
	bl FUN_0823174c
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl FUN_0823174c
	ldr r1, [sp, #0x78]
	strh r0, [r1]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081CEFCC
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEF2E
	bl fetch_082316e4
	b _081CEF30
_081CEF2E:
	movs r0, #0
_081CEF30:
	ldr r2, [sp, #0xfc]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081CEF3E
	asrs r1, r0, #1
	b _081CEF44
_081CEF3E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081CEF44:
	ldr r3, _081CEF58 @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEF5C
	bl fetch_082316e4
	b _081CEF5E
	.align 2, 0
_081CEF58: .4byte 0x00000546
_081CEF5C:
	movs r0, #0
_081CEF5E:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEF74
	bl fetch_082316e4
	b _081CEF76
_081CEF74:
	movs r0, #0
_081CEF76:
	ldr r2, _081CEF8C @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEF90
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CEF92
	.align 2, 0
_081CEF8C: .4byte 0x00000187
_081CEF90:
	movs r1, #0
_081CEF92:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEFA8
	bl fetch_082316e4
	b _081CEFAA
_081CEFA8:
	movs r0, #0
_081CEFAA:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CEFC2
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CEFC4
_081CEFC2:
	movs r1, #0
_081CEFC4:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081CEFCC:
	ldr r3, [sp, #0xfc]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r4, [sp, #0x98]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0xa0]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0xa8]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x9c]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081CF02E
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF014
	bl fetch_082316e4
	b _081CF016
_081CF014:
	movs r0, #0
_081CF016:
	str r0, [r6]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF026
	bl fetch_082316e4
	b _081CF028
_081CF026:
	movs r0, #0
_081CF028:
	ldr r3, _081CF090 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081CF02E:
	movs r0, #0x4b
	movs r1, #2
	bl FUN_0823174c
	ldr r4, [sp, #0x108]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _081CF052
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081CF052:
	movs r0, #0x4c
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _081CF06A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081CF06A:
	ldr r0, [sp, #0x90]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CF094
	movs r0, #1
	b _081CF096
	.align 2, 0
_081CF090: .4byte 0x00000189
_081CF094:
	movs r0, #0
_081CF096:
	cmp r0, #0
	beq _081CF0A6
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081CF0D0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081CF0A6:
	ldr r3, [sp, #0x10c]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081CF0B2
	ldr r1, [r7, #0x44]
_081CF0B2:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081CF0D4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081CF0E0
	.align 2, 0
_081CF0D0: .4byte 0x080f48ac+1
_081CF0D4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081CF0E0:
	ldr r5, [sp, #0xa4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CF12E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081CF12E
	cmp r0, #0x16
	beq _081CF12E
	cmp r0, #0x14
	beq _081CF12E
	cmp r0, #9
	beq _081CF12E
	cmp r0, #0x19
	beq _081CF12E
	cmp r0, #0x1a
	beq _081CF12E
	cmp r0, #0xd
	beq _081CF12E
	cmp r0, #0x1b
	beq _081CF12E
	cmp r0, #0x1f
	beq _081CF12E
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
_081CF12E:
	movs r1, #8
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081CF13E
	movs r0, #1
	b _081CF140
_081CF13E:
	movs r0, #0
_081CF140:
	cmp r0, #0
	beq _081CF14E
	ldr r6, [sp, #0xb0]
	ldr r0, [r6]
	ldr r1, [sp, #0xac]
	str r0, [r1]
	b _081CF160
_081CF14E:
	ldr r2, [sp, #0xb0]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xac]
	str r0, [r3]
_081CF160:
	ldrh r0, [r7]
	ldr r4, [sp, #0x38]
	strh r0, [r4]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x3c]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081CF18A
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
_081CF18A:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _081CF1D2
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF1A4
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CF1A6
_081CF1A4:
	movs r1, #0xc8
_081CF1A6:
	ldr r2, [sp, #0x24]
	ldr r3, _081CF1C0 @ =0x000006CC
	adds r0, r2, r3
	strh r1, [r0]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF1C4
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CF1CA
	.align 2, 0
_081CF1C0: .4byte 0x000006CC
_081CF1C4:
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r4, #0
_081CF1CA:
	ldr r5, [sp, #0x24]
	ldr r6, _081CF1F0 @ =0x000006CE
	adds r0, r5, r6
	strh r1, [r0]
_081CF1D2:
	movs r0, #0x59
	bl prepare_08231510
	cmp r0, #0
	beq _081CF252
	ldr r0, [sp, #0x24]
	ldr r1, _081CF1F4 @ =0x000006B4
	adds r4, r0, r1
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF1F8
	bl fetch_082316e4
	b _081CF1FA
	.align 2, 0
_081CF1F0: .4byte 0x000006CE
_081CF1F4: .4byte 0x000006B4
_081CF1F8:
	movs r0, #0
_081CF1FA:
	str r0, [r4]
	ldr r2, [sp, #0x24]
	ldr r3, _081CF21C @ =0x000006B4
	adds r1, r2, r3
	ldr r0, [r1]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	str r0, [r1]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF220
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CF226
	.align 2, 0
_081CF21C: .4byte 0x000006B4
_081CF220:
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r1, r5, #0
_081CF226:
	ldr r6, [sp, #0x24]
	ldr r2, _081CF240 @ =0x000006C2
	adds r0, r6, r2
	strh r1, [r0]
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF244
	bl fetch_082316e4
	adds r1, r0, #0
	b _081CF24A
	.align 2, 0
_081CF240: .4byte 0x000006C2
_081CF244:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r3, #0
_081CF24A:
	ldr r4, [sp, #0x24]
	ldr r5, _081CF2A0 @ =0x000006C4
	adds r0, r4, r5
	strh r1, [r0]
_081CF252:
	ldr r6, [sp, #0x24]
	movs r0, #0xda
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _081CF2A4 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, _081CF2A8 @ =0x000006D4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	ldr r4, _081CF2AC @ =0x000001F5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl FUN_0823174c
	ldr r3, [sp, #0x5c]
	strh r0, [r3]
	ldr r6, [sp, #0x50]
	strh r4, [r6]
	ldr r0, [sp, #0x54]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x58]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x10c]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CF2B0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081CF2BC
	.align 2, 0
_081CF2A0: .4byte 0x000006C4
_081CF2A4: .4byte 0x0000FFFF
_081CF2A8: .4byte 0x000006D4
_081CF2AC: .4byte 0x000001F5
_081CF2B0:
	ldr r2, [r7, #0x44]
	ldr r0, _081CF2F4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081CF2BC:
	ldr r3, [sp, #0x10c]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081CF30C
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081CF2F8
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
	b _081CF302
	.align 2, 0
_081CF2F4: .4byte 0x03003584
_081CF2F8:
	ldr r5, [sp, #0xa4]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_081CF302:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081CF30C:
	adds r0, r7, #0
	bl 0x081c6850 @ TODO: FUN_081c6850
	ldr r6, [sp, #0x24]
	ldr r1, _081CF4CC @ =0x000006DC
	adds r0, r6, r1
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r6, r6, r2
	mov r8, r6
	ldr r3, _081CF4D0 @ =FUN_081ce654
	mov sb, r3
	ldr r4, _081CF4D4 @ =FUN_081c6604
	mov sl, r4
	ldr r5, _081CF4D8 @ =FUN_081c7ffc
	mov ip, r5
	ldr r5, _081CF4DC @ =FUN_081cd624
	ldr r3, _081CF4E0 @ =FUN_080f62b0
	ldr r6, _081CF4E4 @ =FUN_080f62ac
	str r6, [sp, #0x19c]
	movs r4, #0
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x68]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x6c]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x74]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x100]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x110]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x118]
	str r2, [r6]
	ldr r1, _081CF4E8 @ =FUN_081c7fb4
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r6, _081CF4EC @ =FUN_081c7fd8
	ldr r1, [sp, #0x12c]
	str r6, [r1]
	ldr r2, _081CF4F0 @ =FUN_081c869c
	ldr r6, [sp, #0x140]
	str r2, [r6]
	ldr r1, [sp, #0x144]
	str r3, [r1]
	ldr r2, [sp, #0x14c]
	str r5, [r2]
	ldr r3, _081CF4F4 @ =FUN_081ca3a8
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r1, _081CF4F8 @ =FUN_080f44f4
	ldr r6, [sp, #0x154]
	str r1, [r6]
	ldr r1, _081CF4FC @ =FUN_080f410c
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, _081CF500 @ =FUN_081c88b4
	ldr r5, [sp, #0x148]
	str r3, [r5]
	ldr r6, _081CF504 @ =FUN_081c8698
	ldr r1, [sp, #0x104]
	str r6, [r1]
	ldr r2, [sp, #0x19c]
	ldr r3, [sp, #0x180]
	str r2, [r3]
	ldr r1, _081CF508 @ =FUN_080f0430
	ldr r5, [sp, #0x184]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r1, _081CF50C @ =0x085AD470
	ldr r2, [sp, #0x188]
	str r1, [r2]
	ldr r1, _081CF510 @ =FUN_080e73c8
	ldr r3, [sp, #0x170]
	str r1, [r3]
	ldr r5, [sp, #0x164]
	str r4, [r5]
	ldr r6, [sp, #0x174]
	str r4, [r6]
	ldr r1, [sp, #0x178]
	str r4, [r1]
	ldr r2, [sp, #0x17c]
	str r4, [r2]
	ldr r3, [sp, #0x18c]
	str r4, [r3]
	ldr r1, _081CF514 @ =FUN_080f0320
	ldr r5, [sp, #0x190]
	str r1, [r5]
	ldr r1, _081CF518 @ =FUN_080eff14
	ldr r6, [sp, #0x13c]
	str r1, [r6]
	ldr r1, _081CF51C @ =FUN_080e72b0
	ldr r2, [sp, #0x168]
	str r1, [r2]
	ldr r3, [sp, #0x160]
	str r4, [r3]
	ldr r1, _081CF520 @ =FUN_080f47c8
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r1, _081CF524 @ =FUN_080f54e4
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, [sp, #0x130]
	str r4, [r1]
	ldr r1, _081CF528 @ =FUN_080f6e64
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081CF52C @ =FUN_080f64f0
	ldr r3, [sp, #0x114]
	str r1, [r3]
	ldr r1, _081CF530 @ =FUN_080f84d4
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _081CF534 @ =FUN_080f624c
	ldr r6, [sp, #0x138]
	str r1, [r6]
	ldr r1, _081CF538 @ =FUN_080f56ec
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r1, _081CF53C @ =FUN_080f5b34
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r1, _081CF540 @ =FUN_080f5fac
	ldr r5, [sp, #0x124]
	str r1, [r5]
	ldr r6, [sp, #0x134]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xb4]
	strb r1, [r2]
	ldr r1, [sp, #0x30]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081CF544 @ =FUN_081c64b4
	str r0, [r1]
	ldr r5, _081CF548 @ =0x000005FC
	adds r1, r7, r5
	ldr r0, _081CF54C @ =FUN_081c65f0
	str r0, [r1]
	ldr r6, _081CF550 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _081CF554 @ =FUN_081c5c94
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081CF558 @ =FUN_081c5dc0
	str r0, [r1]
	ldr r2, _081CF55C @ =0x0000058C
	adds r1, r7, r2
	ldr r0, _081CF560 @ =FUN_081cc550
	str r0, [r1]
	subs r3, #0x3c
	adds r1, r7, r3
	ldr r0, _081CF564 @ =FUN_081c9f70
	str r0, [r1]
	adds r5, #0x1c
	adds r1, r7, r5
	ldr r0, _081CF568 @ =FUN_081c7108
	str r0, [r1]
	adds r6, #0x7c
	adds r1, r7, r6
	ldr r0, _081CF56C @ =FUN_080fa384
	str r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	subs r2, #0x49
	adds r1, r7, r2
	movs r0, #0x14
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #8
	ldr r4, [sp, #0x70]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl 0x080e5dd4 @ TODO: Replace by FUN_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl FUN_0823174c
	ldr r5, [sp, #0x80]
	strh r0, [r5]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _081CF57A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081CF4BC:
	bl FUN_082316bc
	cmp r0, #0
	beq _081CF570
	bl fetch_082316e4
	b _081CF572
	.align 2, 0
_081CF4CC: .4byte 0x000006DC
_081CF4D0: .4byte FUN_081ce654
_081CF4D4: .4byte 0x081c6605
_081CF4D8: .4byte 0x081c7ffd
_081CF4DC: .4byte FUN_081cd624
_081CF4E0: .4byte FUN_080f62b0
_081CF4E4: .4byte 0x080f62ac+1
_081CF4E8: .4byte 0x081c7fb4+1
_081CF4EC: .4byte 0x081c7fd8+1
_081CF4F0: .4byte 0x081c869c+1
_081CF4F4: .4byte 0x081ca3a8+1
_081CF4F8: .4byte 0x080f44f4+1
_081CF4FC: .4byte 0x080f410c+1
_081CF500: .4byte 0x081c88b4+1
_081CF504: .4byte 0x081c8698+1
_081CF508: .4byte 0x080f0430+1
_081CF50C: .4byte 0x085AD470
_081CF510: .4byte 0x080e73c8+1
_081CF514: .4byte 0x080f0320+1
_081CF518: .4byte 0x080eff14+1
_081CF51C: .4byte 0x080e72b0+1
_081CF520: .4byte 0x080f47c8+1
_081CF524: .4byte 0x080f54e4+1
_081CF528: .4byte 0x080f6e64+1
_081CF52C: .4byte 0x080f64f0+1
_081CF530: .4byte FUN_080f84d4
_081CF534: .4byte 0x080f624c+1
_081CF538: .4byte 0x080f56ec+1
_081CF53C: .4byte 0x080f5b34+1
_081CF540: .4byte 0x080f5fac+1
_081CF544: .4byte 0x081c64b4+1
_081CF548: .4byte 0x000005FC
_081CF54C: .4byte 0x081c65f0+1
_081CF550: .4byte 0x000005AC
_081CF554: .4byte 0x081c5c94+1
_081CF558: .4byte 0x081c5dc0+1
_081CF55C: .4byte 0x0000058C
_081CF560: .4byte FUN_081cc550
_081CF564: .4byte 0x081c9f70+1
_081CF568: .4byte 0x081c7108+1
_081CF56C: .4byte FUN_080fa384
_081CF570:
	movs r0, #0
_081CF572:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081CF4BC
_081CF57A:
	movs r0, #0x44
	movs r1, #0
	bl FUN_0823174c
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl FUN_0823174c
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _081CF5B2
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x68]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081CF5B2
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081CF5B2:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081CF5C4
	movs r0, #1
	b _081CF5C6
_081CF5C4:
	movs r0, #0
_081CF5C6:
	cmp r0, #0
	beq _081CF5D8
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081CF5D8:
	cmp r2, #1
	beq _081CF618
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081CF628 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081CF62C @ =0x0000046C
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
_081CF618:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081CF630
	movs r0, #1
	b _081CF632
	.align 2, 0
_081CF628: .4byte 0x00000484
_081CF62C: .4byte 0x0000046C
_081CF630:
	movs r0, #0
_081CF632:
	cmp r0, #0
	beq _081CF64C
	ldr r0, _081CF648 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081CF656
	.align 2, 0
_081CF648: .4byte 0x030046A0
_081CF64C:
	ldr r0, [sp, #0x30]
	bl FUN_08241574
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081CF656:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CF666
	movs r0, #1
	b _081CF668
_081CF666:
	movs r0, #0
_081CF668:
	cmp r0, #0
	beq _081CF678
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081CF69C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081CF678:
	movs r0, #0x53
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	bne _081CF6AA
	ldr r0, _081CF6A0 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081CF6A4
	movs r0, #1
	b _081CF6A6
	.align 2, 0
_081CF69C: .4byte 0xFFFFFEFF
_081CF6A0: .4byte 0x030046A0
_081CF6A4:
	movs r0, #0
_081CF6A6:
	cmp r0, #0
	bne _081CF6B2
_081CF6AA:
	adds r0, r7, #0
	movs r1, #0
	bl 0x080f07d0 @ TODO: Replace by FUN_080f07d0
_081CF6B2:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x10c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081CF79A
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
	beq _081CF6F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081CF6FC
_081CF6F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081CF6FC:
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
	beq _081CF720
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081CF728
_081CF720:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081CF728:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081CF760 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081CF7A4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081CF764
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081CF758
	ldrb r0, [r4, #5]
_081CF758:
	subs r0, #1
	strh r0, [r4, #8]
	b _081CF774
	.align 2, 0
_081CF760: .4byte 0x0000FFFF
_081CF764:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081CF774
	strh r1, [r4, #8]
_081CF774:
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
	bne _081CF7A4
	movs r0, #1
	strb r0, [r4, #7]
	b _081CF7A4
_081CF79A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081CF7A4:
	movs r0, #0
	ldr r3, [sp, #0x94]
	str r0, [r3]
	ldr r0, _081CF7BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CF7C0
	movs r0, #1
	b _081CF7C2
	.align 2, 0
_081CF7BC: .4byte 0x030047A4
_081CF7C0:
	movs r0, #0
_081CF7C2:
	cmp r0, #0
	bne _081CF802
	ldr r4, [sp, #0xa4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CF7EA
	adds r0, r1, #0
	cmp r0, #7
	beq _081CF7EA
	cmp r0, #6
	beq _081CF7EA
	cmp r0, #0x15
	beq _081CF7EA
	cmp r0, #0x14
	beq _081CF7EA
	cmp r0, #0x17
	bne _081CF802
_081CF7EA:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081CF802:
	ldr r6, [sp, #0x8c]
	ldr r3, [r6]
	ldr r1, [sp, #0x5c]
	ldrh r0, [r1]
	cmp r0, #1
	bls _081CF812
	cmp r0, #4
	bne _081CF824
_081CF812:
	ldr r4, _081CF820 @ =0x000006AC
	adds r2, r3, r4
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	b _081CF83A
	.align 2, 0
_081CF820: .4byte 0x000006AC
_081CF824:
	ldr r0, _081CF8DC @ =0x000006AC
	adds r2, r3, r0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r1, r3, r4
	movs r0, #0xe1
	lsls r0, r0, #0xa
	str r0, [r1]
_081CF83A:
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, _081CF8E0 @ =0x0000FFFF
	str r0, [r1]
	ldr r6, _081CF8E4 @ =0x000006BC
	adds r1, r3, r6
	ldr r0, [r2]
	str r0, [r1]
	adds r0, r7, #0
	bl 0x080f3680 @ TODO: FUN_080f3680
	adds r0, r7, #0
	bl FUN_081cc53c
	adds r0, r7, #0
	bl 0x081cb138 @ TODO: FUN_081cb138
	adds r0, r7, #0
	bl 0x081cb390 @ TODO: FUN_081cb390
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xe4]
	strh r0, [r2]
	ldr r3, [sp, #0x88]
	ldrh r0, [r3]
	ldr r4, [sp, #0xe0]
	strh r0, [r4]
	ldr r5, [sp, #0x68]
	ldr r0, [r5]
	ldr r6, [sp, #0xc0]
	str r0, [r6]
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	ldr r2, [sp, #0xc4]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc8]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0xcc]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd0]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xd4]
	strb r0, [r3]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	ldr r5, [sp, #0xd8]
	str r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	ldr r1, [sp, #0xdc]
	strb r0, [r1]
	ldr r2, _081CF8E8 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _081CF8EC @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _081CF8F0 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _081CF8F4 @ =FUN_081ce6a0
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _081CF8F8 @ =FUN_081ce6ac
	str r0, [r1]
	adds r0, r7, #0
	bl 0x080ec640 @ TODO: Replace by FUN_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF8FC
	movs r0, #0
	b _081CF900
	.align 2, 0
_081CF8DC: .4byte 0x000006AC
_081CF8E0: .4byte 0x0000FFFF
_081CF8E4: .4byte 0x000006BC
_081CF8E8: .4byte 0x0000057C
_081CF8EC: .4byte 0x080f09e0+1
_081CF8F0: .4byte 0x0000061C
_081CF8F4: .4byte FUN_081ce6a0
_081CF8F8: .4byte FUN_081ce6ac
_081CF8FC:
	movs r0, #1
	rsbs r0, r0, #0
_081CF900:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
