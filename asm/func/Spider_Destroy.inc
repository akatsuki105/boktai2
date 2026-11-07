	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08131110 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08131114
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _0813111C
	.align 2, 0
_08131110: .4byte 0x0000025D
_08131114:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_0813111C:
	ldr r0, [r4, #0x44]
	bl Free
	ldr r1, _08131158 @ =0x0000044C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08131136
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl AuxShadow_Remove
_08131136:
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
	adds r0, r4, #0
	adds r0, #0xd8
	bl Hitbox_Unregister
	adds r0, r4, #0
	bl Enemy_Unregister
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08131158: .4byte 0x0000044C
