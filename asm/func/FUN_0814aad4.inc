	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814AAF8
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl Enemy_SetAnimEntry
	b _0814AB04
_0814AAF8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl Enemy_SetAnimEntry
_0814AB04:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814AB1E
	ldr r0, _0814AB24 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
_0814AB1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814AB24: .4byte 0x00000482
