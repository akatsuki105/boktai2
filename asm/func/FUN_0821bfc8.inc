	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x50
	ldr r0, _0821BFE4 @ =0x00000BC4
	adds r1, r3, r0
	ldr r2, _0821BFE8 @ =0x00000BD4
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	blt _0821BFEC
	asrs r0, r0, #8
	b _0821BFF2
	.align 2, 0
_0821BFE4: .4byte 0x00000BC4
_0821BFE8: .4byte 0x00000BD4
_0821BFEC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821BFF2:
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r0, r3, r5
	ldr r3, [r0]
	lsls r3, r3, #8
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl FUN_0821bda4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
