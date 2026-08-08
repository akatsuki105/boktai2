	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldrb r5, [r4, #4]
	cmp r5, #0
	bne _0822DAB0
	str r2, [r4]
	str r5, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0xf]
	strb r5, [r4, #0x10]
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822dafc
	ldrh r0, [r6, #6]
	ldr r1, _0822DAB8 @ =0x03003584
	lsls r2, r0, #5
	ldr r1, [r1]
	adds r1, r1, r2
	bl FUN_0822d12c
	strb r0, [r4, #0xe]
	str r5, [r4, #0x20]
	str r5, [r4, #0x24]
_0822DAB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0822DAB8: .4byte 0x03003584
