	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807A9F4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _0807A9F8
	cmp r1, #3
	beq _0807A9F8
	ldrh r0, [r0]
	cmp r0, #7
	beq _0807A9F8
_0807A9F4:
	movs r0, #0
	b _0807A9FA
_0807A9F8:
	movs r0, #1
_0807A9FA:
	pop {r1}
	bx r1
	.align 2, 0
