	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _081BE180 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BE038
	movs r0, #0
	strb r0, [r1]
_081BE038:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BE050
	bl _081BE836
_081BE050:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081BE062
	bl _081BE836
_081BE062:
	ldr r2, _081BE184 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081BE070
	bl _081BE832
_081BE070:
	ldr r3, _081BE188 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r1, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081BE18C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _081BE190 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp, #0x10]
	strb r6, [r0]
	ldr r2, _081BE184 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081BE180 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r1, [r3]
	ldr r2, _081BE194 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _081BE198 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r1, [r4]
	ldr r5, _081BE19C @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	strb r6, [r5]
	ldr r1, _081BE1A0 @ =0x00000553
	adds r5, r7, r1
	strb r0, [r5]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r4, r7, r3
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r6, [r3]
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x20]
	mov r0, sl
	str r0, [sp, #0x34]
	mov r0, sb
	str r0, [sp, #0x2c]
	mov r0, r8
	str r0, [sp, #0x24]
	str r5, [sp, #0x50]
	str r4, [sp, #0x54]
	str r3, [sp, #0x40]
	mov sl, r2
	cmp r1, #0
	bne _081BE10E
	b _081BE6A8
_081BE10E:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081BE1A4 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081BE17A
	cmp r1, #0
	blt _081BE17A
	ldr r0, _081BE1A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BE17A
	ldr r0, _081BE1AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE1B0
_081BE17A:
	movs r4, #0
	b _081BE1BE
	.align 2, 0
_081BE180: .4byte 0x0000046C
_081BE184: .4byte 0x00000484
_081BE188: .4byte 0x000001DF
_081BE18C: .4byte 0x00000469
_081BE190: .4byte 0x0000046A
_081BE194: .4byte Enemy_WaitPendingState
_081BE198: .4byte 0x0000046D
_081BE19C: .4byte 0x0000046B
_081BE1A0: .4byte 0x00000553
_081BE1A4: .4byte 0x00000551
_081BE1A8: .4byte 0x030046A8
_081BE1AC: .4byte 0x030046AC
_081BE1B0:
	ldr r0, _081BE1D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BE1BE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BE1D4
	adds r0, #4
	b _081BE1E0
	.align 2, 0
_081BE1D0: .4byte 0x030046A4
_081BE1D4:
	ldr r0, _081BE1F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE1E0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE1F8
	cmp r2, #2
	beq _081BE1FC
	b _081BE200
	.align 2, 0
_081BE1F4: .4byte 0x030046A4
_081BE1F8:
	ldrb r0, [r5, #4]
	b _081BE1FE
_081BE1FC:
	ldrb r0, [r5]
_081BE1FE:
	subs r1, r1, r0
_081BE200:
	strh r1, [r5, #2]
	ldr r0, _081BE214 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BE218
	movs r0, #1
	b _081BE21A
	.align 2, 0
_081BE214: .4byte 0x030047A4
_081BE218:
	movs r0, #0
_081BE21A:
	cmp r0, #0
	beq _081BE258
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081BE23A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BE236
	adds r2, r0, #0
_081BE236:
	cmp r2, #0
	bge _081BE244
_081BE23A:
	ldr r2, _081BE240 @ =0x000005C4
	adds r0, r7, r2
	b _081BE696
	.align 2, 0
_081BE240: .4byte 0x000005C4
_081BE244:
	ldr r1, _081BE254 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BE2A0
	.align 2, 0
_081BE254: .4byte 0x03002BE0
_081BE258:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BE284
	cmp r1, #0
	blt _081BE284
	ldr r0, _081BE288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE284
	ldr r0, _081BE28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE290
_081BE284:
	movs r5, #0
	b _081BE29E
	.align 2, 0
_081BE288: .4byte 0x030046A8
_081BE28C: .4byte 0x030046AC
_081BE290:
	ldr r0, _081BE330 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BE29E:
	movs r2, #0
_081BE2A0:
	ldr r4, _081BE334 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BE2C0
	ldr r1, _081BE338 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BE2C0
	b _081BE5D4
_081BE2C0:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BE2D4
	b _081BE836
_081BE2D4:
	ldr r0, _081BE33C @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081BE340
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x40]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _081BE48E
	.align 2, 0
_081BE330: .4byte 0x030046A4
_081BE334: .4byte 0x00000256
_081BE338: .4byte 0x03002BE0
_081BE33C: .4byte 0x00000222
_081BE340:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x40]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BE3A4
	cmp r1, #0
	blt _081BE3A4
	ldr r0, _081BE3A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE3A4
	ldr r0, _081BE3AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE3B0
_081BE3A4:
	movs r4, #0
	b _081BE3BE
	.align 2, 0
_081BE3A8: .4byte 0x030046A8
_081BE3AC: .4byte 0x030046AC
_081BE3B0:
	ldr r0, _081BE3D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE3BE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BE3D4
	adds r0, #4
	b _081BE3E0
	.align 2, 0
_081BE3D0: .4byte 0x030046A4
_081BE3D4:
	ldr r0, _081BE3F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE3E0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE3F8
	cmp r2, #2
	beq _081BE3FC
	b _081BE400
	.align 2, 0
_081BE3F4: .4byte 0x030046A4
_081BE3F8:
	ldrb r0, [r5, #4]
	b _081BE3FE
_081BE3FC:
	ldrb r0, [r5]
_081BE3FE:
	subs r1, r1, r0
_081BE400:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BE428
	cmp r1, #0
	blt _081BE428
	ldr r0, _081BE42C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE428
	ldr r0, _081BE430 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE434
_081BE428:
	movs r4, #0
	b _081BE442
	.align 2, 0
_081BE42C: .4byte 0x030046A8
_081BE430: .4byte 0x030046AC
_081BE434:
	ldr r0, _081BE454 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE442:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BE458
	adds r0, #4
	b _081BE464
	.align 2, 0
_081BE454: .4byte 0x030046A4
_081BE458:
	ldr r0, _081BE478 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE464:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BE47C
	cmp r3, #2
	beq _081BE480
	b _081BE484
	.align 2, 0
_081BE478: .4byte 0x030046A4
_081BE47C:
	ldrb r0, [r5, #4]
	b _081BE482
_081BE480:
	ldrb r0, [r5]
_081BE482:
	subs r2, r2, r0
_081BE484:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BE48E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _081BE598
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BE4B8
	movs r0, #1
	b _081BE4BA
_081BE4B8:
	movs r0, #0
_081BE4BA:
	ldr r3, _081BE5A8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _081BE598
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081BE5AC @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BE5B0 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _081BE5B4 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r4, _081BE5B8 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _081BE5BC @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _081BE5C0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _081BE5C4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _081BE5C8 @ =0x0203B400
	ldr r1, _081BE5CC @ =0x030046B8
	ldr r5, _081BE5D0 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BE50A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081BE528
	adds r3, #1
	cmp r3, #3
	ble _081BE50A
	mov r0, r8
_081BE528:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_081BE598:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	b _081BE836
	.align 2, 0
_081BE5A8: .4byte 0x00000482
_081BE5AC: .4byte 0x0000054F
_081BE5B0: .4byte 0x0000054C
_081BE5B4: .4byte 0x0000054D
_081BE5B8: .4byte 0x0000054E
_081BE5BC: .4byte 0x00000541
_081BE5C0: .4byte 0x000005BC
_081BE5C4: .4byte 0x00000542
_081BE5C8: .4byte 0x0203B400
_081BE5CC: .4byte 0x030046B8
_081BE5D0: .4byte 0x000003FF
_081BE5D4:
	mov sb, sp
	ldr r6, _081BE610 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _081BE614
	adds r0, #4
	b _081BE61E
	.align 2, 0
_081BE610: .4byte 0x030046A4
_081BE614:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BE61E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081BE658 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BE660
	ldr r0, _081BE65C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BE68A
	.align 2, 0
_081BE658: .4byte 0x000004A4
_081BE65C: .4byte 0xFFFFFDFF
_081BE660:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BE680
	cmp r0, #2
	beq _081BE67C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BE67C:
	movs r0, #1
	b _081BE68C
_081BE680:
	ldr r0, _081BE6A0 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BE68A:
	movs r0, #0
_081BE68C:
	cmp r0, #0
	beq _081BE692
	b _081BE836
_081BE692:
	ldr r4, _081BE6A4 @ =0x000005C4
	adds r0, r7, r4
_081BE696:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081BE836
	.align 2, 0
_081BE6A0: .4byte 0xFFFFFDFF
_081BE6A4: .4byte 0x000005C4
_081BE6A8:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _081BE71C @ =GolemLink_StateMove
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081BE720 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081BE724 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
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
	cmp r2, #0
	blt _081BE716
	cmp r1, #0
	blt _081BE716
	ldr r0, _081BE728 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE716
	ldr r0, _081BE72C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE730
_081BE716:
	movs r4, #0
	b _081BE73E
	.align 2, 0
_081BE71C: .4byte GolemLink_StateMove
_081BE720: .4byte 0x00000554
_081BE724: .4byte 0x00000551
_081BE728: .4byte 0x030046A8
_081BE72C: .4byte 0x030046AC
_081BE730:
	ldr r0, _081BE750 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE73E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BE754
	adds r0, #4
	b _081BE760
	.align 2, 0
_081BE750: .4byte 0x030046A4
_081BE754:
	ldr r0, _081BE774 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE760:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE778
	cmp r2, #2
	beq _081BE77C
	b _081BE780
	.align 2, 0
_081BE774: .4byte 0x030046A4
_081BE778:
	ldrb r0, [r5, #4]
	b _081BE77E
_081BE77C:
	ldrb r0, [r5]
_081BE77E:
	subs r1, r1, r0
_081BE780:
	strh r1, [r5, #2]
	ldr r2, _081BE7B0 @ =0x000004A4
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
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BE7B8
	ldr r0, _081BE7B4 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081BE7E2
	.align 2, 0
_081BE7B0: .4byte 0x000004A4
_081BE7B4: .4byte 0xFFFFFDFF
_081BE7B8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BE7D8
	cmp r0, #2
	beq _081BE7D4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BE7D4:
	movs r0, #1
	b _081BE7E4
_081BE7D8:
	ldr r0, _081BE81C @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081BE7E2:
	movs r0, #0
_081BE7E4:
	adds r3, r0, #0
	cmp r3, #0
	bne _081BE824
	ldr r0, _081BE820 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x2c]
	strb r2, [r1]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r3, [r5]
	ldr r1, [sp, #0x54]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r1, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _081BE836
	.align 2, 0
_081BE81C: .4byte 0xFFFFFDFF
_081BE820: .4byte Enemy_ClearStateBegun
_081BE824:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081BE836

_081BE832:
	adds r0, #1
	str r0, [r1]
_081BE836:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
