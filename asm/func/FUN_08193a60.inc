	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	mov r8, r1
	mov sl, r2
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	ldr r2, _08193B44 @ =0x7FFFFFFF
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	movs r5, #0
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r5, r1
	bge _08193AFC
	add r6, sp, #0xc
	add r4, sp, #0x18
	ldr r7, _08193B48 @ =0xFFFF0000
_08193A96:
	str r2, [sp, #0x24]
	bl Map_GetPathNodes
	lsls r1, r5, #3
	adds r0, r0, r1
	str r0, [r6, #8]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r6, #8]
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r6, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r4, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r2, [sp, #0x24]
	cmp r2, r1
	ble _08193AF2
	mov sb, r5
	adds r2, r1, #0
_08193AF2:
	adds r5, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r5, r1
	blt _08193A96
_08193AFC:
	ldr r0, _08193B44 @ =0x7FFFFFFF
	cmp r2, r0
	beq _08193B34
	mov r0, sp
	movs r1, #0
	mov r2, sb
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
	mov r3, r8
	strh r1, [r3]
	ldr r2, [sp, #0x20]
	ldr r3, _08193B4C @ =0x00000472
	adds r1, r2, r3
	ldrh r1, [r1]
	mov r2, r8
	strh r1, [r2, #2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
_08193B34:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193B44: .4byte 0x7FFFFFFF
_08193B48: .4byte 0xFFFF0000
_08193B4C: .4byte 0x00000472
