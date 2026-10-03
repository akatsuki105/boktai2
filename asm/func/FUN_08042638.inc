	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042682
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055ef8
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	ldrb r0, [r5, #1]
	cmp r0, #0xe
	bne _0804267C
	ldr r0, _08042678 @ =0x0000015F
	bl PlaySound_082406e0
	b _08042682
	.align 2, 0
_08042678: .4byte 0x0000015F
_0804267C:
	ldr r0, _08042698 @ =0x00000327
	bl PlaySound_082406e0
_08042682:
	movs r7, #0x40
	movs r0, #0
	mov r8, r0
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	beq _08042758
	cmp r0, #1
	bgt _0804269C
	cmp r0, #0
	beq _080426A4
	b _0804280E
	.align 2, 0
_08042698: .4byte 0x00000327
_0804269C:
	cmp r0, #2
	bne _080426A2
	b _080427F8
_080426A2:
	b _0804280E
_080426A4:
	lsls r0, r6, #2
	subs r0, r7, r0
	mov sb, r0
	cmp r6, #8
	ble _080426BC
	lsls r7, r6, #3
	adds r1, r6, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r8, r0
_080426BC:
	cmp r6, #0xe
	ble _080426C4
	movs r0, #1
	strb r0, [r5, #0x18]
_080426C4:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080426F0
	cmp r1, #0
	blt _080426F0
	ldr r0, _080426F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080426F0
	ldr r0, _080426F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080426FC
_080426F0:
	movs r4, #0
	b _0804270A
	.align 2, 0
_080426F4: .4byte 0x030046A8
_080426F8: .4byte 0x030046AC
_080426FC:
	ldr r0, _0804271C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0804270A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08042720
	adds r0, #4
	b _0804272C
	.align 2, 0
_0804271C: .4byte 0x030046A4
_08042720:
	ldr r0, _08042754 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0804272C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r0, #0xd0
	mov r1, sb
	adds r2, r7, #0
	movs r3, #0
	bl FUN_08055f80
	b _0804280E
	.align 2, 0
_08042754: .4byte 0x030046A4
_08042758:
	movs r0, #0xc8
	muls r0, r6, r0
	adds r0, #0xa0
	mov r8, r0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0804278C
	cmp r1, #0
	blt _0804278C
	ldr r0, _08042790 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0804278C
	ldr r0, _08042794 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08042798
_0804278C:
	movs r4, #0
	b _080427A6
	.align 2, 0
_08042790: .4byte 0x030046A8
_08042794: .4byte 0x030046AC
_08042798:
	ldr r0, _080427B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080427A6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080427BC
	adds r0, #4
	b _080427C8
	.align 2, 0
_080427B8: .4byte 0x030046A4
_080427BC:
	ldr r0, _080427F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080427C8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	cmp r6, #7
	ble _0804280E
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	ldrb r0, [r5, #0x18]
	adds r0, #1
	strb r0, [r5, #0x18]
	b _0804280E
	.align 2, 0
_080427F4: .4byte 0x030046A4
_080427F8:
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, #0xff
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #2
	bl FUN_08055f1c
_0804280E:
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	ldrb r0, [r5, #1]
	cmp r0, #3
	beq _0804284C
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_0804284C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
