	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	ldr r1, _08045514 @ =0x000F4240
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r7, #0
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r6, #0xf
_08045426:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08045440
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045440
	ldr r0, [r4, #0x44]
	cmp r0, r1
	bhs _08045440
	adds r1, r0, #0
	adds r7, r4, #0
_08045440:
	subs r6, #1
	adds r4, r4, r2
	cmp r6, #0
	bge _08045426
	cmp r7, #0
	beq _0804551C
	mov r1, sb
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	beq _0804551C
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r2, #0xc4
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0xc6
	str r3, [sp, #0x40]
	adds r0, r7, #0
	adds r0, #0xc8
	str r0, [sp, #0x44]
	adds r1, r7, #0
	adds r1, #0x48
	str r1, [sp, #0x38]
	mov r2, sp
	adds r2, #0x30
	str r2, [sp, #0x3c]
	movs r3, #0
	mov r8, r3
	movs r6, #0xf
	movs r5, #0xa8
	lsls r5, r5, #2
	add r5, sb
_08045484:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _080454B8
	ldr r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x60
	ldrb r2, [r5, #2]
	str r2, [sp, #0x48]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r4
	str r3, [sp]
	movs r3, #6
	ldrsh r2, [r5, r3]
	str r2, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	movs r3, #0x64
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x48]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r5, #8]
	mov r3, r8
	strh r3, [r5]
_080454B8:
	subs r6, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r6, #0
	bge _08045484
	ldrh r0, [r7]
	str r0, [sp, #0x10]
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x14]
	ldr r3, [sp, #0x40]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x18]
	ldr r2, [sp, #0x44]
	movs r3, #0
	ldrsh r0, [r2, r3]
	str r0, [sp, #0x1c]
	mov r0, sb
	ldrh r3, [r0, #0x1c]
	ldr r2, [sp, #0x38]
	add r1, sp, #0x20
	movs r6, #3
_080454EC:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r6, #1
	cmp r6, #0
	bge _080454EC
	ldr r0, _08045518 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	add r1, sp, #0x10
	ldr r2, [sp, #0x3c]
	str r1, [r2, #4]
	adds r0, r3, #0
	ldr r1, [sp, #0x3c]
	bl VM_ExecByID
	movs r0, #1
	b _0804551E
	.align 2, 0
_08045514: .4byte 0x000F4240
_08045518: .4byte 0xFFFF0000
_0804551C:
	movs r0, #0
_0804551E:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
