	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080F0700 @ =0x030047A4
	ldr r1, _080F0704 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _080F06CA
	b _080F07C8
_080F06CA:
	movs r1, #4
	ldr r0, _080F0708 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F07C8
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080F078C
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080F070C @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080F0710
	movs r0, #1
	b _080F0712
	.align 2, 0
_080F0700: .4byte 0x030047A4
_080F0704: .4byte 0x030047A0
_080F0708: .4byte 0x03002BC0
_080F070C: .4byte 0x030046A0
_080F0710:
	movs r0, #0
_080F0712:
	cmp r0, #0
	bne _080F0720
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f07d0
	b _080F07C8
_080F0720:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F074C
	ldr r1, _080F0788 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F074C
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080F074C:
	adds r0, r4, #0
	bl FUN_080eafdc
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e35b4
	adds r0, r4, #0
	bl FUN_080e191c
	adds r0, r4, #0
	bl FUN_080eb168
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _080F07CA
	.align 2, 0
_080F0788: .4byte 0x00000624
_080F078C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080F07C2
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080F07B0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080F07B4
	movs r0, #1
	b _080F07B6
	.align 2, 0
_080F07B0: .4byte 0x030046A0
_080F07B4:
	movs r0, #0
_080F07B6:
	cmp r0, #0
	beq _080F07C2
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f0914
_080F07C2:
	adds r0, r4, #0
	bl FUN_080f06ac
_080F07C8:
	movs r0, #0
_080F07CA:
	pop {r4}
	pop {r1}
	bx r1
