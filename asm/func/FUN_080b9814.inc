	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080B9888 @ =0x0000CB05
	ldr r1, _080B988C @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r7, #0
	bl OpenMainSpriteFile
	ldr r1, _080B9890 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	add r4, sp, #0x10
	adds r5, r7, #0
	adds r5, #0x20
	movs r6, #1
_080B9854:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x93
	movs r3, #0x31
	bl MainSprite_Add
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B9854
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9888: .4byte 0x0000CB05
_080B988C: .4byte 0x0000B343
_080B9890: .4byte 0xFFFF0000
