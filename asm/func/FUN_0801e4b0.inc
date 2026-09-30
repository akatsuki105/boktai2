	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r2, #0xea
	lsls r2, r2, #1
	add r2, sl
	mov r1, sl
	adds r1, #0x8c
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	ldrb r0, [r2, #5]
	mov r1, sl
	strh r0, [r1, #0x34]
	adds r1, r0, #0
	subs r1, #0x14
	mov r2, sl
	strh r1, [r2, #0x30]
	adds r0, #0x14
	strh r0, [r2, #0x32]
	cmp r1, #0
	bge _0801E4EA
	movs r0, #0
	strh r0, [r2, #0x30]
	b _0801E4F4
_0801E4EA:
	cmp r1, #0xb0
	ble _0801E4F4
	movs r0, #0xb0
	mov r1, sl
	strh r0, [r1, #0x30]
_0801E4F4:
	mov r2, sl
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _0801E502
	movs r0, #0
	b _0801E50A
_0801E502:
	cmp r0, #0xb0
	ble _0801E50C
	movs r0, #0xb0
	mov r2, sl
_0801E50A:
	strh r0, [r2, #0x32]
_0801E50C:
	movs r1, #0
	mov r0, sl
	strh r1, [r0, #0x36]
	movs r7, #0xfc
	lsls r7, r7, #1
	add r7, sl
	strh r1, [r7, #0x20]
	mov r5, sl
	adds r5, #0xb0
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #0
	bl MainSprite_SetPose
	movs r2, #2
	mov r8, r2
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #1
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0x96
	lsls r7, r7, #2
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #3
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	mov r2, r8
	strb r2, [r7, #0x1a]
	movs r7, #0xae
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x30]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	movs r3, #0
	bl MainSprite_SetPose
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xc6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x32]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #2
	movs r3, #0
	bl MainSprite_SetPose
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xde
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x34]
	strh r0, [r7, #0x20]
	movs r2, #6
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #0
	bl MainSprite_SetPose
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0xf6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x36]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #9
	movs r3, #0
	bl MainSprite_SetPose
	movs r2, #3
	mov sb, r2
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	ldr r0, _0801E694 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801E698 @ =0x000053E0
	adds r0, r0, r1
	movs r4, #0xe7
	lsls r4, r4, #3
	add r4, sl
	ldr r2, _0801E69C @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	movs r7, #0x87
	lsls r7, r7, #3
	add r7, sl
	movs r2, #0
	strh r2, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl MainSprite_SetPose
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x93
	lsls r7, r7, #3
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	movs r2, #0
	str r2, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x9f
	lsls r7, r7, #3
	add r7, sl
	movs r6, #0x20
	movs r1, #0
	mov r8, r1
	movs r4, #4
_0801E65A:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r6, [r7, #0x22]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0x16
	movs r3, #0
	bl MainSprite_SetPose
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r6, #8
	cmp r4, #0
	bge _0801E65A
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E694: .4byte 0x03003584
_0801E698: .4byte 0x000053E0
_0801E69C: .4byte 0x04000008
