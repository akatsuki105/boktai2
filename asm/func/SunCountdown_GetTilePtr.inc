	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _08010DA8 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010DA8: .4byte 0x03003ED0
