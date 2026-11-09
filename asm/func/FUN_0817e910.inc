	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov r8, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	movs r0, #0x94
	lsls r0, r0, #2
	add r0, r8
	ldrb r1, [r0]
	mov r0, sp
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	movs r0, #0
	mov sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp sb, r2
	bge _0817EA06
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _0817E9C4 @ =0xFFFF0000
	mov sl, r3
_0817E952:
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
	mov r3, sl
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
	movs r0, #0
	ldrsh r3, [r5, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r5, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, r0
	ldr r1, [sp, #0x28]
	cmp r4, r1
	blt _0817E9FC
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	movs r1, #0xfe
	lsls r1, r1, #1
	add r1, r8
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0817E9CC
	ldr r2, _0817E9C8 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0817E9DA
	.align 2, 0
_0817E9C4: .4byte 0xFFFF0000
_0817E9C8: .4byte 0xFFFFFF00
_0817E9CC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817E9DA
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_0817E9DA:
	adds r0, r1, #0
	cmp r0, #0
	bge _0817E9E2
	rsbs r0, r0, #0
_0817E9E2:
	cmp r0, #0x3f
	ble _0817E9FC
	cmp sb, r4
	bge _0817E9FC
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0817e8dc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817E9FC
	str r6, [sp, #0x2c]
	mov sb, r4
_0817E9FC:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _0817E952
_0817EA06:
	mov r2, sb
	cmp r2, #0
	bne _0817EA2A
	ldr r2, _0817EA74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817EA78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0817EA7C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_0817EA2A:
	mov r0, r8
	ldr r1, [sp, #0x2c]
	bl FUN_0817e8a8
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
	ldr r1, _0817EA80 @ =0x00000472
	add r1, r8
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
_0817EA74: .4byte 0x030046B8
_0817EA78: .4byte 0x000003FF
_0817EA7C: .4byte 0x0203B400
_0817EA80: .4byte 0x00000472
