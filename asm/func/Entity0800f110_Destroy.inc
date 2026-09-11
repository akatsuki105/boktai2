	push {r4, lr}
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0800F0D6
_0800F0C4:
	adds r0, r1, #0
	adds r0, #0xf0
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_0800e54c
	adds r1, r4, #0
	cmp r1, #0
	bne _0800F0C4
_0800F0D6:
	ldr r1, _0800F0E4 @ =0x03002B3C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0E4: .4byte 0x03002B3C
