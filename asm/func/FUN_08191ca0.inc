	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _08191D1C @ =0x05000002
	bl CpuSet
	movs r2, #0
	mov r8, r2
	add r5, sp, #0x44
	ldr r7, _08191D20 @ =0x030046B8
	ldr r3, _08191D24 @ =0x000003FF
	mov sb, r3
_08191CD4:
	mov r1, sl
	lsls r0, r1, #3
	add r0, sl
	lsls r0, r0, #3
	add r0, sl
	lsls r0, r0, #2
	ldr r2, [sp, #0x4c]
	adds r0, r2, r0
	ldr r3, _08191D28 @ =0x00000674
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
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
	blt _08191D16
	cmp r1, #0
	blt _08191D16
	ldr r0, _08191D2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191D16
	ldr r0, _08191D30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191D34
_08191D16:
	movs r6, #0
	b _08191D42
	.align 2, 0
_08191D1C: .4byte 0x05000002
_08191D20: .4byte 0x030046B8
_08191D24: .4byte 0x000003FF
_08191D28: .4byte 0x00000674
_08191D2C: .4byte 0x030046A8
_08191D30: .4byte 0x030046AC
_08191D34:
	ldr r0, _08191D8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08191D42:
	ldr r0, [r7]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08191D90 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xc8
	bl Mod
	ldrh r1, [r5]
	subs r1, #0x64
	adds r1, r1, r0
	add r0, sp, #0x44
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	add r1, sp, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191D88
	cmp r1, #0
	blt _08191D88
	ldr r0, _08191D94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191D88
	ldr r0, _08191D98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191D9C
_08191D88:
	movs r4, #0
	b _08191DAA
	.align 2, 0
_08191D8C: .4byte 0x030046A4
_08191D90: .4byte 0x0203B400
_08191D94: .4byte 0x030046A8
_08191D98: .4byte 0x030046AC
_08191D9C:
	ldr r0, _08191DBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191DAA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191DC0
	adds r0, #4
	b _08191DCC
	.align 2, 0
_08191DBC: .4byte 0x030046A4
_08191DC0:
	ldr r0, _08191E40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191DCC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r2, #0x46
	add r2, sp
	strh r0, [r2]
	ldr r0, [r7]
	adds r0, #1
	mov r3, sb
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08191E44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xc8
	bl Mod
	add r2, sp, #0x48
	ldrh r1, [r2]
	subs r1, #0x64
	adds r1, r1, r0
	strh r1, [r2]
	ldr r1, [r7]
	adds r1, #1
	mov r3, sb
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _08191E44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	mov r3, sp
	strh r0, [r3, #0x3c]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	str r1, [r7]
	lsls r1, r1, #1
	ldr r3, _08191E44 @ =0x0203B400
	adds r1, r1, r3
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	add r1, sp, #0x3c
	strh r0, [r1, #4]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191E48
	adds r0, #4
	b _08191E54
	.align 2, 0
_08191E40: .4byte 0x030046A4
_08191E44: .4byte 0x0203B400
_08191E48:
	ldr r0, _08191E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191E54:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08191EC4
	adds r1, r5, #0
	add r2, sp, #0x3c
	ldr r3, _08191E7C @ =0x00002E78
	ldr r4, _08191E80 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	mov r0, r8
	cmp r0, #0
	bne _08191E84
	movs r0, #0x80
	lsls r0, r0, #2
	b _08191E88
	.align 2, 0
_08191E78: .4byte 0x030046A4
_08191E7C: .4byte 0x00002E78
_08191E80: .4byte 0x000038E2
_08191E84:
	movs r0, #0x80
	lsls r0, r0, #3
_08191E88:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08191E9C @ =0x0000023B
	str r0, [sp, #0xc]
	mov r0, r8
	cmp r0, #0
	bne _08191EA0
	movs r0, #2
	b _08191EA2
	.align 2, 0
_08191E9C: .4byte 0x0000023B
_08191EA0:
	movs r0, #1
_08191EA2:
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
_08191EC4:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #1
	bgt _08191ED0
	b _08191CD4
_08191ED0:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
