	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A7280 @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne _080A7288
	ldr r0, _080A7284 @ =0x000002F9
	bl PlaySound_082406e0
	b _080A72E0
	.align 2, 0
_080A7280: .4byte 0x00000346
_080A7284: .4byte 0x000002F9
_080A7288:
	cmp r0, #0x95
	bls _080A72E0
	cmp r0, #0x96
	bne _080A7296
	ldr r0, _080A72E8 @ =0x0000012D
	bl PlaySound_082406e0
_080A7296:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #5
	strh r0, [r2]
	ldr r3, _080A72EC @ =0x0000033E
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #5
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x7f
	ble _080A72E0
	movs r0, #1
	strh r0, [r2]
	strh r0, [r1]
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A72C2:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A72C2
	movs r2, #0
	ldr r0, _080A72F0 @ =0x00000341
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _080A72F4 @ =0x00000346
	adds r0, r4, r1
	strh r2, [r0]
_080A72E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A72E8: .4byte 0x0000012D
_080A72EC: .4byte 0x0000033E
_080A72F0: .4byte 0x00000341
_080A72F4: .4byte 0x00000346
