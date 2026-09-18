	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	ldr r1, _08101D90 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_080ffc2c
	adds r0, r7, #0
	bl FUN_08100164
	ldr r2, _08101D94 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08101DA4
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08101D98 @ =0x00009247
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08101D9C @ =0x00001DF8
	bl FUN_080e3804
	ldr r3, _08101DA0 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0xa4]
	cmp r1, #0x11
	beq _08101D80
	cmp r1, #0x17
	bne _08101D84
_08101D80:
	movs r0, #1
	strb r0, [r5, #7]
_08101D84:
	movs r4, #0xef
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08101E0C
	.align 2, 0
_08101D90: .4byte 0x0000065C
_08101D94: .4byte 0x0000025D
_08101D98: .4byte 0x00009247
_08101D9C: .4byte 0x00001DF8
_08101DA0: .4byte 0x000001DF
_08101DA4:
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
	ldr r2, _08101E88 @ =0x05000002
	bl CpuSet
	ldr r0, _08101E8C @ =0x0000CB05
	ldr r1, _08101E90 @ =0x00009247
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
	ldr r6, _08101E94 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0xa4]
_08101E0C:
	str r7, [sp, #0x2c]
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
	ldr r3, _08101E98 @ =0x0000046F
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
	bl VM_GetKeywordValue
	ldr r1, _08101E9C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08101E88 @ =0x05000002
	bl CpuSet
	ldr r3, _08101EA0 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x64]
	str r6, [sp, #0x44]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08101E78
	b _08101FD4
_08101E78:
	bl VM_GetPC
	cmp r0, #0
	beq _08101EA4
	bl Script_GetValue
	adds r1, r0, #0
	b _08101EA6
	.align 2, 0
_08101E88: .4byte 0x05000002
_08101E8C: .4byte 0x0000CB05
_08101E90: .4byte 0x00009247
_08101E94: .4byte 0x000004B7
_08101E98: .4byte 0x0000046F
_08101E9C: .4byte 0x00000474
_08101EA0: .4byte 0x000004B6
_08101EA4:
	movs r1, #0
_08101EA6:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08101ECC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	cmp r0, #0
	beq _08101ED0
	bl Script_GetValue
	adds r1, r0, #0
	b _08101ED2
	.align 2, 0
_08101ECC: .4byte 0x00000251
_08101ED0:
	movs r1, #0
_08101ED2:
	ldr r2, _08101F08 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08101F0C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xc0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc8]
	cmp r0, #0
	beq _08101F10
	bl Script_GetValue
	b _08101F14
	.align 2, 0
_08101F08: .4byte 0x00000252
_08101F0C: .4byte 0x000004B4
_08101F10:
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
_08101F14:
	strb r0, [r6]
	ldr r5, [sp, #0xc0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc8]
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
	blt _08101F4C
	cmp r1, #0
	blt _08101F4C
	ldr r0, _08101F50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08101F4C
	ldr r0, _08101F54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08101F58
_08101F4C:
	movs r1, #0
	b _08101F66
	.align 2, 0
_08101F50: .4byte 0x030046A8
_08101F54: .4byte 0x030046AC
_08101F58:
	ldr r0, _08101F80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08101F66:
	ldr r2, _08101F84 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101F88
	adds r0, #4
	b _08101F94
	.align 2, 0
_08101F80: .4byte 0x030046A4
_08101F84: .4byte 0x00000256
_08101F88:
	ldr r0, _08101FA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101F94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101FAC
	cmp r2, #2
	beq _08101FB0
	b _08101FB4
	.align 2, 0
_08101FA8: .4byte 0x030046A4
_08101FAC:
	ldrb r0, [r4, #4]
	b _08101FB2
_08101FB0:
	ldrb r0, [r4]
_08101FB2:
	subs r1, r1, r0
_08101FB4:
	ldr r3, _08101FCC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08101FD0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _08102014
	.align 2, 0
_08101FCC: .4byte 0x00000472
_08101FD0: .4byte 0x0000FFFF
_08101FD4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08102038 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0810203C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08102040 @ =0x000004B4
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
	str r0, [sp, #0x30]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0xc8]
_08102014:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810205E
	bl VM_GetPC
	cmp r0, #0
	beq _08102044
	bl Script_GetValue
	adds r4, r0, #0
	b _08102046
	.align 2, 0
_08102038: .4byte 0x00000251
_0810203C: .4byte 0x00000252
_08102040: .4byte 0x000004B4
_08102044:
	movs r4, #0x30
_08102046:
	bl VM_GetPC
	cmp r0, #0
	beq _08102058
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0810205A
_08102058:
	movs r5, #0x40
_0810205A:
	mov r8, r4
	b _08102064
_0810205E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08102064:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810209C
	bl VM_GetPC
	cmp r0, #0
	beq _0810207E
	bl Script_GetValue
	adds r6, r0, #0
	b _08102080
_0810207E:
	movs r6, #0
_08102080:
	bl VM_GetPC
	cmp r0, #0
	beq _08102090
	bl Script_GetValue
	adds r1, r0, #0
	b _08102092
_08102090:
	movs r1, #0
_08102092:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081020A6
_0810209C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081020A6:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08102330 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x74]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x70]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	lsls r4, r4, #0x10
	str r4, [sp, #0x90]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x9c]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa0]
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	ldr r4, _08102334 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x1a0]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xac]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x1a4]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x1a8]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x190]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _08102338 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _0810233C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _08102340 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _08102344 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	ldr r6, _08102348 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x84]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x104]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x114]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _0810234C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _08102350 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x140]
	ldr r3, _08102354 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x148]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	ldr r5, _08102358 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _0810235C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _08102360 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x108]
	ldr r3, _08102364 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _08102368 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _0810236C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x184]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	ldr r2, _08102370 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x160]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _08102374 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x178]
	ldr r6, _08102378 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x188]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _0810237C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x164]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _08102380 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x168]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	ldr r2, _08102384 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _08102388 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x110]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x19c]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0810238C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x118]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	ldr r2, _08102390 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x120]
	ldr r3, _08102394 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x130]
	ldr r4, _08102398 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xb4]
	ldr r5, [sp, #0x28]
	adds r5, #8
	str r5, [sp, #0x194]
	adds r6, r7, #0
	adds r6, #0xd8
	str r6, [sp, #0x34]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	ldr r3, _0810239C @ =0x00000496
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081023A0 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0x3c]
	ldr r6, _081023A4 @ =0x0000046A
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _081023A8 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x100]
	movs r3, #0x92
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	movs r4, #0xea
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x98]
	ldr r5, _081023AC @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _081023B0 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	ldr r4, _081023B4 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _081023B8 @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _081023BC @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _081023C0 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _081023C4 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	cmp r0, #0
	bne _08102302
	b _08102420
_08102302:
	movs r4, #0
	mov sl, r4
	movs r5, #0x8d
	lsls r5, r5, #2
	adds r5, r5, r7
	mov sb, r5
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r4, r7, r1
_08102322:
	bl VM_GetPC
	cmp r0, #0
	beq _081023C8
	bl Script_GetValue
	b _081023CA
	.align 2, 0
_08102330: .4byte 0x0000025D
_08102334: .4byte 0x0000025A
_08102338: .4byte 0x0000047A
_0810233C: .4byte 0x0000047C
_08102340: .4byte 0x0000047E
_08102344: .4byte 0x00000476
_08102348: .4byte 0x000004A4
_0810234C: .4byte 0x000005A4
_08102350: .4byte 0x000005C4
_08102354: .4byte 0x000005CC
_08102358: .4byte 0x000005D4
_0810235C: .4byte 0x000005DC
_08102360: .4byte 0x00000584
_08102364: .4byte 0x00000604
_08102368: .4byte 0x0000021D
_0810236C: .4byte 0x0000060C
_08102370: .4byte 0x000005E4
_08102374: .4byte 0x000005FC
_08102378: .4byte 0x00000614
_0810237C: .4byte 0x000005BC
_08102380: .4byte 0x000005EC
_08102384: .4byte 0x00000624
_08102388: .4byte 0x0000058C
_0810238C: .4byte 0x00000594
_08102390: .4byte 0x0000059C
_08102394: .4byte 0x000005B4
_08102398: .4byte 0x00000543
_0810239C: .4byte 0x00000496
_081023A0: .4byte 0x00000469
_081023A4: .4byte 0x0000046A
_081023A8: .4byte 0x00000553
_081023AC: .4byte 0x00000572
_081023B0: .4byte 0x0000055C
_081023B4: .4byte 0x00000564
_081023B8: .4byte 0x00000565
_081023BC: .4byte 0x00000566
_081023C0: .4byte 0x00000567
_081023C4: .4byte 0x0000056C
_081023C8:
	movs r0, #0x18
_081023CA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081023DC
	bl Script_GetValue
	b _081023DE
_081023DC:
	movs r0, #0x18
_081023DE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081023F0
	bl Script_GetValue
	b _081023F2
_081023F0:
	movs r0, #0
_081023F2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08102404
	bl Script_GetValue
	b _08102406
_08102404:
	movs r0, #0
_08102406:
	strh r0, [r6]
	movs r2, #2
	add sb, r2
	movs r3, #4
	add r8, r3
	adds r5, #2
	adds r4, #2
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #3
	bgt _08102420
	b _08102322
_08102420:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810246C
	bl VM_GetPC
	cmp r0, #0
	beq _0810243A
	bl Script_GetValue
	adds r4, r0, #0
	b _0810243E
_0810243A:
	movs r4, #0x96
	lsls r4, r4, #1
_0810243E:
	bl VM_GetPC
	cmp r0, #0
	beq _0810244E
	bl Script_GetValue
	adds r6, r0, #0
	b _08102452
_0810244E:
	movs r6, #0x96
	lsls r6, r6, #1
_08102452:
	bl VM_GetPC
	cmp r0, #0
	beq _08102460
	bl Script_GetValue
	b _08102466
_08102460:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08102466:
	ldr r2, [sp, #0xbc]
	strh r0, [r2]
	b _08102474
_0810246C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xbc]
	strh r6, [r3]
_08102474:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0810248C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0810248C:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810255C
	bl VM_GetPC
	cmp r0, #0
	beq _081024BC
	bl Script_GetValue
	b _081024BE
_081024BC:
	movs r0, #0
_081024BE:
	ldr r3, [sp, #0xd0]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081024CC
	asrs r1, r0, #1
	b _081024D2
_081024CC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081024D2:
	ldr r5, _081024E8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081024EC
	bl Script_GetValue
	b _081024EE
	.align 2, 0
_081024E8: .4byte 0x00000546
_081024EC:
	movs r0, #0
_081024EE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102504
	bl Script_GetValue
	b _08102506
_08102504:
	movs r0, #0
_08102506:
	ldr r3, _0810251C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102520
	bl Script_GetValue
	adds r1, r0, #0
	b _08102522
	.align 2, 0
_0810251C: .4byte 0x00000187
_08102520:
	movs r1, #0
_08102522:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102538
	bl Script_GetValue
	b _0810253A
_08102538:
	movs r0, #0
_0810253A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08102552
	bl Script_GetValue
	adds r1, r0, #0
	b _08102554
_08102552:
	movs r1, #0
_08102554:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0810255C:
	ldr r5, [sp, #0xd0]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x90]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x9c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x94]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081025BE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081025A4
	bl Script_GetValue
	b _081025A6
_081025A4:
	movs r0, #0
_081025A6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081025B6
	bl Script_GetValue
	b _081025B8
_081025B6:
	movs r0, #0
_081025B8:
	ldr r6, _08102620 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081025BE:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xd8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081025E2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081025E2:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081025FA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x64]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081025FA:
	ldr r4, [sp, #0x8c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08102624
	movs r0, #1
	b _08102626
	.align 2, 0
_08102620: .4byte 0x00000189
_08102624:
	movs r0, #0
_08102626:
	cmp r0, #0
	beq _08102636
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08102660 @ =FUN_080f48ac
	ldr r1, [sp, #0x2c]
	bl Entity5941_Register
_08102636:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08102642
	ldr r1, [r7, #0x44]
_08102642:
	ldr r0, [sp, #0x2c]
	bl FUN_0823b46c
	ldr r1, [sp, #0xa4]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08102664
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x1a0]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08102670
	.align 2, 0
_08102660: .4byte FUN_080f48ac
_08102664:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x1a0]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08102670:
	ldr r2, [sp, #0xa4]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081026BE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081026BE
	cmp r0, #0x16
	beq _081026BE
	cmp r0, #0x14
	beq _081026BE
	cmp r0, #9
	beq _081026BE
	cmp r0, #0x19
	beq _081026BE
	cmp r0, #0x1a
	beq _081026BE
	cmp r0, #0xd
	beq _081026BE
	cmp r0, #0x1b
	beq _081026BE
	cmp r0, #0x1f
	beq _081026BE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc0]
	ldrb r2, [r3]
	ldr r4, [sp, #0xc4]
	ldrb r3, [r4]
	ldr r5, [sp, #0xc8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl FUN_0823b490
_081026BE:
	movs r1, #8
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081026CE
	movs r0, #1
	b _081026D0
_081026CE:
	movs r0, #0
_081026D0:
	cmp r0, #0
	beq _081026DE
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xa8]
	str r0, [r2]
	b _081026F0
_081026DE:
	ldr r3, [sp, #0xac]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa8]
	str r0, [r4]
_081026F0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x1a4]
	strh r0, [r5]
	ldr r6, [sp, #0x190]
	ldr r0, [sp, #0x1a8]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _0810271A
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
	ldr r2, [sp, #0x2c]
	strb r0, [r2, #5]
_0810271A:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08102784
	bl VM_GetPC
	cmp r0, #0
	beq _08102734
	bl Script_GetValue
	adds r1, r0, #0
	b _08102736
_08102734:
	movs r1, #0x78
_08102736:
	ldr r3, [sp, #0x24]
	ldr r4, _08102750 @ =0x00000674
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102754
	bl Script_GetValue
	adds r1, r0, #0
	b _08102756
	.align 2, 0
_08102750: .4byte 0x00000674
_08102754:
	movs r1, #0x78
_08102756:
	ldr r5, [sp, #0x24]
	ldr r6, _08102770 @ =0x0000067E
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08102774
	bl Script_GetValue
	adds r1, r0, #0
	b _08102776
	.align 2, 0
_08102770: .4byte 0x0000067E
_08102774:
	movs r1, #0x78
_08102776:
	ldr r2, [sp, #0x24]
	ldr r3, _08102780 @ =0x00000672
	adds r0, r2, r3
	b _08102792
	.align 2, 0
_08102780: .4byte 0x00000672
_08102784:
	ldr r4, [sp, #0x24]
	ldr r5, _081027D0 @ =0x00000674
	adds r0, r4, r5
	movs r1, #0x78
	strb r1, [r0]
	ldr r6, _081027D4 @ =0x0000067E
	adds r0, r4, r6
_08102792:
	strh r1, [r0]
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldr r2, [sp, #0x50]
	strh r4, [r2]
	ldr r3, [sp, #0x54]
	strh r4, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081027D8
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081027E4
	.align 2, 0
_081027D0: .4byte 0x00000674
_081027D4: .4byte 0x0000067E
_081027D8:
	ldr r2, [r7, #0x44]
	ldr r0, _0810281C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081027E4:
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	cmp r0, #1
	bne _08102834
	ldr r2, [sp, #0xa4]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08102820
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
	b _0810282A
	.align 2, 0
_0810281C: .4byte 0x03003584
_08102820:
	ldr r3, [sp, #0xa4]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_0810282A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08102834:
	movs r4, #0
	ldr r5, [sp, #0x50]
	ldrh r0, [r5]
	adds r0, #4
	ldr r6, [sp, #0x48]
	strh r0, [r6]
	ldrh r0, [r5]
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080ffa44
	ldr r2, [sp, #0x24]
	movs r3, #0xd0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r5, _081029F4 @ =0x000006A4
	adds r2, r2, r5
	mov r8, r2
	ldr r6, _081029F8 @ =FUN_08101bc0
	mov sb, r6
	ldr r1, _081029FC @ =FUN_080ffcd0
	mov sl, r1
	ldr r2, _08102A00 @ =FUN_080fba64
	mov ip, r2
	ldr r5, _08102A04 @ =FUN_080fd08c
	ldr r3, _08102A08 @ =FUN_080f62b0
	ldr r6, _08102A0C @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x60]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x80]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x84]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x104]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x10c]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x114]
	str r2, [r6]
	ldr r1, _08102A10 @ =FUN_080fba28
	ldr r2, [sp, #0x124]
	str r1, [r2]
	ldr r6, _08102A14 @ =FUN_080fba40
	ldr r1, [sp, #0x128]
	str r6, [r1]
	ldr r2, _08102A18 @ =FUN_080fc0b8
	ldr r6, [sp, #0x13c]
	str r2, [r6]
	ldr r1, [sp, #0x140]
	str r3, [r1]
	ldr r2, [sp, #0x148]
	str r5, [r2]
	ldr r3, _08102A1C @ =FUN_080fe274
	ldr r5, [sp, #0x14c]
	str r3, [r5]
	ldr r1, _08102A20 @ =FUN_080f44f4
	ldr r6, [sp, #0x150]
	str r1, [r6]
	ldr r1, _08102A24 @ =FUN_080f410c
	ldr r2, [sp, #0x158]
	str r1, [r2]
	ldr r3, _08102A28 @ =FUN_080fc548
	ldr r5, [sp, #0x144]
	str r3, [r5]
	ldr r6, _08102A2C @ =FUN_080fc1e4
	ldr r1, [sp, #0x108]
	str r6, [r1]
	ldr r2, [sp, #0x1ac]
	ldr r3, [sp, #0x17c]
	str r2, [r3]
	ldr r1, _08102A30 @ =FUN_080f0430
	ldr r5, [sp, #0x180]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb0]
	strb r1, [r6]
	ldr r1, _08102A34 @ =0x085AD470
	ldr r2, [sp, #0x184]
	str r1, [r2]
	ldr r1, _08102A38 @ =FUN_080e73c8
	ldr r3, [sp, #0x16c]
	str r1, [r3]
	ldr r5, [sp, #0x160]
	str r4, [r5]
	ldr r6, [sp, #0x170]
	str r4, [r6]
	ldr r1, [sp, #0x174]
	str r4, [r1]
	ldr r2, [sp, #0x178]
	str r4, [r2]
	ldr r3, [sp, #0x188]
	str r4, [r3]
	ldr r1, _08102A3C @ =FUN_080f0320
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	ldr r1, _08102A40 @ =Enemy_080eff14
	ldr r6, [sp, #0x138]
	str r1, [r6]
	ldr r1, _08102A44 @ =FUN_080e72b0
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _08102A48 @ =FUN_080fc4ec
	ldr r5, [sp, #0x15c]
	str r3, [r5]
	ldr r1, _08102A4C @ =FUN_080f47c8
	ldr r6, [sp, #0x168]
	str r1, [r6]
	ldr r1, _08102A50 @ =FUN_080f54e4
	ldr r2, [sp, #0x154]
	str r1, [r2]
	ldr r3, [sp, #0x12c]
	str r4, [r3]
	ldr r1, _08102A54 @ =FUN_080f6e64
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _08102A58 @ =FUN_080f64f0
	ldr r6, [sp, #0x110]
	str r1, [r6]
	ldr r1, _08102A5C @ =FUN_080f84d4
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _08102A60 @ =FUN_080f624c
	ldr r3, [sp, #0x134]
	str r1, [r3]
	ldr r1, _08102A64 @ =FUN_080f56ec
	ldr r5, [sp, #0x118]
	str r1, [r5]
	ldr r1, _08102A68 @ =FUN_080f5b34
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _08102A6C @ =FUN_080f5fac
	ldr r2, [sp, #0x120]
	str r1, [r2]
	ldr r3, [sp, #0x130]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0xb4]
	strb r1, [r4]
	ldr r1, [sp, #0x194]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08102A70 @ =FUN_080ffad8
	str r0, [r1]
	ldr r6, _08102A74 @ =0x000005FC
	adds r1, r7, r6
	ldr r0, _08102A78 @ =FUN_080ffc28
	str r0, [r1]
	ldr r0, _08102A7C @ =0x000005AC
	adds r1, r7, r0
	ldr r0, _08102A80 @ =FUN_080ff6e8
	str r0, [r1]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08102A84 @ =FUN_080ff7c0
	str r0, [r1]
	ldr r3, _08102A88 @ =0x0000058C
	adds r1, r7, r3
	ldr r0, _08102A8C @ =FUN_08100228
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r6, [sp, #0x34]
	ldrh r1, [r6, #6]
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _08102A90 @ =0x000001DF
	adds r0, r7, r1
	movs r2, #4
	strb r2, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x78]
	strh r0, [r3]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08102A9E
	movs r4, #0xce
	lsls r4, r4, #1
	adds r5, r7, r4
	movs r4, #4
_081029E4:
	bl VM_GetPC
	cmp r0, #0
	beq _08102A94
	bl Script_GetValue
	b _08102A96
	.align 2, 0
_081029F4: .4byte 0x000006A4
_081029F8: .4byte FUN_08101bc0
_081029FC: .4byte FUN_080ffcd0
_08102A00: .4byte FUN_080fba64
_08102A04: .4byte FUN_080fd08c
_08102A08: .4byte FUN_080f62b0
_08102A0C: .4byte FUN_080f62ac
_08102A10: .4byte FUN_080fba28
_08102A14: .4byte FUN_080fba40
_08102A18: .4byte FUN_080fc0b8
_08102A1C: .4byte FUN_080fe274
_08102A20: .4byte FUN_080f44f4
_08102A24: .4byte FUN_080f410c
_08102A28: .4byte FUN_080fc548
_08102A2C: .4byte FUN_080fc1e4
_08102A30: .4byte FUN_080f0430
_08102A34: .4byte 0x085AD470
_08102A38: .4byte FUN_080e73c8
_08102A3C: .4byte FUN_080f0320
_08102A40: .4byte Enemy_080eff14
_08102A44: .4byte FUN_080e72b0
_08102A48: .4byte FUN_080fc4ec
_08102A4C: .4byte FUN_080f47c8
_08102A50: .4byte FUN_080f54e4
_08102A54: .4byte FUN_080f6e64
_08102A58: .4byte FUN_080f64f0
_08102A5C: .4byte FUN_080f84d4
_08102A60: .4byte FUN_080f624c
_08102A64: .4byte FUN_080f56ec
_08102A68: .4byte FUN_080f5b34
_08102A6C: .4byte FUN_080f5fac
_08102A70: .4byte FUN_080ffad8
_08102A74: .4byte 0x000005FC
_08102A78: .4byte FUN_080ffc28
_08102A7C: .4byte 0x000005AC
_08102A80: .4byte FUN_080ff6e8
_08102A84: .4byte FUN_080ff7c0
_08102A88: .4byte 0x0000058C
_08102A8C: .4byte FUN_08100228
_08102A90: .4byte 0x000001DF
_08102A94:
	movs r0, #0
_08102A96:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081029E4
_08102A9E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r6, [sp, #0x6c]
	strh r0, [r6]
	cmp r2, #0
	beq _08102AD6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r3, [sp, #0x60]
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	cmp r2, #2
	bne _08102AD6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r3]
_08102AD6:
	movs r2, #0
	movs r1, #4
	ldr r4, [sp, #0x44]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08102AE8
	movs r0, #1
	b _08102AEA
_08102AE8:
	movs r0, #0
_08102AEA:
	cmp r0, #0
	beq _08102AFC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r2, #1
_08102AFC:
	cmp r2, #1
	beq _08102B3C
	movs r1, #0
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	ldr r3, _08102B4C @ =0x00000484
	adds r0, r7, r3
	str r1, [r0]
	ldr r4, _08102B50 @ =0x0000046C
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, [sp, #0x128]
	ldr r3, [r5]
	ldr r6, _08102B54 @ =0x0000046D
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _08102B58 @ =0x0000046B
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, [sp, #0xb8]
	strb r1, [r4]
	ldr r5, [sp, #0x100]
	str r3, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
_08102B3C:
	movs r1, #2
	ldr r2, [sp, #0x44]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08102B5C
	movs r0, #1
	b _08102B5E
	.align 2, 0
_08102B4C: .4byte 0x00000484
_08102B50: .4byte 0x0000046C
_08102B54: .4byte 0x0000046D
_08102B58: .4byte 0x0000046B
_08102B5C:
	movs r0, #0
_08102B5E:
	cmp r0, #0
	beq _08102B78
	ldr r0, _08102B74 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	strh r0, [r4]
	b _08102B82
	.align 2, 0
_08102B74: .4byte 0x030046A0
_08102B78:
	ldr r0, [sp, #0x190]
	bl FUN_08241574
	ldr r5, [sp, #0x68]
	strh r0, [r5]
_08102B82:
	movs r1, #0x40
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08102B92
	movs r0, #1
	b _08102B94
_08102B92:
	movs r0, #0
_08102B94:
	cmp r0, #0
	beq _08102BA2
	ldr r0, _08102BC8 @ =0xFFFFFEFF
	ldr r2, [sp, #0x34]
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08102BA2:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08102BD6
	ldr r0, _08102BCC @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08102BD0
	movs r0, #1
	b _08102BD2
	.align 2, 0
_08102BC8: .4byte 0xFFFFFEFF
_08102BCC: .4byte 0x030046A0
_08102BD0:
	movs r0, #0
_08102BD2:
	cmp r0, #0
	bne _08102BDE
_08102BD6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08102BDE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xe4]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08102CC6
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
	beq _08102C20
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08102C28
_08102C20:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08102C28:
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
	beq _08102C4C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08102C54
_08102C4C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08102C54:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08102C8C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08102CD0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08102C90
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08102C84
	ldrb r0, [r4, #5]
_08102C84:
	subs r0, #1
	strh r0, [r4, #8]
	b _08102CA0
	.align 2, 0
_08102C8C: .4byte 0x0000FFFF
_08102C90:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08102CA0
	strh r1, [r4, #8]
_08102CA0:
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
	bne _08102CD0
	movs r0, #1
	strb r0, [r4, #7]
	b _08102CD0
_08102CC6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
_08102CD0:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08102CE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08102CEC
	movs r0, #1
	b _08102CEE
	.align 2, 0
_08102CE8: .4byte 0x030047A4
_08102CEC:
	movs r0, #0
_08102CEE:
	cmp r0, #0
	bne _08102D2E
	ldr r4, [sp, #0xa4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08102D16
	adds r0, r1, #0
	cmp r0, #7
	beq _08102D16
	cmp r0, #6
	beq _08102D16
	cmp r0, #0x15
	beq _08102D16
	cmp r0, #0x14
	beq _08102D16
	cmp r0, #0x17
	bne _08102D2E
_08102D16:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl EntityMsgBus_Register
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x44]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08102D2E:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_080ff45c
	adds r0, r7, #0
	bl FUN_080ff05c
	adds r0, r7, #0
	bl FUN_080ff668
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ldr r1, [sp, #0xfc]
	strh r0, [r1]
	ldr r2, [sp, #0x88]
	ldrh r0, [r2]
	ldr r3, [sp, #0xf8]
	strh r0, [r3]
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	ldr r5, [sp, #0xcc]
	str r0, [r5]
	ldr r6, [sp, #0x64]
	ldr r0, [r6]
	ldr r1, [sp, #0xd4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xdc]
	strb r0, [r2]
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
	ldr r4, [sp, #0xe0]
	strb r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r2, [sp, #0xec]
	strb r0, [r2]
	ldr r3, [sp, #0x100]
	ldr r0, [r3]
	ldr r4, [sp, #0xf0]
	str r0, [r4]
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf4]
	strb r0, [r6]
	ldr r0, _08102DC0 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _08102DC4 @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _08102DC8 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _08102DCC @ =FUN_08101c1c
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08102DD0 @ =EnemyBoku_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08102DD4
	movs r0, #0
	b _08102DD8
	.align 2, 0
_08102DC0: .4byte 0x0000057C
_08102DC4: .4byte FUN_080f09e0
_08102DC8: .4byte 0x0000061C
_08102DCC: .4byte FUN_08101c1c
_08102DD0: .4byte EnemyBoku_Destroy
_08102DD4:
	movs r0, #1
	rsbs r0, r0, #0
_08102DD8:
	add sp, #0x1b4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
