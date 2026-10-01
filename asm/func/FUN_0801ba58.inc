	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BA8C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BA7E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BA94
_0801BA7E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BA90 @ =0x08DAA1C8
	b _0801BB72
	.align 2, 0
_0801BA8C: .4byte 0x00000978
_0801BA90: .4byte 0x08DAA1C8
_0801BA94:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x24
	bne _0801BAA0
	cmp r0, #0x25
	beq _0801BAA8
_0801BAA0:
	cmp r0, #0x24
	bne _0801BAC4
	cmp r1, #0x25
	bne _0801BAC4
_0801BAA8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BAC4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BAC0 @ =0x08DAA3C0
	b _0801BB72
	.align 2, 0
_0801BAC0: .4byte 0x08DAA3C0
_0801BAC4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BB00 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BB04 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BB08 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BB0C @ =0x03002CF0
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
	bhi _0801BB10
	movs r4, #0
	b _0801BB1C
	.align 2, 0
_0801BB00: .4byte 0x030046B8
_0801BB04: .4byte 0x000003FF
_0801BB08: .4byte 0x0203B400
_0801BB0C: .4byte 0x03002CF0
_0801BB10:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BB1C
	lsls r4, r4, #1
_0801BB1C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BB24
	movs r0, #1
_0801BB24:
	cmp r0, #0
	beq _0801BB70
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BB50
	cmp r0, #2
	bgt _0801BB38
	cmp r0, #1
	beq _0801BB3E
	b _0801BB70
_0801BB38:
	cmp r0, #3
	beq _0801BB60
	b _0801BB70
_0801BB3E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BB4C @ =0x08DAA27C
	b _0801BB72
	.align 2, 0
_0801BB4C: .4byte 0x08DAA27C
_0801BB50:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BB5C @ =0x08DAA330
	b _0801BB72
	.align 2, 0
_0801BB5C: .4byte 0x08DAA330
_0801BB60:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BB6C @ =0x08DAA39C
	b _0801BB72
	.align 2, 0
_0801BB6C: .4byte 0x08DAA39C
_0801BB70:
	movs r0, #0
_0801BB72:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
