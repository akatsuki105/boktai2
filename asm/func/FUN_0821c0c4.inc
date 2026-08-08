	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r1
	str r2, [sp]
	movs r2, #0xbf
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r3, [r1]
	movs r6, #0
	mov r8, r6
	mov ip, r6
	movs r5, #0
	ldr r7, _0821C13C @ =0x00000BF5
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp ip, r0
	bge _0821C128
	mov sb, r0
_0821C0F0:
	ldrh r4, [r3]
	mov r0, sl
	movs r1, #0
	ldrsh r2, [r0, r1]
	subs r2, r4, r2
	ldrh r1, [r3, #2]
	movs r6, #4
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	adds r7, r2, #0
	muls r7, r2, r7
	adds r2, r7, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	cmp r2, r8
	ble _0821C120
	mov r8, r2
	mov ip, r5
	ldr r0, [sp]
	strh r4, [r0]
	ldrh r0, [r3, #2]
	ldr r1, [sp]
	strh r0, [r1, #4]
_0821C120:
	adds r3, #8
	adds r5, #1
	cmp r5, sb
	blt _0821C0F0
_0821C128:
	mov r0, ip
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0821C13C: .4byte 0x00000BF5
