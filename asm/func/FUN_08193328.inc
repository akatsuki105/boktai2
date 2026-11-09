	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x1c]
	mov r8, r1
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r4, sp, #0xc
	add r5, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r7, r0, #0
	ldr r2, _08193384 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	blt _08193388
	asrs r0, r0, #0xc
	b _0819338E
	.align 2, 0
_08193384: .4byte gSineTable
_08193388:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819338E:
	strh r0, [r4]
	ldr r0, _081933A8 @ =gSineTable
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081933AC
	asrs r0, r0, #0xc
	b _081933B2
	.align 2, 0
_081933A8: .4byte gSineTable
_081933AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081933B2:
	strh r0, [r4, #4]
	movs r3, #0
	str r3, [sp, #0x20]
	mov sl, r3
	add r6, sp, #0x14
	ldr r0, _081933F8 @ =0x030046A4
	mov sb, r0
_081933C0:
	ldrh r0, [r4]
	mov r1, sp
	ldrh r1, [r1, #0x14]
	adds r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r1, [r1, #4]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081933F4
	cmp r1, #0
	blt _081933F4
	ldr r0, _081933FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081933F4
	ldr r0, _08193400 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193404
_081933F4:
	movs r5, #0
	b _08193412
	.align 2, 0
_081933F8: .4byte 0x030046A4
_081933FC: .4byte 0x030046A8
_08193400: .4byte 0x030046AC
_08193404:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08193412:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08193422
	adds r0, #4
	b _0819342E
_08193422:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0819342E:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0819350E
	mov r2, sp
	ldrh r0, [r2, #0x14]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	asrs r7, r7, #7
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	bne _0819348C
	ldr r0, _08193470 @ =gSineTable
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #6
	adds r2, r0, #0
	cmp r1, #0
	blt _08193474
	asrs r0, r1, #0xc
	b _0819347A
	.align 2, 0
_08193470: .4byte gSineTable
_08193474:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819347A:
	strh r0, [r4]
	adds r0, r2, #0
	adds r0, #0x80
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	bge _081934C0
	b _081934C4
_0819348C:
	ldr r1, _081934A0 @ =0x085B0B88
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	ldr r2, _081934A4 @ =gSineTable
	cmp r0, #0
	blt _081934A8
	asrs r0, r0, #0xc
	b _081934AE
	.align 2, 0
_081934A0: .4byte 0x085B0B88
_081934A4: .4byte gSineTable
_081934A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081934AE:
	strh r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081934C4
_081934C0:
	asrs r0, r0, #0xc
	b _081934CA
_081934C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081934CA:
	strh r0, [r4, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sp
	ldrh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081934F2
	cmp r1, #0
	blt _081934F2
	ldr r0, _081934F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081934F2
	ldr r0, _081934FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193500
_081934F2:
	movs r5, #0
	b _0819350E
	.align 2, 0
_081934F8: .4byte 0x030046A8
_081934FC: .4byte 0x030046AC
_08193500:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0819350E:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08193596
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08193524
	adds r0, #4
	b _08193530
_08193524:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08193530:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081935C0
	ldr r6, _08193574 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, r8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08193578
	adds r0, #4
	b _08193582
	.align 2, 0
_08193574: .4byte 0x030046A4
_08193578:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08193582:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, r8
	strh r1, [r2, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r2, #4]
	b _08193626
_08193596:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081935A6
	adds r0, #4
	b _081935B2
_081935A6:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081935B2:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081935C0
	movs r0, #1
	str r0, [sp, #0x20]
_081935C0:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #0x7f
	bgt _081935CC
	b _081933C0
_081935CC:
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	ldr r2, _08193638 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819363C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08193640 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	mov r1, sp
	movs r2, #0
	strb r0, [r1, #2]
	mov r0, sp
	strb r2, [r0, #3]
	ldr r0, [sp, #4]
	bl Map_GetPathNodes
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	mov r2, r8
	strh r1, [r2]
	ldr r3, [sp, #0x1c]
	ldr r2, _08193644 @ =0x00000472
	adds r1, r3, r2
	ldrh r1, [r1]
	mov r3, r8
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
_08193626:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193638: .4byte 0x030046B8
_0819363C: .4byte 0x000003FF
_08193640: .4byte 0x0203B400
_08193644: .4byte 0x00000472
