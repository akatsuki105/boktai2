	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080927AC @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080927B0 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0809223c
	ldr r2, _080927B4 @ =0x00003AE8
	adds r5, r4, r2
	adds r0, r5, #0
	bl FUN_0808fbcc
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080916d0
	ldr r1, _080927B8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080927BC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	bl FUN_080923a0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _080927C0 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080927AC: .4byte 0x000014AC
_080927B0: .4byte 0x0000144C
_080927B4: .4byte 0x00003AE8
_080927B8: .4byte 0x00001464
_080927BC: .4byte 0x00003AEB
_080927C0: .4byte FUN_08094070
