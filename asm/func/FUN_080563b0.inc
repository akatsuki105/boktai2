	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov ip, r1
	mov r8, r2
	mov r6, ip
	adds r6, #0x30
	adds r1, #0x4c
	mov r2, ip
	adds r2, #0xc
	mov r3, ip
	ldrh r0, [r3, #0xc]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r3, ip
	ldr r1, [r3, #0x5c]
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
	beq _08056418
	mov r1, ip
	ldr r0, [r1, #0x30]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2, #0x30]
	b _08056424
_08056418:
	mov r3, ip
	ldr r0, [r3, #0x30]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
_08056424:
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
	beq _08056446
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805644E
_08056446:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805644E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056488 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080564CE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08056492
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805648C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080564A8
	.align 2, 0
_08056488: .4byte 0x0000FFFF
_0805648C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080564A6
_08056492:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080564A6
	strh r1, [r4, #8]
	movs r2, #1
	b _080564A8
_080564A6:
	movs r2, #0
_080564A8:
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
	bne _080564D0
	movs r0, #1
	strb r0, [r4, #7]
	b _080564D0
_080564CE:
	movs r2, #0
_080564D0:
	cmp r2, #0
	beq _080564E6
	movs r1, #1
	mov r3, r8
	lsls r1, r3
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	adds r0, r6, #0
	bl AuxSprite_Remove
_080564E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
