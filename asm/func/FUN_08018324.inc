	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801838E
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r5, _080183C0 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	bne _08018366
	ldrh r0, [r4, #0x28]
	str r0, [r5]
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _08018366
	ldr r2, _080183C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080183C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080183CC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2a]
	bl Mod
	ldr r1, [r5]
	adds r1, r1, r0
	str r1, [r5]
_08018366:
	movs r0, #0
	strh r0, [r4, #0x24]
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080183D0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080183D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080183D8 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	movs r0, #2
	bl FUN_080026fc
_0801838E:
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _080183E8
	ldr r0, _080183DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080183B6
	ldr r0, _080183E0 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _080183B6
	ldr r1, _080183E4 @ =0x0300446C
	movs r0, #5
	str r0, [r1]
	movs r0, #0x67
	bl PlaySound_082406e0
_080183B6:
	adds r0, r4, #0
	bl WeatherManager_ResetTimer
	b _08018424
	.align 2, 0
_080183C0: .4byte 0x03000080
_080183C4: .4byte 0x030046B8
_080183C8: .4byte 0x000003FF
_080183CC: .4byte 0x0203B400
_080183D0: .4byte 0x03003E78
_080183D4: .4byte 0x030046A0
_080183D8: .4byte 0x00000934
_080183DC: .4byte 0x030047A4
_080183E0: .4byte 0x03002B48
_080183E4: .4byte 0x0300446C
_080183E8:
	ldr r0, _0801840C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #2
	bls _0801841E
	cmp r1, #5
	bne _08018414
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _08018410 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #2
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	b _0801841E
	.align 2, 0
_0801840C: .4byte 0x030047E0
_08018410: .4byte 0x00001FFF
_08018414:
	cmp r1, #3
	bne _0801841E
	ldr r1, _08018468 @ =0x03002B48
	movs r0, #6
	str r0, [r1]
_0801841E:
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
_08018424:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1d
	bls _08018480
	ldr r0, _0801846C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08018470 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _08018458
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08018474 @ =0x030047A4
	ldr r1, _08018478 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08018480
_08018458:
	ldr r1, _0801847C @ =0x03000080
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl WeatherManager_SetState
	b _080184E0
	.align 2, 0
_08018468: .4byte 0x03002B48
_0801846C: .4byte 0x030046A0
_08018470: .4byte 0x00000942
_08018474: .4byte 0x030047A4
_08018478: .4byte 0x030047A0
_0801847C: .4byte 0x03000080
_08018480:
	ldr r5, _080184C4 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	ble _080184D4
	subs r0, #1
	str r0, [r5]
	ldr r2, _080184C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080184CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080184D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #4
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl WeatherManager_SpawnParticles
	ldr r1, [r4, #0x50]
	movs r0, #1
	subs r0, r0, r1
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _080184E2
	.align 2, 0
_080184C4: .4byte 0x03000080
_080184C8: .4byte 0x030046B8
_080184CC: .4byte 0x000003FF
_080184D0: .4byte 0x0203B400
_080184D4:
	adds r0, r4, #0
	movs r1, #4
	bl WeatherManager_SetState
	movs r0, #0
	str r0, [r5]
_080184E0:
	movs r0, #1
_080184E2:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
