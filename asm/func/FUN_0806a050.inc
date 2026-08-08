	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0806A068 @ =0x000003FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A06C
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08060c40
	b _0806A074
	.align 2, 0
_0806A068: .4byte 0x000003FE
_0806A06C:
	adds r0, r4, #0
	movs r1, #0x1d
	bl FUN_08060c40
_0806A074:
	movs r1, #0x88
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
