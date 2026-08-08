	push {r4, r5, r6, r7, lr}
	ldr r5, [sp, #0x14]
	ldr r6, [sp, #0x18]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #4
	ldr r0, _0822BD24 @ =0x03003ED0
	adds r4, r4, r0
	movs r7, #0x18
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, r0, r1
	ldr r1, [r4, #0x2c]
	lsls r0, r0, #1
	adds r0, r0, r1
	lsls r5, r5, #0xa
	orrs r5, r3
	lsls r6, r6, #0xc
	orrs r6, r5
	strh r6, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822BD24: .4byte 0x03003ED0
