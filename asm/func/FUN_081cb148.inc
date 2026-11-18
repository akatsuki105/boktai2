	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081CB168 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB16C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB16E
	.align 2, 0
_081CB168: .4byte 0x0000046C
_081CB16C:
	movs r0, #0
_081CB16E:
	cmp r0, #0
	beq _081CB212
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _081CB240 @ =FUN_081c9bd8
	movs r2, #0x21
	ldr r0, _081CB244 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB248 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #3
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, _081CB24C @ =0x00000226
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x66
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x74
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xa
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081CB250 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081CB254 @ =0x000006CC
	adds r0, r7, r2
	ldrh r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
_081CB212:
	ldr r4, _081CB248 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CB25C
	ldr r1, _081CB254 @ =0x000006CC
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, _081CB258 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_081c7228
	b _081CB266
	.align 2, 0
_081CB240: .4byte FUN_081c9bd8
_081CB244: .4byte 0x0000046D
_081CB248: .4byte 0x0000046B
_081CB24C: .4byte 0x00000226
_081CB250: .4byte 0x000006D7
_081CB254: .4byte 0x000006CC
_081CB258: .4byte 0xFFFFFEFF
_081CB25C:
	ldr r4, _081CB270 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB266:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB270: .4byte 0x00000484
