	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r2, r1, #0
	ldr r1, _0807A604 @ =0x030046A0
	ldr r3, [r1]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r4, #0
	ldrsh r5, [r0, r4]
	mov r8, r1
	cmp r5, #5
	bne _0807A610
	ldr r0, _0807A608 @ =0x08DA9E68
	ldr r1, _0807A60C @ =0x00000874
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0807A6C0
	.align 2, 0
_0807A604: .4byte 0x030046A0
_0807A608: .4byte 0x08DA9E68
_0807A60C: .4byte 0x00000874
_0807A610:
	ldrb r0, [r6, #1]
	adds r7, r0, #0
	cmp r7, #4
	bne _0807A646
	movs r0, #4
	bl FUN_0807a8c0
	cmp r0, #0x62
	ble _0807A62A
	ldrb r0, [r6, #4]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0807A6C0
_0807A62A:
	movs r0, #4
	bl FUN_0807a8c0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	lsls r0, r0, #1
	b _0807A6C0
_0807A646:
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	adds r4, r1, r0
	cmp r2, #0
	beq _0807A67E
	ldrb r0, [r2, #3]
	cmp r0, #2
	beq _0807A670
	cmp r0, #2
	bgt _0807A664
	cmp r0, #1
	beq _0807A66A
	b _0807A67E
_0807A664:
	cmp r0, #3
	beq _0807A67A
	b _0807A67E
_0807A66A:
	cmp r5, #0
	beq _0807A67A
	b _0807A674
_0807A670:
	cmp r5, #0
	bne _0807A67A
_0807A674:
	ldrb r0, [r2, #4]
	subs r4, r4, r0
	b _0807A67E
_0807A67A:
	ldrb r0, [r2, #4]
	adds r4, r4, r0
_0807A67E:
	cmp r4, #0x63
	ble _0807A684
	movs r4, #0x63
_0807A684:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r4, r0
	asrs r4, r0, #1
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0807A6B0
	movs r0, #3
	bl FUN_0807a8c0
	mov r2, r8
	ldr r1, [r2]
	adds r1, #0x40
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	asrs r0, r0, #2
	b _0807A6BE
_0807A6B0:
	movs r1, #8
	ldrsh r0, [r6, r1]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	cmp r0, #0
	bge _0807A6BE
	movs r0, #0
_0807A6BE:
	adds r0, r4, r0
_0807A6C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
