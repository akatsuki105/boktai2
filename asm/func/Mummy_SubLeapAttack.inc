	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _0812C060 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812C064
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812C066
	.align 2, 0
_0812C060: .4byte 0x0000046C
_0812C064:
	movs r0, #0
_0812C066:
	cmp r0, #0
	beq _0812C09C
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r4, _0812C104 @ =Mummy_StateLeap
	movs r3, #3
	ldr r6, _0812C108 @ =0x0000046D
	adds r1, r7, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812C10C @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0812C09C:
	ldr r4, _0812C10C @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812C0A8
	b _0812C792
_0812C0A8:
	ldr r6, _0812C110 @ =0x0000071E
	adds r2, r5, r6
	ldr r0, _0812C114 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0812C118 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x5c]
	str r2, [sp, #0x60]
	cmp r4, #0
	blt _0812C0FE
	cmp r1, #0
	blt _0812C0FE
	ldr r0, _0812C11C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0812C0FE
	ldr r0, _0812C120 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C124
_0812C0FE:
	movs r4, #0
	b _0812C132
	.align 2, 0
_0812C104: .4byte Mummy_StateLeap
_0812C108: .4byte 0x0000046D
_0812C10C: .4byte 0x0000046B
_0812C110: .4byte 0x0000071E
_0812C114: .4byte 0xFFFFF7FF
_0812C118: .4byte 0x03002BE0
_0812C11C: .4byte 0x030046A8
_0812C120: .4byte 0x030046AC
_0812C124:
	ldr r0, _0812C144 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0812C132:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812C148
	adds r0, #4
	b _0812C154
	.align 2, 0
_0812C144: .4byte 0x030046A4
_0812C148:
	ldr r0, _0812C168 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C154:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812C16C
	cmp r2, #2
	beq _0812C170
	b _0812C174
	.align 2, 0
_0812C168: .4byte 0x030046A4
_0812C16C:
	ldrb r0, [r5, #4]
	b _0812C172
_0812C170:
	ldrb r0, [r5]
_0812C172:
	subs r1, r1, r0
_0812C174:
	strh r1, [r5, #2]
	ldr r0, _0812C188 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812C18C
	movs r0, #1
	b _0812C18E
	.align 2, 0
_0812C188: .4byte 0x030047A4
_0812C18C:
	movs r0, #0
_0812C18E:
	cmp r0, #0
	beq _0812C1CC
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0812C1AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812C1AA
	adds r2, r0, #0
_0812C1AA:
	cmp r2, #0
	bge _0812C1B8
_0812C1AE:
	ldr r3, _0812C1B4 @ =0x000005C4
	adds r0, r7, r3
	b _0812C6EC
	.align 2, 0
_0812C1B4: .4byte 0x000005C4
_0812C1B8:
	ldr r1, _0812C1C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812C214
	.align 2, 0
_0812C1C8: .4byte 0x03002BE0
_0812C1CC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812C1F8
	cmp r1, #0
	blt _0812C1F8
	ldr r0, _0812C1FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812C1F8
	ldr r0, _0812C200 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C204
_0812C1F8:
	movs r5, #0
	b _0812C212
	.align 2, 0
_0812C1FC: .4byte 0x030046A8
_0812C200: .4byte 0x030046AC
_0812C204:
	ldr r0, _0812C254 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812C212:
	movs r2, #0
_0812C214:
	ldr r6, _0812C258 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812C234
	ldr r1, _0812C25C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812C234
	b _0812C630
_0812C234:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	str r2, [sp, #0x34]
	cmp r1, #0
	beq _0812C260
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C254: .4byte 0x030046A4
_0812C258: .4byte 0x00000256
_0812C25C: .4byte 0x03002BE0
_0812C260:
	ldr r3, _0812C300 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x64]
	cmp r6, #0
	beq _0812C314
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0812C304 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0812C308 @ =0x0000046B
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0812C30C @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sl, r3
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r5, r7, r4
	mov r6, r8
	strh r6, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, _0812C310 @ =0x00000469
	adds r3, r7, r6
	strb r2, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	adds r6, #0x1b
	adds r1, r7, r6
	mov r0, r8
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	str r0, [sp, #0x48]
	ldr r0, [sp, #8]
	str r0, [sp, #0x4c]
	mov r6, sb
	str r6, [sp, #0x44]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x80]
	str r5, [sp, #0x58]
	str r4, [sp, #0x38]
	str r3, [sp, #0x3c]
	str r2, [sp, #0x40]
	str r1, [sp, #0x54]
	b _0812C4E6
	.align 2, 0
_0812C300: .4byte 0x00000222
_0812C304: .4byte 0x0000046D
_0812C308: .4byte 0x0000046B
_0812C30C: .4byte 0x00000553
_0812C310: .4byte 0x00000469
_0812C314:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0812C3D4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _0812C3D8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _0812C3DC @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x20]
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812C3E0 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _0812C3E4 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0812C3E8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0812C3EC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x5c]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x60]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x60]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x48]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x4c]
	ldr r2, [sp, #0x14]
	str r2, [sp, #0x44]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x7c]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x80]
	ldr r2, [sp, #0x20]
	str r2, [sp, #0x58]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x38]
	str r5, [sp, #0x3c]
	str r4, [sp, #0x40]
	str r3, [sp, #0x54]
	mov r0, ip
	cmp r0, #0
	blt _0812C3D0
	cmp r1, #0
	blt _0812C3D0
	ldr r0, _0812C3F0 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0812C3D0
	ldr r0, _0812C3F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C3F8
_0812C3D0:
	movs r4, #0
	b _0812C408
	.align 2, 0
_0812C3D4: .4byte 0x0000046D
_0812C3D8: .4byte 0x0000046B
_0812C3DC: .4byte 0x00000553
_0812C3E0: .4byte 0x00000469
_0812C3E4: .4byte 0x0000046A
_0812C3E8: .4byte 0x00000484
_0812C3EC: .4byte 0x0000046C
_0812C3F0: .4byte 0x030046A8
_0812C3F4: .4byte 0x030046AC
_0812C3F8:
	ldr r0, _0812C418 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0812C408:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812C41C
	adds r0, #4
	b _0812C428
	.align 2, 0
_0812C418: .4byte 0x030046A4
_0812C41C:
	ldr r0, _0812C43C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C428:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812C440
	cmp r2, #2
	beq _0812C446
	b _0812C44C
	.align 2, 0
_0812C43C: .4byte 0x030046A4
_0812C440:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _0812C44A
_0812C446:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_0812C44A:
	subs r1, r1, r0
_0812C44C:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812C478
	cmp r1, #0
	blt _0812C478
	ldr r0, _0812C47C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812C478
	ldr r0, _0812C480 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C484
_0812C478:
	movs r4, #0
	b _0812C492
	.align 2, 0
_0812C47C: .4byte 0x030046A8
_0812C480: .4byte 0x030046AC
_0812C484:
	ldr r0, _0812C4A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812C492:
	ldr r0, [sp, #0x5c]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812C4AC
	adds r0, #4
	b _0812C4B8
	.align 2, 0
_0812C4A8: .4byte 0x030046A4
_0812C4AC:
	ldr r0, _0812C4CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C4B8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812C4D0
	cmp r3, #2
	beq _0812C4D4
	b _0812C4D8
	.align 2, 0
_0812C4CC: .4byte 0x030046A4
_0812C4D0:
	ldrb r0, [r5, #4]
	b _0812C4D6
_0812C4D4:
	ldrb r0, [r5]
_0812C4D6:
	subs r2, r2, r0
_0812C4D8:
	ldr r1, [sp, #0x5c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812C4E6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _0812C510 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x50]
	cmp r0, #0
	bne _0812C5F4
	movs r1, #4
	ldr r2, [sp, #0x64]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812C514
	movs r0, #1
	b _0812C516
	.align 2, 0
_0812C510: .4byte 0x00000482
_0812C514:
	movs r0, #0
_0812C516:
	ldr r3, _0812C604 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x50]
	cmp r0, #0
	bne _0812C5F4
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0812C608 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0812C60C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x70]
	ldr r2, _0812C610 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x74]
	ldr r4, _0812C614 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r6, _0812C618 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r0, _0812C61C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _0812C620 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r6, _0812C624 @ =0x0203B400
	ldr r1, _0812C628 @ =0x030046B8
	ldr r5, _0812C62C @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0812C566:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812C584
	adds r3, #1
	cmp r3, #3
	ble _0812C566
	mov r0, r8
_0812C584:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x7c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x38]
	ldrb r0, [r4]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x30]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x4c]
	strb r1, [r4]
	ldr r6, [sp, #0x44]
	strb r3, [r6]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r6, [sp, #0x80]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x58]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x38]
	strb r0, [r4]
	ldr r6, [sp, #0x3c]
	strb r1, [r6]
	ldr r0, [sp, #0x40]
	strb r2, [r0]
	ldr r2, [sp, #0x54]
	str r3, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_0812C5F4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C604: .4byte 0x00000482
_0812C608: .4byte 0x0000054F
_0812C60C: .4byte 0x0000054C
_0812C610: .4byte 0x0000054D
_0812C614: .4byte 0x0000054E
_0812C618: .4byte 0x00000541
_0812C61C: .4byte 0x000005BC
_0812C620: .4byte 0x00000542
_0812C624: .4byte 0x0203B400
_0812C628: .4byte 0x030046B8
_0812C62C: .4byte 0x000003FF
_0812C630:
	mov sb, sp
	ldr r6, _0812C66C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812C670
	adds r0, #4
	b _0812C67A
	.align 2, 0
_0812C66C: .4byte 0x030046A4
_0812C670:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812C67A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _0812C6B0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812C6B4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0812C6DA
	.align 2, 0
_0812C6B0: .4byte 0x000004A4
_0812C6B4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812C6D4
	cmp r0, #2
	beq _0812C6D0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812C6D0:
	movs r0, #1
	b _0812C6E4
_0812C6D4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0812C6DA:
	ldr r1, _0812C6F8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812C6E4:
	cmp r0, #0
	bne _0812C700
	ldr r4, _0812C6FC @ =0x000005C4
	adds r0, r7, r4
_0812C6EC:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C6F8: .4byte 0xFFFFFDFF
_0812C6FC: .4byte 0x000005C4
_0812C700:
	movs r0, #1
_0812C702:
	cmp r0, #0
	beq _0812C792
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r2, _0812C7A4 @ =Enemy_WaitPendingState
	movs r1, #0xe
	ldr r6, _0812C7A8 @ =0x0000046D
	adds r0, r7, r6
	movs r5, #0
	movs r3, #1
	mov sb, r3
	mov r4, sb
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _0812C7AC @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #0xc
	mov sl, r2
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0812C7B0 @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _0812C7B4 @ =0x00000552
	adds r0, r7, r4
	mov r6, sl
	strb r6, [r0]
	movs r1, #3
	subs r2, #0xe9
	adds r0, r7, r2
	strb r1, [r0]
	subs r4, #0xe9
	adds r0, r7, r4
	mov r6, sb
	strb r6, [r0]
	ldr r1, _0812C7B8 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r5, [r0]
	ldr r3, _0812C7BC @ =0x0000046C
	adds r0, r7, r3
	strb r6, [r0]
_0812C792:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812C7A4: .4byte Enemy_WaitPendingState
_0812C7A8: .4byte 0x0000046D
_0812C7AC: .4byte 0x00000553
_0812C7B0: .4byte 0x00000551
_0812C7B4: .4byte 0x00000552
_0812C7B8: .4byte 0x0000046A
_0812C7BC: .4byte 0x0000046C
