	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0
	bne _080DDB42
	b _080DDC90
_080DDB42:
	movs r2, #1
	mov sb, r2
	movs r3, #2
	mov sl, r3
	adds r6, r7, #0
	adds r6, #0x58
	adds r4, r7, #0
	adds r4, #0x18
	mov ip, r1
	movs r0, #0x2f
	mov r8, r0
_080DDB58:
	ldrb r0, [r6]
	cmp r0, #0
	bne _080DDB60
	b _080DDC7E
_080DDB60:
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x28]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x3a]
	ldrh r2, [r4, #0x2a]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x3c]
	ldrh r3, [r4, #0x2c]
	adds r0, r0, r3
	strh r0, [r4, #0x2c]
	ldr r1, _080DDBBC @ =0x00000CDC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080DDBC0
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080DDBC8
	.align 2, 0
_080DDBBC: .4byte 0x00000CDC
_080DDBC0:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DDBC8:
	str r0, [r4, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _080DDBEC
	ldr r0, [r4, #0x10]
	movs r1, #8
	orrs r0, r1
	b _080DDBF4
_080DDBEC:
	ldr r0, [r4, #0x10]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DDBF4:
	str r0, [r4, #0x10]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080DDC2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DDC64
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DDC36
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DDC30
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DDC4C
	.align 2, 0
_080DDC2C: .4byte 0x0000FFFF
_080DDC30:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DDC4A
_080DDC36:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DDC4A
	strh r1, [r4, #8]
	movs r2, #1
	b _080DDC4C
_080DDC4A:
	movs r2, #0
_080DDC4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DDC66
_080DDC64:
	movs r2, #0
_080DDC66:
	cmp r2, #0
	beq _080DDC7E
	movs r0, #0
	strb r0, [r6]
	ldr r0, [r4, #0x10]
	mov r3, sb
	orrs r0, r3
	str r0, [r4, #0x10]
	mov r1, ip
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
_080DDC7E:
	adds r6, #0x44
	adds r4, #0x44
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	blt _080DDC90
	b _080DDB58
_080DDC90:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
