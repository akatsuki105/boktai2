	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F32B2:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F32C2
	movs r0, #1
	b _081F32C4
_081F32C2:
	movs r0, #0
_081F32C4:
	cmp r0, #0
	beq _081F32D4
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F32D4:
	adds r4, #1
	cmp r4, #0xb
	ble _081F32B2
	ldr r1, _081F32E8 @ =0x030001F0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F32E8: .4byte 0x030001F0
