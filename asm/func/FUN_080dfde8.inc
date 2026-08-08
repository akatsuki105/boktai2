	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DFE22
	adds r1, #0xf4
	ldrh r0, [r1, #6]
	movs r2, #4
	movs r4, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	mov r3, ip
	strb r4, [r3]
_080DFE22:
	adds r1, r5, #0
	adds r1, #0x1c
	movs r0, #0xca
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r5, #0
	bl FUN_080df6d4
	ldrb r0, [r5, #6]
	adds r0, #8
	strb r0, [r5, #6]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r1, [r4]
	adds r0, r5, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DFEA4
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_08236424
	adds r0, r5, #0
	bl FUN_080df714
	adds r0, r5, #0
	bl FUN_0822a4e0
	ldr r3, _080DFEA0 @ =0x000001AF
	adds r2, r5, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	bics r0, r1
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, #0xaf
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _080DFEAA
	.align 2, 0
_080DFEA0: .4byte 0x000001AF
_080DFEA4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_080DFEAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
