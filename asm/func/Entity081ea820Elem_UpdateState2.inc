	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081EA46E
	movs r2, #0
	cmp r0, #0x28
	ble _081EA46E
	movs r2, #1
_081EA46E:
	adds r4, r5, #0
	adds r4, #0xcc
	ldr r0, [r4]
	ldr r1, _081EA498 @ =0x085AE468
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081EA4A0
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EA49C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EA49E
	.align 2, 0
_081EA498: .4byte 0x085AE468
_081EA49C:
	orrs r1, r2
_081EA49E:
	str r1, [r6]
_081EA4A0:
	ldr r0, [r7]
	cmp r0, #0x5a
	ble _081EA4E4
	movs r0, #0xd3
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	strh r4, [r0]
	str r4, [r7]
	b _081EA4E8
_081EA4E4:
	adds r0, #1
	str r0, [r7]
_081EA4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
