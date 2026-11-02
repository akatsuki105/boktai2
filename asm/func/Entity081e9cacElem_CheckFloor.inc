	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081E9D1C
	adds r0, r6, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #4
	bls _081E9DAC
_081E9D1C:
	adds r0, r6, #0
	adds r0, #0x82
	movs r1, #0
	ldrsh r7, [r0, r1]
	adds r5, r6, #0
	adds r5, #0xdc
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E9D4C
	cmp r1, #0
	blt _081E9D4C
	ldr r0, _081E9D50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E9D4C
	ldr r0, _081E9D54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E9D58
_081E9D4C:
	movs r4, #0
	b _081E9D66
	.align 2, 0
_081E9D50: .4byte 0x030046A8
_081E9D54: .4byte 0x030046AC
_081E9D58:
	ldr r0, _081E9D78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E9D66:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E9D7C
	adds r0, #4
	b _081E9D88
	.align 2, 0
_081E9D78: .4byte 0x030046A4
_081E9D7C:
	ldr r0, _081E9D9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E9D88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E9DA0
	cmp r2, #2
	beq _081E9DA4
	b _081E9DA8
	.align 2, 0
_081E9D9C: .4byte 0x030046A4
_081E9DA0:
	ldrb r0, [r5, #4]
	b _081E9DA6
_081E9DA4:
	ldrb r0, [r5]
_081E9DA6:
	subs r1, r1, r0
_081E9DA8:
	cmp r7, r1
	blo _081E9DB0
_081E9DAC:
	movs r0, #0
	b _081E9DBC
_081E9DB0:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
_081E9DBC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
