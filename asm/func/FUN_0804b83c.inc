	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B84A
	movs r0, #0
	strb r0, [r4, #0x19]
_0804B84A:
	ldr r1, [r4, #0x24]
	cmp r1, #0x14
	bne _0804B864
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _0804B864
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
	b _0804B868
_0804B864:
	adds r0, r1, #1
	str r0, [r4, #0x24]
_0804B868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
