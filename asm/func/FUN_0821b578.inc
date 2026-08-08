	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x74]
	cmp r0, #0
	bne _0821B58C
	ldr r0, [r7, #0x70]
	adds r0, #1
	str r0, [r7, #0x70]
_0821B58C:
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r7, #0x6c]
	cmp r0, #4
	bls _0821B59C
	b _0821B70A
_0821B59C:
	lsls r0, r0, #2
	ldr r1, _0821B5A8 @ =_0821B5AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821B5A8: .4byte _0821B5AC
_0821B5AC: @ jump table
	.4byte _0821B5C0 @ case 0
	.4byte _0821B5D6 @ case 1
	.4byte _0821B65C @ case 2
	.4byte _0821B690 @ case 3
	.4byte _0821B6E6 @ case 4
_0821B5C0:
	movs r1, #0
	str r1, [r7, #0x74]
	ldr r0, [r7, #0x70]
	cmp r0, #0x37
	bgt _0821B5CC
	b _0821B70A
_0821B5CC:
	movs r0, #1
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	str r0, [r7, #0x74]
	b _0821B70A
_0821B5D6:
	ldr r0, [r7, #0x74]
	movs r1, #0
	mov r8, r1
	str r1, [r7, #0x74]
	cmp r0, #0
	beq _0821B5E6
	movs r0, #2
	strb r0, [r7, #0x1f]
_0821B5E6:
	ldr r6, _0821B650 @ =0x0203B400
	ldr r4, _0821B654 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _0821B658 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x34]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x34]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x36]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x36]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x38]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x38]
	ldr r0, [r7, #0x70]
	cmp r0, #0x3a
	ble _0821B70A
	movs r0, #2
	str r0, [r7, #0x6c]
	mov r0, r8
	b _0821B6DE
	.align 2, 0
_0821B650: .4byte 0x0203B400
_0821B654: .4byte 0x030046B8
_0821B658: .4byte 0x000003FF
_0821B65C:
	movs r3, #0
	str r3, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	subs r1, #0x42
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x30
	ble _0821B682
	subs r0, r2, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
_0821B682:
	ldr r0, [r7, #0x70]
	cmp r0, #6
	ble _0821B70A
	movs r0, #3
	str r0, [r7, #0x6c]
	str r3, [r7, #0x70]
	b _0821B6E0
_0821B690:
	movs r0, #0
	str r0, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0x20
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x3f
	bgt _0821B6AE
	adds r0, r2, #4
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0821B6AE:
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r0, [r1]
	adds r0, #0x64
	strh r0, [r1]
	ldr r0, [r7, #0x70]
	cmp r0, #2
	ble _0821B6D2
	movs r1, #3
	bl Mod
	cmp r0, #0
	bne _0821B6D2
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r7, #0
	bl FUN_0821b35c
_0821B6D2:
	ldr r0, [r7, #0x70]
	cmp r0, #0x1d
	ble _0821B70A
	movs r0, #4
	str r0, [r7, #0x6c]
	movs r0, #0
_0821B6DE:
	str r0, [r7, #0x70]
_0821B6E0:
	movs r0, #1
	str r0, [r7, #0x74]
	b _0821B70A
_0821B6E6:
	ldr r1, [r7, #0x74]
	movs r0, #0
	str r0, [r7, #0x74]
	cmp r1, #0
	beq _0821B6F8
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
_0821B6F8:
	ldr r1, [r7, #0x70]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	ble _0821B72E
	adds r0, r7, #0
	bl KillEntity
	b _0821B72E
_0821B70A:
	ldr r0, [r7, #0x68]
	movs r1, #3
	bl Mod
	cmp r0, #1
	bgt _0821B71E
	cmp r0, #0
	blt _0821B71E
	movs r0, #1
	b _0821B720
_0821B71E:
	movs r0, #0
_0821B720:
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_0821b470
	ldr r0, [r7, #0x68]
	adds r0, #1
	str r0, [r7, #0x68]
_0821B72E:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
