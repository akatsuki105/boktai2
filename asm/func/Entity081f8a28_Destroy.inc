	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _081F89B4 @ =0x0000014D
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x78
	movs r0, #0
	mov r8, r0
_081F89A2:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F89B8
	movs r0, #1
	b _081F89BA
	.align 2, 0
_081F89B4: .4byte 0x0000014D
_081F89B8:
	movs r0, #0
_081F89BA:
	cmp r0, #0
	beq _081F89D8
	ldrb r0, [r4]
	cmp r0, #0
	bne _081F89CE
	adds r0, r5, #0
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r4]
_081F89CE:
	mov r0, r8
	adds r0, #0x3c
	adds r0, r6, r0
	bl AuxSprite_Remove
_081F89D8:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, r5, r0
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _081F89A2
	movs r1, #0
	ldr r0, _081F89FC @ =0x03000208
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F89FC: .4byte 0x03000208
