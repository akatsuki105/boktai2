	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	str r1, [r7, #0x18]
	ldr r0, [r1, #0x2c]
	ldr r1, [r1, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080A9DEC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r7, #0
	adds r6, #0x84
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9DF0
	asrs r0, r0, #8
	b _080A9DF6
	.align 2, 0
_080A9DEC: .4byte 0x0000FFFF
_080A9DF0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9DF6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9E08
	asrs r0, r0, #8
	b _080A9E0E
_080A9E08:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E0E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A9E22
	asrs r0, r0, #8
	b _080A9E28
_080A9E22:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E28:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _080A9E7C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r7, #0
	bl FUN_080a9ccc
	adds r0, r7, #0
	bl FUN_080a9d30
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9E80 @ =FUN_080a9b84
	str r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080A9E84 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A9E7C: .4byte 0x030047C8
_080A9E80: .4byte FUN_080a9b84
_080A9E84: .4byte 0x030047A4
