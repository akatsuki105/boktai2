	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0819ff9c
	adds r0, r4, #0
	bl Ax_RemoveAfterimages
	adds r0, r4, #0
	bl FUN_0819fca4
	ldr r1, _081A18F0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A18F4
	ldr r0, [r4, #0x44]
	bl AuxSprite_Remove
	b _081A18FC
	.align 2, 0
_081A18F0: .4byte 0x0000025D
_081A18F4:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl MainSprite_Remove
_081A18FC:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081A1918 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081A191C
	movs r0, #1
	b _081A191E
	.align 2, 0
_081A1918: .4byte 0x00000474
_081A191C:
	movs r0, #0
_081A191E:
	cmp r0, #0
	beq _081A192A
	adds r0, r4, #0
	adds r0, #0x48
	bl MsgQueue_Unregister
_081A192A:
	ldr r1, _081A1984 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A1942
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Remove
	movs r0, #1
	strb r0, [r5]
_081A1942:
	ldr r0, _081A1988 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A195A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ElementalCondEmitter_Destroy
	movs r0, #1
	strb r0, [r5]
_081A195A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081A1972
	adds r0, r4, #0
	bl FUN_08002a58
_081A1972:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081A198C
	movs r0, #1
	b _081A198E
	.align 2, 0
_081A1984: .4byte 0x0000044C
_081A1988: .4byte 0x0000044D
_081A198C:
	movs r0, #0
_081A198E:
	cmp r0, #0
	beq _081A199A
	adds r0, r4, #0
	adds r0, #0x7c
	bl CWolfTargetManager_Unregister
_081A199A:
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
