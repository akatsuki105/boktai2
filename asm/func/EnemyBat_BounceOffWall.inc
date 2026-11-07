	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08140B80
	cmp r1, #0
	blt _08140B80
	ldr r0, _08140B84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08140B80
	ldr r0, _08140B88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08140B8C
_08140B80:
	movs r4, #0
	b _08140B9A
	.align 2, 0
_08140B84: .4byte 0x030046A8
_08140B88: .4byte 0x030046AC
_08140B8C:
	ldr r0, _08140BAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08140B9A:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08140BB0
	adds r0, #4
	b _08140BBC
	.align 2, 0
_08140BAC: .4byte 0x030046A4
_08140BB0:
	ldr r0, _08140BD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08140BBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08140BD4
	cmp r2, #2
	beq _08140BD8
	b _08140BDC
	.align 2, 0
_08140BD0: .4byte 0x030046A4
_08140BD4:
	ldrb r0, [r6, #4]
	b _08140BDA
_08140BD8:
	ldrb r0, [r6]
_08140BDA:
	subs r1, r1, r0
_08140BDC:
	ldr r2, _08140C10 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _08140C06
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	movs r2, #0
	strh r0, [r1]
	adds r3, #4
	adds r1, r5, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r2, [r5, #0x10]
	strh r2, [r5, #0x14]
_08140C06:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140C10: .4byte 0x00000472
