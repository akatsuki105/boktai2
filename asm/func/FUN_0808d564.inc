	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D5BC
	adds r7, r5, r1
_0808D57A:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _0808D5C4 @ =0x00000C08
	adds r4, r4, r0
	adds r4, r5, r4
	adds r0, r4, #4
	movs r2, #1
	ldrsb r2, [r4, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _0808D5C8 @ =0x00000C02
	adds r0, r5, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r4, #0x26]
	adds r6, #1
	ldrb r0, [r7]
	cmp r6, r0
	blt _0808D57A
_0808D5BC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D5C4: .4byte 0x00000C08
_0808D5C8: .4byte 0x00000C02
