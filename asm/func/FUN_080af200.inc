	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x7f
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080AF2E8
	adds r4, r2, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r2, _080AF24C @ =0x0000068D
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xf3
	bl PlaySound_082406e0
	ldrh r1, [r5, #0x3c]
	ldrh r0, [r6, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080AF230
	movs r1, #0
_080AF230:
	movs r0, #1
	ldr r2, [r5, #0x34]
	ands r0, r2
	cmp r0, #0
	beq _080AF254
	adds r1, #0x14
	ldr r2, _080AF250 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x20
	b _080AF2C2
	.align 2, 0
_080AF24C: .4byte 0x0000068D
_080AF250: .4byte 0x0000068E
_080AF254:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080AF274
	adds r1, #0x64
	ldr r2, _080AF270 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x18
	b _080AF2C2
	.align 2, 0
_080AF270: .4byte 0x0000068E
_080AF274:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080AF290
	adds r1, #0x32
	ldr r2, _080AF28C @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF28C: .4byte 0x0000068E
_080AF290:
	movs r3, #0x10
	ands r3, r2
	cmp r3, #0
	beq _080AF2AC
	adds r1, #0x64
	ldr r2, _080AF2A8 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF2A8: .4byte 0x0000068E
_080AF2AC:
	movs r0, #0x40
	ands r2, r0
	cmp r2, #0
	beq _080AF2C4
	ldr r1, _080AF2F0 @ =0x0000068E
	adds r0, r4, r1
	strh r3, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
_080AF2C0:
	movs r0, #0x80
_080AF2C2:
	strh r0, [r1]
_080AF2C4:
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080AF2DA
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
_080AF2DA:
	ldr r0, _080AF2F0 @ =0x0000068E
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _080AF2E8
	movs r0, #0xc8
	strh r0, [r1]
_080AF2E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF2F0: .4byte 0x0000068E
