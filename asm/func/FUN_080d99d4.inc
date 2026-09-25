	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r7, #0
	beq _080D9A8A
	ldr r0, _080D9A4C @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9A8A
	adds r0, r7, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9A8A
	ldrh r0, [r7, #0x24]
	cmp r0, r3
	bne _080D9A8A
	movs r0, #0x88
	adds r0, r0, r7
	mov ip, r0
	adds r5, r7, #0
	adds r5, #0x5c
	adds r3, r7, #0
	adds r3, #0x3b
	ldrb r0, [r3]
	cmp r0, r4
	bne _080D9A8E
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9A50 @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #1
	bls _080D9A36
	cmp r0, #4
	beq _080D9A36
	cmp r0, #5
	bne _080D9A54
_080D9A36:
	adds r4, r7, #0
	adds r4, #0x44
	ldrb r0, [r4]
	cmp r0, #0
	beq _080D9A7A
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
	b _080D9A7A
	.align 2, 0
_080D9A4C: .4byte 0x0300015C
_080D9A50: .4byte 0x000009FC
_080D9A54:
	movs r5, #0
	adds r6, r7, #0
	adds r6, #0x38
	mov r4, ip
_080D9A5C:
	ldrb r0, [r6]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9A6E
	adds r0, r4, #0
	bl Particle_Remove
_080D9A6E:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9A5C
	movs r0, #0
	strb r0, [r6]
_080D9A7A:
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9A8A:
	movs r0, #0
	b _080D9A90
_080D9A8E:
	adds r0, r7, #0
_080D9A90:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
