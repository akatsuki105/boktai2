	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	ldr r2, _08193C08 @ =0x7FFFFFFF
	mov r8, r2
	ldr r3, [sp, #0x50]
	cmp r3, #0
	bne _08193B88
	movs r0, #0
	mov r8, r0
_08193B88:
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r6, r2
	bge _08193C34
	add r3, sp, #0xc
	mov sb, r3
	add r5, sp, #0x18
_08193B9E:
	bl Map_GetPathNodes
	lsls r1, r6, #3
	adds r0, r0, r1
	mov r1, sb
	str r0, [r1, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	ldr r2, _08193C0C @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r3, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	cmp r4, #0
	beq _08193C2A
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _08193C10
	cmp r4, sl
	bgt _08193C2A
	cmp r8, r4
	bge _08193C2A
	b _08193C18
	.align 2, 0
_08193C08: .4byte 0x7FFFFFFF
_08193C0C: .4byte 0xFFFF0000
_08193C10:
	cmp r4, sl
	blt _08193C2A
	cmp r8, r4
	ble _08193C2A
_08193C18:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08193a2c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08193C2A
	str r6, [sp, #0x2c]
	mov r8, r4
_08193C2A:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _08193B9E
_08193C34:
	mov r2, r8
	cmp r2, #0
	bne _08193C58
	ldr r3, [sp, #0x28]
	ldr r0, _08193C50 @ =0x00000F8C
	adds r1, r3, r0
	ldr r0, _08193C54 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	bl FUN_08193328
	b _08193C90
	.align 2, 0
_08193C50: .4byte 0x00000F8C
_08193C54: .4byte 0x03002BE0
_08193C58:
	adds r0, r7, #0
	ldr r1, [sp, #0x2c]
	bl FUN_081939f8
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
	ldr r2, _08193CA0 @ =0x00000472
	adds r1, r7, r2
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
_08193C90:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193CA0: .4byte 0x00000472
