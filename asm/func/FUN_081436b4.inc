	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _081436E8 @ =0x00000256
	adds r0, r7, r2
	ldrh r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081436EC
	adds r0, #4
	b _081436F8
	.align 2, 0
_081436E8: .4byte 0x00000256
_081436EC:
	ldr r0, _0814370C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081436F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08143710
	cmp r2, #2
	beq _08143714
	b _08143718
	.align 2, 0
_0814370C: .4byte 0x030046A4
_08143710:
	ldrb r0, [r5, #4]
	b _08143716
_08143714:
	ldrb r0, [r5]
_08143716:
	subs r1, r1, r0
_08143718:
	str r1, [sp, #0x14]
	ldr r3, _08143730 @ =0x0000046C
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x18]
	cmp r1, #0
	beq _08143734
	movs r0, #0
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	movs r0, #1
	b _08143736
	.align 2, 0
_08143730: .4byte 0x0000046C
_08143734:
	movs r0, #0
_08143736:
	cmp r0, #0
	bne _0814373C
	b _0814388C
_0814373C:
	ldr r6, _081437AC @ =0x000005A4
	adds r0, r7, r6
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _081437B0 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081437B4 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _081437B8 @ =0x00000553
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x2c
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
	ldr r0, _081437BC @ =0x0000066C
	add r0, sl
	ldrh r5, [r0]
	add r6, sp, #4
	ldr r2, _081437C0 @ =0x030046A4
	mov r8, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
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
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081437C4
	adds r0, #4
	b _081437D0
	.align 2, 0
_081437AC: .4byte 0x000005A4
_081437B0: .4byte 0x0000046D
_081437B4: .4byte 0x0000046B
_081437B8: .4byte 0x00000553
_081437BC: .4byte 0x0000066C
_081437C0: .4byte 0x030046A4
_081437C4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081437D0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r6, #2]
	mov r5, sb
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r6, _08143844 @ =0x0203B400
	mov r8, r6
	ldr r4, _08143848 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r2, _0814384C @ =0x000003FF
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0xff
	mov sb, r3
	ldrb r6, [r0]
	strb r6, [r7, #5]
	movs r5, #0xd6
	lsls r5, r5, #3
	add r5, sl
	str r1, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08143850 @ =0x05000002
	bl CpuSet
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0814384C @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r2, r0, #1
	ldr r1, _08143854 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08143858
	asrs r1, r0, #0xc
	b _0814385E
	.align 2, 0
_08143844: .4byte 0x0203B400
_08143848: .4byte 0x030046B8
_0814384C: .4byte 0x000003FF
_08143850: .4byte 0x05000002
_08143854: .4byte gSineTable
_08143858:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814385E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08143878 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0814387C
	asrs r0, r0, #0xc
	b _08143882
	.align 2, 0
_08143878: .4byte gSineTable
_0814387C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08143882:
	strh r0, [r5, #4]
	ldr r1, _081438EC @ =0x000006B2
	add r1, sl
	movs r0, #0xe
	strh r0, [r1]
_0814388C:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081438A2
	b _081439C2
_081438A2:
	add r3, sp, #0xc
	adds r4, r7, #0
	adds r4, #8
	movs r2, #0xd6
	lsls r2, r2, #3
	add r2, sl
	ldrh r1, [r7, #8]
	ldrh r6, [r2]
	adds r1, r1, r6
	strh r1, [r3]
	ldrh r0, [r4, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081438E6
	cmp r1, #0
	blt _081438E6
	ldr r0, _081438F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081438E6
	ldr r0, _081438F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081438F8
_081438E6:
	movs r1, #0
	b _08143906
	.align 2, 0
_081438EC: .4byte 0x000006B2
_081438F0: .4byte 0x030046A8
_081438F4: .4byte 0x030046AC
_081438F8:
	ldr r0, _08143998 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08143906:
	ldr r0, _0814399C @ =0x0000066C
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r1
	beq _08143920
	movs r0, #0xd6
	lsls r0, r0, #3
	add r0, sl
	movs r1, #0
	strh r1, [r0]
	ldr r0, _081439A0 @ =0x000006B4
	add r0, sl
	strh r1, [r0]
_08143920:
	movs r3, #0xd6
	lsls r3, r3, #3
	add r3, sl
	ldrh r0, [r3]
	ldrh r6, [r7, #0x10]
	adds r0, r0, r6
	movs r4, #0
	movs r5, #0
	strh r0, [r7, #0x10]
	ldr r0, _081439A0 @ =0x000006B4
	add r0, sl
	ldrh r0, [r0]
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r1, _081439A4 @ =0x000006B2
	add r1, sl
	ldrh r0, [r1]
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r6, [sp, #0x14]
	cmp r6, r0
	blt _081439B8
	strh r6, [r7, #0xa]
	mov r1, sp
	ldrh r1, [r1, #0x14]
	strh r1, [r2]
	str r5, [sp]
	mov r0, sp
	adds r1, r3, #0
	ldr r2, _081439A8 @ =0x05000002
	bl CpuSet
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081439AC @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _081439B0 @ =0x0000046A
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _081439B4 @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	movs r0, #1
	ldr r2, [sp, #0x18]
	strb r0, [r2]
	b _081439C2
	.align 2, 0
_08143998: .4byte 0x030046A4
_0814399C: .4byte 0x0000066C
_081439A0: .4byte 0x000006B4
_081439A4: .4byte 0x000006B2
_081439A8: .4byte 0x05000002
_081439AC: .4byte 0x00000469
_081439B0: .4byte 0x0000046A
_081439B4: .4byte 0x00000484
_081439B8:
	ldr r3, _081439D4 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081439C2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081439D4: .4byte 0x00000484
