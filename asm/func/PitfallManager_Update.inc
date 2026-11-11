	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x38
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D0D34 @ =0x030047A4
	ldr r1, _081D0D38 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D0D7A
	movs r1, #4
	ldr r0, _081D0D3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D0D7A
	ldr r0, [r6, #0x68]
	cmp r0, #0
	beq _081D0D7A
	movs r5, #0
	ldr r7, _081D0D40 @ =0x085AE098
	adds r4, r3, #0
_081D0D24:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081D0D44
	movs r0, #1
	b _081D0D46
	.align 2, 0
_081D0D34: .4byte 0x030047A4
_081D0D38: .4byte 0x030047A0
_081D0D3C: .4byte 0x03002BC0
_081D0D40: .4byte 0x085AE098
_081D0D44:
	movs r0, #0
_081D0D46:
	cmp r0, #0
	beq _081D0D72
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081D0D72
	adds r0, r2, #0
	adds r0, #0xb6
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_081D0D72:
	adds r4, #4
	adds r5, #1
	cmp r5, #0xb
	ble _081D0D24
_081D0D7A:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
