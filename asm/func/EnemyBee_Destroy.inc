	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081696A0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081696A4
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _081696AC
	.align 2, 0
_081696A0: .4byte 0x0000025D
_081696A4:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_081696AC:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081696C8 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081696CC
	movs r0, #1
	b _081696CE
	.align 2, 0
_081696C8: .4byte 0x00000474
_081696CC:
	movs r0, #0
_081696CE:
	cmp r0, #0
	beq _081696DA
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_081696DA:
	ldr r1, _08169734 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081696F2
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_081696F2:
	ldr r0, _08169738 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816970A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_0816970A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08169722
	adds r0, r4, #0
	bl FUN_08002a58
_08169722:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816973C
	movs r0, #1
	b _0816973E
	.align 2, 0
_08169734: .4byte 0x0000044C
_08169738: .4byte 0x0000044D
_0816973C:
	movs r0, #0
_0816973E:
	cmp r0, #0
	beq _0816974A
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0816974A:
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
