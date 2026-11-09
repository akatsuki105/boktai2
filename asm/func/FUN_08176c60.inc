	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp, #8]
	ldr r2, _08176CA4 @ =0x00001012
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _08176C84
	b _08176DDC
_08176C84:
	mov sl, r7
	movs r2, #0
	str r2, [sp, #0xc]
	ldr r0, _08176CA8 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _08176CAC @ =0x00000755
	adds r1, r1, r7
	mov sb, r1
_08176C94:
	movs r1, #1
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08176CB0
	movs r0, #1
	b _08176CB2
	.align 2, 0
_08176CA4: .4byte 0x00001012
_08176CA8: .4byte 0x00000674
_08176CAC: .4byte 0x00000755
_08176CB0:
	movs r0, #0
_08176CB2:
	cmp r0, #0
	beq _08176CB8
	b _08176DB6
_08176CB8:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08176CDC
	cmp r1, #0
	blt _08176CDC
	ldr r0, _08176CE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08176CDC
	ldr r0, _08176CE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08176CE8
_08176CDC:
	movs r4, #0
	b _08176CF6
	.align 2, 0
_08176CE0: .4byte 0x030046A8
_08176CE4: .4byte 0x030046AC
_08176CE8:
	ldr r0, _08176D08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08176CF6:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08176D0C
	adds r0, #4
	b _08176D18
	.align 2, 0
_08176D08: .4byte 0x030046A4
_08176D0C:
	ldr r0, _08176D2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176D18:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08176D30
	cmp r3, #2
	beq _08176D34
	b _08176D38
	.align 2, 0
_08176D2C: .4byte 0x030046A4
_08176D30:
	ldrb r0, [r5, #4]
	b _08176D36
_08176D34:
	ldrb r0, [r5]
_08176D36:
	subs r2, r2, r0
_08176D38:
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _08176D80
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [sp, #0xc]
	adds r3, r0, r1
	ldr r1, [r3]
	movs r4, #1
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	bne _08176D76
	orrs r1, r4
	str r1, [r3]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp]
	str r1, [sp, #4]
	lsls r2, r2, #0x10
	ldr r1, _08176D7C @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	movs r1, #2
	bl FUN_08176530
_08176D76:
	movs r2, #1
	rsbs r2, r2, #0
	b _08176DB4
	.align 2, 0
_08176D7C: .4byte 0x0000FFFF
_08176D80:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [sp, #0xc]
	adds r3, r0, r1
	ldr r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08176DB2
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	ldr r0, _08176DEC @ =0x00000674
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	strh r2, [r0, #2]
	movs r1, #2
	bl FUN_08176530
_08176DB2:
	movs r2, #1
_08176DB4:
	add r8, r2
_08176DB6:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	adds r6, r6, r0
	add sb, r0
	ldr r2, [sp, #8]
	adds r2, #1
	str r2, [sp, #8]
	ldr r1, _08176DF0 @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #8]
	cmp r1, r0
	bge _08176DDC
	b _08176C94
_08176DDC:
	ldr r2, _08176DF0 @ =0x00001012
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _08176DF4
	movs r0, #1
	b _08176E02
	.align 2, 0
_08176DEC: .4byte 0x00000674
_08176DF0: .4byte 0x00001012
_08176DF4:
	mov r2, r8
	cmn r2, r0
	ble _08176DFE
	movs r0, #0
	b _08176E02
_08176DFE:
	movs r0, #1
	rsbs r0, r0, #0
_08176E02:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
