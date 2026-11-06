	push {lr}
	ldr r0, _081F7E64 @ =0x03000204
	ldr r0, [r0]
	cmp r0, #0
	beq _081F7E5E
	movs r3, #2
	adds r1, r0, #0
	adds r1, #0xd2
	movs r2, #1
_081F7E4E:
	ldrb r0, [r1]
	cmp r0, #1
	bne _081F7E56
	strb r3, [r1]
_081F7E56:
	adds r1, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _081F7E4E
_081F7E5E:
	pop {r0}
	bx r0
	.align 2, 0
_081F7E64: .4byte 0x03000204
