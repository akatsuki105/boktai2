	push {r4, r5, r6, lr}
	ldr r5, _0824084C @ =0x03004820
	adds r6, r5, #0
	adds r4, r5, #0
_08240834:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0824086A
	adds r0, r5, #0
	adds r0, #0x14
	cmp r4, r0
	bne _08240850
	ldrh r0, [r5, #0x14]
	bl m4aSongNumStartOrContinue
	b _0824086A
	.align 2, 0
_0824084C: .4byte 0x03004820
_08240850:
	adds r0, r5, #0
	adds r0, #0x18
	cmp r4, r0
	beq _08240864
	adds r0, #0x22
	cmp r4, r0
	beq _08240864
	adds r0, #2
	cmp r4, r0
	bne _0824086A
_08240864:
	ldrh r0, [r6]
	bl m4aSongNumStartOrChange
_0824086A:
	adds r6, #2
	adds r4, #2
	adds r0, r5, #0
	adds r0, #0x3e
	cmp r4, r0
	ble _08240834
	pop {r4, r5, r6}
	pop {r0}
	bx r0
