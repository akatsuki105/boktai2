	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08101C40 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08101C44
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _08101C4C
	.align 2, 0
_08101C40: .4byte 0x0000025D
_08101C44:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_08101C4C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08101C68 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08101C6C
	movs r0, #1
	b _08101C6E
	.align 2, 0
_08101C68: .4byte 0x00000474
_08101C6C:
	movs r0, #0
_08101C6E:
	cmp r0, #0
	beq _08101C7A
	adds r0, r4, #0
	adds r0, #0x48
	bl EntityMsgBus_Unregister
_08101C7A:
	ldr r1, _08101CD4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08101C92
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_08101C92:
	ldr r0, _08101CD8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08101CAA
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_08101CAA:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08101CC2
	adds r0, r4, #0
	bl FUN_08002a58
_08101CC2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08101CDC
	movs r0, #1
	b _08101CDE
	.align 2, 0
_08101CD4: .4byte 0x0000044C
_08101CD8: .4byte 0x0000044D
_08101CDC:
	movs r0, #0
_08101CDE:
	cmp r0, #0
	beq _08101CEA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08101CEA:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl Hitbox_Unregister
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
