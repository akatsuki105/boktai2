	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r3
	adds r7, r5, #0
	movs r0, #1
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r5, r1
	ldr r1, [r3]
	ands r0, r1
	cmp r0, #0
	bne _080E5B4C
	b _080E5D22
_080E5B4C:
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	ldr r3, _080E5B9C @ =0x00000252
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, #0xa
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #8
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	bl FUN_08234f90
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r3, r4, #0
	cmp r2, #0
	blt _080E5B98
	cmp r1, #0
	blt _080E5B98
	ldr r0, _080E5BA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E5B98
	ldr r0, _080E5BA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E5BA8
_080E5B98:
	movs r1, #0
	b _080E5BB6
	.align 2, 0
_080E5B9C: .4byte 0x00000252
_080E5BA0: .4byte 0x030046A8
_080E5BA4: .4byte 0x030046AC
_080E5BA8:
	ldr r0, _080E5BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080E5BB6:
	ldr r6, _080E5BD4 @ =0x00000256
	adds r0, r5, r6
	strh r1, [r0]
	ldrh r4, [r0]
	adds r6, r3, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E5BD8
	adds r0, #4
	b _080E5BE4
	.align 2, 0
_080E5BD0: .4byte 0x030046A4
_080E5BD4: .4byte 0x00000256
_080E5BD8:
	ldr r0, _080E5BF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E5BE4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E5BFC
	cmp r2, #2
	beq _080E5C00
	b _080E5C04
	.align 2, 0
_080E5BF8: .4byte 0x030046A4
_080E5BFC:
	ldrb r0, [r6, #4]
	b _080E5C02
_080E5C00:
	ldrb r0, [r6]
_080E5C02:
	subs r1, r1, r0
_080E5C04:
	strh r1, [r7, #0xa]
	ldr r1, _080E5C20 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _080E5C24
	ldr r2, [r5, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080E5C2E
	.align 2, 0
_080E5C20: .4byte 0x0000025D
_080E5C24:
	ldr r2, [r5, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080E5C2E:
	movs r3, #0
	mov r2, r8
	strb r2, [r7, #5]
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E5C78
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _080E5C98 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _080E5C9C @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xa6
	adds r0, r5, r6
	strh r3, [r0]
	ldr r1, _080E5CA0 @ =0x00000202
	adds r0, r5, r1
	strh r3, [r0]
_080E5C78:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r0, [r2]
	ldr r1, _080E5CA4 @ =0x0000FFFB
	ands r1, r0
	strh r1, [r2]
	movs r3, #2
	ldrb r0, [r4]
	cmp r0, #0
	bne _080E5CA8
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r2, r1, #0
	b _080E5CB4
	.align 2, 0
_080E5C98: .4byte 0xFEFFFFFF
_080E5C9C: .4byte 0xFFFFFDFF
_080E5CA0: .4byte 0x00000202
_080E5CA4: .4byte 0x0000FFFB
_080E5CA8:
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
_080E5CB4:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080E5CC6
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E5CD2
_080E5CC6:
	adds r2, #0x20
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_080E5CD2:
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080E5D2C @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _080E5D30 @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _080E5D34 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	ldr r6, _080E5D38 @ =0x00000584
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0xc
	ldr r6, _080E5D3C @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080E5D40 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_080E5D22:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5D2C: .4byte 0x00000469
_080E5D30: .4byte 0x0000046A
_080E5D34: .4byte 0x00000484
_080E5D38: .4byte 0x00000584
_080E5D3C: .4byte 0x0000046D
_080E5D40: .4byte 0x0000046B
