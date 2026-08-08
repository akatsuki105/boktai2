	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, _080636A4 @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _080636A8 @ =0x030046A0
	ldr r5, [r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r3, r0, r2
	ldr r2, [r3]
	cmp r2, #0
	ble _080636C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080636B4
	ldr r7, _080636AC @ =0x00000942
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bgt _080636B0
	movs r0, #0
	b _080636B2
	.align 2, 0
_080636A4: .4byte 0x0000038E
_080636A8: .4byte 0x030046A0
_080636AC: .4byte 0x00000942
_080636B0:
	subs r0, r2, r0
_080636B2:
	str r0, [r3]
_080636B4:
	movs r6, #6
	ldr r2, _080636C0 @ =0x00000958
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080636E0
	.align 2, 0
_080636C0: .4byte 0x00000958
_080636C4:
	ldr r7, _080636F0 @ =0x00000958
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080636E0
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080636DC
	movs r6, #6
_080636DC:
	subs r0, r2, #1
	strh r0, [r3]
_080636E0:
	movs r5, #0
_080636E2:
	cmp r5, #1
	beq _080636FA
	cmp r5, #1
	bgt _080636F4
	cmp r5, #0
	beq _08063748
	b _080637C4
	.align 2, 0
_080636F0: .4byte 0x00000958
_080636F4:
	cmp r5, #2
	beq _08063798
	b _080637C4
_080636FA:
	ldr r0, _0806371C @ =0x0000043E
	adds r2, r4, r0
	ldrh r1, [r2]
	cmp r1, #0
	beq _08063724
	ldr r0, [r4, #0x1c]
	ands r0, r5
	cmp r0, #0
	beq _08063710
	subs r0, r1, #1
	strh r0, [r2]
_08063710:
	movs r6, #2
	ldr r2, _08063720 @ =0x00000956
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080637C4
	.align 2, 0
_0806371C: .4byte 0x0000043E
_08063720: .4byte 0x00000956
_08063724:
	ldr r7, _08063744 @ =0x00000956
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080637C4
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806373C
	movs r6, #2
_0806373C:
	subs r0, r2, #1
	strh r0, [r3]
	b _080637C4
	.align 2, 0
_08063744: .4byte 0x00000956
_08063748:
	ldr r0, _08063790 @ =0x0000043C
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080637C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	subs r0, r2, #1
	strh r0, [r3]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	movs r2, #0x98
	lsls r2, r2, #4
	adds r0, r4, r2
	str r0, [sp]
	ldr r7, _08063794 @ =0x00000984
	adds r0, r4, r7
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	subs r7, #8
	adds r3, r4, r7
	bl FUN_08016e0c
	b _080637C4
	.align 2, 0
_08063790: .4byte 0x0000043C
_08063794: .4byte 0x00000984
_08063798:
	movs r0, #0x88
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080637C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	subs r0, r2, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080637C4
	ldr r0, _080637D4 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x10]
	ldr r2, _080637D8 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_080637C4:
	adds r5, #1
	cmp r5, #2
	ble _080636E2
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080637D4: .4byte 0x030046A0
_080637D8: .4byte 0x00000456
