	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _08157298 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815729C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815729E
	.align 2, 0
_08157298: .4byte 0x0000046D
_0815729C:
	movs r0, #0
_0815729E:
	cmp r0, #0
	beq _081572C2
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
	ldr r2, _08157348 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_081572C2:
	ldr r3, _0815734C @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _081573BC
	cmp r4, #0x1e
	bgt _081572D6
	b _08157438
_081572D6:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _08157350 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08157354 @ =0x0000046A
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
	ldr r2, _08157358 @ =0x0000046B
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
	bne _08157360
	ldr r3, _0815735C @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _0815739C
	.align 2, 0
_08157348: .4byte 0x00000482
_0815734C: .4byte 0x00000542
_08157350: .4byte 0x00000469
_08157354: .4byte 0x0000046A
_08157358: .4byte 0x0000046B
_0815735C: .4byte 0x00000541
_08157360:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _081573AC @ =0x0203B400
	mov ip, r7
	ldr r2, _081573B0 @ =0x030046B8
	ldr r7, _081573B4 @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_08157370:
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
	bne _0815738E
	adds r1, #1
	cmp r1, #3
	ble _08157370
	adds r0, r4, #0
_0815738E:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_0815739C:
	strb r0, [r1]
	ldr r3, _081573B8 @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08157438
	.align 2, 0
_081573AC: .4byte 0x0203B400
_081573B0: .4byte 0x030046B8
_081573B4: .4byte 0x000003FF
_081573B8: .4byte 0x00000542
_081573BC:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #0xf
	ble _08157438
	ldr r4, _08157440 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _08157444 @ =0x0000046D
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
	ldr r2, _08157448 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0815744C @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08157450 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _08157454 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08157438:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08157440: .4byte 0x0000054F
_08157444: .4byte 0x0000046D
_08157448: .4byte 0x00000469
_0815744C: .4byte 0x0000046A
_08157450: .4byte 0x00000484
_08157454: .4byte 0xFFFFFBFF
