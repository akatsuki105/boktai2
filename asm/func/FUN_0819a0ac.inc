	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r6, r0, #0
	ldr r0, _0819A1DC @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r6, #0x18]
	ldr r0, _0819A1E0 @ =0x00000B0C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xae
	lsls r1, r1, #4
	adds r7, r6, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r6, #0x1c]
	strh r2, [r6, #0x1e]
	strh r2, [r6, #0x20]
	strh r2, [r6, #0x24]
	movs r4, #1
	movs r1, #1
	strh r1, [r6, #0x26]
	strh r2, [r6, #0x28]
	adds r5, r6, #0
	adds r5, #0x45
	strb r3, [r5]
	strh r2, [r6, #0x36]
	adds r0, r6, #0
	adds r0, #0x46
	strb r3, [r0]
	adds r0, #0x10
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	subs r0, #5
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	subs r0, #0xa
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	ldrb r0, [r5]
	orrs r1, r0
	strb r1, [r5]
	ldr r3, _0819A1E4 @ =0x00000C38
	adds r1, r6, r3
	ldr r0, _0819A1E8 @ =FUN_081976c4
	str r0, [r1]
	movs r4, #0xc6
	lsls r4, r4, #4
	adds r1, r6, r4
	ldr r0, _0819A1EC @ =FUN_081958b4
	str r0, [r1]
	ldr r5, _0819A1F0 @ =0x00000C5C
	adds r0, r6, r5
	str r2, [r0]
	ldr r0, _0819A1F4 @ =0x00000C68
	adds r1, r6, r0
	movs r0, #0x14
	str r0, [r1]
	ldr r1, _0819A1F8 @ =0x00005291
	mov r0, r8
	bl Video_GetAuxSprite
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r1, _0819A1FC @ =0x00000AEC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0819A200 @ =0x00000CC6
	adds r1, r6, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	add r3, sp, #0x24
	mov sl, r3
	mov r4, r8
	ldr r2, [r4, #0xc]
	adds r5, #0x44
	adds r1, r6, r5
	movs r0, #0xf
	mov sb, r0
_0819A166:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r4, sb
	cmp r4, #0
	bge _0819A166
	movs r5, #0xca
	lsls r5, r5, #4
	adds r0, r6, r5
	mov r1, r8
	str r0, [r1, #0xc]
	ldr r2, _0819A204 @ =0x00000CC2
	adds r1, r6, r2
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r3, _0819A208 @ =0x00000CC3
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _0819A20C @ =0x00000CC4
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _0819A210 @ =0x00000B28
	adds r0, r6, r5
	ldr r3, _0819A214 @ =0x00000AFC
	adds r1, r6, r3
	movs r3, #0x30
	str r3, [sp]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r2, #0x30
	bl AuxShadow_Init
	movs r0, #0x41
	bl VM_SeekToNamedArg
	adds r4, r6, #0
	adds r4, #0x42
	str r4, [sp, #0x34]
	adds r5, r6, #0
	adds r5, #0x40
	str r5, [sp, #0x30]
	cmp r0, #0
	beq _0819A28A
	bl VM_GetPC
	cmp r0, #0
	beq _0819A218
	bl VM_GetValue
	b _0819A21A
	.align 2, 0
_0819A1DC: .4byte 0x03002BE0
_0819A1E0: .4byte 0x00000B0C
_0819A1E4: .4byte 0x00000C38
_0819A1E8: .4byte FUN_081976c4
_0819A1EC: .4byte FUN_081958b4
_0819A1F0: .4byte 0x00000C5C
_0819A1F4: .4byte 0x00000C68
_0819A1F8: .4byte 0x00005291
_0819A1FC: .4byte 0x00000AEC
_0819A200: .4byte 0x00000CC6
_0819A204: .4byte 0x00000CC2
_0819A208: .4byte 0x00000CC3
_0819A20C: .4byte 0x00000CC4
_0819A210: .4byte 0x00000B28
_0819A214: .4byte 0x00000AFC
_0819A218:
	movs r0, #0
_0819A21A:
	strh r0, [r6, #0x36]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A22A
	bl VM_GetValue
	b _0819A22C
_0819A22A:
	movs r0, #0
_0819A22C:
	strh r0, [r6, #0x38]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A23C
	bl VM_GetValue
	b _0819A23E
_0819A23C:
	movs r0, #0
_0819A23E:
	strh r0, [r6, #0x3a]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A24E
	bl VM_GetValue
	b _0819A250
_0819A24E:
	movs r0, #0
_0819A250:
	strh r0, [r6, #0x3c]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A260
	bl VM_GetValue
	b _0819A262
_0819A260:
	movs r0, #0
_0819A262:
	adds r4, r6, #0
	adds r4, #0x42
	strh r0, [r4]
	bl VM_GetPC
	str r4, [sp, #0x34]
	cmp r0, #0
	beq _0819A278
	bl VM_GetValue
	b _0819A27A
_0819A278:
	movs r0, #0
_0819A27A:
	adds r2, r6, #0
	adds r2, #0x40
	strh r0, [r2]
	ldrh r1, [r6, #0x36]
	ldr r3, _0819A2BC @ =0x00000CCC
	adds r0, r6, r3
	strh r1, [r0]
	str r2, [sp, #0x30]
_0819A28A:
	movs r0, #0x54
	bl VM_SeekToNamedArg
	movs r4, #0x1c
	adds r4, r4, r7
	mov r8, r4
	adds r5, r6, #0
	adds r5, #0x60
	str r5, [sp, #0x38]
	cmp r0, #0
	beq _0819A328
	movs r5, #0
	movs r0, #1
	mov sb, r0
_0819A2A6:
	ldr r1, _0819A2C0 @ =0x00000C74
	adds r0, r6, r1
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2C4
	bl VM_GetValue
	b _0819A2C6
	.align 2, 0
_0819A2BC: .4byte 0x00000CCC
_0819A2C0: .4byte 0x00000C74
_0819A2C4:
	movs r0, #0
_0819A2C6:
	strh r0, [r4]
	ldr r2, _0819A2DC @ =0x00000C78
	adds r0, r6, r2
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2E0
	bl VM_GetValue
	b _0819A2E2
	.align 2, 0
_0819A2DC: .4byte 0x00000C78
_0819A2E0:
	movs r0, #0
_0819A2E2:
	strh r0, [r4]
	ldr r3, _0819A2F8 @ =0x00000C7C
	adds r0, r6, r3
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2FC
	bl VM_GetValue
	b _0819A2FE
	.align 2, 0
_0819A2F8: .4byte 0x00000C7C
_0819A2FC:
	movs r0, #0
_0819A2FE:
	strh r0, [r4]
	movs r4, #0xc8
	lsls r4, r4, #4
	adds r0, r6, r4
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A316
	bl VM_GetValue
	b _0819A318
_0819A316:
	movs r0, #0
_0819A318:
	strh r0, [r4]
	adds r5, #2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _0819A2A6
_0819A328:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A344
	bl VM_GetValue
	strh r0, [r7, #0x1c]
	bl VM_GetValue
	strh r0, [r7, #0x1e]
	bl VM_GetValue
	b _0819A348
_0819A344:
	strh r0, [r7, #0x1c]
	strh r0, [r7, #0x1e]
_0819A348:
	strh r0, [r7, #0x20]
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetNamedArgValue
	ldr r2, _0819A578 @ =0x00000CCE
	adds r1, r6, r2
	strb r0, [r1]
	mov r0, r8
	bl Map_GetTileHeightAt
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r0, [r7, #0x1e]
	ldr r2, _0819A57C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _0819A580 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x20]
	movs r0, #0
	str r0, [sp, #0x24]
	mov r4, sl
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r5, _0819A584 @ =0x00000B94
	adds r4, r6, r5
	ldr r2, _0819A588 @ =0x00002001
	movs r5, #0x10
	str r5, [sp]
	add r0, sp, #0x1c
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r2, _0819A58C @ =0x00000C74
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #4
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r3, _0819A590 @ =0x00000C7C
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	movs r3, #0xc8
	lsls r3, r3, #4
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _0819A594 @ =EneSword_OnHit
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r4, _0819A598 @ =0x00000B9A
	adds r2, r6, r4
	ldrh r1, [r2]
	ldr r0, _0819A59C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0819A5A0 @ =0x00000BE4
	adds r4, r6, r0
	ldr r2, _0819A5A4 @ =0x00005009
	str r5, [sp]
	add r1, sp, #0x1c
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r5, #0x38
	ldrsh r1, [r6, r5]
	ldr r0, [sp, #0x34]
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r5, [sp, #0x30]
	movs r0, #0
	ldrsh r3, [r5, r0]
	adds r0, r4, #0
	bl Hitbox_SetPowerAndAttributes
	ldr r1, _0819A5A8 @ =EneSword_OnHurt
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	movs r2, #0xc4
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, _0819A5AC @ =FUN_08195d5c
	str r0, [r1]
	movs r3, #0
	mov sb, r3
	mov r4, sp
	adds r4, #0x1c
	str r4, [sp, #0x2c]
	movs r5, #0xb0
	lsls r5, r5, #2
	adds r7, r6, r5
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r1, r1, r6
	mov r8, r1
_0819A45E:
	mov r0, r8
	ldr r1, _0819A5B0 @ =0x00005291
	bl Video_GetAuxSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x60
	adds r0, r6, r0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	ldr r2, [sp, #0x38]
	adds r1, r2, r4
	ldr r0, _0819A5B4 @ =0x00000203
	str r0, [r1]
	adds r1, r6, r4
	adds r2, r1, #0
	adds r2, #0x67
	movs r0, #3
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x7c
	movs r3, #0
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	movs r4, #0x10
	str r4, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _0819A588 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	bl Hitbox_Register
	ldr r2, _0819A5B8 @ =0x00000C76
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r4, _0819A5BC @ =0x00000C7A
	adds r0, r6, r4
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r4, #4
	adds r0, r6, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r4, #4
	adds r0, r6, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_SetAttack
	ldrh r0, [r5, #6]
	movs r4, #4
	orrs r0, r4
	strh r0, [r5, #6]
	movs r0, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x2c]
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0819A5C0 @ =0x00004009
	movs r3, #0
	bl Hitbox_Init
	movs r3, #0x38
	ldrsh r1, [r6, r3]
	ldr r4, [sp, #0x34]
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r4, [sp, #0x30]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r0, r7, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	movs r1, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r7, #0
	bl Hitbox_Register
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	adds r7, #0x50
	adds r5, #0x50
	movs r2, #0x1c
	add r8, r2
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #3
	ble _0819A45E
	adds r0, r6, #0
	bl FUN_081974c4
	ldr r5, _0819A5C4 @ =0x00000A84
	adds r1, r6, r5
	adds r0, r6, #0
	movs r2, #0xf7
	bl FUN_0819750c
	adds r0, r6, #0
	bl FUN_08197530
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819A578: .4byte 0x00000CCE
_0819A57C: .4byte 0xFFFF0000
_0819A580: .4byte 0x0000FFFF
_0819A584: .4byte 0x00000B94
_0819A588: .4byte 0x00002001
_0819A58C: .4byte 0x00000C74
_0819A590: .4byte 0x00000C7C
_0819A594: .4byte EneSword_OnHit
_0819A598: .4byte 0x00000B9A
_0819A59C: .4byte 0x0000FFFB
_0819A5A0: .4byte 0x00000BE4
_0819A5A4: .4byte 0x00005009
_0819A5A8: .4byte EneSword_OnHurt
_0819A5AC: .4byte FUN_08195d5c
_0819A5B0: .4byte 0x00005291
_0819A5B4: .4byte 0x00000203
_0819A5B8: .4byte 0x00000C76
_0819A5BC: .4byte 0x00000C7A
_0819A5C0: .4byte 0x00004009
_0819A5C4: .4byte 0x00000A84
