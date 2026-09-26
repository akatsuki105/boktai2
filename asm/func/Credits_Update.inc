	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A810 @ =0x085AB550
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804A7DC
	adds r0, r4, #0
	bl _call_via_r1
_0804A7DC:
	ldr r1, _0804A814 @ =0x03004250
	ldr r0, _0804A818 @ =0x00001084
	strh r0, [r1]
	ldr r0, _0804A81C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0804A802
	ldrh r0, [r4, #0x32]
	cmp r0, #0
	beq _0804A802
	ldrb r0, [r4, #0x18]
	cmp r0, #2
	bhi _0804A802
	adds r0, r4, #0
	movs r1, #3
	bl Credits_SetStep
_0804A802:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A810: .4byte 0x085AB550
_0804A814: .4byte 0x03004250
_0804A818: .4byte 0x00001084
_0804A81C: .4byte 0x030044E0
