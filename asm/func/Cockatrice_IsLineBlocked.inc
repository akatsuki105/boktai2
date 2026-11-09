	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	mov r2, sp
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r0, #0x20
	asrs r6, r0, #6
	movs r0, #3
	ands r6, r0
	ldr r1, _0815B394 @ =0x00000256
	adds r0, r4, r1
	ldrh r3, [r0]
	ldr r2, _0815B398 @ =0x00000472
	adds r4, r4, r2
	ldrh r0, [r4]
	lsrs r0, r0, #8
	mov r8, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B390
	cmp r1, #0
	blt _0815B390
	ldr r0, _0815B39C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B390
	ldr r0, _0815B3A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B3A4
_0815B390:
	movs r0, #0
	b _0815B3B2
	.align 2, 0
_0815B394: .4byte 0x00000256
_0815B398: .4byte 0x00000472
_0815B39C: .4byte 0x030046A8
_0815B3A0: .4byte 0x030046AC
_0815B3A4:
	ldr r0, _0815B3E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0815B3B2:
	mov sb, r0
	mov r0, sb
	movs r1, #1
	str r3, [sp, #8]
	bl Map_FindTileOverride
	ldr r7, _0815B3E0 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r3, [sp, #8]
	cmp r6, #1
	beq _0815B444
	cmp r6, #1
	bgt _0815B3E4
	cmp r6, #0
	beq _0815B3EE
	b _0815B512
	.align 2, 0
_0815B3E0: .4byte 0x030046A4
_0815B3E4:
	cmp r6, #2
	beq _0815B484
	cmp r6, #3
	beq _0815B4D4
	b _0815B512
_0815B3EE:
	adds r4, r3, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _0815B406
	b _0815B512
_0815B406:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815B40C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B41C
	adds r0, #4
	b _0815B422
_0815B41C:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815B422:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0815B40C
	b _0815B512
_0815B444:
	adds r4, r3, r1
	cmp r5, r4
	ble _0815B512
	adds r6, r7, #0
_0815B44C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B45C
	adds r0, #4
	b _0815B466
_0815B45C:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B466:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	cmp r5, r4
	bgt _0815B44C
	b _0815B512
_0815B484:
	subs r4, r3, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	blt _0815B512
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815B498:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B4A8
	adds r0, #4
	b _0815B4B0
_0815B4A8:
	ldr r0, _0815B4CC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815B4B0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0815B498
	b _0815B512
	.align 2, 0
_0815B4CC: .4byte 0x030046A4
_0815B4D0:
	movs r0, #0
	b _0815B514
_0815B4D4:
	subs r4, r3, r1
	cmp r4, #0
	blt _0815B512
	adds r5, r7, #0
_0815B4DC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B4EC
	adds r0, #4
	b _0815B4F6
_0815B4EC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B4F6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r4, r0
	cmp r4, #0
	bge _0815B4DC
_0815B512:
	movs r0, #1
_0815B514:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
