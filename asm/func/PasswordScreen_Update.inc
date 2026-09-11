	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #0x28
	bhi _08013022
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08013022
	movs r0, #0x9d
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08013022:
	ldr r0, [r4, #0x18]
	cmp r0, #0x3b
	bls _0801304A
	ldr r0, _08013058 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801304A
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _0801304A
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r4, #0x28]
_0801304A:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013058: .4byte 0x030044E0
