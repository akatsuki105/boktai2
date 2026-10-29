	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	adds r6, r7, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C84CC
	movs r0, #0
	mov r8, r0
	mov r2, r8
	strb r2, [r1]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r6, r3
	ldr r0, _080C8518 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r4, _080C851C @ =0x000002FA
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, #0x80
	ldr r2, _080C8520 @ =0x000002F2
	adds r1, r6, r2
	strh r0, [r1]
	adds r3, #4
	adds r2, r6, r3
	ldr r4, _080C8524 @ =0xFFFFFC00
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #8
	adds r1, r6, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r0, r1
	bge _080C8498
	strh r3, [r2]
_080C8498:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r6, r3
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C84CC:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C8508
	adds r0, r6, #0
	bl Jormungandr_EasePos
	mov r2, sb
	cmp r2, #0x11
	ble _080C8508
	ldr r1, _080C8528 @ =FUN_080c852c
	movs r0, #0x12
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C8508:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8518: .4byte 0x03002BE0
_080C851C: .4byte 0x000002FA
_080C8520: .4byte 0x000002F2
_080C8524: .4byte 0xFFFFFC00
_080C8528: .4byte FUN_080c852c
