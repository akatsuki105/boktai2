	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08094898 @ =0x00003AE8
	adds r5, r4, r0
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080916d0
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r1, _0809489C @ =0x00001464
	adds r6, r4, r1
	ldr r0, _080948A0 @ =0x00003AEB
	adds r5, r4, r0
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _080948A4 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080948A8 @ =0x00001444
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
	bl FUN_080921e8
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094898: .4byte 0x00003AE8
_0809489C: .4byte 0x00001464
_080948A0: .4byte 0x00003AEB
_080948A4: .4byte 0x0000144C
_080948A8: .4byte 0x00001444
