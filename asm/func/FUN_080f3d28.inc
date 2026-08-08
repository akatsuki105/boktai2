	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080F3D44 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F3D48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F3D4A
	.align 2, 0
_080F3D44: .4byte 0x0000046D
_080F3D48:
	movs r0, #0
_080F3D4A:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	cmp r0, #0
	beq _080F3E22
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, _080F3DB4 @ =0xFFFEBE3F
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r3, _080F3DB8 @ =0x0000021E
	adds r0, r7, r3
	movs r4, #0
	strh r4, [r0]
	movs r6, #0x88
	lsls r6, r6, #2
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _080F3DBC @ =0x00000202
	adds r0, r7, r1
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080efc44
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080F3DC0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r1, [r0]
	mov r8, r5
	adds r3, r0, #0
	cmp r1, #0
	bne _080F3DC4
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F3DD2
	.align 2, 0
_080F3DB4: .4byte 0xFFFEBE3F
_080F3DB8: .4byte 0x0000021E
_080F3DBC: .4byte 0x00000202
_080F3DC0: .4byte 0x0000025D
_080F3DC4:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F3DD2:
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strh r0, [r1]
	movs r1, #2
	ldrb r0, [r3]
	cmp r0, #0
	bne _080F3DEA
	ldr r0, [r7, #0x44]
	strb r1, [r0, #7]
	b _080F3DF0
_080F3DEA:
	ldr r0, [r7, #0x44]
	adds r0, #0x3a
	strb r1, [r0]
_080F3DF0:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r7, r6
	bl FUN_08013698
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r3, r7, r0
	ldr r1, _080F3EA0 @ =0xFFF7FFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _080F3EA4 @ =0x00000474
	adds r2, r7, r1
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080F3EA8 @ =0xFFBFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, r3, #0
_080F3E22:
	movs r1, #0x10
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080F3E2E
	b _080F40E8
_080F3E2E:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #1
	bgt _080F3EC0
	movs r3, #0
	movs r4, #0
	strh r4, [r1]
	movs r0, #8
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x11
	ldr r5, _080F3EAC @ =0x0000046D
	adds r0, r7, r5
	movs r5, #1
	strb r5, [r0]
	ldr r6, _080F3EB0 @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080F3EB4 @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _080F3EB8 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _080F3EBC @ =0x00000484
	adds r0, r7, r3
	str r4, [r0]
	adds r6, #4
	adds r0, r7, r6
	b _080F40E6
	.align 2, 0
_080F3EA0: .4byte 0xFFF7FFFF
_080F3EA4: .4byte 0x00000474
_080F3EA8: .4byte 0xFFBFFFFF
_080F3EAC: .4byte 0x0000046D
_080F3EB0: .4byte 0x0000046B
_080F3EB4: .4byte 0x00000469
_080F3EB8: .4byte 0x0000046A
_080F3EBC: .4byte 0x00000484
_080F3EC0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r7, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F3F24 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r5, [r0]
	subs r2, #0x42
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r8, r3
	cmp r2, #0
	blt _080F3F1E
	cmp r1, #0
	blt _080F3F1E
	ldr r0, _080F3F28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F3F1E
	ldr r0, _080F3F2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F3F30
_080F3F1E:
	movs r4, #0
	b _080F3F3E
	.align 2, 0
_080F3F24: .4byte 0x0000FFFB
_080F3F28: .4byte 0x030046A8
_080F3F2C: .4byte 0x030046AC
_080F3F30:
	ldr r0, _080F3F50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F3F3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F3F54
	adds r0, #4
	b _080F3F60
	.align 2, 0
_080F3F50: .4byte 0x030046A4
_080F3F54:
	ldr r0, _080F3F74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F3F60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F3F78
	cmp r2, #2
	beq _080F3F7C
	b _080F3F80
	.align 2, 0
_080F3F74: .4byte 0x030046A4
_080F3F78:
	ldrb r0, [r5, #4]
	b _080F3F7E
_080F3F7C:
	ldrb r0, [r5]
_080F3F7E:
	subs r1, r1, r0
_080F3F80:
	strh r1, [r5, #2]
	ldr r2, _080F3FAC @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F3FB0
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _080F3FD6
	.align 2, 0
_080F3FAC: .4byte 0x000004A4
_080F3FB0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F3FD0
	cmp r0, #2
	beq _080F3FCC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F3FCC:
	movs r0, #1
	b _080F3FE0
_080F3FD0:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_080F3FD6:
	ldr r1, _080F4030 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080F3FE0:
	adds r4, r0, #0
	cmp r4, #0
	bne _080F404C
	ldr r1, _080F4034 @ =FUN_080e48d0
	ldr r2, _080F4038 @ =0x0000046D
	adds r0, r7, r2
	movs r3, #1
	strb r3, [r0]
	ldr r5, _080F403C @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _080F4040 @ =0x00000553
	adds r0, r7, r6
	strb r4, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080F4044 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _080F4048 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	b _080F40E8
	.align 2, 0
_080F4030: .4byte 0xFFFFFDFF
_080F4034: .4byte FUN_080e48d0
_080F4038: .4byte 0x0000046D
_080F403C: .4byte 0x0000046B
_080F4040: .4byte 0x00000553
_080F4044: .4byte 0x00000469
_080F4048: .4byte 0x0000046A
_080F404C:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r4, #0
	movs r5, #0
	movs r2, #1
	movs r6, #1
	strh r6, [r0, #6]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080F40F4 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _080F40F8 @ =FUN_080e6794
	mov ip, r0
	movs r1, #0xe
	adds r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _080F40FC @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, ip
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r1, #0x10
	mov r5, r8
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	ldr r1, _080F4100 @ =0x00000482
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080F4104 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080F4108 @ =0x00000552
	adds r0, r7, r3
_080F40E6:
	strb r5, [r0]
_080F40E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F40F4: .4byte 0x00000469
_080F40F8: .4byte FUN_080e6794
_080F40FC: .4byte 0x0000046B
_080F4100: .4byte 0x00000482
_080F4104: .4byte 0x00000551
_080F4108: .4byte 0x00000552
