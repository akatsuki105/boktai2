	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081ABD06
	cmp r1, #0
	blt _081ABD06
	ldr r0, _081ABD0C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ABD06
	ldr r0, _081ABD10 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ABD14
_081ABD06:
	movs r4, #0
	b _081ABD22
	.align 2, 0
_081ABD0C: .4byte 0x030046A8
_081ABD10: .4byte 0x030046AC
_081ABD14:
	ldr r0, _081ABD34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081ABD22:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ABD38
	adds r0, #4
	b _081ABD44
	.align 2, 0
_081ABD34: .4byte 0x030046A4
_081ABD38:
	ldr r0, _081ABD58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ABD44:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ABD5C
	adds r0, #4
	b _081ABD68
	.align 2, 0
_081ABD58: .4byte 0x030046A4
_081ABD5C:
	ldr r0, _081ABD7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ABD68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ABD80
	cmp r2, #2
	beq _081ABD84
	b _081ABD88
	.align 2, 0
_081ABD7C: .4byte 0x030046A4
_081ABD80:
	ldrb r0, [r7, #4]
	b _081ABD86
_081ABD84:
	ldrb r0, [r7]
_081ABD86:
	subs r1, r1, r0
_081ABD88:
	ldr r2, _081ABDD0 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _081ABD9A
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _081ABDAC
_081ABD9A:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081ABDAC:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa4
	movs r0, #0xca
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081ABDD4
	movs r0, #1
	b _081ABDD6
	.align 2, 0
_081ABDD0: .4byte 0x00000472
_081ABDD4:
	movs r0, #0
_081ABDD6:
	cmp r0, #0
	beq _081ABDE8
	ldr r1, _081ABDE4 @ =0x00000C4D
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	b _081ABECA
	.align 2, 0
_081ABDE4: .4byte 0x00000C4D
_081ABDE8:
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081ABEC4
	ldr r1, _081ABE6C @ =0x00000C4D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081ABECA
	ldr r2, _081ABE70 @ =0x00000CB9
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl Salamander_PickNextTile
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _081ABE74 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081ABE7C
	ldr r3, _081ABE78 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081ABE8A
	.align 2, 0
_081ABE6C: .4byte 0x00000C4D
_081ABE70: .4byte 0x00000CB9
_081ABE74: .4byte 0x000004A4
_081ABE78: .4byte 0xFFFFFF00
_081ABE7C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081ABE8A
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081ABE8A:
	cmp r1, #0
	bge _081ABE90
	rsbs r1, r1, #0
_081ABE90:
	cmp r1, #0x20
	ble _081ABECA
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081ABEBC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0x1a
	adds r0, r5, r3
	str r1, [r0]
	ldr r1, _081ABEC0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081ABECA
	.align 2, 0
_081ABEBC: .4byte 0x00000469
_081ABEC0: .4byte 0x0000046C
_081ABEC4:
	ldr r0, _081ABED8 @ =0x00000C4D
	add r0, r8
	strb r1, [r0]
_081ABECA:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ABED8: .4byte 0x00000C4D
