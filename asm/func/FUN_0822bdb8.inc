	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r2, [sp, #0x24]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0822BE38 @ =0x03003ED0
	adds r1, r1, r0
	ldr r0, [r1, #0x2c]
	str r0, [sp]
	movs r6, #0x18
	ldrsh r0, [r1, r6]
	lsls r0, r0, #1
	mov sl, r0
	adds r7, r4, r3
	adds r2, r2, r5
	mov ip, r2
	mov sb, r4
	cmp r5, ip
	bge _0822BE26
	ldr r0, [sp, #0x2c]
	lsls r6, r0, #0xa
	ldr r0, [sp, #0x28]
	orrs r6, r0
	lsls r4, r4, #1
	mov r8, r4
_0822BDF8:
	mov r4, sb
	adds r3, r5, #1
	cmp r4, r7
	bge _0822BE20
	mov r0, sl
	muls r0, r5, r0
	ldr r2, [sp, #0x30]
	lsls r1, r2, #0xc
	orrs r1, r6
	lsls r0, r0, #1
	ldr r5, [sp]
	adds r0, r0, r5
	mov r5, r8
	adds r2, r5, r0
	subs r4, r7, r4
_0822BE16:
	strh r1, [r2]
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bne _0822BE16
_0822BE20:
	adds r5, r3, #0
	cmp r5, ip
	blt _0822BDF8
_0822BE26:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822BE38: .4byte 0x03003ED0
