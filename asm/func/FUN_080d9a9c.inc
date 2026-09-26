	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r6, #0
	beq _080D9B22
	ldr r0, _080D9B28 @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9B22
	movs r0, #0x88
	adds r0, r0, r6
	mov ip, r0
	adds r0, r6, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9B22
	ldrh r0, [r6, #0x24]
	cmp r0, r3
	bne _080D9B22
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D9B30
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9B2C @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	mov r4, ip
_080D9AF4:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9B06
	adds r0, r4, #0
	bl Particle_Remove
_080D9B06:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9AF4
	movs r0, #0
	strb r0, [r7]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r6, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9B22:
	movs r0, #0
	b _080D9B32
	.align 2, 0
_080D9B28: .4byte 0x0300015C
_080D9B2C: .4byte 0x000009FC
_080D9B30:
	adds r0, r6, #0
_080D9B32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
