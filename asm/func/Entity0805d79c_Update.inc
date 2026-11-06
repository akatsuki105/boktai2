	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r6, r8
	adds r6, #0x38
	movs r7, #0
	adds r5, r6, #0
_0805D6C4:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D716
	adds r4, r6, #0
	adds r4, #0x38
	adds r1, r6, #0
	adds r1, #0x28
	ldrh r0, [r5, #4]
	ldrh r2, [r5, #0x28]
	adds r0, r0, r2
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldrh r0, [r5, #8]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	strh r0, [r5, #0x2c]
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r0, [r5]
	cmp r0, #0x3b
	bls _0805D712
	mov r0, r8
	adds r1, r6, #0
	adds r2, r7, #0
	bl Entity0805d79c_ReleaseElem
	b _0805D716
_0805D712:
	adds r0, #1
	str r0, [r5]
_0805D716:
	adds r7, #1
	adds r5, #0x88
	adds r6, #0x88
	cmp r7, #0x1f
	ble _0805D6C4
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
