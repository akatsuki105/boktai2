	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081452E4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081452E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081452EA
	.align 2, 0
_081452E4: .4byte 0x0000046C
_081452E8:
	movs r0, #0
_081452EA:
	cmp r0, #0
	beq _08145322
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0814534C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _08145350 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x80
	strb r0, [r5, #5]
_08145322:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _08145354 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814535C
	ldr r3, _08145358 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814536C
	.align 2, 0
_0814534C: .4byte 0x0000046D
_08145350: .4byte 0x0000046B
_08145354: .4byte 0x0000A02F
_08145358: .4byte 0x00000482
_0814535C:
	ldr r4, _08145390 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814536C
	movs r0, #1
	strh r0, [r2]
_0814536C:
	ldr r1, _08145394 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08145398
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081453B0
	.align 2, 0
_08145390: .4byte 0x00000482
_08145394: .4byte 0x0000025D
_08145398:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081453B0:
	ldr r2, _081453FC @ =0x00000472
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	ldr r4, _08145400 @ =0xFFFFFEC0
	adds r0, r0, r4
	subs r1, r1, r0
	cmp r1, #0
	bge _081453C6
	rsbs r1, r1, #0
_081453C6:
	cmp r1, #0x10
	bgt _08145410
	ldr r1, _08145404 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x50
	ble _08145410
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08145408 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _0814540C @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0814541A
	.align 2, 0
_081453FC: .4byte 0x00000472
_08145400: .4byte 0xFFFFFEC0
_08145404: .4byte 0x00000484
_08145408: .4byte 0x00000469
_0814540C: .4byte 0x0000046C
_08145410:
	ldr r2, _08145420 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814541A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08145420: .4byte 0x00000484
