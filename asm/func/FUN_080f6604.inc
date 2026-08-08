	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0x80
	lsls r7, r7, #5
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r7
	cmp r0, #0
	beq _080F6630
	movs r1, #0x97
	lsls r1, r1, #3
	adds r4, r5, r1
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r6]
	bics r0, r7
	movs r1, #0
	strh r0, [r6]
	str r1, [r4]
_080F6630:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	ble _080F6640
	b _080F684C
_080F6640:
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _080F666C @ =0xFFFFB634
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _080F6670 @ =0x000004BE
	adds r0, r5, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r7, _080F6674 @ =0x00000474
	adds r1, r5, r7
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _080F6678
	movs r0, #1
	b _080F667A
	.align 2, 0
_080F666C: .4byte 0xFFFFB634
_080F6670: .4byte 0x000004BE
_080F6674: .4byte 0x00000474
_080F6678:
	movs r0, #0
_080F667A:
	cmp r0, #0
	beq _080F668A
	adds r2, r5, #0
	adds r2, #0x7c
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
	str r0, [r2, #4]
_080F668A:
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #0x11
	ldr r2, _080F66F0 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _080F66F4 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _080F66F8 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _080F66FC @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	ldr r0, _080F6700 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F6704
	movs r0, #1
	b _080F6706
	.align 2, 0
_080F66F0: .4byte 0x0000046D
_080F66F4: .4byte 0x0000046B
_080F66F8: .4byte 0x00000469
_080F66FC: .4byte 0x0000046C
_080F6700: .4byte 0x030047A4
_080F6704:
	movs r0, #0
_080F6706:
	cmp r0, #0
	beq _080F6720
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_080ce544
	b _080F6842
_080F6720:
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080F67E2
	movs r1, #0x80
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080F673E
	movs r0, #1
	b _080F6740
_080F673E:
	movs r0, #0
_080F6740:
	cmp r0, #0
	bne _080F67E2
	ldr r1, _080F6780 @ =0x000001DF
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _080F675A
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _080F67C4
_080F675A:
	cmp r1, #5
	beq _080F67C4
	cmp r1, #7
	beq _080F67C4
	cmp r1, #6
	beq _080F67C4
	ldr r2, _080F6784 @ =0x030046A0
	ldr r0, [r2]
	ldr r7, _080F6788 @ =0x00000948
	adds r3, r0, r7
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080F678C @ =0x0000270E
	cmp r1, r0
	bgt _080F6790
	adds r0, r4, #1
	b _080F6794
	.align 2, 0
_080F6780: .4byte 0x000001DF
_080F6784: .4byte 0x030046A0
_080F6788: .4byte 0x00000948
_080F678C: .4byte 0x0000270E
_080F6790:
	ldr r1, _080F67B0 @ =0x0000270F
	adds r0, r1, #0
_080F6794:
	strh r0, [r3]
	ldr r0, [r2]
	movs r7, #0xf8
	lsls r7, r7, #1
	adds r2, r0, r7
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080F67B4 @ =0x0000270E
	cmp r1, r0
	bgt _080F67B8
	adds r0, r3, #1
	b _080F67BC
	.align 2, 0
_080F67B0: .4byte 0x0000270F
_080F67B4: .4byte 0x0000270E
_080F67B8:
	ldr r1, _080F67F0 @ =0x0000270F
	adds r0, r1, #0
_080F67BC:
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_080e9178
_080F67C4:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	bl FUN_0807a798
	movs r7, #0x93
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	ldr r2, _080F67F4 @ =0x00000189
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_0807a840
_080F67E2:
	movs r1, #0x80
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080F67F8
	movs r0, #1
	b _080F67FA
	.align 2, 0
_080F67F0: .4byte 0x0000270F
_080F67F4: .4byte 0x00000189
_080F67F8:
	movs r0, #0
_080F67FA:
	cmp r0, #0
	bne _080F6836
	ldr r0, _080F6810 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F6814
	movs r0, #1
	b _080F6816
	.align 2, 0
_080F6810: .4byte 0x030047A4
_080F6814:
	movs r0, #0
_080F6816:
	cmp r0, #0
	bne _080F6836
	movs r1, #0x80
	lsls r1, r1, #4
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F6836
	ldr r0, _080F6848 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r5]
	bl FUN_080ec5b4
_080F6836:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080F6842:
	movs r0, #1
	b _080F685C
	.align 2, 0
_080F6848: .4byte 0x03002B28
_080F684C:
	ldr r1, _080F6864 @ =0x0000058C
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080F685C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F6864: .4byte 0x0000058C
