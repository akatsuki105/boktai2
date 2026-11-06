	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BD80
	movs r0, #0
	strb r0, [r4]
_0805BD80:
	ldrh r0, [r4, #0x10]
	mov r3, sp
	ldrb r5, [r4, #6]
	lsls r6, r0, #1
	ldr r2, _0805BDA4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDA8
	asrs r1, r0, #0xc
	b _0805BDAE
	.align 2, 0
_0805BDA4: .4byte gSineTable
_0805BDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BDAE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDC6
	asrs r0, r0, #0xc
	b _0805BDCC
_0805BDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BDCC:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _0805BE16
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_0805BE16:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
