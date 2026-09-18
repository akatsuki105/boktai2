	push {lr}
	ldr r0, _080A73DC @ =0x030047A4
	ldr r1, [r0]
	ldr r2, _080A73E0 @ =0xFFFFFBFF
	ands r1, r2
	str r1, [r0]
	movs r0, #2
	bl sound_08240740
	movs r0, #0
	bl FUN_0823a8f4
	pop {r0}
	bx r0
	.align 2, 0
_080A73DC: .4byte 0x030047A4
_080A73E0: .4byte 0xFFFFFBFF
