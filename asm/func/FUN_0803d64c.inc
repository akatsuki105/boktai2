	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r7, #0
	ldr r2, _0803D698 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803D69C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0803d618
	cmp r0, #0
	beq _0803D66E
	b _0803D824
_0803D66E:
	ldr r2, _0803D6A0 @ =0x085AAF2C
	movs r0, #0xab
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r3, _0803D6A4 @ =0x000002B7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #6
	bls _0803D68C
	b _0803D7E8
_0803D68C:
	lsls r0, r0, #2
	ldr r1, _0803D6A8 @ =_0803D6AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D698: .4byte 0x030046B8
_0803D69C: .4byte 0x000003FF
_0803D6A0: .4byte 0x085AAF2C
_0803D6A4: .4byte 0x000002B7
_0803D6A8: .4byte _0803D6AC
_0803D6AC: @ jump table
	.4byte _0803D6C8 @ case 0
	.4byte _0803D72C @ case 1
	.4byte _0803D7A4 @ case 2
	.4byte _0803D7A8 @ case 3
	.4byte _0803D7AC @ case 4
	.4byte _0803D7B0 @ case 5
	.4byte _0803D7C2 @ case 6
_0803D6C8:
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r6, r7, r0
	adds r4, r5, #0
	adds r4, #0x50
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r8, r1
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #6
	mov r3, r8
	bl Map_FindPathNodeBeyond
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #0
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0803D728 @ =0x0000FFFF
	cmp r1, r0
	bgt _0803D71C
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #6
	mov r3, r8
	bl Map_FindPathNodeBeyond
_0803D71C:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x40
	b _0803D78A
	.align 2, 0
_0803D728: .4byte 0x0000FFFF
_0803D72C:
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r6, r7, r1
	adds r4, r5, #0
	adds r4, #0x50
	movs r2, #0xc0
	lsls r2, r2, #2
	mov r8, r2
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #4
	mov r3, r8
	bl Map_FindPathNodeBeyond
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #0
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0803D7A0 @ =0x0000FFFF
	cmp r1, r0
	bgt _0803D780
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	mov r3, r8
	bl Map_FindPathNodeBeyond
_0803D780:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x20
_0803D78A:
	strh r0, [r1]
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _0803D7E8
	.align 2, 0
_0803D7A0: .4byte 0x0000FFFF
_0803D7A4:
	movs r0, #7
	b _0803D7D2
_0803D7A8:
	movs r0, #9
	b _0803D7D2
_0803D7AC:
	movs r0, #3
	b _0803D7D2
_0803D7B0:
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x3f
	ble _0803D7BE
	movs r0, #7
	b _0803D7D2
_0803D7BE:
	movs r0, #8
	b _0803D7D2
_0803D7C2:
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x3f
	ble _0803D7D0
	movs r0, #3
	b _0803D7D2
_0803D7D0:
	movs r0, #0xb
_0803D7D2:
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_0803D7E8:
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0803D824
	movs r0, #0
	strh r0, [r1]
	ldr r2, _0803D830 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803D834 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0803D838 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, _0803D83C @ =0x03002CF0
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #3
	ands r0, r1
	ldr r2, _0803D840 @ =0x000002B7
	adds r1, r7, r2
	strb r0, [r1]
_0803D824:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D830: .4byte 0x030046B8
_0803D834: .4byte 0x000003FF
_0803D838: .4byte 0x0203B400
_0803D83C: .4byte 0x03002CF0
_0803D840: .4byte 0x000002B7
