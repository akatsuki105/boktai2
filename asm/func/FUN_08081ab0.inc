	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08081B04
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08081AFC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08081B00 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08081B0E
	.align 2, 0
_08081AFC: .4byte 0xFFFF0000
_08081B00: .4byte 0x0000FFFF
_08081B04:
	ldr r1, _08081B3C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08081B0E:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08081B36
	cmp r1, #0
	blt _08081B36
	ldr r0, _08081B40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081B36
	ldr r0, _08081B44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081B48
_08081B36:
	movs r4, #0
	b _08081B56
	.align 2, 0
_08081B3C: .4byte 0xFFFF0000
_08081B40: .4byte 0x030046A8
_08081B44: .4byte 0x030046AC
_08081B48:
	ldr r0, _08081B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081B56:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08081B6C
	adds r0, #4
	b _08081B78
	.align 2, 0
_08081B68: .4byte 0x030046A4
_08081B6C:
	ldr r0, _08081B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081B78:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08081B90
	cmp r2, #2
	beq _08081B94
	b _08081B98
	.align 2, 0
_08081B8C: .4byte 0x030046A4
_08081B90:
	ldrb r0, [r5, #4]
	b _08081B96
_08081B94:
	ldrb r0, [r5]
_08081B96:
	subs r1, r1, r0
_08081B98:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r5, r6, #0
	adds r5, #0x24
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldrb r0, [r6, #0x18]
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl Mover_Init
	adds r0, r6, #0
	bl FUN_08081830
	adds r1, r6, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl Mover_SetMainSprite
	movs r0, #0xde
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	add r1, sp, #8
	bl Map_InitMoverTile
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl Mover_SetCollision
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	add r1, sp, #8
	bl Map_InitNavAgent
	ldr r0, _08081C00 @ =0x00000464
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08002a48
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081C00: .4byte 0x00000464
