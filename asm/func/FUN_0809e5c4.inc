	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E5E8 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E62A
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E62A
	bl VM_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0x26
	adds r5, r0, #0
	b _0809E624
	.align 2, 0
_0809E5E8: .4byte 0x03000140
_0809E5EC:
	movs r0, #0xa8
	adds r4, r3, #0
	muls r4, r0, r4
	adds r2, r6, r4
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E622
	cmp r0, r7
	bne _0809E622
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E62A
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809E62A
_0809E622:
	adds r3, #1
_0809E624:
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E5EC
_0809E62A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
