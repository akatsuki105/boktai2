	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	bne _0821B082
	adds r0, r4, #0
	adds r0, #0x38
	bl FUN_0822f1c0
	b _0821B08A
_0821B082:
	adds r0, r4, #0
	adds r0, #0x98
	bl FUN_0822a4e0
_0821B08A:
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822a4e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
