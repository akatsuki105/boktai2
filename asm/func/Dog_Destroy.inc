	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08151930 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08151934
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _0815193C
	.align 2, 0
_08151930: .4byte 0x0000025D
_08151934:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_0815193C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08151958 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815195C
	movs r0, #1
	b _0815195E
	.align 2, 0
_08151958: .4byte 0x00000474
_0815195C:
	movs r0, #0
_0815195E:
	cmp r0, #0
	beq _0815196A
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_0815196A:
	ldr r1, _081519C4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08151982
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_08151982:
	ldr r0, _081519C8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0815199A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_0815199A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081519B2
	adds r0, r4, #0
	bl FUN_08002a58
_081519B2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081519CC
	movs r0, #1
	b _081519CE
	.align 2, 0
_081519C4: .4byte 0x0000044C
_081519C8: .4byte 0x0000044D
_081519CC:
	movs r0, #0
_081519CE:
	cmp r0, #0
	beq _081519DA
	adds r0, r4, #0
	adds r0, #0x7c
	bl CWolfTargetManager_Unregister
_081519DA:
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
