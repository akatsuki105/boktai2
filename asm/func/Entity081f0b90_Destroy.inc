	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r2, #0
_081F0B06:
	movs r1, #1
	lsls r1, r2
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0B16
	movs r0, #1
	b _081F0B18
_081F0B16:
	movs r0, #0
_081F0B18:
	adds r6, r2, #1
	cmp r0, #0
	beq _081F0B42
	movs r0, #0xae
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x3c
	adds r5, r7, r0
	movs r4, #0
_081F0B2A:
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r5, r0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F0B3C
	adds r0, r1, #0
	bl AuxSprite_Remove
_081F0B3C:
	adds r4, #1
	cmp r4, #3
	ble _081F0B2A
_081F0B42:
	adds r2, r6, #0
	cmp r2, #3
	ble _081F0B06
	ldr r1, _081F0B54 @ =0x030001E4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F0B54: .4byte 0x030001E4
