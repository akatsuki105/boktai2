	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	cmp r5, #0
	bne _0822C3AA
	bl FUN_0822e8b4
_0822C3AA:
	mov r1, sp
	adds r0, r6, #0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r4, [sp, #0xc]
	adds r4, r4, r6
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, r0, r6
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, r0, r6
	str r0, [sp, #0x14]
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #4
	ldr r0, _0822C408 @ =0x03003ED0
	adds r2, r2, r0
	add r3, sp, #0x18
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r0, r0, r4
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldr r0, [r3, #8]
	adds r0, r0, r6
	str r0, [r3, #8]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r2, #0x10]
	strh r0, [r2, #0x12]
	ldr r0, [r3, #8]
	str r0, [r2, #0x28]
	ldrh r1, [r3]
	strh r1, [r2, #0x18]
	ldrh r0, [r3, #2]
	strh r0, [r2, #0x1a]
	strh r1, [r2, #0x1c]
	strh r0, [r2, #0x1e]
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822C408: .4byte 0x03003ED0
