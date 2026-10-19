	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0x20
	ldrb r0, [r3, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _08209190
	ldr r1, _0820918C @ =0x085AEBC4
	ldrb r2, [r3, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	strb r2, [r3, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r3, r2
	str r1, [r0]
	str r4, [r3, #0x10]
	movs r5, #1
	strb r5, [r3, #9]
	strb r4, [r3, #0x18]
	ldr r0, [r6, #0x18]
	adds r1, r3, #0
	adds r1, #0x5c
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #2
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r6, #0x18]
	strh r4, [r6, #4]
	strh r5, [r6, #6]
	str r4, [r6, #8]
	movs r0, #1
	b _08209192
	.align 2, 0
_0820918C: .4byte 0x085AEBC4
_08209190:
	movs r0, #0
_08209192:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
