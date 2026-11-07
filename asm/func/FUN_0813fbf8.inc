	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0813FC10 @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FC14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FC16
	.align 2, 0
_0813FC10: .4byte 0x0000046C
_0813FC14:
	movs r0, #0
_0813FC16:
	cmp r0, #0
	beq _0813FC24
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	strb r0, [r3, #5]
_0813FC24:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0813FC68
	movs r2, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _0813FC60 @ =0x0000046A
	adds r0, r3, r2
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _0813FC64 @ =0x0000046C
	adds r1, r3, r0
	b _0813FC88
	.align 2, 0
_0813FC60: .4byte 0x0000046A
_0813FC64: .4byte 0x0000046C
_0813FC68:
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _0813FC94 @ =0x00000484
	adds r0, r3, r1
	str r2, [r0]
	ldr r2, _0813FC98 @ =0x0000046C
	adds r1, r3, r2
_0813FC88:
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813FC94: .4byte 0x00000484
_0813FC98: .4byte 0x0000046C
