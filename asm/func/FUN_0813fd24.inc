	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0813FD44 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FD48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FD4A
	.align 2, 0
_0813FD44: .4byte 0x0000046C
_0813FD48:
	movs r0, #0
_0813FD4A:
	cmp r0, #0
	beq _0813FDEE
	ldr r4, _0813FDA8 @ =FUN_0813f2a8
	movs r3, #0x22
	ldr r0, _0813FDAC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813FDB0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0813FDB4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r4, [r5, #5]
	ldr r2, _0813FDB8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813FDBC
	asrs r1, r0, #0xc
	b _0813FDC2
	.align 2, 0
_0813FDA8: .4byte FUN_0813f2a8
_0813FDAC: .4byte 0x0000046D
_0813FDB0: .4byte 0x0000046B
_0813FDB4: .4byte 0xFFEFFFFF
_0813FDB8: .4byte gSineTable
_0813FDBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FDC2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0813FDDC
	asrs r0, r0, #0xc
	b _0813FDE2
_0813FDDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813FDE2:
	strh r0, [r3, #4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xa
	strh r0, [r1]
_0813FDEE:
	ldr r1, _0813FE18 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813FE20
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0813FE1C @ =0x0000065C
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, #0x14
	cmp r1, r0
	bge _0813FE20
	adds r0, r5, #0
	bl FUN_08140c14
	b _0813FE2A
	.align 2, 0
_0813FE18: .4byte 0x0000046B
_0813FE1C: .4byte 0x0000065C
_0813FE20:
	ldr r0, _0813FE30 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813FE2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813FE30: .4byte 0x00000484
