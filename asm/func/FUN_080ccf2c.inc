	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080CCF84 @ =0x0000071C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFD4
	movs r2, #0
	mov r8, r2
	movs r7, #0
_080CCF44:
	movs r0, #0x34
	adds r1, r7, #0
	muls r1, r0, r1
	adds r0, r5, r1
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFC2
	subs r2, #0x30
	adds r0, r1, r2
	adds r3, r5, r0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strb r2, [r1]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080CCF88
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x30
	strb r6, [r0]
	b _080CCFC2
	.align 2, 0
_080CCF84: .4byte 0x0000071C
_080CCF88:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080CCFA6
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl Particle_SetFrame
_080CCFA6:
	ldrh r0, [r4, #0x28]
	ldrh r2, [r4, #0x18]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r0, #1
	add r8, r0
_080CCFC2:
	adds r7, #1
	cmp r7, #5
	ble _080CCF44
	mov r1, r8
	cmp r1, #0
	bne _080CCFD4
	ldr r2, _080CCFE0 @ =0x0000071C
	adds r0, r5, r2
	strb r1, [r0]
_080CCFD4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCFE0: .4byte 0x0000071C
