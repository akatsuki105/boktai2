	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	bl FUN_08234208
	movs r0, #0
	str r0, [r5, #8]
	ldr r1, _082342A4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #0x18]
	str r0, [r5, #0xc]
	cmp r0, #0
	beq _08234296
	str r5, [r0, #8]
_08234296:
	ldr r0, [r1]
	str r5, [r0, #0x18]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082342A4: .4byte 0x030046A4
