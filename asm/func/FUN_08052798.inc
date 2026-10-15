	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _080527B0
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
_080527B0:
	movs r1, #0x28
	ldrsh r0, [r5, r1]
	adds r2, r5, #0
	adds r2, #0x25
	cmp r0, #8
	ble _080527CC
	ldr r0, _080527F8 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _080527FC @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _080527CC
	movs r0, #8
	strb r0, [r2]
_080527CC:
	movs r1, #0x28
	ldrsh r0, [r5, r1]
	ldrb r1, [r2]
	cmp r0, r1
	blt _08052804
	ldrh r0, [r5, #0x28]
	subs r0, r0, r1
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #0x2a]
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldr r0, [r5, #0x18]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _08052810
	ldr r0, _08052800 @ =0x000002A5
	bl PlaySound_082406e0
	b _08052810
	.align 2, 0
_080527F8: .4byte 0x030044E0
_080527FC: .4byte 0x0000030F
_08052800: .4byte 0x000002A5
_08052804:
	ldrh r0, [r5, #0x28]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	movs r1, #0
	strh r0, [r5, #0x2a]
	strh r1, [r5, #0x28]
_08052810:
	movs r1, #0x2a
	ldrsh r0, [r5, r1]
	ldr r1, _0805283C @ =0x0000270F
	cmp r0, r1
	ble _0805281C
	strh r1, [r5, #0x2a]
_0805281C:
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _08052828
	movs r0, #0
	strh r0, [r5, #0x28]
_08052828:
	movs r0, #0xaa
	lsls r0, r0, #3
	adds r3, r5, r0
	movs r0, #0x28
	ldrsh r2, [r5, r0]
	cmp r2, r1
	ble _08052840
	adds r2, r1, #0
	b _08052846
	.align 2, 0
_0805283C: .4byte 0x0000270F
_08052840:
	cmp r2, #0
	bge _08052846
	movs r2, #0
_08052846:
	adds r4, r5, #0
	adds r4, #0x30
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x60
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #4
	bl FUN_082376a4
	movs r1, #0xda
	lsls r1, r1, #3
	adds r3, r5, r1
	movs r0, #0x2a
	ldrsh r2, [r5, r0]
	ldr r0, _0805287C @ =0x0000270F
	cmp r2, r0
	ble _08052880
	adds r2, r0, #0
	b _08052886
	.align 2, 0
_0805287C: .4byte 0x0000270F
_08052880:
	cmp r2, #0
	bge _08052886
	movs r2, #0
_08052886:
	movs r1, #0
	str r1, [sp]
	movs r0, #0x68
	str r0, [sp, #4]
	movs r0, #0x88
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #4
	bl FUN_082376a4
	movs r2, #0x28
	ldrsh r1, [r5, r2]
	cmp r1, #0
	bne _080528B6
	movs r0, #5
	strb r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _080528BC
_080528B6:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_080528BC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
