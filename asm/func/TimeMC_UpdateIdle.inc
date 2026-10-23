	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A4160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A4120
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A4120
	adds r0, #1
	strh r0, [r1]
_080A4120:
	adds r0, r4, #0
	bl TimeMC_IsPlayerNear
	adds r6, r0, #0
	cmp r6, #0
	beq _080A41CC
	ldrh r0, [r4, #0x18]
	cmp r0, #1
	beq _080A413E
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x18]
_080A413E:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bhi _080A414E
	adds r0, r1, #1
	strh r0, [r7]
_080A414E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x16
	bhi _080A4164
	adds r0, r1, #2
	b _080A4166
	.align 2, 0
_080A4160: .4byte 0x030047A4
_080A4164:
	movs r0, #0x18
_080A4166:
	strh r0, [r5]
	movs r2, #1
	ldr r0, _080A41BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A4202
	ldr r0, _080A41C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A4202
	ldr r6, _080A41C4 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A4202
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A4202
	movs r0, #8
	strh r0, [r7]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, [r6]
	adds r1, r4, #0
	adds r1, #0x64
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A41C8 @ =TimeMC_UpdateActivated
	adds r0, r4, #0
	bl TimeMC_SetUpdateCallback
	b _080A4202
	.align 2, 0
_080A41BC: .4byte 0x03002BC0
_080A41C0: .4byte 0x030044E0
_080A41C4: .4byte 0x03002BE0
_080A41C8: .4byte TimeMC_UpdateActivated
_080A41CC:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A41DA
	ldr r0, _080A41FC @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r4, #0x18]
_080A41DA:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080A41EA
	subs r0, r1, #1
	strh r0, [r7]
_080A41EA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #2
	bls _080A4200
	subs r0, r1, #2
	strh r0, [r5]
	b _080A4202
	.align 2, 0
_080A41FC: .4byte 0x00000199
_080A4200:
	strh r6, [r5]
_080A4202:
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A4212
	ldr r0, [r4, #0x1c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x1c]
	b _080A4228
_080A4212:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x66
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3a]
_080A4228:
	ldrh r0, [r7]
	cmp r0, #7
	bls _080A423C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0x8f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _080A424A
_080A423C:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A424A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
