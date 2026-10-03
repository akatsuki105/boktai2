	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0x3e
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x80
_0804CE5E:
	lsls r2, r4, #2
	movs r1, #2
	lsls r1, r4
	mov r3, sl
	ldrb r0, [r3, #2]
	ands r0, r1
	movs r3, #0xe6
	adds r3, r3, r5
	mov r8, r3
	cmp r0, #0
	beq _0804CEEC
	ldr r0, _0804CEC0 @ =0x030057E0
	adds r0, r2, r0
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CEEC
	ldrb r0, [r3]
	orrs r1, r0
	movs r0, #0
	mov sb, r0
	strb r1, [r3]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl rfu_UNI_clearRecvNewDataFlag
	adds r1, r5, #0
	adds r1, #0xd0
	adds r0, r1, r4
	ldrb r3, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6]
	adds r7, r1, #0
	cmp r0, r2
	beq _0804CEE6
	adds r0, r3, #0
	cmp r0, r2
	bne _0804CEC4
	adds r1, #4
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r2, sb
	strh r2, [r6, #2]
	b _0804CEE6
	.align 2, 0
_0804CEC0: .4byte 0x030057E0
_0804CEC4:
	cmp r0, r2
	bhs _0804CEDA
	adds r1, r5, #0
	adds r1, #0xdc
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r3, sb
	strh r3, [r6, #2]
	b _0804CEE6
_0804CEDA:
	adds r1, r5, #0
	adds r1, #0xd8
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CEE6:
	adds r1, r7, r4
	ldrb r0, [r6]
	strb r0, [r1]
_0804CEEC:
	adds r6, #4
	adds r4, #1
	cmp r4, #3
	ble _0804CE5E
	mov r0, r8
	ldrb r1, [r0]
	mov r2, sl
	ldrb r0, [r2, #2]
	adds r3, r0, #0
	adds r2, r3, #0
	ands r2, r1
	adds r1, r0, #0
	adds r4, r5, #0
	adds r4, #0xe7
	cmp r2, r1
	bne _0804CF1E
	ldrb r0, [r4]
	ands r3, r0
	cmp r3, r2
	beq _0804CF2A
	adds r1, r5, #0
	adds r1, #0xe4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF1E:
	ldrb r0, [r4]
	mov r3, sl
	ldrb r1, [r3, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804CF3E
_0804CF2A:
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, r1
	beq _0804CF3E
	adds r1, r5, #0
	adds r1, #0xe5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF3E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
