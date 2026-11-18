	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _081996E8 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp]
	movs r4, #0
	ldrsh r1, [r3, r4]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r4, r6, r7
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sl, r1
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	subs r7, #0x46
	adds r7, r7, r6
	mov r8, r7
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #8]
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r5, r6, r3
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x64
	ble _081996D8
	movs r7, #0xba
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, _081996EC @ =FUN_081996f0
	str r0, [r1]
	movs r0, #0
	str r0, [r4]
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	adds r3, #0xc
	adds r1, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, sl
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r7, #0x28
	adds r7, r7, r6
	mov sb, r7
	strh r0, [r7]
	ldr r0, [r2]
	adds r3, #2
	adds r1, r6, r3
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, r8
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r7, #0xa7
	lsls r7, r7, #1
	adds r7, r6, r7
	str r7, [sp, #0xc]
	strh r0, [r7]
	ldr r0, [r2]
	adds r3, #2
	adds r1, r6, r3
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r3, r6, r4
	strh r0, [r3]
	mov r7, sb
	ldrh r0, [r7]
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r4, #0x24
	adds r1, r6, r4
	strh r0, [r1]
	ldr r7, [sp, #0xc]
	ldrh r0, [r7]
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r0, r4
	movs r7, #0x97
	lsls r7, r7, #1
	adds r7, r7, r6
	mov ip, r7
	strh r0, [r7]
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r7, #0x98
	lsls r7, r7, #1
	adds r4, r6, r7
	strh r0, [r4]
	ldrh r0, [r6, #0x1c]
	mov r7, sl
	strh r0, [r7]
	ldrh r0, [r6, #0x1e]
	mov r7, r8
	strh r0, [r7]
	ldrh r0, [r6, #0x20]
	strh r0, [r5]
	ldrh r0, [r1]
	mov r6, sl
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r7, [sp]
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	mov r6, r8
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r7, [sp, #4]
	strh r0, [r7]
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0]
	mov r4, sb
	strh r0, [r4]
	ldr r0, [r2]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xc]
	strh r0, [r6]
	ldr r0, [r2]
	ldrh r0, [r0, #4]
	strh r0, [r3]
_081996D8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081996E8: .4byte 0x00000185
_081996EC: .4byte FUN_081996f0
