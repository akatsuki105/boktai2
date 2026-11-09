	push {lr}
	cmp r1, #0
	beq _08137A48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08137A4C @ =0x00000B32
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_08137A48:
	pop {r0}
	bx r0
	.align 2, 0
_08137A4C: .4byte 0x00000B32
