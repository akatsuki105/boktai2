	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r5, #0x40
	movs r1, #1
	mov sb, r1
	movs r2, #7
	mov r8, r2
	adds r7, r0, #0
	adds r7, #0xd4
_082038A8:
	ldrh r0, [r7]
	cmp r0, #0
	bne _082038B0
	b _082039C0
_082038B0:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _082038E0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082038E8
_082038E0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082038E8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0820390C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08203914
_0820390C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203914:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0820394C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08203984
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203950
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203944
	ldrb r0, [r4, #5]
_08203944:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203960
	.align 2, 0
_0820394C: .4byte 0x0000FFFF
_08203950:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203960
	strh r1, [r4, #8]
_08203960:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08203984
	mov r3, sb
	strb r3, [r4, #7]
_08203984:
	adds r4, r5, #0
	adds r4, #0x3c
	adds r1, r5, #0
	adds r1, #0x8c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldrh r0, [r7]
	cmp r0, #0x3b
	bhi _082039AE
	movs r1, #0x3c
	subs r1, r1, r0
	adds r0, r5, #0
	movs r2, #0x14
	movs r3, #0x1e
	bl FUN_082375c8
_082039AE:
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082039C0
	adds r0, r5, #0
	bl FUN_08203860
_082039C0:
	adds r7, #0x98
	adds r5, #0x98
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	blt _082039D2
	b _082038A8
_082039D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
