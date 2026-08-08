	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r0, [r6]
	movs r7, #1
	rsbs r7, r7, #0
	cmp r0, r7
	beq _08221208
	adds r0, r5, #0
	bl FUN_082210f0
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r6]
	str r0, [r4]
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	str r3, [r0]
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r1, _08221260 @ =0x085B0028
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r1, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	str r3, [r0]
	adds r1, #4
	adds r0, r5, r1
	str r3, [r0]
	movs r1, #2
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	str r7, [r6]
	ldr r4, [r4]
	subs r0, r4, #6
	cmp r0, #6
	bhi _08221208
	ldr r2, _08221264 @ =0x00000808
	adds r0, r5, r2
	strb r4, [r0]
_08221208:
	adds r0, r5, #0
	adds r0, #0x98
	movs r1, #0
	str r1, [r0]
	adds r0, #0xf
	strb r1, [r0]
	movs r1, #0x10
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08221258
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08221258
	adds r2, #8
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08221258:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08221260: .4byte 0x085B0028
_08221264: .4byte 0x00000808
