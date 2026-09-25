	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DA908 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	str r0, [sp]
	ldr r1, _080DA90C @ =0x000009FC
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	movs r3, #0
	ldr r2, [sp]
	adds r2, r2, r1
	mov sl, r2
_080DA8F4:
	movs r1, #1
	lsls r1, r3
	mov r7, sl
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DA910
	movs r0, #1
	b _080DA912
	.align 2, 0
_080DA908: .4byte 0x0300015C
_080DA90C: .4byte 0x000009FC
_080DA910:
	movs r0, #0
_080DA912:
	adds r1, r3, #1
	mov sb, r1
	cmp r0, #0
	beq _080DA9AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	ldr r2, [sp]
	adds r5, r2, r0
	adds r4, r5, #0
	adds r4, #0x88
	adds r6, r5, #0
	adds r6, #0x5c
	adds r2, r5, #0
	adds r2, #0x39
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080DA9AE
	movs r1, #1
	lsls r1, r0
	mov r7, sl
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #1
	bls _080DA958
	cmp r0, #4
	beq _080DA958
	cmp r0, #5
	bne _080DA978
_080DA958:
	adds r4, r5, #0
	adds r4, #0x44
	ldrb r0, [r4]
	movs r1, #0x39
	adds r1, r1, r5
	mov r8, r1
	adds r3, #1
	mov sb, r3
	cmp r0, #0
	beq _080DA99E
	adds r0, r6, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
	b _080DA99E
_080DA978:
	movs r6, #0
	mov r8, r2
	adds r7, r5, #0
	adds r7, #0x38
_080DA980:
	ldrb r0, [r7]
	asrs r0, r6
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080DA992
	adds r0, r4, #0
	bl Particle_Remove
_080DA992:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA980
	movs r0, #0
	strb r0, [r7]
_080DA99E:
	adds r0, r5, #0
	movs r1, #0x9a
	lsls r1, r1, #1
	bl ClearMemory
	movs r0, #0xff
	mov r7, r8
	strb r0, [r7]
_080DA9AE:
	mov r3, sb
	cmp r3, #7
	ble _080DA8F4
_080DA9B4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
