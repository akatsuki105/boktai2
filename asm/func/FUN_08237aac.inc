	push {r4, r5, r6, lr}
	ldr r0, _08237AF0 @ =0x04000122
	ldrh r0, [r0]
	adds r3, r0, #0
	ldr r0, _08237AF4 @ =0x04000124
	ldrh r0, [r0]
	adds r2, r0, #0
	ldr r0, _08237AF8 @ =0x04000126
	ldrh r0, [r0]
	adds r4, r0, #0
	movs r5, #0
	ldr r0, _08237AFC @ =0x030046BC
	strh r3, [r0]
	ldr r0, _08237B00 @ =0x04000128
	ldrh r1, [r0]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _08237ADC
	ldr r0, _08237B04 @ =0x0000FFFF
	cmp r2, r0
	bne _08237AE6
	cmp r4, r2
	beq _08237B1C
_08237ADC:
	ldr r0, _08237B04 @ =0x0000FFFF
	cmp r2, r0
	bne _08237AE6
	cmp r4, r2
	beq _08237B0C
_08237AE6:
	ldr r1, _08237B08 @ =0x030046D4
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237B90
	.align 2, 0
_08237AF0: .4byte 0x04000122
_08237AF4: .4byte 0x04000124
_08237AF8: .4byte 0x04000126
_08237AFC: .4byte 0x030046BC
_08237B00: .4byte 0x04000128
_08237B04: .4byte 0x0000FFFF
_08237B08: .4byte 0x030046D4
_08237B0C:
	ldr r1, _08237B18 @ =0x030046D4
	movs r0, #8
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237B90
	.align 2, 0
_08237B18: .4byte 0x030046D4
_08237B1C:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r3
	ldr r6, _08237BB0 @ =0x03000790
	cmp r0, #0
	beq _08237B46
	cmp r3, r4
	beq _08237B46
	ldr r1, _08237BB4 @ =0x030007A0
	ldr r2, _08237BB8 @ =0x03000788
	ldr r0, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08237B46:
	ldr r0, [r6]
	cmp r0, #0x3e
	ble _08237B52
	movs r0, #0x80
	lsls r0, r0, #7
	orrs r5, r0
_08237B52:
	ldr r6, _08237BBC @ =0x0300079C
	ldr r4, [r6]
	cmp r4, #0
	ble _08237B82
	movs r0, #0x80
	lsls r0, r0, #7
	ands r3, r0
	cmp r3, #0
	bne _08237B82
	ldr r0, _08237BC0 @ =0x030007E0
	ldr r2, _08237BC4 @ =0x03000798
	ldr r1, [r2]
	adds r0, r1, r0
	ldrb r0, [r0]
	orrs r5, r0
	adds r1, #1
	movs r0, #0x3f
	ands r1, r0
	str r1, [r2]
	subs r0, r4, #1
	str r0, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r5, r0
_08237B82:
	ldr r0, _08237BC8 @ =0x0000FFFF
	cmp r5, r0
	bne _08237B8C
	movs r5, #0x80
	lsls r5, r5, #8
_08237B8C:
	ldr r0, _08237BCC @ =0x0400012A
	strh r5, [r0]
_08237B90:
	ldr r2, _08237BD0 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08237BD4 @ =0x0400010C
	ldr r2, _08237BD8 @ =0x0000F5D8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08237BDC @ =0x030046C0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237BB0: .4byte 0x03000790
_08237BB4: .4byte 0x030007A0
_08237BB8: .4byte 0x03000788
_08237BBC: .4byte 0x0300079C
_08237BC0: .4byte 0x030007E0
_08237BC4: .4byte 0x03000798
_08237BC8: .4byte 0x0000FFFF
_08237BCC: .4byte 0x0400012A
_08237BD0: .4byte 0x04000128
_08237BD4: .4byte 0x0400010C
_08237BD8: .4byte 0x0000F5D8
_08237BDC: .4byte 0x030046C0
