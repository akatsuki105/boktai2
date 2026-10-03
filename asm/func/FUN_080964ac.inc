	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x20
	bl FUN_08094a94
	ldr r1, _08096508 @ =0x00003AE8
	adds r0, r4, r1
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r0, _0809650C @ =0x00001464
	adds r6, r4, r0
	ldr r1, _08096510 @ =0x00003AEB
	adds r5, r4, r1
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080952f4
	ldr r0, _08096514 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096518 @ =0x00001444
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
	bl FUN_080952f4
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096508: .4byte 0x00003AE8
_0809650C: .4byte 0x00001464
_08096510: .4byte 0x00003AEB
_08096514: .4byte 0x0000144C
_08096518: .4byte 0x00001444
