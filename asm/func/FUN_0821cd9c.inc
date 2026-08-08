	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0x92
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	adds r3, r5, #0
	adds r3, #0x50
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	mov r4, sp
	ldrh r0, [r2]
	ldrh r1, [r3]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4, #4]
	ldr r2, _0821CE14 @ =0x00000BCC
	adds r0, r5, r2
	movs r2, #4
	bl FUN_082352c0
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821CE14: .4byte 0x00000BCC
