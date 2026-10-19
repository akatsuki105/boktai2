	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0808619C @ =0x000003CE
	adds r1, r5, r2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl Coffin_CreateEffSprite
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086198
	cmp r1, #0
	blt _08086198
	ldr r0, _080861A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086198
	ldr r0, _080861A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080861A8
_08086198:
	movs r4, #0
	b _080861B6
	.align 2, 0
_0808619C: .4byte 0x000003CE
_080861A0: .4byte 0x030046A8
_080861A4: .4byte 0x030046AC
_080861A8:
	ldr r0, _080861C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080861B6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080861CC
	adds r0, #4
	b _080861D8
	.align 2, 0
_080861C8: .4byte 0x030046A4
_080861CC:
	ldr r0, _080861EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080861D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080861F0
	cmp r2, #2
	beq _080861F4
	b _080861F8
	.align 2, 0
_080861EC: .4byte 0x030046A4
_080861F0:
	ldrb r0, [r6, #4]
	b _080861F6
_080861F4:
	ldrb r0, [r6]
_080861F6:
	subs r1, r1, r0
_080861F8:
	ldr r2, _0808622C @ =0x0000035A
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08086218
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	bl EnemyTargetManager_Remove
	movs r0, #0
	strb r0, [r4]
_08086218:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	movs r1, #5
	bl Coffin_SetState
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808622C: .4byte 0x0000035A
