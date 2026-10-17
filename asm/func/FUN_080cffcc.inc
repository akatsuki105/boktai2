	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080CFFE8 @ =0x000003A7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0084
	cmp r0, #2
	bgt _080CFFEC
	cmp r0, #0
	beq _080CFFFA
	b _080D01BA
	.align 2, 0
_080CFFE8: .4byte 0x000003A7
_080CFFEC:
	cmp r0, #4
	bne _080CFFF2
	b _080D00EA
_080CFFF2:
	cmp r0, #6
	bne _080CFFF8
	b _080D0150
_080CFFF8:
	b _080D01BA
_080CFFFA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D0080 @ =0xFFFF0000
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D0060
	b _080D01B6
_080D0060:
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	b _080D01B6
	.align 2, 0
_080D0080: .4byte 0xFFFF0000
_080D0084:
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
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
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D014C
_080D00E6:
	movs r0, #1
	b _080D01BE
_080D00EA:
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
_080D014C:
	movs r0, #3
	b _080D01BE
_080D0150:
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
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B6
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
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D01B6
_080D01B2:
	movs r0, #5
	b _080D01BE
_080D01B6:
	movs r0, #7
	b _080D01BE
_080D01BA:
	movs r0, #1
	rsbs r0, r0, #0
_080D01BE:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
