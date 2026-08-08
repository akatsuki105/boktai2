	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r0, _080EF5F0 @ =0x03002C60
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _080EF5C0
	b _080EF828
_080EF5C0:
	ldr r5, [r0, #4]
	cmp r5, #0
	bne _080EF5C8
	b _080EF828
_080EF5C8:
	mov r0, sp
	str r0, [sp, #0x14]
	mov r1, sp
	adds r1, #8
	str r1, [sp, #0x10]
_080EF5D2:
	ldr r2, _080EF5F4 @ =0x0000046F
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080EF60C
	ldr r3, _080EF5F8 @ =0x000001DF
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080EF5FC
	movs r0, #1
	b _080EF5FE
	.align 2, 0
_080EF5F0: .4byte 0x03002C60
_080EF5F4: .4byte 0x0000046F
_080EF5F8: .4byte 0x000001DF
_080EF5FC:
	movs r0, #0
_080EF5FE:
	cmp r0, #0
	bne _080EF60C
	ldr r1, _080EF618 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _080EF61C
_080EF60C:
	mov r2, r8
	ldr r2, [r2]
	mov r8, r2
	ldr r5, [r2, #4]
	b _080EF822
	.align 2, 0
_080EF618: .4byte 0x000001DF
_080EF61C:
	ldr r3, _080EF634 @ =0x00000256
	adds r0, r5, r3
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EF638
	adds r0, #4
	b _080EF644
	.align 2, 0
_080EF634: .4byte 0x00000256
_080EF638:
	ldr r0, _080EF6E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EF644:
	ldrh r2, [r0, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080EF6F8
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	ldr r3, _080EF6E4 @ =0x00000472
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r0, r1
	bgt _080EF6F8
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080EF678
	b _080EF81A
_080EF678:
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	bne _080EF686
	ldr r2, _080EF6E8 @ =FUN_080f54e4
_080EF686:
	ldr r0, _080EF6EC @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080EF6F0 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	movs r1, #0x16
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	movs r2, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080EF6F4 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xa
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	b _080EF814
	.align 2, 0
_080EF6E0: .4byte 0x030046A4
_080EF6E4: .4byte 0x00000472
_080EF6E8: .4byte 0x080f54e4+1
_080EF6EC: .4byte 0x0000046D
_080EF6F0: .4byte 0x0000046B
_080EF6F4: .4byte 0x00000469
_080EF6F8:
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	bne _080EF702
	b _080EF81A
_080EF702:
	movs r1, #0x10
	ldr r0, _080EF718 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080EF71C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EF720
	movs r0, #1
	b _080EF722
	.align 2, 0
_080EF718: .4byte 0x030046A0
_080EF71C: .4byte 0x00000934
_080EF720:
	movs r0, #0
_080EF722:
	cmp r0, #0
	beq _080EF81A
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080EF81A
	ldr r1, _080EF774 @ =0x00000256
	adds r0, r5, r1
	ldrh r6, [r0]
	mov sl, sp
	ldr r7, _080EF778 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x14]
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EF77C
	adds r0, #4
	b _080EF786
	.align 2, 0
_080EF774: .4byte 0x00000256
_080EF778: .4byte 0x030046A4
_080EF77C:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080EF786:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #8
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	ldr r1, [sp, #0x10]
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	ldr r3, [sp, #0x10]
	strh r0, [r3, #2]
	ldr r1, [sp, #0x14]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	asrs r0, r0, #5
	ldr r3, _080EF838 @ =0x000001DD
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x20
	str r0, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	subs r3, #0xc7
	adds r2, r5, r3
	strh r0, [r2]
	ldrh r1, [r1]
	ldr r2, _080EF83C @ =0x0000048A
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #0x28
	strh r0, [r1]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x40
	str r0, [r1]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r3, #0x60
	adds r1, r5, r3
_080EF814:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080EF81A:
	mov r0, r8
	ldr r0, [r0]
	mov r8, r0
	ldr r5, [r0, #4]
_080EF822:
	cmp r5, #0
	beq _080EF828
	b _080EF5D2
_080EF828:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EF838: .4byte 0x000001DD
_080EF83C: .4byte 0x0000048A
