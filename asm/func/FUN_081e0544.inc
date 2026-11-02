	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E057C @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0556
	ldrb r1, [r0, #0x1c]
_081E0556:
	cmp r1, #0x18
	bne _081E0576
	ldr r1, _081E0580 @ =FUN_081e0588
	movs r2, #6
	movs r4, #0xf4
	lsls r4, r4, #2
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _081E0584 @ =0x000003E9
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
_081E0576:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E057C: .4byte 0x03002C68
_081E0580: .4byte FUN_081e0588
_081E0584: .4byte 0x000003E9
