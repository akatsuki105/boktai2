	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r3, #0
	ldr r0, _0800A09C @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A0E8
	cmp r1, #0
	beq _0800A0E8
	ldr r0, _0800A0A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A0B4
	ldr r0, _0800A0A4 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A0B0
	ldr r2, _0800A0A8 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A096
	ldr r4, _0800A0AC @ =0x00000442
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A096
	movs r2, #1
_0800A096:
	adds r0, r2, #0
	b _0800A0E4
	.align 2, 0
_0800A09C: .4byte gClock
_0800A0A0: .4byte 0x030047A4
_0800A0A4: .4byte 0x03002BE0
_0800A0A8: .4byte 0x00000446
_0800A0AC: .4byte 0x00000442
_0800A0B0:
	movs r0, #0
	b _0800A0E4
_0800A0B4:
	ldr r0, _0800A110 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A0E8
	ldr r0, _0800A114 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A0E8
	ldr r0, _0800A118 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A0E2
	ldr r0, _0800A11C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A0E2
	movs r1, #1
_0800A0E2:
	adds r0, r1, #0
_0800A0E4:
	cmp r0, #0
	beq _0800A120
_0800A0E8:
	movs r3, #1
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A0F8:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A104
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A104:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A0F8
	b _0800A142
	.align 2, 0
_0800A110: .4byte 0x03002B48
_0800A114: .4byte 0x030046A0
_0800A118: .4byte 0x03002B8C
_0800A11C: .4byte 0x03002B60
_0800A120:
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A12E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A13A
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A13A:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A12E
_0800A142:
	strb r3, [r5, #0x18]
	movs r4, #0
	ldr r7, _0800A16C @ =0x085AA6B8
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r6, r0, #2
_0800A14E:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A182
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _0800A170
	adds r0, r5, #0
	bl FUN_08009c08
	b _0800A182
	.align 2, 0
_0800A16C: .4byte 0x085AA6B8
_0800A170:
	strb r0, [r1, #8]
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_0800A182:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A14E
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
