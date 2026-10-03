	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BCAD8 @ =0x000012EE
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080BCA8E
	b _080BCBB8
_080BCA8E:
	subs r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080BCB5C
	ldr r0, _080BCADC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	beq _080BCB5C
	ldr r1, _080BCAE0 @ =0x0000151D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BCAE4
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BCAFC
	.align 2, 0
_080BCAD8: .4byte 0x000012EE
_080BCADC: .4byte 0x030046A0
_080BCAE0: .4byte 0x0000151D
_080BCAE4:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BCAFC:
	str r0, [r1]
	ldr r0, _080BCB28 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #0xc0
	lsls r5, r5, #2
	ands r5, r1
	cmp r5, #0
	beq _080BCB38
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCB2C @ =0x000012ED
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BCB30
	adds r0, r4, #0
	bl FUN_080bc350
	b _080BCBD6
	.align 2, 0
_080BCB28: .4byte 0x030044E0
_080BCB2C: .4byte 0x000012ED
_080BCB30:
	adds r0, r4, #0
	bl FUN_080bb160
	b _080BCBD6
_080BCB38:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCB54 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCB58 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _080BCB92
	.align 2, 0
_080BCB54: .4byte 0x00000119
_080BCB58: .4byte 0x0000FFFF
_080BCB5C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080BCBA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCBAC @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCBB0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
_080BCB92:
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BCBB4 @ =FUN_080bcbf4
	adds r0, r4, #0
	bl Entity3019_SetState
	b _080BCBE2
	.align 2, 0
_080BCBA8: .4byte 0x030044E0
_080BCBAC: .4byte 0x00000119
_080BCBB0: .4byte 0x0000FFFF
_080BCBB4: .4byte FUN_080bcbf4
_080BCBB8:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BCBEC @ =0x0000151D
	adds r0, r4, r1
	strb r3, [r0]
_080BCBD6:
	ldr r1, _080BCBF0 @ =0x0000153C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BCBE2:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BCBEC: .4byte 0x0000151D
_080BCBF0: .4byte 0x0000153C
