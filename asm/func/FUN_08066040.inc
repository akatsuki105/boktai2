	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _0806605C @ =0x000003A7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080660F8
	cmp r0, #2
	bgt _08066060
	cmp r0, #0
	beq _0806606E
	b _0806622E
	.align 2, 0
_0806605C: .4byte 0x000003A7
_08066060:
	cmp r0, #4
	bne _08066066
	b _0806615E
_08066066:
	cmp r0, #6
	bne _0806606C
	b _080661C4
_0806606C:
	b _0806622E
_0806606E:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080660F4 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _080660D4
	b _0806622A
_080660D4:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	b _0806622A
	.align 2, 0
_080660F4: .4byte 0xFFFF0000
_080660F8:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _080661C0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _080661C0
_0806615A:
	movs r0, #1
	b _08066232
_0806615E:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _080661C0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
_080661C0:
	movs r0, #3
	b _08066232
_080661C4:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806622A
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _0806622A
_08066226:
	movs r0, #5
	b _08066232
_0806622A:
	movs r0, #7
	b _08066232
_0806622E:
	movs r0, #1
	rsbs r0, r0, #0
_08066232:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
