	push {lr}
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048984
	subs r0, #1
	strb r0, [r1]
	ldr r3, _08048988 @ =0x00000105
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #7]
_08048984:
	pop {r0}
	bx r0
	.align 2, 0
_08048988: .4byte 0x00000105
