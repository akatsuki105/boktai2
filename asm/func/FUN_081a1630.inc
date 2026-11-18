	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081A16B4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A1654
	movs r0, #0
	strb r0, [r1]
_081A1654:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A166A
	b _081A17A4
_081A166A:
	ldr r2, _081A16B8 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081A1676
	b _081A17A0
_081A1676:
	adds r0, r6, #0
	bl Ax_PickRandomPathNode
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _081A16AE
	cmp r1, #0
	blt _081A16AE
	ldr r0, _081A16BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A16AE
	ldr r0, _081A16C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A16C4
_081A16AE:
	movs r4, #0
	b _081A16D2
	.align 2, 0
_081A16B4: .4byte 0x0000046C
_081A16B8: .4byte 0x00000484
_081A16BC: .4byte 0x030046A8
_081A16C0: .4byte 0x030046AC
_081A16C4:
	ldr r0, _081A16E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081A16D2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A16E8
	adds r0, #4
	b _081A16F4
	.align 2, 0
_081A16E4: .4byte 0x030046A4
_081A16E8:
	ldr r0, _081A1708 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A16F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A170C
	cmp r2, #2
	beq _081A1710
	b _081A1714
	.align 2, 0
_081A1708: .4byte 0x030046A4
_081A170C:
	ldrb r0, [r7, #4]
	b _081A1712
_081A1710:
	ldrb r0, [r7]
_081A1712:
	subs r1, r1, r0
_081A1714:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl Ax_StartCurve
	adds r0, r6, #0
	bl Ax_StepCurve
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	mov r2, r8
	str r2, [r0]
	ldr r2, _081A1794 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _081A1798 @ =0x00000F0C
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _081A179C @ =0x05000002
	bl CpuSet
	b _081A17A4
	.align 2, 0
_081A1794: .4byte 0x0000046C
_081A1798: .4byte 0x00000F0C
_081A179C: .4byte 0x05000002
_081A17A0:
	adds r0, #1
	str r0, [r1]
_081A17A4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
