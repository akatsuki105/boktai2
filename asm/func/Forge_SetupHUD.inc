	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrb r0, [r2, #2]
	cmp r0, #4
	bhi _0801D142
	lsls r0, r0, #2
	ldr r1, _0801D104 @ =_0801D108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D104: .4byte _0801D108
_0801D108: @ jump table
	.4byte _0801D11C @ case 0
	.4byte _0801D124 @ case 1
	.4byte _0801D12C @ case 2
	.4byte _0801D132 @ case 3
	.4byte _0801D13A @ case 4
_0801D11C:
	movs r3, #0x28
	movs r1, #8
	str r1, [sp, #4]
	b _0801D148
_0801D124:
	movs r3, #0x1e
	movs r4, #7
	str r4, [sp, #4]
	b _0801D148
_0801D12C:
	movs r3, #0x14
	movs r0, #6
	b _0801D146
_0801D132:
	movs r3, #0xa
	movs r1, #5
	str r1, [sp, #4]
	b _0801D148
_0801D13A:
	movs r3, #0xa
	movs r4, #5
	str r4, [sp, #4]
	b _0801D148
_0801D142:
	movs r3, #0x28
	movs r0, #8
_0801D146:
	str r0, [sp, #4]
_0801D148:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0xe1
	lsls r0, r0, #3
	str r0, [r1]
	ldrb r0, [r2, #5]
	adds r2, r6, #0
	adds r2, #0x60
	strh r0, [r2]
	subs r0, r0, r3
	subs r1, #0x58
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, r0, r3
	adds r3, r6, #0
	adds r3, #0x5e
	strh r0, [r3]
	movs r4, #0
	ldrsh r0, [r1, r4]
	str r2, [sp, #0xc]
	mov r8, r1
	mov sb, r3
	cmp r0, #0
	bge _0801D17C
	movs r0, #0
	b _0801D184
_0801D17C:
	cmp r0, #0xb0
	ble _0801D186
	movs r0, #0xb0
	mov r1, r8
_0801D184:
	strh r0, [r1]
_0801D186:
	mov r2, sb
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bge _0801D196
	movs r0, #0
	strh r0, [r2]
	b _0801D1A0
_0801D196:
	cmp r0, #0xb0
	ble _0801D1A0
	movs r0, #0xb0
	mov r1, sb
	strh r0, [r1]
_0801D1A0:
	adds r2, r6, #0
	adds r2, #0x62
	str r2, [sp, #8]
	movs r4, #0
	strh r4, [r2]
	ldr r0, _0801D318 @ =0x00000E04
	adds r7, r6, r0
	strh r4, [r7, #0x20]
	movs r1, #0xd8
	adds r1, r1, r6
	mov sl, r1
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl MainSprite_SetPose
	strb r4, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	ldr r0, _0801D31C @ =0x00000E64
	adds r7, r6, r0
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #3
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	strb r4, [r7, #0x1a]
	ldr r4, _0801D320 @ =0x00000EC4
	adds r7, r6, r4
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #2
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	ldr r2, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #9
	movs r3, #0
	bl MainSprite_SetPose
	movs r2, #1
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #8]
	ldr r0, _0801D324 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801D328 @ =0x000053E0
	adds r0, r0, r1
	ldr r2, _0801D32C @ =0x000012E4
	adds r4, r6, r2
	ldr r2, _0801D330 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	ldr r4, _0801D334 @ =0x00001044
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0xa
	movs r3, #0
	bl MainSprite_SetPose
	movs r1, #1
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	movs r1, #0
	str r1, [sp]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r5, #0x20
	mov r8, sl
	movs r0, #0
	mov sb, r0
	movs r4, #4
_0801D2D6:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r5, [r7, #0x22]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x16
	movs r3, #0
	bl MainSprite_SetPose
	mov r1, sb
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r5, #8
	cmp r4, #0
	bge _0801D2D6
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D318: .4byte 0x00000E04
_0801D31C: .4byte 0x00000E64
_0801D320: .4byte 0x00000EC4
_0801D324: .4byte 0x03003584
_0801D328: .4byte 0x000053E0
_0801D32C: .4byte 0x000012E4
_0801D330: .4byte 0x04000008
_0801D334: .4byte 0x00001044
