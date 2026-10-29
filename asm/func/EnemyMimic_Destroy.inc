	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08148CD8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08148CDC
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _08148CE4
	.align 2, 0
_08148CD8: .4byte 0x0000025D
_08148CDC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_08148CE4:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08148D00 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08148D04
	movs r0, #1
	b _08148D06
	.align 2, 0
_08148D00: .4byte 0x00000474
_08148D04:
	movs r0, #0
_08148D06:
	cmp r0, #0
	beq _08148D12
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_08148D12:
	ldr r1, _08148D6C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08148D2A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_08148D2A:
	ldr r0, _08148D70 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08148D42
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_08148D42:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08148D5A
	adds r0, r4, #0
	bl FUN_08002a58
_08148D5A:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08148D74
	movs r0, #1
	b _08148D76
	.align 2, 0
_08148D6C: .4byte 0x0000044C
_08148D70: .4byte 0x0000044D
_08148D74:
	movs r0, #0
_08148D76:
	cmp r0, #0
	beq _08148D82
	adds r0, r4, #0
	adds r0, #0x7c
	bl Entity5941_Unregister
_08148D82:
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
