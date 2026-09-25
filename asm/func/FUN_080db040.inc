	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	bne _080DB056
	adds r0, r5, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DB056:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0x12
	bne _080DB06C
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #0x51
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
_080DB06C:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	movs r2, #2
	cmp r0, #0x3c
	bgt _080DB07E
	movs r2, #0
	cmp r0, #0x28
	ble _080DB07E
	movs r2, #1
_080DB07E:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	ldr r1, _080DB0A4 @ =0x085AD310
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _080DB0AC
	ldr r1, [r7]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DB0A8
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _080DB0AA
	.align 2, 0
_080DB0A4: .4byte 0x085AD310
_080DB0A8:
	orrs r1, r2
_080DB0AA:
	str r1, [r7]
_080DB0AC:
	ldrh r1, [r5, #0x3c]
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	cmp r0, #0x5a
	ble _080DB0EC
	adds r6, r5, #0
	adds r6, #0x42
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4, #0x38]
	bics r0, r1
	str r0, [r4, #0x38]
	movs r4, #0
	strh r4, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x4c
	bl Hitbox_Unregister
	adds r0, r7, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
	ldr r0, _080DB0E8 @ =0x0000FFFF
	strh r0, [r6]
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	b _080DB0F0
	.align 2, 0
_080DB0E8: .4byte 0x0000FFFF
_080DB0EC:
	adds r0, r1, #1
	strh r0, [r5, #0x3c]
_080DB0F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
