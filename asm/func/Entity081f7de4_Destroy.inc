	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F7D82:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7D92
	movs r0, #1
	b _081F7D94
_081F7D92:
	movs r0, #0
_081F7D94:
	cmp r0, #0
	beq _081F7DA4
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F7DA4:
	adds r4, #1
	cmp r4, #1
	ble _081F7D82
	ldr r1, _081F7DB8 @ =0x03000204
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F7DB8: .4byte 0x03000204
