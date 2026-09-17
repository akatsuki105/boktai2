	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080139E2
	cmp r1, #0
	blt _080139E2
	ldr r0, _080139E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080139E2
	ldr r0, _080139EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080139F0
_080139E2:
	movs r0, #0
	b _080139FE
	.align 2, 0
_080139E8: .4byte 0x030046A8
_080139EC: .4byte 0x030046AC
_080139F0:
	ldr r0, _08013A18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080139FE:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r2, [r4, #8]
	ldrh r0, [r2]
	strh r0, [r4, #0x28]
	ldrb r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013A1C
	ldrh r0, [r2, #2]
	strh r0, [r4, #0x2a]
	b _08013A5E
	.align 2, 0
_08013A18: .4byte 0x030046A4
_08013A1C:
	adds r5, r2, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013A2E
	adds r0, #4
	b _08013A3A
_08013A2E:
	ldr r0, _08013A50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013A3A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08013A54
	cmp r2, #2
	beq _08013A58
	b _08013A5C
	.align 2, 0
_08013A50: .4byte 0x030046A4
_08013A54:
	ldrb r0, [r5, #4]
	b _08013A5A
_08013A58:
	ldrb r0, [r5]
_08013A5A:
	subs r1, r1, r0
_08013A5C:
	strh r1, [r4, #0x2a]
_08013A5E:
	ldr r1, [r4, #8]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2c]
	movs r0, #2
	ldrsh r1, [r1, r0]
	movs r2, #0x2a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0
	bgt _08013A7C
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r1, [r0]
	subs r0, #2
	b _08013AA6
_08013A7C:
	adds r0, r4, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08013A92
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5e
	b _08013AB4
_08013A92:
	adds r0, r4, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _08013AAC
	adds r0, r4, #0
	adds r0, #0x55
	ldrb r1, [r0]
	subs r0, #1
_08013AA6:
	strb r1, [r0]
	adds r1, r0, #0
	b _08013AC2
_08013AAC:
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5c
_08013AB4:
	ldrh r0, [r0]
	asrs r1, r0
	ldrb r0, [r2]
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x54
	strb r0, [r1]
_08013AC2:
	adds r2, r1, #0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bgt _08013AD0
	movs r0, #1
	strb r0, [r2]
_08013AD0:
	ldrb r0, [r1]
	strb r0, [r4, #0x14]
	ldrb r0, [r1]
	strb r0, [r4, #0x15]
	ldr r0, [r4, #8]
	movs r1, #2
	ldrsh r0, [r0, r1]
	movs r2, #0x2a
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08013B10
	cmp r1, #0
	beq _08013B10
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013AFA
	adds r0, #4
	b _08013B06
_08013AFA:
	ldr r0, _08013B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013B06:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08013B1C
_08013B10:
	ldr r0, [r4, #0xc]
	movs r1, #1
	orrs r0, r1
	b _08013B24
	.align 2, 0
_08013B18: .4byte 0x030046A4
_08013B1C:
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08013B24:
	str r0, [r4, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
