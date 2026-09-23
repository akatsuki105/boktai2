	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1d]
	cmp r3, r2
	bge _0801FAFE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x26
_0801FAEC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAF6
	movs r0, #1
	b _0801FB00
_0801FAF6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FAEC
_0801FAFE:
	movs r0, #0
_0801FB00:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
