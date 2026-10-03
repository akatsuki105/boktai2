	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B0A14 @ =0x00000C6C
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_080b02e0
	ldr r1, _080B0A18 @ =0x085AD054
	ldr r2, _080B0A1C @ =0x000012E4
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r0, _080B0A20 @ =0x000012F6
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080B0A28
	ldr r1, _080B0A24 @ =0x00001292
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _080B0A42
	.align 2, 0
_080B0A14: .4byte 0x00000C6C
_080B0A18: .4byte 0x085AD054
_080B0A1C: .4byte 0x000012E4
_080B0A20: .4byte 0x000012F6
_080B0A24: .4byte 0x00001292
_080B0A28:
	ldr r3, _080B0A94 @ =0x00001292
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _080B0A98 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B0A9C @ =0x0000128C
	adds r0, r4, r1
	ldr r2, _080B0AA0 @ =0x00001284
	adds r1, r4, r2
	movs r2, #0
	bl Hitbox_SetPos
_080B0A42:
	ldr r3, _080B0AA4 @ =0x00000C0F
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B0A52
	adds r0, r5, #0
	bl FUN_080af6c4
_080B0A52:
	movs r6, #0x3e
	ldr r1, _080B0AA8 @ =0x0000135C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B0A84
	ldr r3, _080B0AAC @ =0x00001348
	adds r2, r4, r3
	ldr r0, _080B0AB0 @ =0x0000134A
	adds r1, r4, r0
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bhs _080B0A82
	ldrh r3, [r2]
	ldrh r0, [r1]
	subs r0, #0x5a
	cmp r3, r0
	blt _080B0A84
	lsrs r0, r3, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0A84
_080B0A82:
	movs r6, #0x3f
_080B0A84:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080b087c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0A94: .4byte 0x00001292
_080B0A98: .4byte 0x0000FFFB
_080B0A9C: .4byte 0x0000128C
_080B0AA0: .4byte 0x00001284
_080B0AA4: .4byte 0x00000C0F
_080B0AA8: .4byte 0x0000135C
_080B0AAC: .4byte 0x00001348
_080B0AB0: .4byte 0x0000134A
