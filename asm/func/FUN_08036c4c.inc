	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08036C88 @ =0x0203B400
	mov r8, r0
	ldr r6, _08036C8C @ =0x030046B8
	ldr r0, [r6]
	adds r0, #1
	ldr r7, _08036C90 @ =0x000003FF
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	adds r0, r4, r0
	adds r4, r0, #1
	movs r0, #3
	ands r4, r0
	cmp r4, #1
	beq _08036CD4
	cmp r4, #1
	bgt _08036C94
	cmp r4, #0
	beq _08036C9E
	b _08036D66
	.align 2, 0
_08036C88: .4byte 0x0203B400
_08036C8C: .4byte 0x030046B8
_08036C90: .4byte 0x000003FF
_08036C94:
	cmp r4, #2
	beq _08036D14
	cmp r4, #3
	beq _08036D30
	b _08036D66
_08036C9E:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	lsls r0, r0, #8
	movs r4, #0x94
	lsls r4, r4, #5
	adds r2, r4, #0
	adds r0, r0, r2
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r3
	lsls r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r0, r0, r1
	b _08036D64
_08036CD4:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	ldr r4, _08036D10 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #8
	movs r4, #0xc4
	lsls r4, r4, #5
	adds r0, r4, #0
	subs r0, r0, r2
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	ldr r0, _08036D10 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r3
	lsls r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r0, r0, r1
	b _08036D64
	.align 2, 0
_08036D10: .4byte 0x0203B400
_08036D14:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	lsls r0, r0, #8
	movs r4, #0x94
	lsls r4, r4, #5
	adds r2, r4, #0
	adds r0, r0, r2
	b _08036D4A
_08036D30:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #8
	movs r4, #0xc4
	lsls r4, r4, #5
	adds r0, r4, #0
	subs r0, r0, r2
_08036D4A:
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ands r1, r3
	lsls r1, r1, #8
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r2, #0
	subs r0, r0, r1
_08036D64:
	strh r0, [r5, #4]
_08036D66:
	adds r0, r5, #0
	bl FUN_08036908
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08036D90
	cmp r1, #0
	blt _08036D90
	ldr r0, _08036D94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08036D90
	ldr r0, _08036D98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08036D9C
_08036D90:
	movs r4, #0
	b _08036DAA
	.align 2, 0
_08036D94: .4byte 0x030046A8
_08036D98: .4byte 0x030046AC
_08036D9C:
	ldr r0, _08036DBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08036DAA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08036DC0
	adds r0, #4
	b _08036DCC
	.align 2, 0
_08036DBC: .4byte 0x030046A4
_08036DC0:
	ldr r0, _08036DE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08036DCC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08036DE4
	cmp r2, #2
	beq _08036DE8
	b _08036DEC
	.align 2, 0
_08036DE0: .4byte 0x030046A4
_08036DE4:
	ldrb r0, [r5, #4]
	b _08036DEA
_08036DE8:
	ldrb r0, [r5]
_08036DEA:
	subs r1, r1, r0
_08036DEC:
	strh r1, [r5, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
