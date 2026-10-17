	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _080CD9E0 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080CD97A
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cd738
_080CD97A:
	adds r0, r5, #0
	bl FUN_080cd6ec
	adds r2, r0, #0
	ldr r6, _080CD9E4 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _080CD998
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _080CD9A6
_080CD998:
	strh r4, [r1]
	ldr r1, _080CD9E8 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080cd5a0
_080CD9A6:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r4, [r2]
	cmp r4, #0
	beq _080CD9B4
	b _080CDADE
_080CD9B4:
	adds r0, r5, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CDA40
	ldr r6, _080CD9EC @ =0x00000121
	adds r0, r0, r6
	ldr r2, _080CD9F0 @ =0x00000962
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _080CD9F4 @ =0x03003584
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r3, _080CD9F8 @ =0x00000964
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080CD9FC
	adds r2, r1, #0
	b _080CDA12
	.align 2, 0
_080CD9E0: .4byte 0x00000951
_080CD9E4: .4byte 0x0000094C
_080CD9E8: .4byte 0x0000094E
_080CD9EC: .4byte 0x00000121
_080CD9F0: .4byte 0x00000962
_080CD9F4: .4byte 0x03003584
_080CD9F8: .4byte 0x00000964
_080CD9FC:
	cmp r1, #0x2f
	bhi _080CDA04
	movs r2, #0x20
	b _080CDA12
_080CDA04:
	cmp r1, #0x4f
	bhi _080CDA10
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _080CDA12
_080CDA10:
	movs r2, #0
_080CDA12:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cd780
	ldr r6, _080CDA3C @ =0x00000964
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _080CDA36
	b _080CDBA0
_080CDA36:
	movs r0, #0
	b _080CDB9E
	.align 2, 0
_080CDA3C: .4byte 0x00000964
_080CDA40:
	ldr r0, _080CDA7C @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _080CDAAE
	ldr r1, _080CDA80 @ =0x03003584
	ldr r6, _080CDA84 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080CDA6E
	movs r0, #0x30
	strh r0, [r3]
_080CDA6E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _080CDA88
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDA9C
	.align 2, 0
_080CDA7C: .4byte 0x00000964
_080CDA80: .4byte 0x03003584
_080CDA84: .4byte 0x00000962
_080CDA88:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080CDA9C
	strh r4, [r3]
_080CDA9C:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080cd780
	b _080CDBA0
_080CDAAE:
	strh r4, [r3]
	ldr r1, _080CDAC8 @ =0x00000359
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDACC
	adds r1, r5, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	b _080CDBA0
	.align 2, 0
_080CDAC8: .4byte 0x00000359
_080CDACC:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r5, r6
	str r0, [r1, #0xc]
	b _080CDBA0
_080CDADE:
	ldr r1, _080CDB24 @ =0x00000964
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _080CDB76
	ldr r1, _080CDB28 @ =0x03003584
	ldr r2, _080CDB2C @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _080CDB30 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDB4E
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_080CDB14:
	subs r0, r3, #5
	cmp r0, #1
	bls _080CDB1E
	cmp r3, #0xd
	bne _080CDB34
_080CDB1E:
	ldrh r0, [r4]
	b _080CDB36
	.align 2, 0
_080CDB24: .4byte 0x00000964
_080CDB28: .4byte 0x03003584
_080CDB2C: .4byte 0x0000095E
_080CDB30: .4byte 0x00000359
_080CDB34:
	ldrh r0, [r1]
_080CDB36:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _080CDB14
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _080CDB94
_080CDB4E:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_080CDB56:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _080CDB56
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080CDB94
_080CDB76:
	ldr r1, _080CDBA8 @ =0x03003584
	ldr r3, _080CDBAC @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080cd780
_080CDB94:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
_080CDB9E:
	strh r0, [r1]
_080CDBA0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CDBA8: .4byte 0x03003584
_080CDBAC: .4byte 0x0000095E
