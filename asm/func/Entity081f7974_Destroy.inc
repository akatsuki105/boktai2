	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x3c
_081F7916:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7926
	movs r0, #1
	b _081F7928
_081F7926:
	movs r0, #0
_081F7928:
	cmp r0, #0
	beq _081F7932
	adds r0, r4, #0
	bl AuxSprite_Remove
_081F7932:
	adds r4, #0x48
	adds r5, #1
	cmp r5, #0xf
	ble _081F7916
	movs r1, #0
	ldr r0, _081F7948 @ =0x03000200
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F7948: .4byte 0x03000200
