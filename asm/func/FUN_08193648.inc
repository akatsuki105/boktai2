	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x1c]
	mov sb, r1
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
	ldr r2, _081936A8 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	adds r3, r4, #0
	cmp r0, #0
	blt _081936AC
	asrs r0, r0, #0xc
	b _081936B2
	.align 2, 0
_081936A8: .4byte gSineTable
_081936AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081936B2:
	strh r0, [r3]
	ldr r0, _081936CC @ =gSineTable
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081936D0
	asrs r0, r0, #0xc
	b _081936D6
	.align 2, 0
_081936CC: .4byte gSineTable
_081936D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081936D6:
	strh r0, [r3, #4]
	ldr r1, [sp, #0x1c]
	ldr r2, _08193724 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r5, #0
	add r6, sp, #0x14
	ldr r0, _08193728 @ =0x085B0B08
	mov sl, r0
_081936EA:
	ldrh r0, [r3]
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
	blt _0819371E
	cmp r1, #0
	blt _0819371E
	ldr r0, _0819372C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819371E
	ldr r0, _08193730 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193734
_0819371E:
	movs r4, #0
	b _08193742
	.align 2, 0
_08193724: .4byte 0x00000256
_08193728: .4byte 0x085B0B08
_0819372C: .4byte 0x030046A8
_08193730: .4byte 0x030046AC
_08193734:
	ldr r0, _08193758 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08193742:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x20]
	bl Map_FindTileOverride
	ldr r3, [sp, #0x20]
	cmp r0, #0
	beq _0819375C
	adds r0, #4
	b _08193768
	.align 2, 0
_08193758: .4byte 0x030046A4
_0819375C:
	ldr r0, _081937A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08193768:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0819383A
	mov r1, sp
	ldrh r0, [r1, #0x14]
	ldrh r1, [r3]
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
	bne _081937C4
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #6
	ldr r1, _081937A8 @ =gSineTable
	cmp r0, #0
	blt _081937AC
	asrs r0, r0, #0xc
	b _081937B2
	.align 2, 0
_081937A4: .4byte 0x030046A4
_081937A8: .4byte gSineTable
_081937AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937B2:
	strh r0, [r3]
	adds r0, r1, #0
	adds r0, #0x80
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	bge _081937EC
	b _081937F0
_081937C4:
	ldr r1, _081937D4 @ =0x085B0B88
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081937D8
	asrs r0, r0, #0xc
	b _081937DE
	.align 2, 0
_081937D4: .4byte 0x085B0B88
_081937D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937DE:
	strh r0, [r3]
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081937F0
_081937EC:
	asrs r0, r0, #0xc
	b _081937F6
_081937F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937F6:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0819381E
	cmp r1, #0
	blt _0819381E
	ldr r0, _08193824 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819381E
	ldr r0, _08193828 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819382C
_0819381E:
	movs r4, #0
	b _0819383A
	.align 2, 0
_08193824: .4byte 0x030046A8
_08193828: .4byte 0x030046AC
_0819382C:
	ldr r0, _08193850 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819383A:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x20]
	bl Map_FindTileOverride
	ldr r3, [sp, #0x20]
	cmp r0, #0
	beq _08193854
	adds r0, #4
	b _08193860
	.align 2, 0
_08193850: .4byte 0x030046A4
_08193854:
	ldr r0, _081938A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08193860:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081938C6
	ldr r5, _081938A4 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	mov r0, r8
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	mov r0, r8
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sb
	strh r4, [r0]
	mov r0, r8
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081938A8
	adds r0, #4
	b _081938B4
	.align 2, 0
_081938A4: .4byte 0x030046A4
_081938A8:
	ldr r0, [r5]
	mov r2, r8
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081938B4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sb
	strh r1, [r3, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	b _08193928
_081938C6:
	mov r8, r4
	adds r5, #1
	cmp r5, #0x7f
	bgt _081938D0
	b _081936EA
_081938D0:
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	ldr r2, _0819393C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08193940 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08193944 @ =0x0203B400
	adds r0, r0, r1
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
	mov r2, sb
	strh r1, [r2]
	ldr r3, [sp, #0x1c]
	ldr r2, _08193948 @ =0x00000472
	adds r1, r3, r2
	ldrh r1, [r1]
	mov r3, sb
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
_08193928:
	strh r0, [r3, #4]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819393C: .4byte 0x030046B8
_08193940: .4byte 0x000003FF
_08193944: .4byte 0x0203B400
_08193948: .4byte 0x00000472
