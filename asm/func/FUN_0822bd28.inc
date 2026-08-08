	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r2, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	mov r8, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0822BDB4 @ =0x03003ED0
	adds r1, r1, r0
	ldr r6, [r1, #0x2c]
	str r6, [sp, #4]
	movs r6, #0x18
	ldrsh r0, [r1, r6]
	lsls r0, r0, #1
	str r0, [sp]
	adds r7, r4, r3
	adds r2, r2, r5
	mov ip, r2
	mov sl, r4
	cmp r5, ip
	bge _0822BDA4
	lsls r4, r4, #1
	mov sb, r4
_0822BD64:
	mov r4, sl
	adds r6, r5, #1
	cmp r4, r7
	bge _0822BD9E
	ldr r1, [sp]
	adds r0, r1, #0
	muls r0, r5, r0
	ldr r2, [sp, #0x30]
	lsls r3, r2, #0xa
	ldr r5, [sp, #0x34]
	lsls r1, r5, #0xc
	lsls r0, r0, #1
	ldr r2, [sp, #4]
	adds r0, r0, r2
	mov r5, sb
	adds r2, r5, r0
	subs r4, r7, r4
_0822BD86:
	mov r5, r8
	adds r5, #4
	mov r8, r5
	subs r5, #4
	ldm r5!, {r0}
	orrs r0, r3
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bne _0822BD86
_0822BD9E:
	adds r5, r6, #0
	cmp r5, ip
	blt _0822BD64
_0822BDA4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822BDB4: .4byte 0x03003ED0
