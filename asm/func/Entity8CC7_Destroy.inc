	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D998C @ =0x00000ECC
	adds r7, r6, r0
_081D997A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D9990
	movs r0, #1
	b _081D9992
	.align 2, 0
_081D998C: .4byte 0x00000ECC
_081D9990:
	movs r0, #0
_081D9992:
	cmp r0, #0
	beq _081D99B6
	movs r0, #0xbc
	muls r0, r5, r0
	adds r0, #0x1c
	adds r4, r6, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D99B6
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D99B6:
	adds r5, #1
	cmp r5, #0x13
	ble _081D997A
	ldr r1, _081D99C8 @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D99C8: .4byte 0x030001A4
