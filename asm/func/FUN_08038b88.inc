	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	ldr r6, _08038C20 @ =0x0203B400
	ldr r4, _08038C24 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08038C28 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r7, [r0]
	movs r0, #0x3f
	ands r7, r0
	movs r0, #5
	bl Map_GetPath
	mov sl, r0
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r1, #0xc5
	lsls r1, r1, #1
	add r1, sb
	ldr r0, _08038C2C @ =0x03002CF0
	ldr r0, [r0]
	adds r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xf
	ands r2, r1
	adds r6, r0, r2
	mov r0, sl
	ldrb r1, [r0]
	adds r0, r6, #0
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	add r0, sp, #4
	movs r1, #5
	bl Map_GetPathNodePos
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08038C1A
	cmp r1, #0
	blt _08038C1A
	ldr r0, _08038C30 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08038C1A
	ldr r0, _08038C34 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08038C38
_08038C1A:
	movs r4, #0
	b _08038C46
	.align 2, 0
_08038C20: .4byte 0x0203B400
_08038C24: .4byte 0x030046B8
_08038C28: .4byte 0x000003FF
_08038C2C: .4byte 0x03002CF0
_08038C30: .4byte 0x030046A8
_08038C34: .4byte 0x030046AC
_08038C38:
	ldr r0, _08038C58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08038C46:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08038C5C
	adds r0, #4
	b _08038C68
	.align 2, 0
_08038C58: .4byte 0x030046A4
_08038C5C:
	ldr r0, _08038C7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08038C68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08038C80
	cmp r2, #2
	beq _08038C84
	b _08038C88
	.align 2, 0
_08038C7C: .4byte 0x030046A4
_08038C80:
	ldrb r0, [r5, #4]
	b _08038C86
_08038C84:
	ldrb r0, [r5]
_08038C86:
	subs r1, r1, r0
_08038C88:
	add r0, sp, #4
	movs r4, #0
	strh r1, [r0, #2]
	str r7, [sp]
	mov r0, sb
	add r1, sp, #4
	movs r2, #1
	movs r3, #1
	bl FUN_08038aac
	ldr r0, _08038D10 @ =0x0000018B
	add r0, sb
	strb r4, [r0]
	movs r1, #0
	mov r8, r1
	add r5, sp, #4
_08038CA8:
	ldr r2, _08038D14 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08038D18 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08038D1C @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r3, r6, #1
	movs r2, #1
	ands r1, r2
	ldr r0, _08038D20 @ =0x03002CF0
	ldr r0, [r0]
	mov r4, r8
	lsrs r0, r4
	ands r0, r2
	adds r1, r1, r0
	adds r6, r3, r1
	mov r0, sl
	ldrb r1, [r0]
	adds r0, r6, #0
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	add r0, sp, #4
	movs r1, #5
	bl Map_GetPathNodePos
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08038D0C
	cmp r1, #0
	blt _08038D0C
	ldr r0, _08038D24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08038D0C
	ldr r0, _08038D28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08038D2C
_08038D0C:
	movs r4, #0
	b _08038D3A
	.align 2, 0
_08038D10: .4byte 0x0000018B
_08038D14: .4byte 0x030046B8
_08038D18: .4byte 0x000003FF
_08038D1C: .4byte 0x0203B400
_08038D20: .4byte 0x03002CF0
_08038D24: .4byte 0x030046A8
_08038D28: .4byte 0x030046AC
_08038D2C:
	ldr r0, _08038D4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08038D3A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08038D50
	adds r0, #4
	b _08038D5C
	.align 2, 0
_08038D4C: .4byte 0x030046A4
_08038D50:
	ldr r0, _08038D70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08038D5C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08038D74
	cmp r2, #2
	beq _08038D78
	b _08038D7C
	.align 2, 0
_08038D70: .4byte 0x030046A4
_08038D74:
	ldrb r0, [r5, #4]
	b _08038D7A
_08038D78:
	ldrb r0, [r5]
_08038D7A:
	subs r1, r1, r0
_08038D7C:
	strh r1, [r5, #2]
	movs r0, #0x3f
	ands r0, r7
	str r0, [sp]
	mov r0, sb
	add r1, sp, #4
	movs r2, #1
	movs r3, #0
	bl FUN_08038aac
	ldr r1, _08038DBC @ =0x0000018B
	add r1, sb
	ldrb r0, [r1]
	cmp r0, r7
	bge _08038D9C
	strb r7, [r1]
_08038D9C:
	adds r7, #0x10
	movs r1, #1
	add r8, r1
	mov r4, r8
	cmp r4, #3
	bgt _08038DAA
	b _08038CA8
_08038DAA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038DBC: .4byte 0x0000018B
