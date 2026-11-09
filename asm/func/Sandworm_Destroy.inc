	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_0817759c
	ldr r0, _0817A4E8 @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A4D6
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_0817A4D6:
	ldr r2, _0817A4EC @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817A4F0
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _0817A4F8
	.align 2, 0
_0817A4E8: .4byte 0x0000044C
_0817A4EC: .4byte 0x0000025D
_0817A4F0:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_0817A4F8:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0817A514 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0817A518
	movs r0, #1
	b _0817A51A
	.align 2, 0
_0817A514: .4byte 0x00000474
_0817A518:
	movs r0, #0
_0817A51A:
	cmp r0, #0
	beq _0817A526
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_0817A526:
	ldr r1, _0817A580 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A53E
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_0817A53E:
	ldr r0, _0817A584 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0817A556
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ElementalCondEmitter_Destroy
	movs r0, #1
	strb r0, [r5]
_0817A556:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0817A56E
	adds r0, r4, #0
	bl FUN_08002a58
_0817A56E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0817A588
	movs r0, #1
	b _0817A58A
	.align 2, 0
_0817A580: .4byte 0x0000044C
_0817A584: .4byte 0x0000044D
_0817A588:
	movs r0, #0
_0817A58A:
	cmp r0, #0
	beq _0817A596
	adds r0, r4, #0
	adds r0, #0x7c
	bl CWolfTargetManager_Unregister
_0817A596:
	adds r0, r4, #0
	bl Mover_Unlink
	adds r0, r4, #0
	adds r0, #0xd8
	bl Hitbox_Unregister
	adds r0, r4, #0
	bl Enemy_Unregister
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
