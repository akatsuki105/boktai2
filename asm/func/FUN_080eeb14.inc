	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080EEB40 @ =0x03002C5C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _080EEB30
	b _080EEC5E
_080EEB30:
	cmp r3, #0x17
	beq _080EEB4A
	cmp r3, #0x17
	bgt _080EEB44
	cmp r3, #0xb
	beq _080EEB50
	b _080EEC5E
	.align 2, 0
_080EEB40: .4byte 0x03002C5C
_080EEB44:
	cmp r3, #0x1b
	beq _080EEB56
	b _080EEC5E
_080EEB4A:
	movs r7, #0x8c
	lsls r7, r7, #1
	b _080EEB5A
_080EEB50:
	mov r7, r8
	adds r7, #0x64
	b _080EEB5C
_080EEB56:
	movs r7, #0xe6
	lsls r7, r7, #1
_080EEB5A:
	add r7, r8
_080EEB5C:
	adds r0, r3, #0
	bl FUN_080ed020
	ldr r0, _080EEBAC @ =0x03003584
	lsls r1, r4, #5
	ldr r0, [r0]
	lsls r2, r5, #5
	strh r4, [r7, #0x22]
	movs r3, #0
	mov ip, r3
	adds r4, r7, #0
	adds r4, #0x84
	str r4, [sp, #4]
	adds r5, r7, #0
	adds r5, #0x94
	str r5, [sp, #8]
	adds r3, r7, #0
	adds r3, #0xa4
	str r3, [sp, #0x14]
	subs r4, #0x60
	str r4, [sp, #0xc]
	subs r5, #0x50
	str r5, [sp]
	subs r3, #0x40
	str r3, [sp, #0x10]
	adds r6, r0, r1
	movs r4, #0
	mov sb, r4
	adds r0, r0, r2
	str r0, [sp, #0x18]
	mov sl, r7
_080EEB9A:
	mov r5, r8
	ldr r0, [r5, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	cmp r0, #0
	beq _080EEBB0
	movs r0, #1
	b _080EEBB2
	.align 2, 0
_080EEBAC: .4byte 0x03003584
_080EEBB0:
	movs r0, #0
_080EEBB2:
	cmp r0, #0
	beq _080EEBC2
	ldrh r0, [r7, #0x20]
	cmp r0, #0x20
	beq _080EEBC2
	mov r2, sl
	ldrh r5, [r2]
	b _080EEBC6
_080EEBC2:
	ldr r3, [sp, #0x18]
	ldrh r5, [r3]
_080EEBC6:
	ldr r2, [sp, #4]
	add r2, ip
	ldrb r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	adds r3, r5, #0
	movs r4, #0x1f
	ands r3, r4
	subs r0, r0, r3
	strb r0, [r2]
	ldr r1, [sp, #8]
	add r1, ip
	ldrh r0, [r6]
	lsrs r0, r0, #5
	ands r0, r4
	asrs r2, r5, #5
	ands r2, r4
	subs r0, r0, r2
	strb r0, [r1]
	ldr r4, [sp, #0x14]
	add r4, ip
	ldrh r0, [r6]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r1, r5, #0xa
	movs r5, #0x1f
	ands r1, r5
	subs r0, r0, r1
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	add r0, sb
	lsls r3, r3, #5
	strh r3, [r0]
	ldr r0, [sp]
	add r0, sb
	lsls r2, r2, #5
	strh r2, [r0]
	ldr r0, [sp, #0x10]
	add r0, sb
	lsls r1, r1, #5
	strh r1, [r0]
	adds r6, #2
	movs r0, #2
	add sb, r0
	ldr r1, [sp, #0x18]
	adds r1, #2
	str r1, [sp, #0x18]
	add sl, r0
	movs r2, #1
	add ip, r2
	mov r3, ip
	cmp r3, #0xf
	ble _080EEB9A
	movs r1, #0x80
	lsls r1, r1, #6
	mov r4, r8
	ldr r0, [r4, #0x2c]
	orrs r0, r1
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strh r0, [r7, #0x20]
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _080EEC54
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x2c]
	orrs r0, r1
	str r0, [r4, #0x2c]
	b _080EEC5E
_080EEC54:
	ldr r1, _080EEC70 @ =0xFFFDFFFF
	mov r5, r8
	ldr r0, [r5, #0x2c]
	ands r0, r1
	str r0, [r5, #0x2c]
_080EEC5E:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EEC70: .4byte 0xFFFDFFFF
