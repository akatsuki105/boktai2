	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #4
	mov sb, r1
	subs r1, #9
	mov sl, r1
	adds r6, r0, #0
	adds r6, #0x48
	adds r5, r0, #0
	adds r5, #0x98
	adds r4, r0, #0
	adds r4, #0x1c
	adds r7, r0, #0
	adds r7, #0xfd
	movs r0, #5
	mov r8, r0
_081F61DA:
	ldrb r1, [r7]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081F6216
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _081F6216
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r4, #0x32]
	mov r0, sl
	ands r0, r1
	strh r0, [r4, #0x32]
	ldrh r1, [r5, #6]
	mov r0, sl
	ands r0, r1
	b _081F6224
_081F6216:
	ldrh r1, [r4, #0x32]
	mov r0, sb
	orrs r0, r1
	strh r0, [r4, #0x32]
	ldrh r1, [r5, #6]
	mov r0, sb
	orrs r0, r1
_081F6224:
	strh r0, [r5, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r6, r6, r1
	adds r5, r5, r1
	adds r4, r4, r1
	adds r7, r7, r1
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _081F61DA
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
