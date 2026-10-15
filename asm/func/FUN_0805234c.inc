	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08052364
	movs r0, #0
	strb r0, [r7, #0x1d]
_08052364:
	ldr r0, _080523B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _080523B4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _08052374
	movs r0, #0x64
	str r0, [r7, #0x18]
_08052374:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1d
	bhi _080523C4
	ldr r0, _080523B8 @ =0x0203B400
	mov r8, r0
	ldr r1, _080523BC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _080523C0 @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	str r0, [sp, #0x14]
	ldr r1, _080523BC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	b _080523CE
	.align 2, 0
_080523B0: .4byte 0x030044E0
_080523B4: .4byte 0x0000030F
_080523B8: .4byte 0x0203B400
_080523BC: .4byte 0x030046B8
_080523C0: .4byte 0x000003FF
_080523C4:
	ldrb r0, [r7, #0x1e]
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x21
	ldrb r0, [r0]
_080523CE:
	str r0, [sp, #0x1c]
	ldr r0, [r7, #0x18]
	cmp r0, #0x3b
	bhi _08052420
	ldr r1, _08052414 @ =0x0203B400
	mov sb, r1
	ldr r1, _08052418 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805241C @ =0x000003FF
	mov r8, r1
	ands r0, r1
	ldr r1, _08052418 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x3c
	bl Mod
	str r0, [sp, #0x18]
	ldr r1, _08052418 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	ldr r1, _08052418 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x3c
	bl Mod
	b _0805242A
	.align 2, 0
_08052414: .4byte 0x0203B400
_08052418: .4byte 0x030046B8
_0805241C: .4byte 0x000003FF
_08052420:
	ldrb r0, [r7, #0x1f]
	str r0, [sp, #0x18]
	adds r0, r7, #0
	adds r0, #0x22
	ldrb r0, [r0]
_0805242A:
	str r0, [sp, #0x20]
	ldr r0, [r7, #0x18]
	cmp r0, #0x59
	bhi _0805247C
	ldr r1, _08052470 @ =0x0203B400
	mov sb, r1
	ldr r1, _08052474 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08052478 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	ldr r1, _08052474 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	mov sl, r0
	ldr r1, _08052474 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	ldr r1, _08052474 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x63
	bl Mod
	b _0805248A
	.align 2, 0
_08052470: .4byte 0x0203B400
_08052474: .4byte 0x030046B8
_08052478: .4byte 0x000003FF
_0805247C:
	adds r0, r7, #0
	adds r0, #0x20
	ldrb r0, [r0]
	mov sl, r0
	adds r0, r7, #0
	adds r0, #0x23
	ldrb r0, [r0]
_0805248A:
	str r0, [sp, #0x24]
	ldr r0, [r7, #0x18]
	cmp r0, #0x59
	bhi _080524A2
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _080524A2
	ldr r0, _080525B8 @ =0x000002A5
	bl PlaySound_082406e0
_080524A2:
	ldr r0, [sp, #0x14]
	cmp r0, #0x63
	ble _080524AC
	movs r1, #0x63
	str r1, [sp, #0x14]
_080524AC:
	ldr r0, [sp, #0x1c]
	cmp r0, #0x63
	ble _080524B6
	movs r1, #0x63
	str r1, [sp, #0x1c]
_080524B6:
	ldr r0, [sp, #0x18]
	cmp r0, #0x3b
	ble _080524C0
	movs r1, #0x3b
	str r1, [sp, #0x18]
_080524C0:
	ldr r0, [sp, #0x20]
	cmp r0, #0x3b
	ble _080524CA
	movs r1, #0x3b
	str r1, [sp, #0x20]
_080524CA:
	mov r0, sl
	cmp r0, #0x63
	ble _080524D4
	movs r1, #0x63
	mov sl, r1
_080524D4:
	ldr r0, [sp, #0x24]
	cmp r0, #0x63
	ble _080524DE
	movs r1, #0x63
	str r1, [sp, #0x24]
_080524DE:
	adds r0, r7, #0
	adds r0, #0xd0
	adds r5, r7, #0
	adds r5, #0x30
	movs r6, #0
	str r6, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #8
	mov sb, r1
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x14]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x18]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xd8
	mov r8, r1
	str r1, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	mov r2, sl
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xa8
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x1c]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	movs r1, #0xc0
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	movs r3, #2
	bl FUN_082376a4
	movs r1, #0x92
	lsls r1, r1, #3
	adds r0, r7, r1
	str r6, [sp]
	mov r1, r8
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r1, r5, #0
	ldr r2, [sp, #0x24]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r7, #0x18]
	cmp r0, #0x63
	bls _080525BC
	movs r0, #2
	strb r0, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r6, [r7, #0x18]
	b _080525C0
	.align 2, 0
_080525B8: .4byte 0x000002A5
_080525BC:
	adds r0, #1
	str r0, [r7, #0x18]
_080525C0:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
