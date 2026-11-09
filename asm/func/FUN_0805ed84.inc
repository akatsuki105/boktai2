	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _0805ED98
	movs r0, #0
	strb r0, [r1, #2]
	strh r0, [r3, #0x10]
_0805ED98:
	ldr r0, [r1, #0x14]
	cmp r0, #5
	beq _0805EDAE
	cmp r0, #0xa
	bne _0805EDB2
	movs r0, #2
	strh r0, [r3, #0x10]
	adds r0, r4, #0
	bl Entity0805ee80_RemoveElem
	b _0805EDB8
_0805EDAE:
	movs r0, #1
	strh r0, [r3, #0x10]
_0805EDB2:
	ldr r0, [r1, #0x14]
	adds r0, #1
	str r0, [r1, #0x14]
_0805EDB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
