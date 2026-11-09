	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08179AAE
	b _08179BF0
_08179AAE:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	bl Entity081f73ec_IsIdle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08179AC2
	b _08179BF0
_08179AC2:
	movs r2, #8
	ldrsh r0, [r5, r2]
	movs r3, #0xc
	ldrsh r1, [r5, r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r7, _08179B70 @ =0x0000021D
	adds r3, r5, r7
	ldrb r4, [r3]
	movs r3, #2
	orrs r3, r4
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge _08179AEE
	b _08179BF0
_08179AEE:
	adds r0, r5, #0
	bl FUN_080e8f20
	ldr r2, _08179B74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08179B78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08179B7C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08179B84
	movs r2, #0x81
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r7, #0x27
	adds r3, r5, r7
	ldr r3, [r3]
	subs r7, #0xc
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp]
	ldr r7, _08179B80 @ =0x00000F9C
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	adds r7, #4
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	mov r4, r8
	str r4, [sp, #0x14]
	adds r7, #0x12
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl Entity081f73ec_Spawn
	b _08179BE8
	.align 2, 0
_08179B70: .4byte 0x0000021D
_08179B74: .4byte 0x030046B8
_08179B78: .4byte 0x000003FF
_08179B7C: .4byte 0x0203B400
_08179B80: .4byte 0x00000F9C
_08179B84:
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r4, #0x91
	lsls r4, r4, #2
	adds r3, r5, r4
	ldr r3, [r3]
	movs r7, #0x8e
	lsls r7, r7, #2
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp]
	ldr r7, _08179BEC @ =0x00000F9E
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	adds r7, #4
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	adds r7, #0x10
	adds r4, r6, r7
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl Entity081f73ec_Spawn
_08179BE8:
	movs r0, #1
	b _08179BF2
	.align 2, 0
_08179BEC: .4byte 0x00000F9E
_08179BF0:
	movs r0, #0
_08179BF2:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
