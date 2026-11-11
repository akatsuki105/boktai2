	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r5, [r6, #0x70]
	movs r0, #0
	mov r8, r0
	ldrh r1, [r6, #0x18]
	cmp r8, r1
	blt _0800433E
	b _080044E8
_0800433E:
	adds r7, r5, #0
	adds r7, #0xce
	mov sb, r0
	adds r4, r5, #0
	adds r4, #0x18
_08004348:
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _08004350
	b _080044D2
_08004350:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _080043C0
	cmp r0, #3
	bne _0800436E
	ldr r1, _080043B8 @ =0x085AA658
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0800436E
	adds r0, r5, #0
	bl _call_via_r1
_0800436E:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _080043AA
	ldrh r0, [r4, #0x14]
	str r0, [sp, #4]
	ldrb r0, [r5]
	str r0, [sp, #8]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	str r0, [sp, #0xc]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x14]
	ldr r1, _080043BC @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r0, [r4, #0x10]
	bl VM_ExecByID
	mov r1, sb
	str r1, [r4, #0x10]
_080043AA:
	adds r0, r5, #0
	bl MovableBlock_DropUpper
	adds r0, r5, #0
	bl MovableBlock_Release
	b _080044D2
	.align 2, 0
_080043B8: .4byte 0x085AA658
_080043BC: .4byte 0xFFFF0000
_080043C0:
	adds r0, r5, #0
	adds r0, #0x2c
	bl Mover_ApplyMove
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _080043DA
	adds r0, r5, #0
	bl _call_via_r1
_080043DA:
	ldrb r1, [r5, #1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800440E
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08004404
	ldrh r0, [r4, #0x16]
	ldr r2, _08004400 @ =0x0000FFFD
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #0x16]
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r5, r1
	bl Map_UpdateZoneEvents
	b _08004418
	.align 2, 0
_08004400: .4byte 0x0000FFFD
_08004404:
	ldrh r0, [r4, #0x16]
	movs r1, #2
	orrs r0, r1
	strh r0, [r4, #0x16]
	b _08004418
_0800440E:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r5, r2
	bl Map_UpdateZoneEvents
_08004418:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08004422
	subs r0, #1
	strb r0, [r4, #9]
_08004422:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004446
	ldr r0, _0800443C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08004440
	movs r0, #1
	b _08004442
	.align 2, 0
_0800443C: .4byte 0x030046A0
_08004440:
	movs r0, #0
_08004442:
	cmp r0, #0
	beq _08004450
_08004446:
	ldr r0, [r4, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08004456
_08004450:
	ldr r0, [r4, #0x74]
	movs r1, #1
	orrs r0, r1
_08004456:
	str r0, [r4, #0x74]
	ldrb r1, [r4]
	cmp r1, #0
	bne _08004466
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _0800446C
_08004466:
	subs r0, r1, #1
	strb r0, [r4]
	b _080044B0
_0800446C:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004492
	ldr r0, _08004488 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _0800448C
	movs r0, #1
	b _0800448E
	.align 2, 0
_08004488: .4byte 0x030046A0
_0800448C:
	movs r0, #0
_0800448E:
	cmp r0, #0
	beq _080044B0
_08004492:
	ldrh r0, [r7]
	ldr r2, _080044AC @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r7]
	adds r0, r5, #0
	adds r0, #0xc8
	adds r1, r5, #0
	adds r1, #0x34
	movs r2, #0
	bl Hitbox_SetPos
	b _080044B8
	.align 2, 0
_080044AC: .4byte 0x0000FFFB
_080044B0:
	ldrh r0, [r7]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7]
_080044B8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _080044D2
	subs r0, #1
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080044D2
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r4, #2]
	bl Video_SetAuxSpritePltt
_080044D2:
	movs r0, #1
	add r8, r0
	movs r1, #0xce
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r4, r4, r1
	adds r5, r5, r1
	ldrh r2, [r6, #0x18]
	cmp r8, r2
	bge _080044E8
	b _08004348
_080044E8:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	beq _0800454E
	adds r0, r6, #0
	adds r0, #0x30
	ldr r1, [r6, #0x20]
	ldr r2, [r6, #0x28]
	movs r4, #0x1c
	ldrsh r3, [r6, r4]
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	adds r0, r6, #0
	adds r0, #0x50
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x2c]
	movs r5, #0x1c
	ldrsh r3, [r6, r5]
	str r4, [sp]
	bl BlendPltt
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne _08004532
	ldrh r0, [r6, #0x1c]
	adds r0, #1
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800454E
	movs r0, #0x20
	strh r0, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1b]
	b _0800454E
_08004532:
	ldrh r0, [r6, #0x1c]
	subs r0, #1
	movs r1, #0
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800454E
	movs r0, #0
	strh r0, [r6, #0x1c]
	strb r1, [r6, #0x1b]
	ldrb r0, [r6, #0x1f]
	cmp r0, #0
	beq _0800454E
	strb r1, [r6, #0x1f]
_0800454E:
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #0x1a]
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
