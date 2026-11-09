	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08194418 @ =0x000003E5
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_0818f808
	ldr r0, _0819441C @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08194404
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_08194404:
	ldr r2, _08194420 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08194424
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _0819442C
	.align 2, 0
_08194418: .4byte 0x000003E5
_0819441C: .4byte 0x0000044C
_08194420: .4byte 0x0000025D
_08194424:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_0819442C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08194448 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0819444C
	movs r0, #1
	b _0819444E
	.align 2, 0
_08194448: .4byte 0x00000474
_0819444C:
	movs r0, #0
_0819444E:
	cmp r0, #0
	beq _0819445A
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_0819445A:
	ldr r1, _081944B4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08194472
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_08194472:
	ldr r0, _081944B8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0819448A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ElementalCondEmitter_Destroy
	movs r0, #1
	strb r0, [r5]
_0819448A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081944A2
	adds r0, r4, #0
	bl FUN_08002a58
_081944A2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081944BC
	movs r0, #1
	b _081944BE
	.align 2, 0
_081944B4: .4byte 0x0000044C
_081944B8: .4byte 0x0000044D
_081944BC:
	movs r0, #0
_081944BE:
	cmp r0, #0
	beq _081944CA
	adds r0, r4, #0
	adds r0, #0x7c
	bl CWolfTargetManager_Unregister
_081944CA:
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
