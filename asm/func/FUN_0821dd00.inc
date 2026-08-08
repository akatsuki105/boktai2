	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0821DD1A
	adds r0, r5, #0
	bl FUN_0821d9fc
_0821DD1A:
	ldrh r0, [r4]
	cmp r0, #1
	bne _0821DDAC
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #2
	beq _0821DD34
	cmp r0, #4
	beq _0821DD34
	cmp r0, #6
	bne _0821DDAC
_0821DD34:
	adds r0, r6, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DD4C
	ldr r3, _0821DD48 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	movs r2, #0x20
	b _0821DD54
	.align 2, 0
_0821DD48: .4byte 0xFFFF0000
_0821DD4C:
	ldr r3, _0821DDB4 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	ldr r2, _0821DDB8 @ =0x0000FFE0
_0821DD54:
	orrs r1, r2
	ldr r0, [sp, #0x18]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x18]
	ldr r0, _0821DDBC @ =0x0000FFFF
	ands r1, r0
	movs r0, #0xa0
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, _0821DDC0 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0x50
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	add r2, sp, #0x14
	movs r3, #0
	bl FUN_0807ab64
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_0821d900
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0821d88c
	movs r0, #0xd3
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0821DDAC:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821DDB4: .4byte 0xFFFF0000
_0821DDB8: .4byte 0x0000FFE0
_0821DDBC: .4byte 0x0000FFFF
_0821DDC0: .4byte 0x03002BE0
