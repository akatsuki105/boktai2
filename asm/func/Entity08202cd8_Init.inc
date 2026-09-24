	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sb, r3
	movs r0, #0
	ldrsh r6, [r5, r0]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08202A50
	cmp r1, #0
	blt _08202A50
	ldr r0, _08202A54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08202A50
	ldr r0, _08202A58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08202A5C
_08202A50:
	movs r4, #0
	b _08202A6A
	.align 2, 0
_08202A54: .4byte 0x030046A8
_08202A58: .4byte 0x030046AC
_08202A5C:
	ldr r0, _08202A7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08202A6A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202A80
	adds r0, #4
	b _08202A8C
	.align 2, 0
_08202A7C: .4byte 0x030046A4
_08202A80:
	ldr r0, _08202B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08202A8C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #4
	ldrsh r3, [r5, r2]
	add r2, sp, #0xc
	adds r0, r2, #0
	strh r6, [r0]
	strh r1, [r2, #2]
	strh r3, [r2, #4]
	ldr r3, _08202B1C @ =0x0000069C
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _08202B20 @ =0x00002E78
	adds r0, r3, #0
	bl Video_GetAuxSprite
	ldr r1, _08202B24 @ =0x00002E7B
	ldr r0, [sp, #0x28]
	bl Video_GetAuxSprite
	ldr r1, [sp, #0x24]
	ldrh r0, [r1, #6]
	strh r0, [r7, #0x26]
	adds r6, r7, #0
	adds r6, #0x28
	ldr r2, _08202B28 @ =0x000006E2
	adds r0, r7, r2
	mov r3, r8
	strh r3, [r0]
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strh r2, [r0]
	movs r3, #0
	str r3, [sp, #0x2c]
	adds r0, r7, #0
	adds r0, #0x24
	str r0, [sp, #0x30]
	adds r1, r7, #0
	adds r1, #0x25
	str r1, [sp, #0x34]
	mov sl, r3
	add r2, sp, #0x14
	mov sb, r2
	add r3, sp, #0x1c
	mov r8, r3
	movs r0, #0x82
	lsls r0, r0, #3
	str r0, [sp, #0x38]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #0x3c]
_08202B02:
	ldr r2, [sp, #0x2c]
	cmp r2, #2
	bgt _08202B2C
	adds r0, r6, #0
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl AuxSprite_Add
	mov r3, sl
	strh r3, [r6, #0x10]
	b _08202B50
	.align 2, 0
_08202B18: .4byte 0x030046A4
_08202B1C: .4byte 0x0000069C
_08202B20: .4byte 0x00002E78
_08202B24: .4byte 0x00002E7B
_08202B28: .4byte 0x000006E2
_08202B2C:
	ldr r0, [sp, #0x2c]
	cmp r0, #4
	bgt _08202B42
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #8
	strh r0, [r6, #0x10]
	b _08202B50
_08202B42:
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sl
	strh r1, [r6, #0x10]
_08202B50:
	ldr r0, [r6]
	movs r2, #1
	orrs r0, r2
	str r0, [r6]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r3, [sp, #0x3c]
	adds r5, r7, r3
	ldr r0, [sp, #0x14]
	ldr r1, _08202CAC @ =0xFFFF0000
	ands r0, r1
	movs r2, #0x32
	orrs r0, r2
	ldr r3, _08202CB0 @ =0x0000FFFF
	ands r0, r3
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r1, sb
	ldr r0, [r1, #4]
	ldr r2, _08202CAC @ =0xFFFF0000
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	str r0, [r1, #4]
	movs r0, #0
	str r0, [sp, #0x1c]
	mov r1, r8
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x10
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _08202CB4 @ =0x00003001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	ldr r1, _08202CB8 @ =FUN_082029b8
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r1, [r0]
	mov r2, sl
	str r2, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x64
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r3, [sp, #0x38]
	adds r5, r7, r3
	movs r1, #0x64
	add r0, sp, #0x14
	strh r1, [r0]
	mov r0, sb
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	add r0, sp, #0x1c
	mov r1, sl
	strh r1, [r0]
	mov r2, r8
	strh r1, [r2, #2]
	strh r1, [r2, #4]
	movs r3, #0x10
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r2, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _08202CBC @ =0x00005001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	ldr r1, _08202CC0 @ =FUN_082029bc
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r1, _08202CC4 @ =0x000006E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #8
	movs r3, #4
	bl Hitbox_SetPowerAndAttributes
	adds r0, r5, #0
	bl Hitbox_Register
	adds r6, #0x2c
	ldr r2, [sp, #0x38]
	adds r2, #0x50
	str r2, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	adds r3, #0x50
	str r3, [sp, #0x3c]
	ldr r0, [sp, #0x2c]
	adds r0, #1
	str r0, [sp, #0x2c]
	cmp r0, #7
	bgt _08202C52
	b _08202B02
_08202C52:
	movs r2, #0
	ldr r1, _08202CC8 @ =0x00000694
	adds r3, r7, r1
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r3]
	str r1, [r3, #4]
	str r2, [r7, #0x1c]
	ldr r3, [sp, #0x30]
	strb r2, [r3]
	ldr r0, [sp, #0x34]
	strb r2, [r0]
	movs r1, #0
	strh r2, [r7, #0x20]
	strh r2, [r7, #0x22]
	ldr r3, _08202CCC @ =0x000006DB
	adds r0, r7, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #8
	adds r0, r7, r3
	str r2, [r0]
	str r2, [r7, #0x18]
	adds r3, #4
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r3, _08202CD0 @ =0x000006EC
	adds r0, r7, r3
	str r2, [r0]
	ldr r2, _08202CD4 @ =0x000006DD
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08202CAC: .4byte 0xFFFF0000
_08202CB0: .4byte 0x0000FFFF
_08202CB4: .4byte 0x00003001
_08202CB8: .4byte FUN_082029b8
_08202CBC: .4byte 0x00005001
_08202CC0: .4byte FUN_082029bc
_08202CC4: .4byte 0x000006E2
_08202CC8: .4byte 0x00000694
_08202CCC: .4byte 0x000006DB
_08202CD0: .4byte 0x000006EC
_08202CD4: .4byte 0x000006DD
