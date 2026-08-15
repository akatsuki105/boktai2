	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	mov sb, r1
	mov r0, sb
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EED20
	movs r0, #0x80
	lsls r0, r0, #6
	mov r2, r8
	ldr r1, [r2, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080EECA2
	movs r0, #1
	b _080EECA4
_080EECA2:
	movs r0, #0
_080EECA4:
	cmp r0, #0
	beq _080EED20
	movs r4, #0
	ldr r0, _080EECC0 @ =0x000001DF
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0x17
	beq _080EECCA
	cmp r0, #0x17
	bgt _080EECC4
	cmp r0, #0xb
	beq _080EECDC
	b _080EEE5E
	.align 2, 0
_080EECC0: .4byte 0x000001DF
_080EECC4:
	cmp r0, #0x1b
	beq _080EECF8
	b _080EEE5E
_080EECCA:
	movs r6, #0x8c
	lsls r6, r6, #1
	add r6, r8
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080EECEA
	b _080EECEE
_080EECDC:
	mov r6, r8
	adds r6, #0x64
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080EECEE
_080EECEA:
	movs r0, #1
	b _080EECF0
_080EECEE:
	movs r0, #0
_080EECF0:
	cmp r0, #0
	beq _080EED24
	movs r4, #1
	b _080EED24
_080EECF8:
	movs r6, #0xe6
	lsls r6, r6, #1
	add r6, r8
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _080EED0C
	movs r0, #1
	b _080EED0E
_080EED0C:
	movs r0, #0
_080EED0E:
	cmp r0, #0
	beq _080EED14
	movs r4, #1
_080EED14:
	mov r0, sb
	bl FUN_0817e83c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EED24
_080EED20:
	movs r0, #0
	b _080EEE60
_080EED24:
	ldrh r0, [r6, #0x20]
	cmp r0, #0
	bne _080EED60
	ldr r1, _080EED50 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EED3C
	b _080EEE5E
_080EED3C:
	ldr r0, _080EED54 @ =0x0000025D
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EED58
	mov r1, sb
	ldr r0, [r1, #0x44]
	str r6, [r0, #0x38]
	b _080EEE5E
	.align 2, 0
_080EED50: .4byte 0x02008000
_080EED54: .4byte 0x0000025D
_080EED58:
	mov r2, sb
	ldr r0, [r2, #0x44]
	str r6, [r0, #0x68]
	b _080EEE5E
_080EED60:
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, sb
	str r0, [sp, #4]
	cmp r4, #0
	bne _080EEE2A
	movs r5, #0
	adds r1, r6, #0
	adds r1, #0x24
	str r1, [sp, #0xc]
	adds r2, r6, #0
	adds r2, #0x84
	str r2, [sp]
	adds r0, r6, #0
	adds r0, #0x44
	str r0, [sp, #0x10]
	adds r1, #0x70
	str r1, [sp, #8]
	movs r2, #0x64
	adds r2, r2, r6
	mov sl, r2
	movs r0, #0xa4
	adds r0, r0, r6
	mov ip, r0
	adds r7, r6, #0
_080EED92:
	lsls r1, r5, #1
	ldr r2, [sp, #0xc]
	adds r4, r2, r1
	ldr r2, [sp]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldr r0, [sp, #0x10]
	adds r3, r0, r1
	ldr r2, [sp, #8]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	add r1, sl
	mov r2, ip
	adds r0, r2, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrh r0, [r1]
	adds r2, r2, r0
	strh r2, [r1]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x15
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
	lsls r0, r0, #5
	orrs r1, r0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x15
	lsls r2, r2, #0xa
	orrs r1, r2
	strh r1, [r7]
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080EED92
	ldrh r0, [r6, #0x20]
	subs r0, #1
	strh r0, [r6, #0x20]
	ldr r0, _080EEE08 @ =0x000001DF
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0x17
	beq _080EEE12
	cmp r0, #0x17
	bgt _080EEE0C
	cmp r0, #0xb
	beq _080EEE18
	b _080EEE2A
	.align 2, 0
_080EEE08: .4byte 0x000001DF
_080EEE0C:
	cmp r0, #0x1b
	beq _080EEE1E
	b _080EEE2A
_080EEE12:
	movs r1, #0x80
	lsls r1, r1, #8
	b _080EEE22
_080EEE18:
	movs r1, #0x80
	lsls r1, r1, #7
	b _080EEE22
_080EEE1E:
	movs r1, #0x80
	lsls r1, r1, #9
_080EEE22:
	mov r2, r8
	ldr r0, [r2, #0x2c]
	orrs r0, r1
	str r0, [r2, #0x2c]
_080EEE2A:
	ldr r1, _080EEE48 @ =0x02008000
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080EEE56
	ldr r0, _080EEE4C @ =0x0000025D
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EEE50
	mov r1, sb
	ldr r0, [r1, #0x44]
	str r6, [r0, #0x38]
	b _080EEE56
	.align 2, 0
_080EEE48: .4byte 0x02008000
_080EEE4C: .4byte 0x0000025D
_080EEE50:
	mov r2, sb
	ldr r0, [r2, #0x44]
	str r6, [r0, #0x68]
_080EEE56:
	ldrh r0, [r6, #0x20]
	cmp r0, #0
	beq _080EEE5E
	b _080EED20
_080EEE5E:
	movs r0, #1
_080EEE60:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

