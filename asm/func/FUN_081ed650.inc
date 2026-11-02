	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r2, #0
	mov r4, sp
	ldrh r0, [r1]
	ldrh r2, [r5]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _081ED6C8 @ =0x000003FF
	cmp r1, r0
	ble _081ED6C2
	adds r0, r2, #0
	movs r1, #2
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, #2]
	strh r0, [r4, #2]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r1, #2
	adds r2, r6, #0
	bl FUN_081eb178
	cmp r0, #0
	blt _081ED6CC
_081ED6C2:
	movs r0, #1
	b _081ED6CE
	.align 2, 0
_081ED6C8: .4byte 0x000003FF
_081ED6CC:
	movs r0, #0
_081ED6CE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
