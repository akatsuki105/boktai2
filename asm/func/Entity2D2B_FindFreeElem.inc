	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bhs _08007F20
	adds r3, r0, #0
_08007F0E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08007F18
	adds r0, r1, #0
	b _08007F22
_08007F18:
	adds r2, #1
	adds r1, #0xe8
	cmp r2, r3
	blo _08007F0E
_08007F20:
	movs r0, #0
_08007F22:
	pop {r1}
	bx r1
	.align 2, 0
