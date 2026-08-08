	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0822431C @ =0x03000248
	ldr r5, [r0]
	cmp r5, #0
	bne _0822430E
	ldr r0, _08224320 @ =0x0000BB34
	movs r1, #0
	bl FUN_08229c6c
	adds r5, r0, #0
	cmp r5, #0
	beq _082243A0
_0822430E:
	cmp r4, #0xc
	bne _08224324
	movs r0, #0x90
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _082243A0
	.align 2, 0
_0822431C: .4byte 0x03000248
_08224320: .4byte 0x0000BB34
_08224324:
	cmp r4, #0xe
	bne _0822432E
	bl FUN_080a6edc
	b _082243A0
_0822432E:
	lsls r3, r4, #0x10
	ldr r0, _082243A8 @ =0x00000F16
	adds r6, r5, r0
	ldrb r0, [r6]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082243AC @ =0x00000F18
	adds r4, r5, r1
	strh r0, [r4]
	movs r2, #3
	ldrb r1, [r6]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r6]
	lsrs r3, r3, #0xc
	ldrh r1, [r6]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	orrs r0, r3
	strh r0, [r6]
	ldrh r0, [r4]
	cmp r0, #3
	bne _08224384
	ldrb r1, [r6]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224384
	ldr r2, _082243B0 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r2, _082243B4 @ =0x00000F42
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _082243B8 @ =0x00000DF2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
_08224384:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _082243A8 @ =0x00000F16
	adds r0, r5, r2
	ldrh r0, [r0]
	lsrs r0, r0, #4
	adds r2, #0x24
	adds r1, r5, r2
	strh r0, [r1]
_082243A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082243A8: .4byte 0x00000F16
_082243AC: .4byte 0x00000F18
_082243B0: .4byte 0x00000DEC
_082243B4: .4byte 0x00000F42
_082243B8: .4byte 0x00000DF2
