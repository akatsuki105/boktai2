	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	bl Hitbox_Unregister
	ldr r2, _08113E00 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08113E04
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _08113E0C
	.align 2, 0
_08113E00: .4byte 0x0000025D
_08113E04:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_08113E0C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08113E28 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08113E2C
	movs r0, #1
	b _08113E2E
	.align 2, 0
_08113E28: .4byte 0x00000474
_08113E2C:
	movs r0, #0
_08113E2E:
	cmp r0, #0
	beq _08113E3A
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_08113E3A:
	ldr r1, _08113E94 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08113E52
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_08113E52:
	ldr r0, _08113E98 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08113E6A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_08113E6A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08113E82
	adds r0, r4, #0
	bl FUN_08002a58
_08113E82:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08113E9C
	movs r0, #1
	b _08113E9E
	.align 2, 0
_08113E94: .4byte 0x0000044C
_08113E98: .4byte 0x0000044D
_08113E9C:
	movs r0, #0
_08113E9E:
	cmp r0, #0
	beq _08113EAA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08113EAA:
	adds r0, r4, #0
	bl Mover_Unlink
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
