	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801851C
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #3
	bl FUN_080026fc
	ldr r0, _080185AC @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080185B0 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080185B4 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq _0801851C
	movs r1, #0
	bl Script_ExecById
_0801851C:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080185B8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bhi _0801853C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0801853C
	bics r2, r5
	strh r2, [r3]
_0801853C:
	ldr r0, [r4, #0x1c]
	cmp r0, #7
	bhi _0801854E
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl WeatherManager_SpawnParticles
_0801854E:
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bls _080185D4
	adds r0, r4, #0
	movs r1, #0
	bl WeatherManager_SetState
	ldr r2, _080185B8 @ =0x03003E78
	ldr r0, _080185BC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r4, _080185AC @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080185C0 @ =0x03000074
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, _080185C4 @ =0x03000078
	ldr r3, [r0]
	cmp r3, #0
	ble _080185A6
	ldr r2, _080185C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080185CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080185D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
	ldr r2, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
_080185A6:
	movs r0, #1
	b _080185DE
	.align 2, 0
_080185AC: .4byte 0x030046A0
_080185B0: .4byte 0x00000934
_080185B4: .4byte 0xFFFFF7FF
_080185B8: .4byte 0x03003E78
_080185BC: .4byte 0xFFFFFDFF
_080185C0: .4byte 0x03000074
_080185C4: .4byte 0x03000078
_080185C8: .4byte 0x030046B8
_080185CC: .4byte 0x000003FF
_080185D0: .4byte 0x0203B400
_080185D4:
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_080185DE:
	pop {r4, r5}
	pop {r1}
	bx r1
