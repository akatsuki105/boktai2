	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	ble _081D6BA0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D6BA0
	ldr r1, _081D6BB0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r7, sp
	str r7, [r0, #4]
	mov sl, r0
	cmp r2, #0
	ble _081D6BA0
	ldr r0, _081D6BB4 @ =0x0203B400
	mov r8, r0
	ldr r1, _081D6BB8 @ =0x030046B8
	mov sb, r1
	ldr r3, _081D6BBC @ =0x000003FF
	adds r6, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r5, r4, r2
_081D6B32:
	mov r7, sb
	ldr r1, [r7]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1c
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1e
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r1, #1
	ands r1, r3
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	subs r0, #0x40
	ands r1, r7
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	str r0, [sp, #0xc]
	adds r7, #0xb9
	adds r0, r4, r7
	ldrh r0, [r0]
	mov r1, sl
	str r3, [sp, #0x18]
	bl Script_ExecById
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	subs r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #0
	bne _081D6B32
_081D6BA0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6BB0: .4byte 0xFFFF0000
_081D6BB4: .4byte 0x0203B400
_081D6BB8: .4byte 0x030046B8
_081D6BBC: .4byte 0x000003FF
