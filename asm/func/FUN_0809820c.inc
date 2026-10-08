	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08098278 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808de50
	adds r0, r4, #0
	bl FUN_08097d4c
	adds r0, r4, #0
	bl FUN_08097e3c
	ldr r1, _0809827C @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _08098280 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097ab8
	ldr r1, _08098284 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08098288 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r4, #0
	bl FUN_08097c04
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _0809828C @ =FUN_08098290
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098278: .4byte 0x000014AC
_0809827C: .4byte 0x0000144C
_08098280: .4byte 0x00003AE8
_08098284: .4byte 0x00001464
_08098288: .4byte 0x00003AEB
_0809828C: .4byte FUN_08098290
