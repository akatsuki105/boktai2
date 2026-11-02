	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081E9C2E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9C3E
	movs r1, #1
	b _081E9C40
_081E9C3E:
	movs r1, #0
_081E9C40:
	cmp r1, #0
	beq _081E9C5E
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r4, #0x90
	adds r0, r4, #0
	bl AuxSprite_Remove
_081E9C5E:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9C2E
	ldr r2, _081E9C70 @ =0x030001B4
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C70: .4byte 0x030001B4
