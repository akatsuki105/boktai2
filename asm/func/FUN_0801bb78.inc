	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BBAC @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BB9E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BBB4
_0801BB9E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BBB0 @ =0x08DAA474
	b _0801BC92
	.align 2, 0
_0801BBAC: .4byte 0x00000978
_0801BBB0: .4byte 0x08DAA474
_0801BBB4:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x37
	bne _0801BBC0
	cmp r0, #0x38
	beq _0801BBC8
_0801BBC0:
	cmp r0, #0x37
	bne _0801BBE4
	cmp r1, #0x38
	bne _0801BBE4
_0801BBC8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BBE4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BBE0 @ =0x08DAA66C
	b _0801BC92
	.align 2, 0
_0801BBE0: .4byte 0x08DAA66C
_0801BBE4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BC20 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BC24 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BC28 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BC2C @ =0x03002CF0
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
	bhi _0801BC30
	movs r4, #0
	b _0801BC3C
	.align 2, 0
_0801BC20: .4byte 0x030046B8
_0801BC24: .4byte 0x000003FF
_0801BC28: .4byte 0x0203B400
_0801BC2C: .4byte 0x03002CF0
_0801BC30:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BC3C
	lsls r4, r4, #1
_0801BC3C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BC44
	movs r0, #1
_0801BC44:
	cmp r0, #0
	beq _0801BC90
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BC70
	cmp r0, #2
	bgt _0801BC58
	cmp r0, #1
	beq _0801BC5E
	b _0801BC90
_0801BC58:
	cmp r0, #3
	beq _0801BC80
	b _0801BC90
_0801BC5E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BC6C @ =0x08DAA528
	b _0801BC92
	.align 2, 0
_0801BC6C: .4byte 0x08DAA528
_0801BC70:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BC7C @ =0x08DAA5DC
	b _0801BC92
	.align 2, 0
_0801BC7C: .4byte 0x08DAA5DC
_0801BC80:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BC8C @ =0x08DAA648
	b _0801BC92
	.align 2, 0
_0801BC8C: .4byte 0x08DAA648
_0801BC90:
	movs r0, #0
_0801BC92:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
