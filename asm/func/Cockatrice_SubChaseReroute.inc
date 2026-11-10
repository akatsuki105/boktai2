	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	adds r7, r0, #0
	ldr r0, _08158EAC @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158EB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08158EB2
	.align 2, 0
_08158EAC: .4byte 0x0000046C
_08158EB0:
	movs r0, #0
_08158EB2:
	cmp r0, #0
	beq _08158F04
	ldr r1, _08159044 @ =0x000005A4
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _08159048 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0815904C @ =0x0000046B
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08159050 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _08159054 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _08159058 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	subs r6, #0xf6
	adds r0, r7, r6
	strh r3, [r0]
_08158F04:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158F1A
	b _08159584
_08158F1A:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08158F2C
	b _08159584
_08158F2C:
	ldr r2, _0815905C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08158F38
	b _08159580
_08158F38:
	ldr r3, _08159060 @ =0x00000222
	adds r3, r7, r3
	str r3, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	movs r4, #0
	strh r0, [r3]
	ldr r1, _08159064 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r5, _08159048 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r5, #1
	ldr r6, [sp, #0xc]
	strb r5, [r6]
	subs r2, #0x19
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r4, [r2]
	ldr r3, _08159050 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x14]
	strb r0, [r3]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x18]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	mov r1, r8
	strh r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r6, _08159068 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0815906C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08159070 @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _0815905C @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _08159074 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x58]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x54]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x3c]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x40]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x68]
	ldr r3, [sp, #8]
	mov r8, r3
	mov r0, ip
	str r0, [sp, #0x48]
	mov r3, sl
	str r3, [sp, #0x4c]
	mov r0, sb
	str r0, [sp, #0x50]
	str r6, [sp, #0x64]
	adds r6, r4, #0
	mov sb, r2
	cmp r5, #0
	blt _08159040
	cmp r1, #0
	blt _08159040
	ldr r0, _08159078 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08159040
	ldr r0, _0815907C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159080
_08159040:
	movs r5, #0
	b _0815908E
	.align 2, 0
_08159044: .4byte 0x000005A4
_08159048: .4byte 0x0000046D
_0815904C: .4byte 0x0000046B
_08159050: .4byte 0x00000553
_08159054: .4byte 0xFEFFFFFF
_08159058: .4byte 0xFFFFFDFF
_0815905C: .4byte 0x00000484
_08159060: .4byte 0x00000222
_08159064: .4byte Enemy_WaitPendingState
_08159068: .4byte 0x00000554
_0815906C: .4byte 0x00000551
_08159070: .4byte 0x00000552
_08159074: .4byte 0x0000046C
_08159078: .4byte 0x030046A8
_0815907C: .4byte 0x030046AC
_08159080:
	ldr r0, _081590A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_0815908E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081590A4
	adds r0, #4
	b _081590B0
	.align 2, 0
_081590A0: .4byte 0x030046A4
_081590A4:
	ldr r0, _081590C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081590B0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081590C8
	cmp r2, #2
	beq _081590CE
	b _081590D4
	.align 2, 0
_081590C4: .4byte 0x030046A4
_081590C8:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _081590D2
_081590CE:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_081590D2:
	subs r1, r1, r0
_081590D4:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _081590EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081590F0
	movs r0, #1
	b _081590F2
	.align 2, 0
_081590EC: .4byte 0x030047A4
_081590F0:
	movs r0, #0
_081590F2:
	cmp r0, #0
	beq _08159130
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08159112
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815910E
	adds r2, r0, #0
_0815910E:
	cmp r2, #0
	bge _0815911C
_08159112:
	ldr r6, _08159118 @ =0x000005C4
	adds r0, r7, r6
	b _0815956C
	.align 2, 0
_08159118: .4byte 0x000005C4
_0815911C:
	ldr r1, _0815912C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08159178
	.align 2, 0
_0815912C: .4byte 0x03002BE0
_08159130:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815915C
	cmp r1, #0
	blt _0815915C
	ldr r0, _08159160 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815915C
	ldr r0, _08159164 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159168
_0815915C:
	movs r5, #0
	b _08159176
	.align 2, 0
_08159160: .4byte 0x030046A8
_08159164: .4byte 0x030046AC
_08159168:
	ldr r0, _0815920C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08159176:
	movs r2, #0
_08159178:
	ldr r3, _08159210 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08159198
	ldr r1, _08159214 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08159198
	b _081594B0
_08159198:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sl, r2
	cmp r3, #0
	beq _081591B2
	b _08159584
_081591B2:
	movs r0, #5
	rsbs r0, r0, #0
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	mov r1, r8
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08159218
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x5c]
	strb r2, [r6]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x40]
	str r1, [r0]
	ldr r1, [sp, #0x68]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x48]
	strb r5, [r4]
	ldr r6, [sp, #0x4c]
	strb r5, [r6]
	ldr r1, [sp, #0x50]
	strb r0, [r1]
	ldr r4, [sp, #0x64]
	str r3, [r4]
	ldr r5, [sp, #0x58]
	strb r2, [r5]
	b _08159366
	.align 2, 0
_0815920C: .4byte 0x030046A4
_08159210: .4byte 0x00000256
_08159214: .4byte 0x03002BE0
_08159218:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x5c]
	strb r0, [r3]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	str r1, [r4]
	ldr r1, [sp, #0x68]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x48]
	strb r5, [r3]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r1, [sp, #0x64]
	str r2, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815927C
	cmp r1, #0
	blt _0815927C
	ldr r0, _08159280 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815927C
	ldr r0, _08159284 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159288
_0815927C:
	movs r5, #0
	b _08159296
	.align 2, 0
_08159280: .4byte 0x030046A8
_08159284: .4byte 0x030046AC
_08159288:
	ldr r0, _081592A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08159296:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081592AC
	adds r0, #4
	b _081592B8
	.align 2, 0
_081592A8: .4byte 0x030046A4
_081592AC:
	ldr r0, _081592CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081592B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081592D0
	cmp r2, #2
	beq _081592D4
	b _081592D8
	.align 2, 0
_081592CC: .4byte 0x030046A4
_081592D0:
	ldrb r0, [r4, #4]
	b _081592D6
_081592D4:
	ldrb r0, [r4]
_081592D6:
	subs r1, r1, r0
_081592D8:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08159300
	cmp r1, #0
	blt _08159300
	ldr r0, _08159304 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08159300
	ldr r0, _08159308 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815930C
_08159300:
	movs r5, #0
	b _0815931A
	.align 2, 0
_08159304: .4byte 0x030046A8
_08159308: .4byte 0x030046AC
_0815930C:
	ldr r0, _0815932C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815931A:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159330
	adds r0, #4
	b _0815933C
	.align 2, 0
_0815932C: .4byte 0x030046A4
_08159330:
	ldr r0, _08159350 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815933C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08159354
	cmp r3, #2
	beq _08159358
	b _0815935C
	.align 2, 0
_08159350: .4byte 0x030046A4
_08159354:
	ldrb r0, [r4, #4]
	b _0815935A
_08159358:
	ldrb r0, [r4]
_0815935A:
	subs r2, r2, r0
_0815935C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08159366:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	ldr r6, _08159390 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x60]
	cmp r0, #0
	bne _08159474
	movs r1, #4
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08159394
	movs r0, #1
	b _08159396
	.align 2, 0
_08159390: .4byte 0x00000482
_08159394:
	movs r0, #0
_08159396:
	ldr r3, _08159484 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x60]
	cmp r0, #0
	bne _08159474
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08159488 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0815948C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08159490 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _08159494 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r4, _08159498 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _0815949C @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _081594A0 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	ldr r6, _081594A4 @ =0x0203B400
	ldr r1, _081594A8 @ =0x030046B8
	ldr r2, _081594AC @ =0x000003FF
	movs r5, #3
	mov r4, sb
_081593E6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _08159404
	adds r3, #1
	cmp r3, #3
	ble _081593E6
	mov r0, sb
_08159404:
	movs r3, #0
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0x30]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x28]
	strb r4, [r2]
	ldr r4, [sp, #0x44]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x5c]
	strb r1, [r5]
	ldr r6, [sp, #0x54]
	strb r3, [r6]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x68]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, [sp, #0x50]
	strb r2, [r6]
	ldr r0, [sp, #0x64]
	str r3, [r0]
	ldr r2, [sp, #0x58]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
_08159474:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	b _08159584
	.align 2, 0
_08159484: .4byte 0x00000482
_08159488: .4byte 0x0000054F
_0815948C: .4byte 0x0000054C
_08159490: .4byte 0x0000054D
_08159494: .4byte 0x0000054E
_08159498: .4byte 0x00000541
_0815949C: .4byte 0x000005BC
_081594A0: .4byte 0x00000542
_081594A4: .4byte 0x0203B400
_081594A8: .4byte 0x030046B8
_081594AC: .4byte 0x000003FF
_081594B0:
	mov sb, sp
	ldr r6, _081594EC @ =0x030046A4
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
	beq _081594F0
	adds r0, #4
	b _081594FA
	.align 2, 0
_081594EC: .4byte 0x030046A4
_081594F0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081594FA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08159530 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08159534
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0815955A
	.align 2, 0
_08159530: .4byte 0x000004A4
_08159534:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08159554
	cmp r0, #2
	beq _08159550
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08159550:
	movs r0, #1
	b _08159564
_08159554:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0815955A:
	ldr r1, _08159578 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08159564:
	cmp r0, #0
	bne _08159584
	ldr r3, _0815957C @ =0x000005C4
	adds r0, r7, r3
_0815956C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08159584
	.align 2, 0
_08159578: .4byte 0xFFFFFDFF
_0815957C: .4byte 0x000005C4
_08159580:
	adds r0, #1
	str r0, [r1]
_08159584:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
