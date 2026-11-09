	push {lr}
	cmp r1, #0
	beq _0819081C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08190820 @ =0x00000F2E
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819081C:
	pop {r0}
	bx r0
	.align 2, 0
_08190820: .4byte 0x00000F2E
