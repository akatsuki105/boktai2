	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x18
_081D2132:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2142
	movs r0, #1
	b _081D2144
_081D2142:
	movs r0, #0
_081D2144:
	cmp r0, #0
	beq _081D214E
	adds r0, r4, #0
	bl AuxSprite_Remove
_081D214E:
	adds r4, #0x88
	adds r5, #1
	cmp r5, #7
	ble _081D2132
	movs r1, #0
	ldr r0, _081D2164 @ =0x03000190
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081D2164: .4byte 0x03000190
