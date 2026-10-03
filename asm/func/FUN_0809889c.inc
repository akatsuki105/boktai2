	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0
	bl FUN_08097ab8
	ldr r1, _080988F8 @ =0x00003AE8
	adds r0, r4, r1
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r0, _080988FC @ =0x00001464
	adds r6, r4, r0
	ldr r1, _08098900 @ =0x00003AEB
	adds r5, r4, r1
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08097ca0
	ldr r0, _08098904 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08098908 @ =0x00001444
	adds r0, r4, r1
	adds r4, #0x60
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08097ca0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080988F8: .4byte 0x00003AE8
_080988FC: .4byte 0x00001464
_08098900: .4byte 0x00003AEB
_08098904: .4byte 0x0000144C
_08098908: .4byte 0x00001444
