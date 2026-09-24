	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r1, _08200CD4 @ =0x000006DC
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _08200D5E
	subs r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08200CB8
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	beq _08200CD8
_08200CB8:
	movs r0, #0x82
	lsls r0, r0, #3
	adds r4, r2, r0
	movs r1, #4
	movs r5, #7
_08200CC2:
	ldrh r0, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _08200CC2
	b _08200D5E
	.align 2, 0
_08200CD4: .4byte 0x000006DC
_08200CD8:
	ldr r0, _08200D6C @ =0x03002CF0
	ldr r1, [r0]
	movs r0, #3
	ands r1, r0
	movs r0, #0x28
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r7, r2, r0
	movs r0, #0x82
	lsls r0, r0, #3
	adds r4, r2, r0
	movs r0, #0x2c
	muls r0, r1, r0
	add r8, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, r1, #0
	cmp r5, #7
	bgt _08200D5E
	movs r1, #4
	mov sb, r1
_08200D0C:
	mov r6, r8
	adds r6, #0x1c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r2, sb
	mvns r0, r2
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r5, #1
	cmp r0, #7
	bgt _08200D34
	adds r1, r4, #0
	adds r1, #0x50
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
_08200D34:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08200D4C
	adds r0, r7, #0
	bl Hitbox_Register
_08200D4C:
	movs r2, #0xb0
	add r8, r2
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, #4
	cmp r5, #7
	ble _08200D0C
_08200D5E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200D6C: .4byte 0x03002CF0
