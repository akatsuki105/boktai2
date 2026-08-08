	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08223B00 @ =0x030044E0
	ldr r0, [r0]
	cmp r0, #0
	beq _08223B16
	ldr r1, _08223B04 @ =0x00000F58
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	ldr r0, _08223B08 @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _08223AF4
	cmp r0, #0
	beq _08223AF4
	cmp r0, #4
	bne _08223B0C
_08223AF4:
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08223B14
	.align 2, 0
_08223B00: .4byte 0x030044E0
_08223B04: .4byte 0x00000F58
_08223B08: .4byte 0x030047E0
_08223B0C:
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08223BBC @ =0x00002A30
_08223B14:
	strh r0, [r1]
_08223B16:
	ldr r1, _08223BC0 @ =0x00000F58
	adds r0, r4, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	ble _08223BB4
	ldr r1, _08223BC4 @ =0x00000F14
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08223BB4
	subs r2, #7
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08223BC8 @ =0x00000F16
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #4
	adds r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _08223BC8 @ =0x00000F16
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x50
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08223BCC @ =0x00000F18
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _08223B8A
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08223B8A
	ldr r2, _08223BD0 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _08223BD4 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08223BD8 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_08223B8A:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08223BDC @ =0x00000F4C
	adds r1, r4, r2
	ldr r0, _08223BE0 @ =FUN_08223bf0
	str r0, [r1]
	ldr r1, _08223BE4 @ =0x00000E38
	adds r0, r4, r1
	strh r3, [r0]
	ldr r2, _08223BE8 @ =0x00000DBA
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _08223BEC @ =0x00000F36
	adds r0, r4, r2
	strh r1, [r0]
_08223BB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08223BBC: .4byte 0x00002A30
_08223BC0: .4byte 0x00000F58
_08223BC4: .4byte 0x00000F14
_08223BC8: .4byte 0x00000F16
_08223BCC: .4byte 0x00000F18
_08223BD0: .4byte 0x00000DEC
_08223BD4: .4byte 0x00000F42
_08223BD8: .4byte 0x00000DF2
_08223BDC: .4byte 0x00000F4C
_08223BE0: .4byte FUN_08223bf0
_08223BE4: .4byte 0x00000E38
_08223BE8: .4byte 0x00000DBA
_08223BEC: .4byte 0x00000F36
