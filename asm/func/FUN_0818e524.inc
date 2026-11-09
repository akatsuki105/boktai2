	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	cmp r1, #1
	beq _0818E558
	cmp r1, #1
	bgt _0818E540
	cmp r1, #0
	beq _0818E54A
	b _0818E5A0
_0818E540:
	cmp r1, #2
	beq _0818E574
	cmp r1, #3
	beq _0818E584
	b _0818E5A0
_0818E54A:
	ldr r1, _0818E554 @ =0x00000256
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r5, r0, #1
	b _0818E5A6
	.align 2, 0
_0818E554: .4byte 0x00000256
_0818E558:
	ldr r2, _0818E56C @ =0x00000256
	adds r1, r6, r2
	ldr r0, _0818E570 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r5, r0, r1
	b _0818E5A6
	.align 2, 0
_0818E56C: .4byte 0x00000256
_0818E570: .4byte 0x030046A4
_0818E574:
	ldr r1, _0818E580 @ =0x00000256
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r5, r0, #1
	b _0818E5A6
	.align 2, 0
_0818E580: .4byte 0x00000256
_0818E584:
	ldr r2, _0818E598 @ =0x00000256
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r0, _0818E59C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r1, r0
	b _0818E5A6
	.align 2, 0
_0818E598: .4byte 0x00000256
_0818E59C: .4byte 0x030046A4
_0818E5A0:
	ldr r1, _0818E5D0 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
_0818E5A6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldr r2, _0818E5D0 @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	movs r1, #1
	bl Map_FindTileOverride
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E5D8
	adds r0, #4
	ldr r1, _0818E5D4 @ =0x030046A4
	mov r8, r1
	b _0818E5E6
	.align 2, 0
_0818E5D0: .4byte 0x00000256
_0818E5D4: .4byte 0x030046A4
_0818E5D8:
	ldr r2, _0818E628 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov r8, r2
_0818E5E6:
	ldrh r7, [r0, #2]
	mov sl, sp
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E62C
	adds r0, #4
	b _0818E638
	.align 2, 0
_0818E628: .4byte 0x030046A4
_0818E62C:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E638:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, sl
	strh r1, [r2, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r2, #4]
	mov r4, sp
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818E65E
	adds r0, #4
	b _0818E66A
_0818E65E:
	ldr r0, _0818E680 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818E66A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818E684
	cmp r2, #2
	beq _0818E688
	b _0818E68C
	.align 2, 0
_0818E680: .4byte 0x030046A4
_0818E684:
	ldrb r0, [r4, #4]
	b _0818E68A
_0818E688:
	ldrb r0, [r4]
_0818E68A:
	subs r1, r1, r0
_0818E68C:
	ldr r2, _0818E6B4 @ =0x00000472
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _0818E6AC
	cmp r1, #0
	beq _0818E6B8
	adds r0, r1, #0
	cmp r0, #0
	bge _0818E6A8
	rsbs r0, r0, #0
_0818E6A8:
	cmp r0, #0xfe
	ble _0818E6B8
_0818E6AC:
	movs r0, #1
	rsbs r0, r0, #0
	b _0818E6BA
	.align 2, 0
_0818E6B4: .4byte 0x00000472
_0818E6B8:
	adds r0, r5, #0
_0818E6BA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
