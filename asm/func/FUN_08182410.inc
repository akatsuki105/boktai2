	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08182430 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182434
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182436
	.align 2, 0
_08182430: .4byte 0x0000046C
_08182434:
	movs r0, #0
_08182436:
	cmp r0, #0
	beq _081824FA
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _081824B8 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081824BC @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	ldr r1, _081824C0 @ =0x00000256
	adds r0, r6, r1
	ldrh r7, [r0]
	ldr r2, _081824C4 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	movs r4, #0x1c
	adds r4, r4, r5
	mov sl, r4
	ldr r0, _081824C8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5, #0x1c]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081824CC
	adds r0, #4
	b _081824D8
	.align 2, 0
_081824B8: .4byte 0x0000046D
_081824BC: .4byte 0x0000046B
_081824C0: .4byte 0x00000256
_081824C4: .4byte 0x000004A4
_081824C8: .4byte 0x030046A4
_081824CC:
	mov r4, r8
	ldr r0, [r4]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081824D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r4, _08182554 @ =0x000004A4
	adds r0, r6, r4
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
_081824FA:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818251C
	adds r0, r6, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818251C
	b _08182656
_0818251C:
	adds r0, r6, #0
	movs r1, #1
	bl Enemy_PlayAnim
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _08182558 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08182560
	ldr r0, _0818255C @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08182570
	.align 2, 0
_08182554: .4byte 0x000004A4
_08182558: .4byte 0x0000A02F
_0818255C: .4byte 0x00000482
_08182560:
	ldr r1, _08182594 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08182570
	movs r0, #1
	strh r0, [r2]
_08182570:
	ldr r4, _08182598 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818259C
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081825B4
	.align 2, 0
_08182594: .4byte 0x00000482
_08182598: .4byte 0x0000025D
_0818259C:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081825B4:
	ldr r1, _08182634 @ =0x000004A4
	adds r0, r6, r1
	ldr r1, [r0]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_0817d204
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _0818264C
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818260E
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _08182638 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0818263C @ =0xFFFFFDFF
	ldrh r0, [r5]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08182640 @ =0x0000021E
	adds r0, r6, r2
	strh r3, [r0]
	adds r4, #0x86
	adds r0, r6, r4
	strh r3, [r0]
_0818260E:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08182644 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _08182648 @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r6, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _08182656
	.align 2, 0
_08182634: .4byte 0x000004A4
_08182638: .4byte 0xFEFFFFFF
_0818263C: .4byte 0xFFFFFDFF
_08182640: .4byte 0x0000021E
_08182644: .4byte 0x00000469
_08182648: .4byte 0x0000046A
_0818264C:
	ldr r0, _08182668 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08182656:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08182668: .4byte 0x00000484
