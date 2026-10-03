	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BDA54 @ =0x00001784
	adds r7, r5, r0
	ldr r1, _080BDA58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BDA5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r6, _080BDA60 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BDA6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bcdec
	ldr r1, _080BDA64 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA34
	b _080BDC5A
_080BDA34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BDA68 @ =0x00001657
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BDA4E
	b _080BDC5A
_080BDA4E:
	movs r0, #0
	strb r0, [r1]
	b _080BDC5A
	.align 2, 0
_080BDA54: .4byte 0x00001784
_080BDA58: .4byte 0x00000C78
_080BDA5C: .4byte 0x00000C18
_080BDA60: .4byte 0x030044E0
_080BDA64: .4byte 0x00000EB8
_080BDA68: .4byte 0x00001657
_080BDA6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bcdec
	ldr r0, _080BDAD4 @ =0x00000EB8
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA90
	b _080BDC34
_080BDA90:
	ldr r2, _080BDAD8 @ =0x00001787
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BDAF0
	ldr r0, _080BDADC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDAE0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080bce20
	ldr r2, _080BDAE4 @ =0x000017B4
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BDAE8 @ =0x000015D8
	adds r0, r5, r1
	adds r1, #0x7e
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDAEC @ =FUN_080bddc0
	b _080BDC26
	.align 2, 0
_080BDAD4: .4byte 0x00000EB8
_080BDAD8: .4byte 0x00001787
_080BDADC: .4byte 0x00000107
_080BDAE0: .4byte 0x00001644
_080BDAE4: .4byte 0x000017B4
_080BDAE8: .4byte 0x000015D8
_080BDAEC: .4byte FUN_080bddc0
_080BDAF0:
	ldr r2, _080BDB54 @ =0x00001785
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BDBA8
	movs r6, #1
	ldr r1, _080BDB58 @ =0x00001654
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r4, [r4]
	adds r0, r0, r4
	ldr r2, _080BDB5C @ =0x0000165C
	adds r1, r5, r2
	adds r1, r1, r0
	movs r3, #0
	ldrsb r3, [r1, r3]
	cmp r3, #0
	ble _080BDB48
	ldr r0, _080BDB60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _080BDB64 @ =0x08DA9E68
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0xa]
	cmp r2, r0
	blt _080BDB48
	ldr r2, _080BDB68 @ =0x0000168C
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BDB44
	movs r6, #0
_080BDB44:
	cmp r6, #0
	bne _080BDB6C
_080BDB48:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDC5A
	.align 2, 0
_080BDB54: .4byte 0x00001785
_080BDB58: .4byte 0x00001654
_080BDB5C: .4byte 0x0000165C
_080BDB60: .4byte 0x030046A0
_080BDB64: .4byte 0x08DA9E68
_080BDB68: .4byte 0x0000168C
_080BDB6C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDBA4 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDBA4: .4byte 0x00000F38
_080BDBA8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDC08 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r4, [r4]
	adds r0, r4, #0
	bl GetWeaponID
	adds r6, r0, #0
	adds r0, r4, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	bge _080BDBFC
	cmp r6, #0
	ble _080BDBFC
	ldr r0, _080BDC0C @ =0x08DA9E68
	lsls r1, r6, #3
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	bne _080BDC14
_080BDBFC:
	ldr r2, _080BDC10 @ =0x00001784
	adds r0, r5, r2
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDC08: .4byte 0x00000F38
_080BDC0C: .4byte 0x08DA9E68
_080BDC10: .4byte 0x00001784
_080BDC14:
	adds r0, r7, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BDC1C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
	ldr r1, _080BDC30 @ =FUN_080bdc64
_080BDC26:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDC5A
	.align 2, 0
_080BDC30: .4byte FUN_080bdc64
_080BDC34:
	adds r0, r7, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BDC5A
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
_080BDC5A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
