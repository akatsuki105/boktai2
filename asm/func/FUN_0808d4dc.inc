	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r6, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D554
	adds r7, r4, r1
	mov r8, r6
	ldr r0, _0808D51C @ =0x00000DA4
	adds r5, r4, r0
_0808D4FC:
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0808D520
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	b _0808D52E
	.align 2, 0
_0808D51C: .4byte 0x00000DA4
_0808D520:
	ldrb r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
_0808D52E:
	ldr r1, _0808D560 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r5, #0x22]
	movs r0, #0x68
	add r8, r0
	adds r5, #0x68
	adds r6, #1
	ldrb r1, [r7]
	cmp r6, r1
	blt _0808D4FC
_0808D554:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D560: .4byte 0x00000D98
