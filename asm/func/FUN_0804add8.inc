	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AE2C
	movs r5, #0
	strb r5, [r1]
	adds r1, #3
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r6, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r6, #0
	bl FUN_0804ab00
	adds r0, r6, #0
	adds r0, #0x2d
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0804AE2C:
	ldr r0, [r6, #0x34]
	cmp r0, #0x1e
	bls _0804AE3C
	adds r0, r6, #0
	bl EntityB88C_ConfirmOrCancel
	cmp r0, #0
	bne _0804AEBA
_0804AE3C:
	adds r0, r6, #0
	bl EntityB88C_MoveCursor
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r3, [r2]
	ldr r0, [r6, #0x30]
	lsls r1, r3, #1
	adds r1, r1, r0
	ldr r0, _0804AE68 @ =0x030044E0
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804AE6C
	adds r0, r3, #1
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r1, r0, #0
	b _0804AE7A
	.align 2, 0
_0804AE68: .4byte 0x030044E0
_0804AE6C:
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #0
	beq _0804AE7A
	movs r0, #0
	strb r0, [r2]
	strb r0, [r1]
_0804AE7A:
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _0804AE8E
	strb r3, [r2]
	strb r3, [r1]
_0804AE8E:
	ldrb r0, [r2]
	cmp r0, #0xf
	bls _0804AEB4
	movs r1, #3
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r3, [r6, #0x34]
	ldr r1, _0804AEC0 @ =0x0000369F
	ldr r0, _0804AEC4 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0x10]
	ldr r0, _0804AEC8 @ =0x00000296
	bl PlaySound_082406e0
_0804AEB4:
	ldr r0, [r6, #0x34]
	adds r0, #1
	str r0, [r6, #0x34]
_0804AEBA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AEC0: .4byte 0x0000369F
_0804AEC4: .4byte gSystemSaveData
_0804AEC8: .4byte 0x00000296
