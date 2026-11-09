	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #0x18]
	mov r8, r1
	str r2, [sp, #0x1c]
	str r3, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r2, [sp, #0x18]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r3, #0
	mov sl, r3
	ldr r4, _08177D88 @ =0x00001012
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08177E66
	ldr r2, _08177D8C @ =0x00000764
	adds r7, r6, r2
	str r3, [sp, #0x24]
	ldr r4, _08177D90 @ =0x00000755
	adds r4, r4, r6
	mov sb, r4
_08177D78:
	movs r1, #2
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08177D94
	movs r0, #1
	b _08177D96
	.align 2, 0
_08177D88: .4byte 0x00001012
_08177D8C: .4byte 0x00000764
_08177D90: .4byte 0x00000755
_08177D94:
	movs r0, #0
_08177D96:
	cmp r0, #0
	beq _08177E48
	movs r1, #1
	mov r3, sb
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08177DAA
	movs r0, #1
	b _08177DAC
_08177DAA:
	movs r0, #0
_08177DAC:
	cmp r0, #0
	bne _08177E48
	mov r5, sp
	ldr r4, [sp, #0x24]
	adds r2, r4, r6
	ldr r3, _08177EA4 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r7]
	ldrh r0, [r2]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x20]
	cmp r1, r0
	ble _08177E48
	mov r1, r8
	cmp r1, #1
	bge _08177E06
	movs r4, #1
	mov r8, r4
_08177E06:
	adds r0, r2, #0
	mov r1, r8
	str r3, [sp, #0x28]
	bl Div
	ldr r1, [sp, #0x24]
	adds r4, r6, r1
	ldr r3, [sp, #0x28]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	mov r1, r8
	bl Div
	ldr r3, _08177EA8 @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	mov r1, r8
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_08177E48:
	movs r3, #0x92
	lsls r3, r3, #1
	adds r7, r7, r3
	ldr r4, [sp, #0x24]
	adds r4, r4, r3
	str r4, [sp, #0x24]
	add sb, r3
	movs r0, #1
	add sl, r0
	ldr r1, _08177EAC @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sl, r0
	blt _08177D78
_08177E66:
	ldr r3, [sp, #0x18]
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r4, #0
	mov sl, r4
	ldr r1, _08177EAC @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sl, r0
	bge _08177F5A
	add r7, sp, #0x10
	mov sb, r4
	ldr r3, _08177EB0 @ =0x00000755
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r5, r6, r4
_08177E92:
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08177EB4
	movs r0, #1
	b _08177EB6
	.align 2, 0
_08177EA4: .4byte 0x00000674
_08177EA8: .4byte 0x00000676
_08177EAC: .4byte 0x00001012
_08177EB0: .4byte 0x00000755
_08177EB4:
	movs r0, #0
_08177EB6:
	cmp r0, #0
	bne _08177F40
	add r4, sp, #8
	mov r3, sb
	adds r2, r3, r6
	ldr r0, _08177F70 @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r7]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r2, [r4, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08177F74 @ =0x000031B4
	cmp r1, r0
	ble _08177F30
	adds r0, r2, #0
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldr r1, [sp, #0x1c]
	bl Div
	ldrh r1, [r5, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
_08177F30:
	mov r3, sb
	adds r0, r6, r3
	ldr r4, _08177F70 @ =0x00000674
	adds r0, r0, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
_08177F40:
	movs r0, #0x92
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r5, r5, r0
	movs r1, #1
	add sl, r1
	ldr r2, _08177F78 @ =0x00001012
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sl, r0
	blt _08177E92
_08177F5A:
	ldr r0, [sp, #0x18]
	bl FUN_081775f8
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177F70: .4byte 0x00000674
_08177F74: .4byte 0x000031B4
_08177F78: .4byte 0x00001012
