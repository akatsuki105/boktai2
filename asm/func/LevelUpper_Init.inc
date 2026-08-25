	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A8768
	bl VM_GetValueSafe2
	str r0, [r6, #0x78]
_080A8768:
	ldr r0, _080A87B0 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x62
	bgt _080A8782
	adds r1, r0, #0
	adds r0, r6, #0
	bl GetNextLvExp
	str r0, [r6, #0x74]
_080A8782:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x68
_080A8788:
	adds r0, r5, #0
	bl GetWeaponSkillLevel
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _080A8788
	adds r0, r6, #0
	bl LevelUpper_Init_Helper_080a86cc
	adds r0, r6, #0
	bl LevelUpper_Init_Helper_080a8704
	ldr r0, _080A87B4 @ =0x03000154
	str r6, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A87B0: .4byte 0x030046A0
_080A87B4: .4byte 0x03000154
