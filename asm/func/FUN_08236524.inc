	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	beq _08236532
	b _0823663A
_08236532:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r5, #0x38]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08236544
	ldrh r1, [r5, #0x3c]
	b _0823654C
_08236544:
	ldrh r1, [r5, #0x3c]
	mov r3, ip
	ldrh r0, [r3, #0x3c]
	subs r1, r1, r0
_0823654C:
	cmp r1, #0
	bgt _08236552
	movs r1, #1
_08236552:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08236560
	movs r3, #0
	b _08236568
_08236560:
	mov r0, ip
	ldr r3, [r0, #0x38]
	movs r0, #0x7f
	ands r3, r0
_08236568:
	mov r0, ip
	ldr r4, [r0, #0x34]
	movs r0, #0x7f
	ands r4, r0
	ands r2, r0
	cmp r2, #0
	bne _0823657C
	mov r3, ip
	strh r1, [r3, #0x3e]
	b _082365DE
_0823657C:
	cmp r3, #0
	bne _0823658C
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _082365E0
_0823658C:
	cmp r3, #0x40
	bne _0823659E
	asrs r0, r1, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _082365E4
_0823659E:
	cmp r2, #0x40
	bne _082365AE
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _082365E0
_082365AE:
	ands r3, r2
	cmp r3, #0
	beq _082365C2
	asrs r0, r1, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _082365E4
_082365C2:
	ands r4, r2
	cmp r4, #0
	beq _082365D4
	lsls r0, r1, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	adds r1, #0x43
	movs r0, #4
	b _082365E4
_082365D4:
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
_082365DE:
	mov r1, ip
_082365E0:
	adds r1, #0x43
	movs r0, #1
_082365E4:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, ip
	ldrh r1, [r0, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823662E
	ldrh r1, [r5, #6]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823662E
	mov r0, ip
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _08236616
	rsbs r0, r0, #0
_08236616:
	cmp r0, #0x20
	bgt _0823662E
	mov r3, ip
	ldrh r1, [r3, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r3, #0x3e]
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_0823662E:
	mov r1, ip
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _0823663A
	movs r0, #1
	strh r0, [r1, #0x3e]
_0823663A:
	pop {r4, r5}
	pop {r0}
	bx r0
