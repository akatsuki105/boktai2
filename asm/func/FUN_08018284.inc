	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _080182B0
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080182D0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080182D4 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _080182B0
	movs r1, #0
	bl Script_ExecById
_080182B0:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080182D8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #0xe
	bhi _080182DC
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _080182F6
	b _080182F2
	.align 2, 0
_080182D0: .4byte 0x030046A0
_080182D4: .4byte 0x00000934
_080182D8: .4byte 0x03003E78
_080182DC:
	cmp r1, #0x1d
	bhi _080182EA
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _080182F6
	b _080182F2
_080182EA:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080182F6
_080182F2:
	bics r2, r5
	strh r2, [r3]
_080182F6:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl WeatherManager_SpawnParticles
	ldr r1, [r4, #0x1c]
	cmp r1, #0x2c
	bhi _08018314
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801831E
_08018314:
	adds r0, r4, #0
	movs r1, #3
	bl WeatherManager_SetState
	movs r0, #1
_0801831E:
	pop {r4, r5}
	pop {r1}
	bx r1
