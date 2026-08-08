	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #1
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _080F08F8
	adds r0, r6, #0
	bl FUN_080e4a68
	ldr r2, _080F0900 @ =0x0000044C
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F0896
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r6, r3
	bl FUN_08013698
_080F0896:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F0904 @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r5, #0
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_080ee2c8
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _080F0908 @ =0x00000469
	adds r0, r6, r3
	strb r4, [r0]
	ldr r1, _080F090C @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r6, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r6, r3
	strb r7, [r0]
	ldr r1, _080F0910 @ =0x00000584
	adds r0, r6, r1
	ldr r2, [r0]
	movs r1, #0xc
	adds r3, #1
	adds r0, r6, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
_080F08F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F0900: .4byte 0x0000044C
_080F0904: .4byte 0x0000FFFB
_080F0908: .4byte 0x00000469
_080F090C: .4byte 0x0000046A
_080F0910: .4byte 0x00000584
