	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	ldr r5, _0809DA1C @ =0x0000CB05
	ldr r1, _0809DA20 @ =0x0000B343
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0809D954
	b _0809DD12
_0809D954:
	mov r1, r8
	adds r1, #0x28
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r4, r8
	adds r4, #0x28
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _0809DA24 @ =0x00005D04
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x24]
	cmp r2, #0
	bne _0809D982
	b _0809DD12
_0809D982:
	mov r1, r8
	adds r1, #0x48
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	mov r4, r8
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _0809DA28 @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x28]
	cmp r2, #0
	bne _0809D9B0
	b _0809DD12
_0809D9B0:
	mov r1, r8
	adds r1, #0x68
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r4, r6}
	stm r1!, {r4, r6}
	mov r4, r8
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _0809DA2C @ =0x0000DE23
	adds r0, r5, #0
	bl GetFile
	adds r2, r0, #0
	str r4, [sp, #0x1c]
	cmp r2, #0
	bne _0809D9DE
	b _0809DD12
_0809D9DE:
	adds r4, #0x20
	adds r1, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r6, #0
	str r4, [sp, #0x20]
	add r0, sp, #0x10
	mov sl, r0
	mov r5, r8
	adds r5, #0xa8
	mov sb, r6
_0809DA04:
	mov r1, r8
	ldr r0, [r1, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DA5A
	cmp r6, #0
	bne _0809DA30
	movs r4, #0x3c
	movs r7, #0x30
	b _0809DA34
	.align 2, 0
_0809DA1C: .4byte 0x0000CB05
_0809DA20: .4byte 0x0000B343
_0809DA24: .4byte 0x00005D04
_0809DA28: .4byte 0x0000DCC1
_0809DA2C: .4byte 0x0000DE23
_0809DA30:
	movs r4, #0
	movs r7, #0x31
_0809DA34:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r3, sb
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r4, sl
	str r4, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl MainSprite_Add
	b _0809DAB2
_0809DA5A:
	adds r0, r6, #0
	bl GetWeaponID
	adds r4, r0, #0
	movs r7, #0x30
	cmp r4, #0
	bne _0809DA6A
	movs r7, #0x31
_0809DA6A:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl MainSprite_Add
	adds r0, r6, #0
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809DAA8
	adds r0, r5, #0
	ldr r1, _0809DAA4 @ =0x000002DF
	bl FUN_080b95bc
	b _0809DAB2
	.align 2, 0
_0809DAA4: .4byte 0x000002DF
_0809DAA8:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
_0809DAB2:
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0809DA04
	add r5, sp, #0x10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0
	movs r3, #0x31
	bl MainSprite_Add
	movs r0, #0xf9
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x40
	movs r3, #0x31
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	movs r5, #0xed
	lsls r5, r5, #3
	add r5, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0x39
	movs r3, #0x30
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _0809DC58 @ =0x00000828
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x41
	movs r3, #0x31
	bl MainSprite_Add
	movs r6, #0
	add r4, sp, #0x10
	mov sl, r4
_0809DB4A:
	adds r1, r6, #0
	movs r5, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x20
	mov r1, sl
	strh r0, [r1]
	asrs r0, r6, #1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r1, #2]
	movs r3, #0
	strh r3, [r1, #4]
	ldr r0, _0809DC5C @ =0x00000F71
	add r0, r8
	ldrb r0, [r0]
	asrs r0, r6
	ands r0, r5
	movs r4, #0x31
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _0809DB7E
	movs r5, #0x30
	str r5, [sp, #0x18]
_0809DB7E:
	movs r7, #0
	lsls r1, r6, #1
	adds r0, r6, #1
	mov sb, r0
	add r5, sp, #0x10
	adds r0, #0x15
	adds r4, r1, r0
_0809DB8C:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0xa8
	add r0, r8
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0
	ldr r3, [sp, #0x18]
	bl MainSprite_Add
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _0809DB8C
	mov r6, sb
	cmp r6, #3
	ble _0809DB4A
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	movs r0, #0xe1
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0xcf
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC60 @ =0x00000D68
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x93
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC64 @ =0x00000DC8
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x15
	movs r3, #0x30
	bl MainSprite_Add
	movs r0, #0xf7
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0809DC40
	movs r0, #0xdd
	lsls r0, r0, #4
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_0809DC40:
	mov r4, r8
	ldr r0, [r4, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809DC68
	cmp r0, #1
	ble _0809DC80
	cmp r0, #2
	beq _0809DC74
	b _0809DC80
	.align 2, 0
_0809DC58: .4byte 0x00000828
_0809DC5C: .4byte 0x00000F71
_0809DC60: .4byte 0x00000D68
_0809DC64: .4byte 0x00000DC8
_0809DC68:
	ldr r2, _0809DC70 @ =0x0000016B
	movs r4, #0x26
	b _0809DC84
	.align 2, 0
_0809DC70: .4byte 0x0000016B
_0809DC74:
	ldr r2, _0809DC7C @ =0x000002F9
	movs r4, #0x27
	b _0809DC84
	.align 2, 0
_0809DC7C: .4byte 0x000002F9
_0809DC80:
	movs r2, #4
	movs r4, #0x1d
_0809DC84:
	ldr r0, _0809DC9C @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0809DCA0
	adds r0, r1, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809DCA0
	movs r0, #1
	b _0809DCA2
	.align 2, 0
_0809DC9C: .4byte 0x03002C68
_0809DCA0:
	movs r0, #0
_0809DCA2:
	cmp r0, #0
	beq _0809DCC0
	ldr r0, [r3]
	cmp r0, #0
	bne _0809DCB2
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DCB6
_0809DCB2:
	movs r5, #0x18
	ldrsh r0, [r0, r5]
_0809DCB6:
	adds r4, r0, #0
	adds r4, #0x22
	cmp r0, #0
	bge _0809DCC0
	movs r4, #0x22
_0809DCC0:
	movs r3, #0
	movs r1, #0x24
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	ldr r0, _0809DD24 @ =0x00000888
	add r0, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl MainSprite_Add
	ldr r0, _0809DD28 @ =0x000008C2
	add r0, r8
	strh r4, [r0]
	movs r3, #0x8d
	lsls r3, r3, #4
	add r3, r8
	ldr r2, _0809DD2C @ =0x03003584
	ldrh r1, [r0]
	lsls r1, r1, #5
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0809DD30 @ =0x00000E58
	add r0, r8
	bl FUN_080b99a0
	mov r0, r8
	bl FUN_0809d300
	mov r0, r8
	bl FUN_0809d00c
_0809DD12:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809DD24: .4byte 0x00000888
_0809DD28: .4byte 0x000008C2
_0809DD2C: .4byte 0x03003584
_0809DD30: .4byte 0x00000E58
