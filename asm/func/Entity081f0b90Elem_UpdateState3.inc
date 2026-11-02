	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F066E
	subs r1, #7
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
_081F0636:
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r5, r0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F0648
	adds r0, r1, #0
	bl AuxSprite_Remove
_081F0648:
	adds r4, #1
	cmp r4, #3
	ble _081F0636
	ldr r0, _081F0674 @ =0x00000153
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0x51
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl Entity081f0b90Elem_ExecScript
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
_081F066E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081F0674: .4byte 0x00000153
