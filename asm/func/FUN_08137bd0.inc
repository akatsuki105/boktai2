	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08137BEA
	b _08137D6C
_08137BEA:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08137C08
	b _08137D6C
_08137C08:
	movs r0, #0
	str r0, [sp]
	ldr r0, _08137C3C @ =0x00000B3A
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	blt _08137C1C
	b _08137D6C
_08137C1C:
	ldr r5, _08137C40 @ =0x00000676
	add r5, sl
	ldr r7, _08137C44 @ =0x00000674
	add r7, sl
	ldr r3, _08137C48 @ =0x00000755
	add r3, sl
	mov r8, r3
_08137C2A:
	movs r1, #2
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08137C4C
	movs r0, #1
	b _08137C4E
	.align 2, 0
_08137C3C: .4byte 0x00000B3A
_08137C40: .4byte 0x00000676
_08137C44: .4byte 0x00000674
_08137C48: .4byte 0x00000755
_08137C4C:
	movs r0, #0
_08137C4E:
	cmp r0, #0
	bne _08137C54
	b _08137D4E
_08137C54:
	movs r1, #1
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08137C64
	movs r0, #1
	b _08137C66
_08137C64:
	movs r0, #0
_08137C66:
	cmp r0, #0
	bne _08137D4E
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08137C8E
	cmp r1, #0
	blt _08137C8E
	ldr r0, _08137C94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08137C8E
	ldr r0, _08137C98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08137C9C
_08137C8E:
	movs r4, #0
	b _08137CAA
	.align 2, 0
_08137C94: .4byte 0x030046A8
_08137C98: .4byte 0x030046AC
_08137C9C:
	ldr r0, _08137CBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08137CAA:
	adds r6, r7, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08137CC0
	adds r0, #4
	b _08137CCC
	.align 2, 0
_08137CBC: .4byte 0x030046A4
_08137CC0:
	ldr r0, _08137CE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08137CCC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08137CE4
	cmp r2, #2
	beq _08137CE8
	b _08137CEC
	.align 2, 0
_08137CE0: .4byte 0x030046A4
_08137CE4:
	ldrb r0, [r6, #4]
	b _08137CEA
_08137CE8:
	ldrb r0, [r6]
_08137CEA:
	subs r1, r1, r0
_08137CEC:
	adds r2, r1, #0
	movs r3, #2
	ldrsh r0, [r7, r3]
	cmp r0, r2
	beq _08137D4E
	cmp r0, r2
	bge _08137D26
	subs r0, r2, r0
	adds r1, r0, #0
	cmp r0, #0
	bge _08137D04
	rsbs r1, r0, #0
_08137D04:
	cmp r1, #0xff
	ble _08137D10
	mov r1, sb
	ldrh r0, [r1, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D10:
	cmp r0, #0
	bge _08137D16
	rsbs r0, r0, #0
_08137D16:
	cmp r0, #0xff
	bgt _08137D1E
	strh r2, [r5]
	b _08137D4E
_08137D1E:
	mov r2, sb
	ldrh r0, [r2, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D26:
	subs r1, r1, r0
	adds r2, r1, #0
	cmp r1, #0
	bge _08137D30
	rsbs r2, r1, #0
_08137D30:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	ble _08137D40
	mov r3, sb
	ldrh r0, [r3, #0xa]
	strh r0, [r5]
	b _08137D4E
_08137D40:
	adds r0, r1, #0
	movs r1, #0xa
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
_08137D4E:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r0, _08137D7C @ =0x00000B3A
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08137D6C
	b _08137C2A
_08137D6C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137D7C: .4byte 0x00000B3A
