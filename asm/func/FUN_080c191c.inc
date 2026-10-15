	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080C1938
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080C19A4
_080C1938:
	cmp r0, #4
	bne _080C199A
	adds r0, r2, #0
	adds r0, #0x6e
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _080C1952
	movs r0, #7
	b _080C1960
_080C1952:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _080C195E
	movs r0, #8
	b _080C1960
_080C195E:
	movs r0, #6
_080C1960:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _080C196E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080C1994
_080C196E:
	cmp r1, #4
	bgt _080C197E
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080C1986
_080C197E:
	cmp r1, #5
	bgt _080C198C
	ldr r0, [r2]
	movs r1, #0xc
_080C1986:
	orrs r0, r1
	str r0, [r2]
	b _080C19A4
_080C198C:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080C1994:
	ands r0, r1
	str r0, [r2]
	b _080C19A4
_080C199A:
	cmp r0, #6
	bls _080C19A4
	adds r0, r2, #0
	bl KillEntity
_080C19A4:
	pop {r0}
	bx r0
