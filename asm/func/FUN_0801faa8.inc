	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1c]
	cmp r3, r2
	bge _0801FACE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x1e
_0801FABC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAC6
	movs r0, #1
	b _0801FAD0
_0801FAC6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FABC
_0801FACE:
	movs r0, #0
_0801FAD0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
