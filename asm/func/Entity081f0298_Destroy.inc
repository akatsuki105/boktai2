	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F0226:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0236
	movs r0, #1
	b _081F0238
_081F0236:
	movs r0, #0
_081F0238:
	cmp r0, #0
	beq _081F0248
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F0248:
	adds r4, #1
	cmp r4, #0xb
	ble _081F0226
	ldr r1, _081F025C @ =0x030001E0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F025C: .4byte 0x030001E0
