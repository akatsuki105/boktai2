	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r2, _081DDFE0 @ =0x0000FFFF
	movs r1, #0
	cmp r1, r4
	bhs _081DDFF4
	movs r6, #0x80
	lsls r6, r6, #8
	ldr r5, _081DDFE4 @ =0x00001021
_081DDFC4:
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r3, #0
	adds r1, #1
_081DDFD0:
	adds r0, r2, #0
	ands r0, r6
	cmp r0, #0
	beq _081DDFE8
	lsls r2, r2, #1
	eors r2, r5
	b _081DDFEA
	.align 2, 0
_081DDFE0: .4byte 0x0000FFFF
_081DDFE4: .4byte 0x00001021
_081DDFE8:
	lsls r2, r2, #1
_081DDFEA:
	adds r3, #1
	cmp r3, #7
	bls _081DDFD0
	cmp r1, r4
	blo _081DDFC4
_081DDFF4:
	ldr r0, _081DE000 @ =0x0000FFFF
	bics r0, r2
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE000: .4byte 0x0000FFFF
