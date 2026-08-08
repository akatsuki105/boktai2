	push {lr}
	adds r2, r0, #0
	ldr r1, _080F6E5C @ =0x0000049C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0xc4
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _080F6E56
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r0, _080F6E60 @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080F6E56:
	pop {r0}
	bx r0
	.align 2, 0
_080F6E5C: .4byte 0x0000049C
_080F6E60: .4byte 0xFFFFF636
