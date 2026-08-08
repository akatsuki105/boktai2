	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806168E
	b _080617B6
_0806168E:
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
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
	beq _080616C2
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	b _080616CC
_080616C2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080616CC:
	mov r2, ip
	str r0, [r2]
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
	beq _080616F4
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080616FE
_080616F4:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080616FE:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08061738 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806177E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08061742
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806173C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08061758
	.align 2, 0
_08061738: .4byte 0x0000FFFF
_0806173C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08061756
_08061742:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08061756
	strh r1, [r4, #8]
	movs r2, #1
	b _08061758
_08061756:
	movs r2, #0
_08061758:
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
	bne _08061780
	movs r0, #1
	strb r0, [r4, #7]
	b _08061780
_0806177E:
	movs r2, #0
_08061780:
	cmp r2, #0
	beq _0806179A
	mov r1, ip
	adds r1, #0x64
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080617B6
_0806179A:
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	mov r1, ip
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x1c]
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
_080617B6:
	pop {r4, r5}
	pop {r0}
	bx r0
