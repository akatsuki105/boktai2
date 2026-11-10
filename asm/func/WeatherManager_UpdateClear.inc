	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018146
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r0, _080181A0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080181A4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080181A8 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	bl FUN_080026fc
	ldr r2, _080181AC @ =0x03003E78
	ldr r0, _080181B0 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08018146:
	adds r0, r4, #0
	bl WeatherManager_GetChance
	mov ip, r0
	ldr r6, _080181A0 @ =0x030046A0
	ldr r3, [r6]
	ldr r1, _080181B4 @ =0x00000942
	adds r0, r3, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080181B8 @ =0x030047A4
	ldr r1, _080181BC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08018242
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018242
	cmp r5, #0
	ble _080181C4
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	asrs r1, r5, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r0, _080181C0 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018242
	str r0, [r2]
	b _08018242
	.align 2, 0
_080181A0: .4byte 0x030046A0
_080181A4: .4byte 0x00000934
_080181A8: .4byte 0xFFFFF7FF
_080181AC: .4byte 0x03003E78
_080181B0: .4byte 0xFFFFFDFF
_080181B4: .4byte 0x00000942
_080181B8: .4byte 0x030047A4
_080181BC: .4byte 0x030047A0
_080181C0: .4byte 0x03000074
_080181C4:
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _08018230
	ldr r7, _0801821C @ =0x0203B400
	ldr r3, _08018220 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r5, _08018224 @ =0x000003FF
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, ip
	blt _08018236
	ldr r0, _08018228 @ =0x03000074
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0801822C @ =0x03000078
	ldr r1, [r0]
	cmp r1, #0
	ble _08018242
	ldr r0, [r3]
	adds r0, #1
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Mod
	ldr r2, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	b _08018242
	.align 2, 0
_0801821C: .4byte 0x0203B400
_08018220: .4byte 0x030046B8
_08018224: .4byte 0x000003FF
_08018228: .4byte 0x03000074
_0801822C: .4byte 0x03000078
_08018230:
	subs r0, #1
	str r0, [r2]
	b _08018242
_08018236:
	adds r0, r4, #0
	movs r1, #1
	bl WeatherManager_SetState
	movs r0, #1
	b _0801824A
_08018242:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_0801824A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
