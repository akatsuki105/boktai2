	push {r4, r5, lr}
	sub sp, #0x40
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r1, [r0]
	str r1, [sp]
	mov r3, ip
	ldrh r1, [r3, #8]
	str r1, [sp, #4]
	add r3, sp, #8
	stm r3!, {r2}
	ldr r1, [r0, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	movs r2, #2
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	movs r2, #4
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	add r4, sp, #0x38
	mov r1, ip
	adds r1, #0x10
	movs r2, #3
_0823489C:
	ldrh r0, [r1]
	stm r3!, {r0}
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0823489C
	mov r0, ip
	ldr r5, [r0, #0x24]
	mov r1, ip
	adds r1, #0x18
	movs r2, #3
_082348B2:
	ldrh r0, [r1]
	stm r3!, {r0}
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _082348B2
	ldr r1, _082348E4 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r1
	movs r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	mov r2, sp
	str r2, [r4, #4]
	mov r3, ip
	ldrh r1, [r3, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _082348E8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823a8a4
	b _082348F0
	.align 2, 0
_082348E4: .4byte 0xFFFF0000
_082348E8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823a88c
_082348F0:
	add sp, #0x40
	pop {r4, r5}
	pop {r0}
	bx r0
