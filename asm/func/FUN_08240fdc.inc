	push {lr}
	ldr r0, _08240FFC @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	beq _08240FF6
	adds r1, r0, #0
	adds r1, #0x98
	movs r2, #0
	adds r0, #0xd4
_08240FEE:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08240FEE
_08240FF6:
	pop {r0}
	bx r0
	.align 2, 0
_08240FFC: .4byte 0x03001700
