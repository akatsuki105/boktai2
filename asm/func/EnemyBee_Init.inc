	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b8
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
	ldr r2, _081697F4 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x14
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08168330
	ldr r3, _081697F8 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08169804
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081697FC @ =0x00009506
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08169800 @ =0x000062C7
	bl FUN_080e3804
	ldr r4, _081697F4 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xb4]
	cmp r1, #0x11
	beq _081697E2
	cmp r1, #0x17
	bne _081697E6
_081697E2:
	movs r0, #1
	strb r0, [r5, #7]
_081697E6:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _0816986C
	.align 2, 0
_081697F4: .4byte 0x000001DF
_081697F8: .4byte 0x0000025D
_081697FC: .4byte 0x00009506
_08169800: .4byte 0x000062C7
_08169804:
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
	ldr r2, _081698E8 @ =0x05000002
	bl CpuSet
	ldr r0, _081698EC @ =0x0000CB05
	ldr r1, _081698F0 @ =0x00009506
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
	ldr r0, _081698F4 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081698F8 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xb4]
_0816986C:
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
	ldr r5, _081698FC @ =0x0000046F
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
	ldr r1, _08169900 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081698E8 @ =0x05000002
	bl CpuSet
	ldr r3, _08169904 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x80]
	mov r3, r8
	str r3, [sp, #0x84]
	str r6, [sp, #0x58]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _081698D8
	b _08169A38
_081698D8:
	bl VM_GetPC
	cmp r0, #0
	beq _08169908
	bl Script_GetValue
	adds r1, r0, #0
	b _0816990A
	.align 2, 0
_081698E8: .4byte 0x05000002
_081698EC: .4byte 0x0000CB05
_081698F0: .4byte 0x00009506
_081698F4: .4byte 0x000004B7
_081698F8: .4byte 0x000001DF
_081698FC: .4byte 0x0000046F
_08169900: .4byte 0x00000474
_08169904: .4byte 0x000004B6
_08169908:
	movs r1, #0
_0816990A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08169930 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x12c]
	str r4, [sp, #0x130]
	cmp r0, #0
	beq _08169934
	bl Script_GetValue
	adds r1, r0, #0
	b _08169936
	.align 2, 0
_08169930: .4byte 0x00000251
_08169934:
	movs r1, #0
_08169936:
	ldr r2, _0816996C @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08169970 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x12c]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x134]
	cmp r0, #0
	beq _08169974
	bl Script_GetValue
	b _08169978
	.align 2, 0
_0816996C: .4byte 0x00000252
_08169970: .4byte 0x000004B4
_08169974:
	ldr r4, [sp, #0x12c]
	ldrb r0, [r4]
_08169978:
	strb r0, [r6]
	ldr r5, [sp, #0x12c]
	ldrb r1, [r5]
	ldr r6, [sp, #0x134]
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
	blt _081699B0
	cmp r1, #0
	blt _081699B0
	ldr r0, _081699B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081699B0
	ldr r0, _081699B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081699BC
_081699B0:
	movs r1, #0
	b _081699CA
	.align 2, 0
_081699B4: .4byte 0x030046A8
_081699B8: .4byte 0x030046AC
_081699BC:
	ldr r0, _081699E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081699CA:
	ldr r2, _081699E8 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081699EC
	adds r0, #4
	b _081699F8
	.align 2, 0
_081699E4: .4byte 0x030046A4
_081699E8: .4byte 0x00000256
_081699EC:
	ldr r0, _08169A0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081699F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08169A10
	cmp r2, #2
	beq _08169A14
	b _08169A18
	.align 2, 0
_08169A0C: .4byte 0x030046A4
_08169A10:
	ldrb r0, [r4, #4]
	b _08169A16
_08169A14:
	ldrb r0, [r4]
_08169A16:
	subs r1, r1, r0
_08169A18:
	ldr r3, _08169A30 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08169A34 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08169A78
	.align 2, 0
_08169A30: .4byte 0x00000472
_08169A34: .4byte 0x0000FFFF
_08169A38:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08169A9C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08169AA0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08169AA4 @ =0x000004B4
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
	str r5, [sp, #0x12c]
	str r4, [sp, #0x130]
	str r3, [sp, #0x134]
_08169A78:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _08169AC2
	bl VM_GetPC
	cmp r0, #0
	beq _08169AA8
	bl Script_GetValue
	adds r4, r0, #0
	b _08169AAA
	.align 2, 0
_08169A9C: .4byte 0x00000251
_08169AA0: .4byte 0x00000252
_08169AA4: .4byte 0x000004B4
_08169AA8:
	movs r4, #0x30
_08169AAA:
	bl VM_GetPC
	cmp r0, #0
	beq _08169ABC
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08169ABE
_08169ABC:
	movs r5, #0x40
_08169ABE:
	mov r8, r4
	b _08169AC8
_08169AC2:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08169AC8:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08169B00
	bl VM_GetPC
	cmp r0, #0
	beq _08169AE2
	bl Script_GetValue
	adds r6, r0, #0
	b _08169AE4
_08169AE2:
	movs r6, #0
_08169AE4:
	bl VM_GetPC
	cmp r0, #0
	beq _08169AF4
	bl Script_GetValue
	adds r1, r0, #0
	b _08169AF6
_08169AF4:
	movs r1, #0
_08169AF6:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08169B0A
_08169B00:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08169B0A:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08169D9C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x144]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x124]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x8c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x88]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x138]
	lsls r4, r4, #0x10
	str r4, [sp, #0xa8]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xb0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xb8]
	lsls r5, r5, #0x10
	str r5, [sp, #0xac]
	ldr r4, _08169DA0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x140]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xa0]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xbc]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xc4]
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
	str r6, [sp, #0x68]
	ldr r1, _08169DA4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _08169DA8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r3, _08169DAC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _08169DB0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x78]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	ldr r4, _08169DB4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _08169DB8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x154]
	ldr r1, _08169DBC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x15c]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x160]
	ldr r3, _08169DC0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x164]
	ldr r4, _08169DC4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x16c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _08169DC8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x100]
	ldr r1, _08169DCC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x190]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x194]
	ldr r3, _08169DD0 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	ldr r4, _08169DD4 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x198]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x180]
	ldr r6, _08169DD8 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x174]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x184]
	ldr r2, _08169DDC @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x188]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18c]
	ldr r4, _08169DE0 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x19c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a0]
	ldr r6, _08169DE4 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x14c]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x178]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _08169DE8 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x168]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x128]
	ldr r6, _08169DEC @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x1a4]
	ldr r1, _08169DF0 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1a8]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x148]
	ldr r4, _08169DF4 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x110]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x114]
	ldr r6, _08169DF8 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x118]
	ldr r1, _08169DFC @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _08169E00 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xc0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x90]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x94]
	ldr r5, _08169E04 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _08169E08 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _08169E0C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _08169E10 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _08169E14 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x50]
	ldr r5, _08169E18 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _08169E1C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r1, _08169E20 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	ldr r6, _08169E24 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xf0]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x98]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xec]
	ldr r3, _08169E28 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	ldr r5, _08169E2C @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	ldr r6, _08169E30 @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08169E34 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	ldr r2, _08169E38 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	ldr r4, _08169E3C @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	cmp r0, #0
	bne _08169D6C
	b _08169E98
_08169D6C:
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
_08169D8C:
	bl VM_GetPC
	cmp r0, #0
	beq _08169E40
	bl Script_GetValue
	b _08169E42
	.align 2, 0
_08169D9C: .4byte 0x0000025D
_08169DA0: .4byte 0x0000025A
_08169DA4: .4byte 0x0000047A
_08169DA8: .4byte 0x0000047C
_08169DAC: .4byte 0x0000047E
_08169DB0: .4byte 0x000004A4
_08169DB4: .4byte 0x000005A4
_08169DB8: .4byte 0x000005C4
_08169DBC: .4byte 0x000005CC
_08169DC0: .4byte 0x000005D4
_08169DC4: .4byte 0x000005DC
_08169DC8: .4byte 0x00000584
_08169DCC: .4byte 0x00000604
_08169DD0: .4byte 0x0000021D
_08169DD4: .4byte 0x0000060C
_08169DD8: .4byte 0x000005E4
_08169DDC: .4byte 0x000005FC
_08169DE0: .4byte 0x00000614
_08169DE4: .4byte 0x000005BC
_08169DE8: .4byte 0x000005EC
_08169DEC: .4byte 0x00000624
_08169DF0: .4byte 0x0000058C
_08169DF4: .4byte 0x00000594
_08169DF8: .4byte 0x0000059C
_08169DFC: .4byte 0x000005B4
_08169E00: .4byte 0x00000543
_08169E04: .4byte 0x00000496
_08169E08: .4byte 0x00000469
_08169E0C: .4byte 0x0000046A
_08169E10: .4byte 0x00000484
_08169E14: .4byte 0x0000046C
_08169E18: .4byte 0x0000046D
_08169E1C: .4byte 0x0000046B
_08169E20: .4byte 0x00000553
_08169E24: .4byte 0x00000572
_08169E28: .4byte 0x0000055C
_08169E2C: .4byte 0x00000564
_08169E30: .4byte 0x00000565
_08169E34: .4byte 0x00000566
_08169E38: .4byte 0x00000567
_08169E3C: .4byte 0x0000056C
_08169E40:
	movs r0, #0x18
_08169E42:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08169E54
	bl Script_GetValue
	b _08169E56
_08169E54:
	movs r0, #0x18
_08169E56:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08169E68
	bl Script_GetValue
	b _08169E6A
_08169E68:
	movs r0, #0
_08169E6A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08169E7C
	bl Script_GetValue
	b _08169E7E
_08169E7C:
	movs r0, #0
_08169E7E:
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
	bgt _08169E98
	b _08169D8C
_08169E98:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _08169EE4
	bl VM_GetPC
	cmp r0, #0
	beq _08169EB2
	bl Script_GetValue
	adds r4, r0, #0
	b _08169EB6
_08169EB2:
	movs r4, #0x96
	lsls r4, r4, #1
_08169EB6:
	bl VM_GetPC
	cmp r0, #0
	beq _08169EC6
	bl Script_GetValue
	adds r6, r0, #0
	b _08169ECA
_08169EC6:
	movs r6, #0x96
	lsls r6, r6, #1
_08169ECA:
	bl VM_GetPC
	cmp r0, #0
	beq _08169ED8
	bl Script_GetValue
	b _08169EDE
_08169ED8:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_08169EDE:
	ldr r3, [sp, #0x124]
	strh r0, [r3]
	b _08169EEC
_08169EE4:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x124]
	strh r6, [r5]
_08169EEC:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08169F04
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x84]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08169F04:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x8c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08169FD4
	bl VM_GetPC
	cmp r0, #0
	beq _08169F34
	bl Script_GetValue
	b _08169F36
_08169F34:
	movs r0, #0
_08169F36:
	ldr r1, [sp, #0x138]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08169F44
	asrs r1, r0, #1
	b _08169F4A
_08169F44:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08169F4A:
	ldr r2, _08169F60 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08169F64
	bl Script_GetValue
	b _08169F66
	.align 2, 0
_08169F60: .4byte 0x00000546
_08169F64:
	movs r0, #0
_08169F66:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08169F7C
	bl Script_GetValue
	b _08169F7E
_08169F7C:
	movs r0, #0
_08169F7E:
	ldr r5, _08169F94 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08169F98
	bl Script_GetValue
	adds r1, r0, #0
	b _08169F9A
	.align 2, 0
_08169F94: .4byte 0x00000187
_08169F98:
	movs r1, #0
_08169F9A:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08169FB0
	bl Script_GetValue
	b _08169FB2
_08169FB0:
	movs r0, #0
_08169FB2:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08169FCA
	bl Script_GetValue
	adds r1, r0, #0
	b _08169FCC
_08169FCA:
	movs r1, #0
_08169FCC:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08169FD4:
	ldr r0, [sp, #0x138]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0xa8]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0xb0]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xb8]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0xac]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _0816A036
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0816A01C
	bl Script_GetValue
	b _0816A01E
_0816A01C:
	movs r0, #0
_0816A01E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0816A02E
	bl Script_GetValue
	b _0816A030
_0816A02E:
	movs r0, #0
_0816A030:
	ldr r2, _0816A098 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0816A036:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x140]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816A05A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x84]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0816A05A:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816A072
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x84]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0816A072:
	ldr r6, [sp, #0xa0]
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
	ldr r2, [sp, #0x58]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816A09C
	movs r0, #1
	b _0816A09E
	.align 2, 0
_0816A098: .4byte 0x00000189
_0816A09C:
	movs r0, #0
_0816A09E:
	cmp r0, #0
	beq _0816A0AE
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0816A0D8 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_0816A0AE:
	ldr r3, [sp, #0x144]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0816A0BA
	ldr r1, [r7, #0x44]
_0816A0BA:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0816A0DC
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _0816A0E8
	.align 2, 0
_0816A0D8: .4byte FUN_080f48ac
_0816A0DC:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_0816A0E8:
	ldr r5, [sp, #0xb4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816A136
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0816A136
	cmp r0, #0x16
	beq _0816A136
	cmp r0, #0x14
	beq _0816A136
	cmp r0, #9
	beq _0816A136
	cmp r0, #0x19
	beq _0816A136
	cmp r0, #0x1a
	beq _0816A136
	cmp r0, #0xd
	beq _0816A136
	cmp r0, #0x1b
	beq _0816A136
	cmp r0, #0x1f
	beq _0816A136
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x12c]
	ldrb r2, [r6]
	ldr r0, [sp, #0x130]
	ldrb r3, [r0]
	ldr r4, [sp, #0x134]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_0816A136:
	movs r1, #8
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816A146
	movs r0, #1
	b _0816A148
_0816A146:
	movs r0, #0
_0816A148:
	cmp r0, #0
	beq _0816A156
	ldr r6, [sp, #0xc4]
	ldr r0, [r6]
	ldr r1, [sp, #0xbc]
	str r0, [r1]
	b _0816A168
_0816A156:
	ldr r2, [sp, #0xc4]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xbc]
	str r0, [r3]
_0816A168:
	ldrh r0, [r7]
	ldr r4, [sp, #0x38]
	strh r0, [r4]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x3c]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0816A192
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
_0816A192:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _0816A1E0
	bl VM_GetPC
	cmp r0, #0
	beq _0816A1AC
	bl Script_GetValue
	adds r2, r0, #0
	b _0816A1AE
_0816A1AC:
	movs r2, #0x68
_0816A1AE:
	ldr r3, [sp, #0x24]
	ldr r4, _0816A1D0 @ =0x000006AD
	adds r0, r3, r4
	movs r1, #0
	strb r2, [r0]
	movs r5, #0xcc
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816A1D4
	bl Script_GetValue
	adds r1, r0, #0
	b _0816A1D6
	.align 2, 0
_0816A1D0: .4byte 0x000006AD
_0816A1D4:
	movs r1, #0x64
_0816A1D6:
	ldr r6, [sp, #0x24]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
_0816A1E0:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	bne _0816A1EC
	b _0816A322
_0816A1EC:
	bl VM_GetPC
	cmp r0, #0
	beq _0816A1FA
	bl Script_GetValue
	b _0816A1FC
_0816A1FA:
	movs r0, #0
_0816A1FC:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0816A20C
	bl Script_GetValue
	b _0816A20E
_0816A20C:
	movs r0, #0
_0816A20E:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0816A21E
	bl Script_GetValue
	b _0816A220
_0816A21E:
	movs r0, #0
_0816A220:
	strh r0, [r7, #0xc]
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	ldrb r0, [r7, #5]
	cmp r0, #0
	bne _0816A244
	adds r1, r2, #0
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0816A240 @ =0xFFFF0000
	ands r0, r2
	adds r2, r0, #0
	orrs r2, r1
	b _0816A254
	.align 2, 0
_0816A240: .4byte 0xFFFF0000
_0816A244:
	adds r1, r3, #0
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0816A288 @ =0xFFFF0000
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
_0816A254:
	ldr r4, [sp, #0x24]
	ldr r5, _0816A28C @ =0x0000070C
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
	blt _0816A282
	cmp r1, #0
	blt _0816A282
	ldr r0, _0816A290 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816A282
	ldr r0, _0816A294 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816A298
_0816A282:
	movs r1, #0
	b _0816A2A6
	.align 2, 0
_0816A288: .4byte 0xFFFF0000
_0816A28C: .4byte 0x0000070C
_0816A290: .4byte 0x030046A8
_0816A294: .4byte 0x030046AC
_0816A298:
	ldr r0, _0816A2C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0816A2A6:
	ldr r6, _0816A2C8 @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r0, [sp, #0x24]
	ldr r1, _0816A2CC @ =0x0000070C
	adds r5, r0, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816A2D0
	adds r0, #4
	b _0816A2DC
	.align 2, 0
_0816A2C4: .4byte 0x030046A4
_0816A2C8: .4byte 0x00000256
_0816A2CC: .4byte 0x0000070C
_0816A2D0:
	ldr r0, _0816A2F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816A2DC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816A2F4
	cmp r2, #2
	beq _0816A2F8
	b _0816A2FC
	.align 2, 0
_0816A2F0: .4byte 0x030046A4
_0816A2F4:
	ldrb r0, [r5, #4]
	b _0816A2FA
_0816A2F8:
	ldrb r0, [r5]
_0816A2FA:
	subs r1, r1, r0
_0816A2FC:
	ldr r3, _0816A378 @ =0x00000472
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r1
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r1, r7, r4
	strh r0, [r1]
	ldr r5, [sp, #0x24]
	ldr r6, _0816A37C @ =0x0000065C
	adds r1, r5, r6
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r7, #0xa]
	ldrh r1, [r2]
	ldr r2, _0816A380 @ =0x0000065E
	adds r0, r5, r2
	strh r1, [r0]
_0816A322:
	ldr r3, [sp, #0x24]
	ldr r4, _0816A384 @ =0x000006C4
	adds r1, r3, r4
	movs r0, #0
	str r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r5, #0x8e
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	movs r4, #0xb0
	adds r5, #0x16
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x68]
	strh r0, [r6]
	ldr r0, [sp, #0x5c]
	strh r4, [r0]
	ldr r1, [sp, #0x60]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, #0xb0
	ldr r2, [sp, #0x64]
	strh r0, [r2]
	ldr r3, [sp, #0x5c]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x144]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0816A388
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0816A394
	.align 2, 0
_0816A378: .4byte 0x00000472
_0816A37C: .4byte 0x0000065C
_0816A380: .4byte 0x0000065E
_0816A384: .4byte 0x000006C4
_0816A388:
	ldr r2, [r7, #0x44]
	ldr r0, _0816A3CC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0816A394:
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	cmp r0, #1
	bne _0816A3E4
	ldr r6, [sp, #0xb4]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0816A3D0
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
	b _0816A3DA
	.align 2, 0
_0816A3CC: .4byte 0x03003584
_0816A3D0:
	ldr r1, [sp, #0xb4]
	ldrb r0, [r1]
	bl FUN_080ecf60
	adds r4, r0, #1
_0816A3DA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0816A3E4:
	adds r0, r7, #0
	bl FUN_0816800c
	ldr r2, [sp, #0x24]
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r4, r2, r3
	ldr r6, _0816A578 @ =0x000006EC
	adds r5, r2, r6
	ldr r0, _0816A57C @ =FUN_0816962c
	str r0, [sp, #0x1b4]
	ldr r1, _0816A580 @ =FUN_081680a0
	mov r8, r1
	movs r2, #0
	ldr r3, _0816A584 @ =FUN_0816701c
	mov sb, r3
	ldr r6, _0816A588 @ =FUN_08167270
	mov sl, r6
	ldr r0, _0816A58C @ =FUN_08167560
	mov ip, r0
	ldr r3, _0816A590 @ =FUN_080f62b0
	ldr r1, _0816A594 @ =FUN_080f62ac
	str r1, [sp, #0x1ac]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x80]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x78]
	str r4, [r0]
	ldr r1, [sp, #0x7c]
	str r5, [r1]
	ldr r4, [sp, #0x1b4]
	ldr r5, [sp, #0xfc]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0x104]
	str r6, [r0]
	ldr r1, [sp, #0x10c]
	str r2, [r1]
	mov r4, sb
	ldr r5, [sp, #0x11c]
	str r4, [r5]
	mov r6, sl
	ldr r0, [sp, #0x120]
	str r6, [r0]
	ldr r1, [sp, #0x150]
	str r2, [r1]
	ldr r4, [sp, #0x154]
	str r3, [r4]
	mov r5, ip
	ldr r6, [sp, #0x15c]
	str r5, [r6]
	ldr r0, _0816A598 @ =FUN_081676e8
	ldr r1, [sp, #0x160]
	str r0, [r1]
	ldr r0, _0816A59C @ =FUN_080f44f4
	ldr r3, [sp, #0x164]
	str r0, [r3]
	ldr r0, _0816A5A0 @ =FUN_080f410c
	ldr r4, [sp, #0x16c]
	str r0, [r4]
	ldr r5, [sp, #0x158]
	str r2, [r5]
	ldr r6, [sp, #0x100]
	str r2, [r6]
	ldr r0, [sp, #0x1ac]
	ldr r1, [sp, #0x190]
	str r0, [r1]
	ldr r0, _0816A5A4 @ =FUN_080f0430
	ldr r3, [sp, #0x194]
	str r0, [r3]
	movs r5, #1
	ldr r4, [sp, #0xf4]
	strb r5, [r4]
	ldr r0, _0816A5A8 @ =0x085AD470
	ldr r6, [sp, #0x198]
	str r0, [r6]
	ldr r0, _0816A5AC @ =FUN_080e73c8
	ldr r1, [sp, #0x180]
	str r0, [r1]
	ldr r3, [sp, #0x174]
	str r2, [r3]
	ldr r4, [sp, #0x184]
	str r2, [r4]
	ldr r5, [sp, #0x188]
	str r2, [r5]
	ldr r6, [sp, #0x18c]
	str r2, [r6]
	ldr r0, [sp, #0x19c]
	str r2, [r0]
	ldr r0, _0816A5B0 @ =FUN_080f0320
	ldr r1, [sp, #0x1a0]
	str r0, [r1]
	ldr r0, _0816A5B4 @ =FUN_080eff14
	ldr r3, [sp, #0x14c]
	str r0, [r3]
	ldr r0, _0816A5B8 @ =FUN_080e72b0
	ldr r4, [sp, #0x178]
	str r0, [r4]
	ldr r5, [sp, #0x170]
	str r2, [r5]
	ldr r0, _0816A5BC @ =FUN_080f47c8
	ldr r6, [sp, #0x17c]
	str r0, [r6]
	ldr r0, _0816A5C0 @ =FUN_080f54e4
	ldr r1, [sp, #0x168]
	str r0, [r1]
	ldr r3, [sp, #0x128]
	str r2, [r3]
	ldr r0, _0816A5C4 @ =FUN_080f6e64
	ldr r4, [sp, #0x1a4]
	str r0, [r4]
	ldr r0, _0816A5C8 @ =FUN_080f64f0
	ldr r5, [sp, #0x108]
	str r0, [r5]
	ldr r0, _0816A5CC @ =FUN_080f84d4
	ldr r6, [sp, #0x1a8]
	str r0, [r6]
	ldr r0, _0816A5D0 @ =FUN_080f624c
	ldr r1, [sp, #0x148]
	str r0, [r1]
	ldr r0, _0816A5D4 @ =FUN_080f56ec
	ldr r3, [sp, #0x110]
	str r0, [r3]
	ldr r0, _0816A5D8 @ =FUN_080f5b34
	ldr r4, [sp, #0x114]
	str r0, [r4]
	ldr r0, _0816A5DC @ =FUN_080f5fac
	ldr r5, [sp, #0x118]
	str r0, [r5]
	ldr r6, [sp, #0x13c]
	str r2, [r6]
	movs r0, #0x28
	ldr r1, [sp, #0xc0]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0816A5E0 @ =FUN_08167c2c
	str r0, [r1]
	ldr r4, _0816A5E4 @ =0x000005FC
	adds r0, r7, r4
	str r2, [r0]
	ldr r5, _0816A5E8 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _0816A5EC @ =0x081687C5
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0816A5F0 @ =FUN_08168750
	str r0, [r1]
	ldr r2, _0816A5F4 @ =0x0000058C
	adds r1, r7, r2
	ldr r0, _0816A5F8 @ =FUN_080f8400
	str r0, [r1]
	adds r3, #0x14
	adds r1, r7, r3
	ldr r0, _0816A5FC @ =0x085ADA68
	str r0, [r1]
	ldr r1, _0816A600 @ =0x02100408
	ldr r4, [sp, #0x84]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	ldr r5, [sp, #0x58]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x90]
	strh r0, [r6]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _0816A60E
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0816A568:
	bl VM_GetPC
	cmp r0, #0
	beq _0816A604
	bl Script_GetValue
	b _0816A606
	.align 2, 0
_0816A578: .4byte 0x000006EC
_0816A57C: .4byte FUN_0816962c
_0816A580: .4byte FUN_081680a0
_0816A584: .4byte FUN_0816701c
_0816A588: .4byte FUN_08167270
_0816A58C: .4byte FUN_08167560
_0816A590: .4byte FUN_080f62b0
_0816A594: .4byte FUN_080f62ac
_0816A598: .4byte FUN_081676e8
_0816A59C: .4byte FUN_080f44f4
_0816A5A0: .4byte FUN_080f410c
_0816A5A4: .4byte FUN_080f0430
_0816A5A8: .4byte 0x085AD470
_0816A5AC: .4byte FUN_080e73c8
_0816A5B0: .4byte FUN_080f0320
_0816A5B4: .4byte FUN_080eff14
_0816A5B8: .4byte FUN_080e72b0
_0816A5BC: .4byte FUN_080f47c8
_0816A5C0: .4byte FUN_080f54e4
_0816A5C4: .4byte FUN_080f6e64
_0816A5C8: .4byte FUN_080f64f0
_0816A5CC: .4byte FUN_080f84d4
_0816A5D0: .4byte FUN_080f624c
_0816A5D4: .4byte FUN_080f56ec
_0816A5D8: .4byte FUN_080f5b34
_0816A5DC: .4byte FUN_080f5fac
_0816A5E0: .4byte FUN_08167c2c
_0816A5E4: .4byte 0x000005FC
_0816A5E8: .4byte 0x000005AC
_0816A5EC: .4byte 0x081687C5
_0816A5F0: .4byte FUN_08168750
_0816A5F4: .4byte 0x0000058C
_0816A5F8: .4byte FUN_080f8400
_0816A5FC: .4byte 0x085ADA68
_0816A600: .4byte 0x02100408
_0816A604:
	movs r0, #0
_0816A606:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0816A568
_0816A60E:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x94]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x74]
	strh r0, [r3]
	cmp r2, #0
	beq _0816A646
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x80]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0816A646
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0816A646:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816A658
	movs r0, #1
	b _0816A65A
_0816A658:
	movs r0, #0
_0816A65A:
	cmp r0, #0
	beq _0816A66C
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_0816A66C:
	cmp r2, #1
	beq _0816A6A0
	movs r0, #0
	ldr r1, [sp, #0x40]
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r4, [sp, #0x6c]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, [sp, #0x120]
	ldr r2, [r6]
	ldr r3, [sp, #0x54]
	strb r1, [r3]
	ldr r4, [sp, #0x4c]
	strb r0, [r4]
	ldr r5, [sp, #0xc8]
	strb r0, [r5]
	ldr r6, [sp, #0xf8]
	str r2, [r6]
	ldr r1, [sp, #0x9c]
	strh r0, [r1]
_0816A6A0:
	movs r1, #2
	ldr r2, [sp, #0x58]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816A6B0
	movs r0, #1
	b _0816A6B2
_0816A6B0:
	movs r0, #0
_0816A6B2:
	cmp r0, #0
	beq _0816A6CC
	ldr r0, _0816A6C8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x70]
	strh r0, [r4]
	b _0816A6D6
	.align 2, 0
_0816A6C8: .4byte 0x030046A0
_0816A6CC:
	ldr r0, [sp, #0x30]
	bl FUN_08241574
	ldr r5, [sp, #0x70]
	strh r0, [r5]
_0816A6D6:
	movs r1, #0x40
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816A6E6
	movs r0, #1
	b _0816A6E8
_0816A6E6:
	movs r0, #0
_0816A6E8:
	cmp r0, #0
	beq _0816A6F8
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0816A71C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0816A6F8:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0816A72A
	ldr r0, _0816A720 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x70]
	ldrh r2, [r2]
	cmp r0, r2
	bne _0816A724
	movs r0, #1
	b _0816A726
	.align 2, 0
_0816A71C: .4byte 0xFFFFFEFF
_0816A720: .4byte 0x030046A0
_0816A724:
	movs r0, #0
_0816A726:
	cmp r0, #0
	bne _0816A732
_0816A72A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0816A732:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, [sp, #0x144]
	ldrb r0, [r3]
	cmp r0, #0
	bne _0816A81A
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
	beq _0816A774
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816A77C
_0816A774:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816A77C:
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
	beq _0816A7A0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0816A7A8
_0816A7A0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0816A7A8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _0816A7E0 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0816A824
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0816A7E4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0816A7D8
	ldrb r0, [r4, #5]
_0816A7D8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0816A7F4
	.align 2, 0
_0816A7E0: .4byte 0x0000FFFF
_0816A7E4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0816A7F4
	strh r1, [r4, #8]
_0816A7F4:
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
	bne _0816A824
	movs r0, #1
	strb r0, [r4, #7]
	b _0816A824
_0816A81A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0816A824:
	movs r0, #0
	ldr r3, [sp, #0xa4]
	str r0, [r3]
	ldr r0, _0816A83C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0816A840
	movs r0, #1
	b _0816A842
	.align 2, 0
_0816A83C: .4byte 0x030047A4
_0816A840:
	movs r0, #0
_0816A842:
	cmp r0, #0
	bne _0816A882
	ldr r4, [sp, #0xb4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816A86A
	adds r0, r1, #0
	cmp r0, #7
	beq _0816A86A
	cmp r0, #6
	beq _0816A86A
	cmp r0, #0x15
	beq _0816A86A
	cmp r0, #0x14
	beq _0816A86A
	cmp r0, #0x17
	bne _0816A882
_0816A86A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x58]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0816A882:
	movs r5, #2
	movs r1, #0
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r0, [sp, #0x44]
	strb r5, [r0]
	ldr r2, [sp, #0x48]
	strb r1, [r2]
	ldr r3, [sp, #0x6c]
	str r1, [r3]
	movs r4, #1
	ldr r6, [sp, #0x50]
	strb r4, [r6]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r3, [sp, #0x54]
	strb r4, [r3]
	ldr r6, [sp, #0x4c]
	strb r1, [r6]
	ldr r2, [sp, #0xc8]
	strb r4, [r2]
	ldr r3, [sp, #0xf8]
	str r0, [r3]
	ldr r6, [sp, #0x9c]
	strh r1, [r6]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08167a24
	adds r0, r7, #0
	bl FUN_08169604
	adds r0, r7, #0
	bl FUN_08169618
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	ldr r0, [r7, #0x44]
	strb r4, [r0, #7]
	ldr r2, [sp, #0x58]
	ldrh r0, [r2]
	ldr r3, [sp, #0xf0]
	strh r0, [r3]
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ldr r5, [sp, #0xec]
	strh r0, [r5]
	ldr r6, [sp, #0x80]
	ldr r0, [r6]
	ldr r1, [sp, #0xcc]
	str r0, [r1]
	ldr r2, [sp, #0x84]
	ldr r0, [r2]
	ldr r3, [sp, #0xd0]
	str r0, [r3]
	ldrb r0, [r7, #5]
	ldr r4, [sp, #0xd4]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	ldr r6, [sp, #0xd8]
	strb r0, [r6]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0xdc]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	ldr r4, [sp, #0xe0]
	strb r0, [r4]
	ldr r5, [sp, #0xf8]
	ldr r0, [r5]
	ldr r6, [sp, #0xe4]
	str r0, [r6]
	ldr r1, [sp, #0xc8]
	ldrb r0, [r1]
	ldr r2, [sp, #0xe8]
	strb r0, [r2]
	ldr r3, _0816A954 @ =0x0000057C
	adds r1, r7, r3
	ldr r0, _0816A958 @ =FUN_080f09e0
	str r0, [r1]
	ldr r4, _0816A95C @ =0x0000061C
	adds r1, r7, r4
	ldr r0, _0816A960 @ =FUN_08169668
	str r0, [r1]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _0816A964 @ =FUN_08169688
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816A968
	movs r0, #0
	b _0816A96C
	.align 2, 0
_0816A954: .4byte 0x0000057C
_0816A958: .4byte FUN_080f09e0
_0816A95C: .4byte 0x0000061C
_0816A960: .4byte FUN_08169668
_0816A964: .4byte FUN_08169688
_0816A968:
	movs r0, #1
	rsbs r0, r0, #0
_0816A96C:
	add sp, #0x1b8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
