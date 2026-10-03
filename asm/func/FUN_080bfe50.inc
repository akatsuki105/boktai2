	push {r4, r5, lr}
	adds r1, r0, #0
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrh r3, [r4]
	adds r2, r3, #0
	cmp r2, #0
	beq _080BFEEC
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bne _080BFEAC
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080BFE92
	movs r2, #1
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r3, #5
_080BFE82:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE82
	b _080BFEEC
_080BFE92:
	ldr r5, _080BFEA8 @ =0x0000026E
	adds r1, r1, r5
	movs r3, #5
_080BFE98:
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE98
	b _080BFEEC
	.align 2, 0
_080BFEA8: .4byte 0x0000026E
_080BFEAC:
	cmp r2, #3
	bls _080BFECC
	ldr r0, _080BFEC8 @ =0x0000026E
	adds r2, r1, r0
	movs r3, #5
_080BFEB6:
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFEB6
	b _080BFEE0
	.align 2, 0
_080BFEC8: .4byte 0x0000026E
_080BFECC:
	ldr r5, _080BFEF4 @ =0x0000026E
	adds r2, r1, r5
	movs r3, #5
_080BFED2:
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFED2
_080BFEE0:
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_080BFEEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFEF4: .4byte 0x0000026E
