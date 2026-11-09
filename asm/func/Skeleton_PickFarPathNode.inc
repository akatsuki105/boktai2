	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	movs r0, #0
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r8, r2
	bge _08107858
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _081078C4 @ =0xFFFF0000
	mov sb, r3
_081077E0:
	bl Map_GetPathNodes
	lsls r1, r6, #3
	adds r0, r0, r1
	str r0, [r7, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r7, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r7, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	ldr r0, [sp, #0x28]
	cmp r4, r0
	blt _0810784E
	cmp r8, r4
	bge _0810784E
	mov r0, sl
	adds r1, r6, #0
	bl Skeleton_IsRecentNode
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0810784E
	str r6, [sp, #0x2c]
	mov r8, r4
_0810784E:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _081077E0
_08107858:
	mov r2, r8
	cmp r2, #0
	bne _0810787C
	ldr r2, _081078C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081078CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081078D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_0810787C:
	mov r0, sl
	ldr r1, [sp, #0x2c]
	bl Skeleton_PushRecentNode
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl Map_GetPathNodes
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r1, _081078D4 @ =0x00000472
	add r1, sl
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081078C4: .4byte 0xFFFF0000
_081078C8: .4byte 0x030046B8
_081078CC: .4byte 0x000003FF
_081078D0: .4byte 0x0203B400
_081078D4: .4byte 0x00000472
