	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp, #0x4c]
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _08191B00 @ =0x05000002
	bl CpuSet
	movs r0, #0
	mov sl, r0
	add r5, sp, #0x44
	ldr r1, _08191B04 @ =0x030046B8
	mov sb, r1
	ldr r2, _08191B08 @ =0x000003FF
	mov r8, r2
	ldr r7, _08191B0C @ =0x030046A4
_08191ACA:
	ldr r3, [sp, #0x4c]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	add r1, sp, #0x44
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191AFA
	cmp r1, #0
	blt _08191AFA
	ldr r0, _08191B10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191AFA
	ldr r0, _08191B14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191B18
_08191AFA:
	movs r6, #0
	b _08191B24
	.align 2, 0
_08191B00: .4byte 0x05000002
_08191B04: .4byte 0x030046B8
_08191B08: .4byte 0x000003FF
_08191B0C: .4byte 0x030046A4
_08191B10: .4byte 0x030046A8
_08191B14: .4byte 0x030046AC
_08191B18:
	ldr r0, [r7]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08191B24:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08191B70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r0, #0x40
	movs r1, #0x7f
	ands r2, r1
	adds r0, r0, r2
	add r2, sp, #0x44
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	add r3, sp, #0x48
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191B6A
	cmp r1, #0
	blt _08191B6A
	ldr r0, _08191B74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191B6A
	ldr r0, _08191B78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191B7C
_08191B6A:
	movs r4, #0
	b _08191B88
	.align 2, 0
_08191B70: .4byte 0x0203B400
_08191B74: .4byte 0x030046A8
_08191B78: .4byte 0x030046AC
_08191B7C:
	ldr r0, [r7]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191B88:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191B98
	adds r0, #4
	b _08191BA2
_08191B98:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08191BA2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0x46
	add r1, sp
	strh r0, [r1]
	mov r2, sb
	ldr r1, [r2]
	adds r1, #1
	mov r3, r8
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _08191C14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	add r0, sp, #0x48
	ldrh r2, [r0]
	subs r2, #0x40
	movs r0, #0x7f
	ands r3, r0
	adds r2, r2, r3
	add r3, sp, #0x48
	strh r2, [r3]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _08191C14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	mov r3, sp
	strh r0, [r3, #0x3c]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r3, sb
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08191C14 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	add r1, sp, #0x3c
	strh r0, [r1, #4]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191C18
	adds r0, #4
	b _08191C22
	.align 2, 0
_08191C14: .4byte 0x0203B400
_08191C18:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08191C22:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08191C7E
	adds r1, r5, #0
	add r2, sp, #0x3c
	ldr r3, _08191C44 @ =0x00002E78
	ldr r4, _08191C48 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	mov r0, sl
	cmp r0, #0
	bne _08191C4C
	movs r0, #0x80
	lsls r0, r0, #2
	b _08191C50
	.align 2, 0
_08191C44: .4byte 0x00002E78
_08191C48: .4byte 0x000038E2
_08191C4C:
	movs r0, #0x80
	lsls r0, r0, #3
_08191C50:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08191C9C @ =0x0000023B
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r4, #0
	bl Entity081f26bc_Spawn
_08191C7E:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #1
	bgt _08191C8A
	b _08191ACA
_08191C8A:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191C9C: .4byte 0x0000023B
