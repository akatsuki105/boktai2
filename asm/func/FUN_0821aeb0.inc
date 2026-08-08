	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AECE
	asrs r0, r0, #0x10
	b _0821AED4
_0821AECE:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821AED4:
	str r0, [sp, #0x1c]
	movs r2, #0x88
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AEE6
	asrs r0, r0, #0x10
	b _0821AEEC
_0821AEE6:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821AEEC:
	mov sl, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov sb, r4
	adds r0, r7, #0
	adds r0, #0xf4
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _0821AF90
	ldr r0, _0821AF80 @ =0x0000CB05
	ldr r1, _0821AF84 @ =0x0000DE23
	bl FUN_082310cc
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	bl FUN_0822f284
	add r4, sp, #0x14
	mov r0, r8
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0821AF88 @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x38
	mov r1, sp
	ldrh r1, [r1, #0x1c]
	strh r1, [r4]
	mov r2, sl
	strh r2, [r4, #2]
	ldr r3, _0821AF8C @ =0x00008012
	movs r0, #1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #7
	bl FUN_0822f3fc
	mov r1, r8
	str r1, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	adds r0, r7, #0
	adds r0, #0x6c
	mov r2, sb
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	b _0821AFE6
	.align 2, 0
_0821AF80: .4byte 0x0000CB05
_0821AF84: .4byte 0x0000DE23
_0821AF88: .4byte 0x05000002
_0821AF8C: .4byte 0x00008012
_0821AF90:
	adds r4, r7, #0
	adds r4, #0xc4
	ldr r1, _0821B050 @ =0x000097D3
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r7, #0
	adds r0, #0x98
	ldr r2, _0821B054 @ =0x00008012
	adds r1, r4, #0
	bl FUN_0822a470
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	movs r4, #0
	mov r3, sp
	ldrh r3, [r3, #0x1c]
	strh r3, [r0]
	adds r0, #2
	mov r5, sl
	strh r5, [r0]
	subs r0, #0x16
	mov r2, sb
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	subs r0, #2
	strb r1, [r0]
	ldr r0, _0821B058 @ =0x0000922E
	ldr r1, _0821B05C @ =0x0000C6A0
	bl FUN_082310cc
	adds r1, r0, #0
	adds r0, r7, #0
	adds r0, #0xf0
	str r1, [r0]
	subs r0, #0x10
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
_0821AFE6:
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r5, r7, r3
	ldr r1, _0821B060 @ =0x00001C1B
	adds r0, r5, #0
	bl FUN_0822b16c
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x12
	bl FUN_0822a470
	movs r0, #5
	strh r0, [r4, #0x10]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r0]
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r4, sl
	strh r4, [r0]
	mov r5, sb
	lsls r0, r5, #1
	add r0, sb
	movs r1, #4
	bl Div
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _0821B064 @ =0x00000145
	adds r1, r7, r3
	strb r0, [r1]
	ldr r4, _0821B068 @ =0x00000143
	adds r1, r7, r4
	movs r0, #2
	strb r0, [r1]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821B050: .4byte 0x000097D3
_0821B054: .4byte 0x00008012
_0821B058: .4byte 0x0000922E
_0821B05C: .4byte 0x0000C6A0
_0821B060: .4byte 0x00001C1B
_0821B064: .4byte 0x00000145
_0821B068: .4byte 0x00000143
