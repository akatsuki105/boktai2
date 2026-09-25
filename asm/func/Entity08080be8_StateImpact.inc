	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08080968
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080809D4
_08080968:
	cmp r0, #4
	bne _080809CA
	adds r0, r2, #0
	adds r0, #0xc8
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08080982
	movs r0, #7
	b _08080990
_08080982:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _0808098E
	movs r0, #8
	b _08080990
_0808098E:
	movs r0, #6
_08080990:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _0808099E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080809C4
_0808099E:
	cmp r1, #4
	bgt _080809AE
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080809B6
_080809AE:
	cmp r1, #5
	bgt _080809BC
	ldr r0, [r2]
	movs r1, #0xc
_080809B6:
	orrs r0, r1
	str r0, [r2]
	b _080809D4
_080809BC:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080809C4:
	ands r0, r1
	str r0, [r2]
	b _080809D4
_080809CA:
	cmp r0, #6
	bls _080809D4
	adds r0, r2, #0
	bl KillEntity
_080809D4:
	pop {r0}
	bx r0
