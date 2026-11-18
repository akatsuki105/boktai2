	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081C9F88 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9F8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9F8E
	.align 2, 0
_081C9F88: .4byte 0x0000046D
_081C9F8C:
	movs r0, #0
_081C9F8E:
	cmp r0, #0
	beq _081C9FB2
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _081CA038 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_081C9FB2:
	ldr r3, _081CA03C @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _081CA0AC
	cmp r4, #0x14
	bgt _081C9FC6
	b _081CA128
_081C9FC6:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _081CA040 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081CA044 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r1, #2
	adds r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _081CA048 @ =0x0000046B
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _081CA050
	ldr r3, _081CA04C @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _081CA08C
	.align 2, 0
_081CA038: .4byte 0x00000482
_081CA03C: .4byte 0x00000542
_081CA040: .4byte 0x00000469
_081CA044: .4byte 0x0000046A
_081CA048: .4byte 0x0000046B
_081CA04C: .4byte 0x00000541
_081CA050:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _081CA09C @ =0x0203B400
	mov ip, r7
	ldr r2, _081CA0A0 @ =0x030046B8
	ldr r7, _081CA0A4 @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_081CA060:
	ldr r0, [r2]
	adds r0, #1
	ands r0, r7
	str r0, [r2]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _081CA07E
	adds r1, #1
	cmp r1, #3
	ble _081CA060
	adds r0, r4, #0
_081CA07E:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_081CA08C:
	strb r0, [r1]
	ldr r3, _081CA0A8 @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _081CA128
	.align 2, 0
_081CA09C: .4byte 0x0203B400
_081CA0A0: .4byte 0x030046B8
_081CA0A4: .4byte 0x000003FF
_081CA0A8: .4byte 0x00000542
_081CA0AC:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #6
	ble _081CA128
	ldr r4, _081CA130 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _081CA134 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #0xe4
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #0xb
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _081CA138 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081CA13C @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _081CA140 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _081CA144 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CA128:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CA130: .4byte 0x0000054F
_081CA134: .4byte 0x0000046D
_081CA138: .4byte 0x00000469
_081CA13C: .4byte 0x0000046A
_081CA140: .4byte 0x00000484
_081CA144: .4byte 0xFFFFFBFF
