	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0824108c
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_08241030
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08241068
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r5, #8
	cmp r0, r5
	bne _08241256
	movs r0, #1
	b _08241258
_08241256:
	movs r0, #0
_08241258:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
