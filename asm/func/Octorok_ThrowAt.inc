	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldrh r1, [r1, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _081EA670 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sl
	ldrh r1, [r0, #0xc]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r6, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _081EA674 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081EA678 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	adds r4, #0x1e
	adds r0, r6, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl Div
	ldr r1, [r5]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _081EA680 @ =0x0000FFFF
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x30
	ble _081EA60A
	adds r0, r7, #0
	ands r0, r2
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA60A:
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081EA622
	ldr r0, [sp, #0xc]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA622:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0x30
	ble _081EA634
	ldr r0, [sp, #0x10]
	ands r0, r7
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA634:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _081EA646
	ldr r0, [sp, #0x10]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA646:
	ldr r2, [sp, #0x18]
	str r2, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	mov r0, sb
	mov r1, sl
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	bl Octorok_Spawn
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA670: .4byte 0xFFFF0000
_081EA674: .4byte 0x030046B8
_081EA678: .4byte 0x000003FF
_081EA67C: .4byte 0x0203B400
_081EA680: .4byte 0x0000FFFF
_081EA684: .4byte 0x0000FFD0
