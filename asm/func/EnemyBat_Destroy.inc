	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081414C8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081414CC
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _081414D4
	.align 2, 0
_081414C8: .4byte 0x0000025D
_081414CC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_081414D4:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081414F0 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081414F4
	movs r0, #1
	b _081414F6
	.align 2, 0
_081414F0: .4byte 0x00000474
_081414F4:
	movs r0, #0
_081414F6:
	cmp r0, #0
	beq _08141502
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_08141502:
	ldr r1, _0814155C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0814151A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_0814151A:
	ldr r0, _08141560 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08141532
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	movs r0, #1
	strb r0, [r5]
_08141532:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814154A
	adds r0, r4, #0
	bl FUN_08002a58
_0814154A:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08141564
	movs r0, #1
	b _08141566
	.align 2, 0
_0814155C: .4byte 0x0000044C
_08141560: .4byte 0x0000044D
_08141564:
	movs r0, #0
_08141566:
	cmp r0, #0
	beq _08141572
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08141572:
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
