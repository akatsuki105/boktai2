	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807E992
	cmp r1, #0
	blt _0807E992
	ldr r0, _0807E998 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807E992
	ldr r0, _0807E99C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807E9A0
_0807E992:
	movs r4, #0
	b _0807E9AE
	.align 2, 0
_0807E998: .4byte 0x030046A8
_0807E99C: .4byte 0x030046AC
_0807E9A0:
	ldr r0, _0807E9C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807E9AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807E9C4
	adds r0, #4
	b _0807E9D0
	.align 2, 0
_0807E9C0: .4byte 0x030046A4
_0807E9C4:
	ldr r0, _0807EA00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807E9D0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807EA1E
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807EA1E
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _0807EA04 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0807EA08 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EA0C
	movs r0, #1
	b _0807EA0E
	.align 2, 0
_0807EA00: .4byte 0x030046A4
_0807EA04: .4byte 0x030046A0
_0807EA08: .4byte 0x00000934
_0807EA0C:
	movs r0, #0
_0807EA0E:
	cmp r0, #0
	beq _0807EA18
	adds r0, r5, #0
	movs r1, #0x1d
	b _0807EA36
_0807EA18:
	adds r0, r5, #0
	movs r1, #0x1c
	b _0807EA36
_0807EA1E:
	ldr r0, _0807EA40 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xdd
	lsls r7, r7, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0807EA44 @ =0x00001387
	cmp r1, r0
	ble _0807EA48
	adds r0, r5, #0
	movs r1, #0x1e
_0807EA36:
	movs r2, #0
	bl FUN_08060b84
_0807EA3C:
	movs r0, #1
	b _0807EC8E
	.align 2, 0
_0807EA40: .4byte 0x030046A0
_0807EA44: .4byte 0x00001387
_0807EA48:
	movs r7, #0xe5
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA64
	adds r0, r5, #0
	bl FUN_08065cb8
	ldr r1, _0807EA60 @ =0x00000376
	adds r2, r5, r1
	b _0807EA78
	.align 2, 0
_0807EA60: .4byte 0x00000376
_0807EA64:
	ldr r2, _0807EB14 @ =0x00000396
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA7E
	adds r0, r5, #0
	bl FUN_08065e24
	ldr r7, _0807EB18 @ =0x00000376
	adds r2, r5, r7
_0807EA78:
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_0807EA7E:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq _0807EA8C
	b _0807EBA0
_0807EA8C:
	ldr r2, _0807EB1C @ =0x0000043E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807EAB6
	movs r7, #0xf6
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0807EAB6
	ldr r0, _0807EB18 @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r3, [r2]
_0807EAB6:
	ldr r1, _0807EB20 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807EAFC
	ldr r7, _0807EB24 @ =0x000004C7
	adds r2, r5, r7
	ldrb r0, [r2]
	cmp r0, #0
	beq _0807EAFC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r0, _0807EB28 @ =0x000003DA
	adds r6, r5, r0
	ldrh r4, [r6]
	adds r4, #1
	strh r4, [r6]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r1, [r2]
	movs r0, #0x3c
	bl Div
	cmp r4, r0
	blt _0807EAFC
	ldr r1, _0807EB18 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	movs r0, #0
	strh r0, [r6]
_0807EAFC:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, _0807EB2C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0807EB30 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EB34
	movs r0, #1
	b _0807EB36
	.align 2, 0
_0807EB14: .4byte 0x00000396
_0807EB18: .4byte 0x00000376
_0807EB1C: .4byte 0x0000043E
_0807EB20: .4byte 0x000004C5
_0807EB24: .4byte 0x000004C7
_0807EB28: .4byte 0x000003DA
_0807EB2C: .4byte 0x030046A0
_0807EB30: .4byte 0x00000934
_0807EB34:
	movs r0, #0
_0807EB36:
	cmp r0, #0
	beq _0807EB64
	movs r7, #0xf8
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0807EB6E
	ldr r1, _0807EB60 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #0
	strh r0, [r2]
	b _0807EB6E
	.align 2, 0
_0807EB60: .4byte 0x00000376
_0807EB64:
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0x78
	strh r0, [r1]
_0807EB6E:
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r7, #0xde
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EBA0
	ldr r0, _0807EBF8 @ =0x000003E2
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _0807EBA0
	ldr r1, _0807EBFC @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #0
	strh r0, [r2]
_0807EBA0:
	ldr r2, _0807EBFC @ =0x00000376
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807EC0C
	ldr r7, _0807EC00 @ =0x00000446
	adds r0, r5, r7
	ldrh r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _0807EBC2
	ldr r1, _0807EC04 @ =0x00000442
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0807EBC2
	movs r6, #1
_0807EBC2:
	cmp r6, #0
	bne _0807EC0C
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r7, _0807EBFC @ =0x00000376
	adds r4, r5, r7
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0x2c
	movs r7, #0x97
	lsls r7, r7, #4
	adds r2, r5, r7
	str r2, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r2, [r1]
	ldrh r0, [r4]
	cmp r2, r0
	bhs _0807EC08
	strh r6, [r1]
	b _0807EC0C
	.align 2, 0
_0807EBF8: .4byte 0x000003E2
_0807EBFC: .4byte 0x00000376
_0807EC00: .4byte 0x00000446
_0807EC04: .4byte 0x00000442
_0807EC08:
	subs r0, r2, r0
	strh r0, [r1]
_0807EC0C:
	ldr r1, _0807EC98 @ =0x00000376
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r7, _0807EC9C @ =0x00000972
	adds r0, r5, r7
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807EC8C
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807EC8C
	ldr r0, _0807ECA0 @ =0x030047A4
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r4, r0
	cmp r4, #0
	beq _0807EC50
	b _0807EA3C
_0807EC50:
	movs r0, #0x30
	bl CheckItemOwn
	cmp r0, #0
	bne _0807EC5C
	b _0807EA3C
_0807EC5C:
	ldr r2, _0807ECA4 @ =0x000003D6
	adds r0, r5, r2
	strh r4, [r0]
	movs r7, #0xd6
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r0, [r3]
	cmp r0, #0
	bne _0807EC80
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #1
	strh r0, [r3]
_0807EC80:
	movs r0, #0x30
	bl RemoveSpecifiedItem
	adds r0, r5, #0
	bl FUN_080a9e88
_0807EC8C:
	movs r0, #0
_0807EC8E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807EC98: .4byte 0x00000376
_0807EC9C: .4byte 0x00000972
_0807ECA0: .4byte 0x030047A4
_0807ECA4: .4byte 0x000003D6
