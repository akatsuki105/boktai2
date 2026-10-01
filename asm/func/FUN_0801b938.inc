	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801B96C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B95E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801B974
_0801B95E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801B970 @ =0x08DA9F1C
	b _0801BA52
	.align 2, 0
_0801B96C: .4byte 0x00000978
_0801B970: .4byte 0x08DA9F1C
_0801B974:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x11
	bne _0801B980
	cmp r0, #0x12
	beq _0801B988
_0801B980:
	cmp r0, #0x11
	bne _0801B9A4
	cmp r1, #0x12
	bne _0801B9A4
_0801B988:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801B9A4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801B9A0 @ =0x08DAA114
	b _0801BA52
	.align 2, 0
_0801B9A0: .4byte 0x08DAA114
_0801B9A4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801B9E0 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801B9E4 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801B9E8 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801B9EC @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801B9F0
	movs r4, #0
	b _0801B9FC
	.align 2, 0
_0801B9E0: .4byte 0x030046B8
_0801B9E4: .4byte 0x000003FF
_0801B9E8: .4byte 0x0203B400
_0801B9EC: .4byte 0x03002CF0
_0801B9F0:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801B9FC
	lsls r4, r4, #1
_0801B9FC:
	movs r0, #0
	cmp r2, r4
	bgt _0801BA04
	movs r0, #1
_0801BA04:
	cmp r0, #0
	beq _0801BA50
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BA30
	cmp r0, #2
	bgt _0801BA18
	cmp r0, #1
	beq _0801BA1E
	b _0801BA50
_0801BA18:
	cmp r0, #3
	beq _0801BA40
	b _0801BA50
_0801BA1E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BA2C @ =0x08DA9FD0
	b _0801BA52
	.align 2, 0
_0801BA2C: .4byte 0x08DA9FD0
_0801BA30:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BA3C @ =0x08DAA084
	b _0801BA52
	.align 2, 0
_0801BA3C: .4byte 0x08DAA084
_0801BA40:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BA4C @ =0x08DAA0F0
	b _0801BA52
	.align 2, 0
_0801BA4C: .4byte 0x08DAA0F0
_0801BA50:
	movs r0, #0
_0801BA52:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
