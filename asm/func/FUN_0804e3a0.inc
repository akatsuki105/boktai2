	push {lr}
	ldr r0, _0804E3B4 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E3B8
	ldrb r0, [r0, #0x1f]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _0804E3BC
	.align 2, 0
_0804E3B4: .4byte 0x03002B58
_0804E3B8:
	movs r0, #1
	rsbs r0, r0, #0
_0804E3BC:
	pop {r1}
	bx r1
