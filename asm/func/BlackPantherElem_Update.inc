	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x7c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl SpriteHolder_AdvanceAnim
	ldr r1, _080549DC @ =0x085AB95C
	ldrb r0, [r6, #0xb]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r0, #0
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r4, #0x10
	adds r4, r4, r0
	ldr r2, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r4, #1
	ldrb r0, [r6, #0xa]
	ands r0, r4
	cmp r0, #0
	beq _080549E0
	adds r0, r7, #0
	movs r1, #1
	bl SpriteHolder_SetFlags
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	orrs r1, r4
	str r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r6, r2
	bl ParticleShadow_Hide
	b _08054AB4
	.align 2, 0
_080549DC: .4byte 0x085AB95C
_080549E0:
	adds r0, r7, #0
	movs r1, #1
	bl SpriteHolder_ClearFlags
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	bl ParticleShadow_Show
	movs r0, #0x96
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0x84
	lsls r1, r1, #1
	adds r3, r6, r1
	ldr r0, [r3]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x10
	strh r0, [r2]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r5, [r3]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08054A50
	cmp r1, #0
	blt _08054A50
	ldr r0, _08054A54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08054A50
	ldr r0, _08054A58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08054A5C
_08054A50:
	movs r4, #0
	b _08054A6A
	.align 2, 0
_08054A54: .4byte 0x030046A8
_08054A58: .4byte 0x030046AC
_08054A5C:
	ldr r0, _08054A7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08054A6A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08054A80
	adds r0, #4
	b _08054A8C
	.align 2, 0
_08054A7C: .4byte 0x030046A4
_08054A80:
	ldr r0, _08054AA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08054A8C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08054AA4
	cmp r2, #2
	beq _08054AA8
	b _08054AAC
	.align 2, 0
_08054AA0: .4byte 0x030046A4
_08054AA4:
	ldrb r0, [r5, #4]
	b _08054AAA
_08054AA8:
	ldrb r0, [r5]
_08054AAA:
	subs r1, r1, r0
_08054AAC:
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
_08054AB4:
	adds r0, r6, #0
	adds r0, #0x30
	bl Mover_ApplyMove
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	ldrh r1, [r6, #0x2c]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	cmp r0, #0
	ble _08054ADE
	subs r0, r1, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08054ADE
	movs r0, #3
	strh r0, [r6, #0x2c]
_08054ADE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
