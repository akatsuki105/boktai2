	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _0814B0D4 @ =0x00000256
	add r1, sb
	str r1, [sp, #0x14]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x1c]
	str r2, [sp, #0x18]
	ldr r0, _0814B0D8 @ =0x030046A4
	mov sl, r0
_0814B0C0:
	ldr r1, [sp, #0x14]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814B0DC
	adds r0, #4
	b _0814B0E8
	.align 2, 0
_0814B0D4: .4byte 0x00000256
_0814B0D8: .4byte 0x030046A4
_0814B0DC:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B0E8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814B0FC
	cmp r3, #2
	beq _0814B102
	b _0814B108
_0814B0FC:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _0814B106
_0814B102:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_0814B106:
	subs r2, r2, r0
_0814B108:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814B11A
	adds r0, #4
	b _0814B126
_0814B11A:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B126:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0814B138
	asrs r0, r0, #6
	b _0814B13E
_0814B138:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814B13E:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0814B17C
	cmp r1, #1
	bgt _0814B150
	cmp r1, #0
	beq _0814B15A
	b _0814B230
_0814B150:
	cmp r1, #2
	beq _0814B1B8
	cmp r1, #3
	beq _0814B1DA
	b _0814B230
_0814B15A:
	adds r4, r6, #1
	movs r5, #0
_0814B15E:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B178
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0814B15E
_0814B178:
	subs r5, r4, #1
	b _0814B234
_0814B17C:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_0814B18A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B214
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _0814B18A
	ldr r2, _0814B1B4 @ =0x030046A4
	b _0814B216
	.align 2, 0
_0814B1B4: .4byte 0x030046A4
_0814B1B8:
	subs r4, r6, #1
	movs r5, #0
_0814B1BC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B1D6
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0814B1BC
_0814B1D6:
	adds r5, r4, #1
	b _0814B234
_0814B1DA:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_0814B1E8:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B222
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _0814B1E8
	ldr r2, _0814B210 @ =0x030046A4
	b _0814B224
	.align 2, 0
_0814B210: .4byte 0x030046A4
_0814B214:
	mov r2, sl
_0814B216:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0814B234
_0814B222:
	mov r2, sl
_0814B224:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _0814B234
_0814B230:
	ldr r2, [sp, #0x14]
	ldrh r5, [r2]
_0814B234:
	ldr r0, [sp, #0x14]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0814B270
	ldr r1, [sp, #0xc]
	ldr r2, _0814B258 @ =0x000006D6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0814B25C
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	b _0814B264
	.align 2, 0
_0814B258: .4byte 0x000006D6
_0814B25C:
	mov r2, sb
	ldrb r0, [r2, #5]
	subs r0, #0x40
	strb r0, [r2, #5]
_0814B264:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _0814B270
	b _0814B0C0
_0814B270:
	ldr r2, _0814B294 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814B298 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0814B29C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0814B2A4
	ldr r2, [sp, #0xc]
	ldr r0, _0814B2A0 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #1
	b _0814B2AC
	.align 2, 0
_0814B294: .4byte 0x030046B8
_0814B298: .4byte 0x000003FF
_0814B29C: .4byte 0x0203B400
_0814B2A0: .4byte 0x000006D6
_0814B2A4:
	ldr r2, [sp, #0xc]
	ldr r0, _0814B2F4 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #0
_0814B2AC:
	strb r0, [r1]
	mov r1, sp
	ldrb r2, [r1, #8]
	mov r1, sb
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _0814B2F8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814B2FC
	adds r0, #4
	b _0814B306
	.align 2, 0
_0814B2F4: .4byte 0x000006D6
_0814B2F8: .4byte 0x030046A4
_0814B2FC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B306:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _0814B34C @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _0814B350
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814B350
	cmp r0, #2
	beq _0814B348
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814B348:
	movs r0, #1
	b _0814B360
	.align 2, 0
_0814B34C: .4byte 0x000004A4
_0814B350:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _0814B374 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814B360:
	cmp r0, #0
	beq _0814B37C
	ldr r2, [sp, #0xc]
	ldr r0, _0814B378 @ =0x000006D7
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b _0814B38A
	.align 2, 0
_0814B374: .4byte 0xFFFFFDFF
_0814B378: .4byte 0x000006D7
_0814B37C:
	ldr r0, _0814B39C @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_0814B38A:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814B39C: .4byte 0x000005C4
