	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080190A4
	ldrb r0, [r5, #0xd]
	ldrb r1, [r5, #0x10]
	cmp r0, r1
	blo _0801909C
	ldrb r1, [r5, #0xe]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r1, #0
	cmp r2, #0
	bne _080190C0
	movs r0, #1
	strb r0, [r5, #0xf]
	strb r2, [r5, #0xd]
	b _080190C8
_0801909C:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190D6
_080190A4:
	ldrb r0, [r5, #0xd]
	ldrb r2, [r5, #0x11]
	cmp r0, r2
	blo _080190D0
	ldrb r1, [r5, #0xe]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #0
	bne _080190C8
	strb r0, [r5, #0xf]
	strb r0, [r5, #0xd]
_080190C0:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190DC
_080190C8:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
	b _080190DC
_080190D0:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
_080190D6:
	adds r0, #1
	strb r0, [r5, #0xd]
	ldrb r3, [r5, #0xe]
_080190DC:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _08019170
	cmp r1, #0
	ble _080190F2
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #5
	bl Div
	b _080190F4
_080190F2:
	movs r0, #0
_080190F4:
	mov r8, r0
	movs r0, #0x20
	mov r1, r8
	subs r1, r0, r1
	mov sb, r1
	movs r6, #0
	ldrb r2, [r5, #0xc]
	cmp r6, r2
	bge _0801918C
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	mov ip, r4
_0801910E:
	lsls r1, r6, #1
	str r1, [sp]
	ldrh r1, [r7]
	mov r2, ip
	ldrh r3, [r2]
	adds r0, r1, #0
	ldr r4, _08019168 @ =0x00007C1F
	ands r0, r4
	mov r2, r8
	muls r2, r0, r2
	adds r0, r3, #0
	ands r0, r4
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r2, r2, r0
	ldr r0, _0801916C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r4, r8
	muls r4, r1, r4
	adds r1, r4, #0
	ands r3, r0
	mov r0, sb
	muls r0, r3, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	ldr r0, [r5, #8]
	ldr r1, [sp]
	adds r4, r1, r0
	strh r2, [r4]
	movs r2, #2
	add ip, r2
	adds r7, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801910E
	b _0801918C
	.align 2, 0
_08019168: .4byte 0x00007C1F
_0801916C: .4byte 0x000F83E0
_08019170:
	movs r6, #0
	ldrb r0, [r5, #0xc]
	cmp r6, r0
	bge _0801918C
	adds r2, r4, #0
	ldr r1, [r5, #8]
_0801917C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801917C
_0801918C:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
