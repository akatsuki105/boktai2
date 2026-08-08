	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sl, r1
	ldr r1, _0823631C @ =0x030046A4
	ldr r1, [r1]
	ldr r7, [r1, #0x14]
	movs r1, #0xff
	strh r1, [r6, #4]
	strh r1, [r6, #6]
	movs r3, #0
	b _0823635A
	.align 2, 0
_0823631C: .4byte 0x030046A4
_08236320:
	lsls r2, r3, #2
	adds r1, r7, #4
	adds r1, r1, r2
	ldr r1, [r1]
	adds r5, r7, r1
	ldr r1, [r5, #8]
	adds r1, r1, r5
	mov r8, r1
	movs r4, #0
	adds r1, r3, #1
	mov sb, r1
	b _08236352
_08236338:
	mov r0, r8
	mov r1, sl
	adds r2, r4, #0
	str r3, [sp]
	bl FUN_08235924
	adds r1, r0, #0
	ldr r3, [sp]
	cmp r1, #0
	beq _08236350
	strh r3, [r6, #4]
	strh r4, [r6, #6]
_08236350:
	adds r4, #1
_08236352:
	ldrh r1, [r5]
	cmp r4, r1
	blt _08236338
	mov r3, sb
_0823635A:
	ldrh r1, [r7]
	cmp r3, r1
	blt _08236320
	movs r1, #0
	strh r1, [r6]
	mov r3, sl
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0xc]
	str r2, [r6, #0x10]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	str r1, [r6, #0x14]
	str r2, [r6, #0x18]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
