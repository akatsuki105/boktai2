	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081454AC @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081454B0
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _081454B8
	.align 2, 0
_081454AC: .4byte 0x0000025D
_081454B0:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_081454B8:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081454D4 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081454D8
	movs r0, #1
	b _081454DA
	.align 2, 0
_081454D4: .4byte 0x00000474
_081454D8:
	movs r0, #0
_081454DA:
	cmp r0, #0
	beq _081454E6
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_081454E6:
	ldr r1, _08145540 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081454FE
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_081454FE:
	ldr r0, _08145544 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08145516
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_08145516:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814552E
	adds r0, r4, #0
	bl FUN_08002a58
_0814552E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08145548
	movs r0, #1
	b _0814554A
	.align 2, 0
_08145540: .4byte 0x0000044C
_08145544: .4byte 0x0000044D
_08145548:
	movs r0, #0
_0814554A:
	cmp r0, #0
	beq _08145556
	adds r0, r4, #0
	adds r0, #0x7c
	bl CWolfTargetManager_Unregister
_08145556:
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
