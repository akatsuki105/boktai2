	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0
	beq _08200BC2
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08200BC2
	adds r4, r7, #0
	adds r4, #0x28
	movs r5, #7
_08200BB2:
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_08200b48
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _08200BB2
_08200BC2:
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	mov sb, r0
	cmp r0, #0
	beq _08200BD4
	subs r0, #1
	strb r0, [r1]
	b _08200C72
_08200BD4:
	ldr r0, _08200C80 @ =0x000006EC
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	cmp r0, #0
	ble _08200C72
	bl FUN_081fa608
	add r2, sp, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r7, r1
	adds r4, r7, #0
	adds r4, #0x44
	ldrh r0, [r3]
	ldrh r5, [r4]
	subs r0, r0, r5
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r6, [r4, #2]
	subs r0, r0, r6
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r3, [r4, #4]
	subs r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r1]
	ldrh r0, [r2, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r2, #4]
	adds r0, r1, #0
	ldrh r0, [r0]
	adds r5, r5, r0
	adds r0, r1, #0
	strh r5, [r0]
	ldrh r0, [r2, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	adds r3, r3, r0
	strh r3, [r2, #4]
	ldr r4, _08200C84 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _08200C88 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	ldr r1, [r3]
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	add r3, sp, #8
	bl FUN_0805fe7c
	mov r0, sb
	mov r1, r8
	str r0, [r1]
_08200C72:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200C80: .4byte 0x000006EC
_08200C84: .4byte 0xFFFF0000
_08200C88: .4byte 0x0000FFFF
