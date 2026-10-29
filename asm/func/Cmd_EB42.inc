	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E570 @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E5BE
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E5BE
	bl VM_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	b _0809E5B8
	.align 2, 0
_0809E570: .4byte 0x03000140
_0809E574:
	movs r0, #0xa8
	adds r5, r3, #0
	muls r5, r0, r5
	adds r2, r4, r5
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E5B6
	cmp r0, r7
	bne _0809E5B6
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r5
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809E5BE
_0809E5B6:
	adds r3, #1
_0809E5B8:
	ldrb r0, [r6]
	cmp r3, r0
	blt _0809E574
_0809E5BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
