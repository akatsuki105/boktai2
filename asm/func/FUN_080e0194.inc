	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _080E01B4 @ =0x0000354D
	bl FUN_0822b16c
	ldr r0, _080E01B8 @ =0x0300017C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080E01B4: .4byte 0x0000354D
_080E01B8: .4byte 0x0300017C
