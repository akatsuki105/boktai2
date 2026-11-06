	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0xdc
	mov r2, ip
	adds r2, #0xf8
	mov r3, ip
	ldr r0, [r3, #0x14]
	ldr r1, [r3, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, ip
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0805BC52
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0805BC5A
_0805BC52:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805BC5A:
	str r0, [r6]
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
	beq _0805BC7E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805BC86
_0805BC7E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805BC86:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805BCC0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0805BD06
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805BCCA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805BCC4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805BCE0
	.align 2, 0
_0805BCC0: .4byte 0x0000FFFF
_0805BCC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805BCDE
_0805BCCA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805BCDE
	strh r1, [r4, #8]
	movs r2, #1
	b _0805BCE0
_0805BCDE:
	movs r2, #0
_0805BCE0:
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
	bne _0805BD08
	movs r0, #1
	strb r0, [r4, #7]
	b _0805BD08
_0805BD06:
	movs r2, #0
_0805BD08:
	mov r3, ip
	strb r2, [r3, #2]
	ldrb r0, [r3, #1]
	cmp r0, #7
	beq _0805BD58
	movs r0, #0x16
	ldrsh r1, [r3, r0]
	ldrh r0, [r3, #0xe]
	cmp r1, r0
	ble _0805BD24
	ldrh r0, [r3, #0x16]
	subs r0, #1
	strh r0, [r3, #0x16]
	b _0805BD30
_0805BD24:
	cmp r1, r0
	bge _0805BD30
	mov r1, ip
	ldrh r0, [r1, #0x16]
	adds r0, #1
	strh r0, [r1, #0x16]
_0805BD30:
	ldr r0, _0805BD48 @ =gSineTable
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805BD4C
	asrs r1, r0, #0xc
	b _0805BD52
	.align 2, 0
_0805BD48: .4byte gSineTable
_0805BD4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BD52:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
_0805BD58:
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
