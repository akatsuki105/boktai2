	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _080A109C
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _080A1094 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1098 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	b _080A10D8
	.align 2, 0
_080A1094: .4byte 0x030046A0
_080A1098: .4byte 0x00000934
_080A109C:
	ldr r0, _080A10E0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080A10E4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080A10E8 @ =0xFFFFEFFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A10D8
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10C8
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10C8:
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A10D8
	movs r1, #0
	bl VM_ExecByID
_080A10D8:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A10E0: .4byte 0x030046A0
_080A10E4: .4byte 0x00000934
_080A10E8: .4byte 0xFFFFEFFF
