	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	mov sl, r1
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x70]
	mov sb, r0
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081F0DF4 @ =0x05000002
	bl CpuSet
	cmp r5, r7
	bne _081F0DE0
	b _081F0FCE
_081F0DE0:
	ldr r6, _081F0DF8 @ =0x030046A4
_081F0DE2:
	adds r4, r5, #0
	mov r1, sb
	cmp r1, #1
	beq _081F0E0C
	cmp r1, #1
	bgt _081F0DFC
	cmp r1, #0
	beq _081F0E08
	b _081F0E26
	.align 2, 0
_081F0DF4: .4byte 0x05000002
_081F0DF8: .4byte 0x030046A4
_081F0DFC:
	mov r2, sb
	cmp r2, #2
	beq _081F0E18
	cmp r2, #3
	beq _081F0E1C
	b _081F0E26
_081F0E08:
	adds r5, #1
	b _081F0E26
_081F0E0C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	b _081F0E26
_081F0E18:
	subs r5, #1
	b _081F0E26
_081F0E1C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_081F0E26:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F0E36
	adds r0, #4
	b _081F0E40
_081F0E36:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0E40:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _081F0E4C
	movs r0, #1
	b _081F0FCE
_081F0E4C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F0E5C
	adds r0, #4
	b _081F0E66
_081F0E5C:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0E66:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	str r4, [sp, #0x4c]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r1, r0, #0
	cmp r1, #0
	beq _081F0E80
	adds r1, #4
	b _081F0E8A
_081F0E80:
	ldr r1, [r6]
	lsls r2, r5, #2
	adds r2, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r2
_081F0E8A:
	ldrb r2, [r1]
	movs r1, #0xf
	ands r1, r2
	ldr r2, [sp, #0x4c]
	cmp r2, r1
	blt _081F0E98
	b _081F0FC8
_081F0E98:
	add r6, sp, #0x44
	ldr r7, _081F0ED4 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r2, r6, #0
	cmp r0, #0
	beq _081F0ED8
	adds r0, #4
	b _081F0EE2
	.align 2, 0
_081F0ED4: .4byte 0x030046A4
_081F0ED8:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0EE2:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r0, sb
	cmp r0, #1
	beq _081F0F1C
	cmp r0, #1
	bgt _081F0F04
	cmp r0, #0
	beq _081F0F10
	b _081F0F3A
_081F0F04:
	mov r1, sb
	cmp r1, #2
	beq _081F0F28
	cmp r1, #3
	beq _081F0F32
	b _081F0F3A
_081F0F10:
	ldrh r0, [r2]
	subs r0, #0x80
	mov r2, sl
	strh r0, [r2]
	movs r0, #1
	b _081F0FCE
_081F0F1C:
	ldrh r0, [r2, #4]
	subs r0, #0x80
	mov r4, sl
	strh r0, [r4, #4]
	movs r0, #1
	b _081F0FCE
_081F0F28:
	ldrh r0, [r2]
	adds r0, #0x80
	mov r1, sl
	strh r0, [r1]
	b _081F0F3A
_081F0F32:
	ldrh r0, [r2, #4]
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
_081F0F3A:
	ldr r4, _081F0FB0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _081F0FB4 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r1, r0, #1
	ldr r2, _081F0FB8 @ =0x0203B400
	adds r1, r1, r2
	ldr r4, [sp, #0x4c]
	lsls r2, r4, #8
	ldrb r1, [r1]
	adds r2, r2, r1
	mov r1, sl
	strh r2, [r1, #2]
	adds r0, #1
	ands r0, r3
	ldr r2, _081F0FB0 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081F0FB8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x1e
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	movs r2, #1
	str r2, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	ldr r0, _081F0FBC @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, sl
	add r1, sp, #0x3c
	ldr r2, _081F0FC0 @ =0x00001C1A
	ldr r3, _081F0FC4 @ =0x0000D1B8
	bl Entity081f26bc_Spawn
	movs r0, #1
	b _081F0FCE
	.align 2, 0
_081F0FB0: .4byte 0x030046B8
_081F0FB4: .4byte 0x000003FF
_081F0FB8: .4byte 0x0203B400
_081F0FBC: .4byte 0x00200004
_081F0FC0: .4byte 0x00001C1A
_081F0FC4: .4byte 0x0000D1B8
_081F0FC8:
	cmp r5, r7
	beq _081F0FCE
	b _081F0DE2
_081F0FCE:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
