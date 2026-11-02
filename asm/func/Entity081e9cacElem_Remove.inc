	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E91F8 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E91F2
	cmp r5, #0
	beq _081E91F2
	adds r0, r5, #0
	adds r0, #0xe4
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #0
	bge _081E91FC
_081E91F2:
	movs r0, #0
	b _081E924C
	.align 2, 0
_081E91F8: .4byte 0x030001B4
_081E91FC:
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E9210
	movs r0, #1
	b _081E9212
_081E9210:
	movs r0, #0
_081E9212:
	cmp r0, #0
	beq _081E924A
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E924A
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r7]
	adds r1, r5, #0
	adds r1, #0xe8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
	b _081E924C
_081E924A:
	adds r0, r5, #0
_081E924C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
