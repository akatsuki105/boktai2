	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080933A0 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809334A
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextBox_SetRect
	ldr r1, _080933A4 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xfd
	bl TextBox_ShowLine
_0809334A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093368
	cmp r0, #0xf
	bls _0809339A
	ldr r0, _080933A8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809339A
_08093368:
	ldr r0, _080933AC @ =0x000020DA
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080933B0 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl FUN_08092744
_0809339A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080933A0: .4byte 0x000009EE
_080933A4: .4byte 0x00003F9D
_080933A8: .4byte 0x030044E0
_080933AC: .4byte 0x000020DA
_080933B0: .4byte 0x000020AC
