	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080EE5A4 @ =0x00000252
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r5, r6, #0
	adds r5, #0x9c
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0xb
	adds r0, r6, r2
	ldrb r2, [r0]
	ldrb r3, [r3]
	adds r0, r5, #0
	bl FUN_08234de8
	ldr r1, _080EE5A8 @ =0x000004A4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, r6, #0
	adds r4, #8
	adds r1, r4, #0
	bl FUN_082362fc
	str r5, [r6, #0x24]
	ldrh r0, [r6, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080EE59E
	cmp r1, #0
	blt _080EE59E
	ldr r0, _080EE5AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080EE59E
	ldr r0, _080EE5B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EE5B4
_080EE59E:
	movs r1, #0
	b _080EE5C2
	.align 2, 0
_080EE5A4: .4byte 0x00000252
_080EE5A8: .4byte 0x000004A4
_080EE5AC: .4byte 0x030046A8
_080EE5B0: .4byte 0x030046AC
_080EE5B4:
	ldr r0, _080EE5E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080EE5C2:
	ldr r2, _080EE5E4 @ =0x00000256
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EE5E8
	adds r0, #4
	b _080EE5F4
	.align 2, 0
_080EE5E0: .4byte 0x030046A4
_080EE5E4: .4byte 0x00000256
_080EE5E8:
	ldr r0, _080EE608 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EE5F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080EE60C
	cmp r2, #2
	beq _080EE610
	b _080EE614
	.align 2, 0
_080EE608: .4byte 0x030046A4
_080EE60C:
	ldrb r0, [r5, #4]
	b _080EE612
_080EE610:
	ldrb r0, [r5]
_080EE612:
	subs r1, r1, r0
_080EE614:
	strh r1, [r6, #0xa]
	ldr r1, _080EE630 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _080EE634
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080EE63E
	.align 2, 0
_080EE630: .4byte 0x0000025D
_080EE634:
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080EE63E:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r5, #0
	strh r5, [r0]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #8
	bl ClearMemory
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	movs r2, #0x80
	lsls r2, r2, #0xe
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r4, r6, r1
	cmp r0, #0
	beq _080EE6A4
	ldr r1, _080EE6C8 @ =0xFEFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _080EE6CC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080EE6D0 @ =0x0000021E
	adds r0, r6, r1
	strh r5, [r0]
	subs r2, #0x1a
	adds r0, r6, r2
	strh r5, [r0]
_080EE6A4:
	ldr r1, _080EE6D4 @ =0x0000047A
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080EE6D8
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080EE6E4
	.align 2, 0
_080EE6C8: .4byte 0xFEFFFFFF
_080EE6CC: .4byte 0xFFFFFDFF
_080EE6D0: .4byte 0x0000021E
_080EE6D4: .4byte 0x0000047A
_080EE6D8:
	ldr r2, [r6, #0x44]
	ldr r0, _080EE714 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080EE6E4:
	ldr r1, _080EE718 @ =0xFDFF7FFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r1, _080EE71C @ =0xFFFFBE3F
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r1, _080EE720 @ =0x00000494
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080EE724 @ =0x00000492
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #2
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080EE728
	ldr r0, [r6, #0x44]
	strb r1, [r0, #7]
	b _080EE72E
	.align 2, 0
_080EE714: .4byte 0x03003584
_080EE718: .4byte 0xFDFF7FFF
_080EE71C: .4byte 0xFFFFBE3F
_080EE720: .4byte 0x00000494
_080EE724: .4byte 0x00000492
_080EE728:
	ldr r0, [r6, #0x44]
	adds r0, #0x3a
	strb r1, [r0]
_080EE72E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
