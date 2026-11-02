	push {r4, r5, r6, r7, lr}
	ldr r0, _081E9278 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E92C4
	ldr r0, [r6, #0x38]
	cmp r0, #0
	beq _081E92C4
	movs r7, #0
_081E9266:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E927C
	movs r0, #1
	b _081E927E
	.align 2, 0
_081E9278: .4byte 0x030001B4
_081E927C:
	movs r0, #0
_081E927E:
	cmp r0, #0
	beq _081E92BE
	movs r0, #0xf4
	muls r0, r7, r0
	adds r0, #0x3c
	adds r5, r6, r0
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E92BE
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
_081E92BE:
	adds r7, #1
	cmp r7, #0xb
	ble _081E9266
_081E92C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
