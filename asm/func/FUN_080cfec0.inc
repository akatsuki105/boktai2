	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFEEA
	cmp r1, #0
	blt _080CFEEA
	ldr r0, _080CFEF0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFEEA
	ldr r0, _080CFEF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFEF8
_080CFEEA:
	movs r4, #0
	b _080CFF06
	.align 2, 0
_080CFEF0: .4byte 0x030046A8
_080CFEF4: .4byte 0x030046AC
_080CFEF8:
	ldr r0, _080CFF18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF06:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080CFF1C
	adds r0, #4
	b _080CFF28
	.align 2, 0
_080CFF18: .4byte 0x030046A4
_080CFF1C:
	ldr r0, _080CFF3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFF28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CFF40
	cmp r2, #2
	beq _080CFF44
	b _080CFF48
	.align 2, 0
_080CFF3C: .4byte 0x030046A4
_080CFF40:
	ldrb r0, [r5, #4]
	b _080CFF46
_080CFF44:
	ldrb r0, [r5]
_080CFF46:
	subs r1, r1, r0
_080CFF48:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _080CFFC4
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFF74
	cmp r1, #0
	blt _080CFF74
	ldr r0, _080CFF78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFF74
	ldr r0, _080CFF7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFF80
_080CFF74:
	movs r4, #0
	b _080CFF8E
	.align 2, 0
_080CFF78: .4byte 0x030046A8
_080CFF7C: .4byte 0x030046AC
_080CFF80:
	ldr r0, _080CFFA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF8E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080CFFA4
	adds r0, #4
	b _080CFFB0
	.align 2, 0
_080CFFA0: .4byte 0x030046A4
_080CFFA4:
	ldr r0, _080CFFC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFFB0:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CFFC4
	movs r0, #0
	b _080CFFC6
	.align 2, 0
_080CFFC0: .4byte 0x030046A4
_080CFFC4:
	movs r0, #1
_080CFFC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
