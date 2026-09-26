	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov sb, r1
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB2B0
	movs r0, #1
	rsbs r0, r0, #0
	b _080DB42C
_080DB2B0:
	movs r5, #0
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r1, #5
	add r1, sp
	mov r8, r1
	mov r0, sb
	add r1, sp, #4
	mov r2, r8
	bl FUN_080db260
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	adds r0, r4, #0
	bl GetMapAreaAt
	movs r1, #0x46
	adds r1, r1, r7
	mov sl, r1
	strh r0, [r1]
	movs r2, #0x40
	adds r2, r2, r7
	mov sb, r2
	strh r5, [r2]
	adds r0, r7, #0
	adds r0, #0x48
	strh r5, [r0]
	str r7, [sp, #8]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Setup
	subs r4, #0x70
	ldr r1, [r6, #0x34]
	mov r2, r8
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	mov r8, sl
	mov r6, sb
	cmp r2, r0
	beq _080DB34A
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB352
_080DB34A:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB352:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB378
	ldr r2, [sp, #8]
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080DB384
_080DB378:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
_080DB384:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB3BC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB3F4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB3C0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB3B4
	ldrb r0, [r4, #5]
_080DB3B4:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB3D0
	.align 2, 0
_080DB3BC: .4byte 0x0000FFFF
_080DB3C0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB3D0
	strh r1, [r4, #8]
_080DB3D0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB3F4
	movs r0, #1
	strb r0, [r4, #7]
_080DB3F4:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB41A
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB41A:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
	adds r0, r7, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r0, [r0, r2]
_080DB42C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
