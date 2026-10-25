	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _0800F258 @ =0x000002DA
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r5, r2
	bge _0800F19E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r7, r4, r3
	adds r6, r4, #0
	adds r6, #0x54
	mov ip, r5
	adds r3, r0, #0
_0800F184:
	lsls r2, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r6, r2
	mov r0, ip
	strh r0, [r2]
	adds r5, #1
	ldrh r1, [r3]
	cmp r5, r1
	blt _0800F184
_0800F19E:
	ldr r2, _0800F258 @ =0x000002DA
	adds r0, r4, r2
	ldrh r5, [r0]
	movs r3, #0xb7
	lsls r3, r3, #2
	mov ip, r3
	adds r0, r4, r3
	ldr r1, _0800F25C @ =0x000002D6
	adds r1, r1, r4
	mov sl, r1
	subs r2, #2
	adds r2, r4, r2
	str r2, [sp]
	ldrh r0, [r0]
	cmp r5, r0
	bge _0800F210
	ldr r3, _0800F260 @ =0x0203B400
	mov sb, r3
	ldr r6, _0800F264 @ =0x030046B8
	ldr r0, _0800F25C @ =0x000002D6
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r7, r4, r1
_0800F1D0:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0800F268 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r1, #0
	muls r2, r0, r2
	asrs r2, r2, #0x12
	lsls r3, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x54
	adds r1, r1, r3
	lsls r0, r2, #8
	orrs r2, r0
	strh r2, [r1]
	adds r5, #1
	mov r1, ip
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r5, r0
	blt _0800F1D0
_0800F210:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0x9f
	bgt _0800F23E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r6, r4, r3
	adds r3, r4, #0
	adds r3, #0x54
	movs r4, #0
_0800F228:
	lsls r2, r5, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r4, [r2]
	adds r5, #1
	cmp r5, #0x9f
	ble _0800F228
_0800F23E:
	mov r1, sl
	ldr r2, [sp]
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0800F26C
	movs r0, #0
	b _0800F274
	.align 2, 0
_0800F258: .4byte 0x000002DA
_0800F25C: .4byte 0x000002D6
_0800F260: .4byte 0x0203B400
_0800F264: .4byte 0x030046B8
_0800F268: .4byte 0x000003FF
_0800F26C:
	cmp r0, #0x80
	ble _0800F276
	movs r0, #0x80
	mov r1, sl
_0800F274:
	strh r0, [r1]
_0800F276:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
