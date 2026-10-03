	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	ldr r5, [r0, #0x18]
	movs r0, #3
	ands r5, r0
	mov sl, r5
	adds r0, r5, #4
	cmp r5, r0
	bge _081E1426
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0x18
	adds r1, r1, r4
	mov ip, r1
_081E136E:
	movs r7, #3
	ands r7, r5
	lsls r2, r7, #2
	mov r0, r8
	adds r0, #0x5c
	adds r0, r0, r2
	ldr r3, [r0]
	cmp r3, #0
	beq _081E141C
	movs r0, #0xc
	ldr r1, _081E13EC @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _081E141C
	movs r1, #0x80
	lsls r1, r1, #0x15
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081E141C
	lsls r0, r7, #3
	mov r6, r8
	adds r2, r0, r6
	adds r2, #0x3c
	mov r0, ip
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #2
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	str r1, [sp]
	mov r0, sb
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #0x2e
	ldrsh r0, [r3, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13C2
	rsbs r0, r0, #0
_081E13C2:
	cmp r0, #0x7f
	bgt _081E13F0
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13D6
	rsbs r0, r0, #0
_081E13D6:
	cmp r0, #0xe
	bgt _081E13F0
	movs r0, #0x18
	rsbs r0, r0, #0
	ldr r6, [sp]
	cmp r6, r0
	blt _081E13F0
	cmp r6, #4
	bgt _081E13F0
	movs r0, #1
	b _081E13F2
	.align 2, 0
_081E13EC: .4byte 0x03002BC0
_081E13F0:
	movs r0, #0
_081E13F2:
	cmp r0, #0
	beq _081E141C
	strb r7, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_081df6dc
	mov r0, r8
	adds r1, r4, #0
	bl FUN_081e12c8
	ldr r0, _081E1418 @ =FUN_081e169c
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4, #4]
	b _081E1428
	.align 2, 0
_081E1418: .4byte FUN_081e169c
_081E141C:
	adds r5, #1
	mov r0, sl
	adds r0, #4
	cmp r5, r0
	blt _081E136E
_081E1426:
	movs r0, #0
_081E1428:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
