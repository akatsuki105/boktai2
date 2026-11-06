	push {r4, lr}
	ldr r0, _081F8AB0 @ =0x03000208
	ldr r0, [r0]
	cmp r0, #0
	beq _081F8AA8
	movs r4, #3
	movs r2, #0xad
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0x92
	lsls r3, r3, #1
	movs r2, #7
_081F8A98:
	ldrb r0, [r1]
	cmp r0, #2
	bne _081F8AA0
	strb r4, [r1]
_081F8AA0:
	adds r1, r1, r3
	subs r2, #1
	cmp r2, #0
	bge _081F8A98
_081F8AA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F8AB0: .4byte 0x03000208
