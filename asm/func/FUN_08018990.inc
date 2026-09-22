	push {r4, r5, lr}
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080189AA
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	b _080189B0
_080189AA:
	movs r4, #0x96
	lsls r4, r4, #3
	adds r5, r4, #0
_080189B0:
	movs r0, #0x69
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080189C2
	bl Script_GetValue
	b _080189E4
_080189C2:
	ldr r1, _080189F4 @ =0x03000078
	ldr r3, [r1]
	cmp r3, #0
	ble _080189E4
	ldr r2, _080189F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080189FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08018A00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
_080189E4:
	ldr r1, _08018A04 @ =0x03000074
	str r5, [r1]
	ldr r1, _080189F4 @ =0x03000078
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080189F4: .4byte 0x03000078
_080189F8: .4byte 0x030046B8
_080189FC: .4byte 0x000003FF
_08018A00: .4byte 0x0203B400
_08018A04: .4byte 0x03000074
