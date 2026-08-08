	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #0x80
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r2, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807AB04
	lsls r1, r3, #1
	adds r0, r2, #0
	bl FUN_0807aa60
	b _0807AB0C
_0807AB04:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0807aa60
_0807AB0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
