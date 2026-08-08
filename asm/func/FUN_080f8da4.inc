	push {r4, r5, r6, lr}
	ldr r0, _080F8E0C @ =0x03000184
	ldr r4, [r0]
	cmp r4, #0
	beq _080F8E36
	ldr r0, [r4, #0x20]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _080F8E36
	ldr r4, [r4, #0x28]
	cmp r4, #0
	beq _080F8E36
	movs r6, #0x80
	lsls r6, r6, #5
_080F8DC4:
	ldrb r1, [r4, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F8E30
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F8E30
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _080F8DF8
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F8DF8
	movs r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F8E10
_080F8DF8:
	ldrb r1, [r4, #4]
	movs r0, #0xfd
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #8]
	movs r0, #0x78
	strh r0, [r4, #6]
	b _080F8E32
	.align 2, 0
_080F8E0C: .4byte 0x03000184
_080F8E10:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r0, r6
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _080F8E30
	ldrb r0, [r4, #4]
	movs r1, #0xfd
	ands r1, r0
	strb r1, [r4, #4]
	str r2, [r4, #8]
	movs r0, #0x78
	strh r0, [r4, #6]
_080F8E30:
	ldr r4, [r4, #0xc]
_080F8E32:
	cmp r4, #0
	bne _080F8DC4
_080F8E36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
