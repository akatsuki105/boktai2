	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	strh r1, [r7, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3EA4
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A3E44
	cmp r1, #0
	blt _080A3E44
	ldr r0, _080A3E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A3E44
	ldr r0, _080A3E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3E50
_080A3E44:
	movs r6, #0
	b _080A3E5E
	.align 2, 0
_080A3E48: .4byte 0x030046A8
_080A3E4C: .4byte 0x030046AC
_080A3E50:
	ldr r0, _080A3E70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3E5E:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A3E74
	adds r0, #4
	b _080A3E80
	.align 2, 0
_080A3E70: .4byte 0x030046A4
_080A3E74:
	ldr r0, _080A3E94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3E80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A3E98
	cmp r2, #2
	beq _080A3E9C
	b _080A3EA0
	.align 2, 0
_080A3E94: .4byte 0x030046A4
_080A3E98:
	ldrb r0, [r4, #4]
	b _080A3E9E
_080A3E9C:
	ldrb r0, [r4]
_080A3E9E:
	subs r1, r1, r0
_080A3EA0:
	strh r1, [r5]
	b _080A3EB6
_080A3EA4:
	adds r1, r7, #0
	adds r1, #0xac
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	str r1, [sp, #0xc]
_080A3EB6:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3ED0
	bl VM_GetValue
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	b _080A3ED8
_080A3ED0:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
_080A3ED8:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F2C
	adds r0, r7, #0
	adds r0, #0xfc
	str r0, [sp, #8]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x64
	str r2, [sp, #0x18]
	subs r0, #0x91
	str r0, [sp, #0x1c]
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #0x20]
	movs r2, #0xe0
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	adds r1, #0x3b
	str r1, [sp, #0x10]
	adds r2, r7, #0
	adds r2, #0xd0
	str r2, [sp, #0x14]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r5, #1
_080A3F1C:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F1C
	b _080A3F72
_080A3F2C:
	adds r1, r7, #0
	adds r1, #0xfc
	str r1, [sp, #8]
	movs r2, #0x90
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [sp, #0x18]
	subs r1, #0x91
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x20]
	movs r0, #0xe0
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0xb4
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0x3b
	str r2, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0x14]
	movs r1, #0
	movs r5, #1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r7, r2
_080A3F68:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F68
_080A3F72:
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F80
	bl VM_GetValue
_080A3F80:
	strb r0, [r7, #0x1b]
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	beq _080A3FA4
	adds r4, r7, #0
	adds r4, #0x20
	ldrh r1, [r7, #0x18]
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
_080A3FA4:
	movs r0, #0x6a
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r6, _080A4044 @ =0x00000BA8
	mov r0, r8
	adds r1, r6, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	movs r5, #7
	ldr r2, [sp, #0x18]
	strh r5, [r2, #0x10]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r4, #3
	ldr r1, [sp, #0x1c]
	strb r4, [r1]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sl
	adds r1, r6, #0
	bl Video_GetAuxSprite
	mov r0, sb
	mov r1, sl
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	strh r5, [r0, #0x10]
	ldr r2, [sp, #8]
	ldrh r1, [r2]
	mov r0, sl
	bl Video_SetAuxSpritePltt
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x10]
	strb r4, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4048 @ =Entity7C62_UpdateIdle
	adds r0, r7, #0
	bl Entity7C62_SetUpdateCallback
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4044: .4byte 0x00000BA8
_080A4048: .4byte Entity7C62_UpdateIdle
