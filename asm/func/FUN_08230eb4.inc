	push {r4, lr}
	bl FUN_08230e88
	adds r4, r0, #0
	ldr r0, _08230EE4 @ =0x030044BC
	ldr r3, [r0]
	cmp r3, #0
	bne _08230EDE
	ldr r2, _08230EE8 @ =0x03000740
	ldr r1, [r2]
	movs r0, #1
	eors r1, r0
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r4, r0
	str r3, [r0]
	str r3, [r0, #4]
_08230EDE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08230EE4: .4byte 0x030044BC
_08230EE8: .4byte 0x03000740
