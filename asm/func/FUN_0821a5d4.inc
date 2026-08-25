	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0821A6E0 @ =0x0000CB05
	ldr r1, _0821A6E4 @ =0x00000C23
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	movs r5, #0x18
	adds r5, r5, r7
	mov sb, r5
	mov r0, sb
	bl OpenSpriteSetFile
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0821A6E8 @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x38
	movs r1, #0x78
	strh r1, [r4]
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r3, #0x3c
	mov r8, r3
	str r3, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r3, #0x32
	bl FUN_0822f3fc
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrb r1, [r5]
	adds r0, r7, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r1, _0821A6EC @ =0x00000171
	adds r1, r1, r7
	mov sl, r1
	ldrb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x6d
	strb r0, [r1]
	movs r2, #0
	strh r2, [r6, #0x36]
	adds r6, #0x60
	movs r3, #0x78
	strh r3, [r4]
	movs r0, #0x60
	strh r0, [r4, #2]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #1
	movs r3, #0x32
	bl FUN_0822f3fc
	ldrb r1, [r5]
	adds r0, r7, #0
	adds r0, #0xcc
	strb r1, [r0]
	mov r2, sl
	ldrb r0, [r2]
	adds r1, r7, #0
	adds r1, #0xcd
	strb r0, [r1]
	movs r3, #0
	strh r3, [r6, #0x36]
	adds r6, #0x60
	movs r0, #0x78
	strh r0, [r4]
	movs r0, #0x80
	strh r0, [r4, #2]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #2
	movs r3, #0x32
	bl FUN_0822f3fc
	ldrb r1, [r5]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	mov r4, sl
	ldrb r0, [r4]
	ldr r5, _0821A6F0 @ =0x0000012D
	adds r1, r7, r5
	strb r0, [r1]
	movs r0, #0
	strh r0, [r6, #0x36]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821A6E0: .4byte 0x0000CB05
_0821A6E4: .4byte 0x00000C23
_0821A6E8: .4byte 0x05000002
_0821A6EC: .4byte 0x00000171
_0821A6F0: .4byte 0x0000012D
