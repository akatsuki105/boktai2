	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x48
	ldr r3, _081FC8E8 @ =0x00000808
	adds r0, r6, r3
	adds r5, r6, #0
	adds r5, #0x50
	ldr r3, [r6, #0x50]
	ldr r4, [r6, #0x54]
	str r3, [r0]
	str r4, [r0, #4]
	ldr r0, _081FC8EC @ =0x00000806
	adds r3, r6, r0
	strb r1, [r3]
	ldr r1, _081FC8F0 @ =0x00000807
	adds r0, r6, r1
	strb r2, [r0]
	ldrb r1, [r3]
	ldrb r2, [r0]
	adds r0, r5, #0
	bl Map_GetPathNodePos
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FC8E4
	cmp r1, #0
	blt _081FC8E4
	ldr r0, _081FC8F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FC8E4
	ldr r0, _081FC8F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FC8FC
_081FC8E4:
	movs r4, #0
	b _081FC90A
	.align 2, 0
_081FC8E8: .4byte 0x00000808
_081FC8EC: .4byte 0x00000806
_081FC8F0: .4byte 0x00000807
_081FC8F4: .4byte 0x030046A8
_081FC8F8: .4byte 0x030046AC
_081FC8FC:
	ldr r0, _081FC91C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FC90A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FC920
	adds r0, #4
	b _081FC92C
	.align 2, 0
_081FC91C: .4byte 0x030046A4
_081FC920:
	ldr r0, _081FC968 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FC92C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r3, #0
	strh r0, [r5, #2]
	mov r2, sp
	movs r1, #0xf0
	lsls r1, r1, #3
	mov r0, sp
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FC962
	ldr r0, _081FC96C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FC962
	ldr r0, _081FC970 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FC974
_081FC962:
	movs r4, #0
	b _081FC97C
	.align 2, 0
_081FC968: .4byte 0x030046A4
_081FC96C: .4byte 0x030046A8
_081FC970: .4byte 0x030046AC
_081FC974:
	ldr r0, _081FC98C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FC97C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FC990
	adds r0, #4
	b _081FC99C
	.align 2, 0
_081FC98C: .4byte 0x030046A4
_081FC990:
	ldr r0, _081FC9FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FC99C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sp
	strh r0, [r1, #2]
	mov r2, sp
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0xc
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FC9FC: .4byte 0x030046A4
