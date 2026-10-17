	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r2
	ldr r0, _08086354 @ =0x03002C00
	ldr r3, [r0]
	adds r2, r0, #0
	cmp r3, #0
	bne _080862B2
	b _0808657E
_080862B2:
	movs r0, #0
	ldrsh r1, [r5, r0]
	adds r0, r3, #0
	adds r0, #0x48
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r6, r1, r0
	movs r7, #4
	ldrsh r1, [r5, r7]
	adds r0, r3, #0
	adds r0, #0x4c
	movs r7, #0
	ldrsh r0, [r0, r7]
	subs r1, r1, r0
	mov r8, r1
	adds r0, r6, #0
	muls r0, r6, r0
	adds r7, r1, #0
	mov r1, r8
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, _08086358 @ =0x0000BD10
	cmp r0, r1
	ble _080862E4
	b _0808657E
_080862E4:
	ldr r1, _0808635C @ =0x000001F5
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080862F8
	b _08086408
_080862F8:
	adds r0, r1, #0
	cmp r0, #0
	beq _08086308
	cmp r0, #3
	beq _08086308
	cmp r0, #4
	beq _08086308
	b _0808657E
_08086308:
	ldr r0, [r2]
	ldr r2, _08086360 @ =0x00000386
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r7, #0xe1
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrb r3, [r0]
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808626c
	cmp r0, #0
	bne _08086326
	b _0808657E
_08086326:
	ldrh r2, [r5]
	lsls r0, r2, #0x10
	asrs r4, r0, #0x18
	ldrh r1, [r5, #4]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	mov ip, r2
	mov sb, r1
	cmp r4, #0
	blt _0808634E
	cmp r3, #0
	blt _0808634E
	ldr r0, _08086364 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0808634E
	ldr r0, _08086368 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _0808636C
_0808634E:
	movs r4, #0
	b _0808637A
	.align 2, 0
_08086354: .4byte 0x03002C00
_08086358: .4byte 0x0000BD10
_0808635C: .4byte 0x000001F5
_08086360: .4byte 0x00000386
_08086364: .4byte 0x030046A8
_08086368: .4byte 0x030046AC
_0808636C:
	ldr r0, _080863A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0808637A:
	ldr r2, _080863AC @ =0x03002C00
	ldr r1, [r2]
	adds r1, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080863A4
	cmp r1, #0
	blt _080863A4
	ldr r0, _080863B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080863A4
	ldr r0, _080863B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080863B8
_080863A4:
	movs r3, #0
	b _080863C6
	.align 2, 0
_080863A8: .4byte 0x030046A4
_080863AC: .4byte 0x03002C00
_080863B0: .4byte 0x030046A8
_080863B4: .4byte 0x030046AC
_080863B8:
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080863C6:
	cmp r4, r3
	beq _08086408
	adds r0, r3, #1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, #1
	cmp r4, r0
	beq _080863EE
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	mov sl, r0
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r3, r1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, r1
	cmp r4, r0
	bne _08086410
_080863EE:
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086402
	rsbs r0, r0, #0
_08086402:
	cmp r0, #0xff
	ble _08086408
	b _0808657E
_08086408:
	movs r0, #1
	b _08086580
	.align 2, 0
_0808640C: .4byte 0x030046A4
_08086410:
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086424
	rsbs r0, r0, #0
_08086424:
	cmp r0, #0xff
	ble _0808642A
	b _0808657E
_0808642A:
	mov r7, ip
	subs r1, r7, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08086478 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sb
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086472
	cmp r1, #0
	blt _08086472
	ldr r0, _0808647C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086472
	ldr r0, _08086480 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086484
_08086472:
	movs r4, #0
	b _08086490
	.align 2, 0
_08086478: .4byte 0xFFFF0000
_0808647C: .4byte 0x030046A8
_08086480: .4byte 0x030046AC
_08086484:
	lsls r0, r1, #1
	mov r1, sl
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, r2
_08086490:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080864A0
	adds r0, #4
	b _080864AC
_080864A0:
	ldr r0, _080864C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080864AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080864C4
	cmp r2, #2
	beq _080864C8
	b _080864CC
	.align 2, 0
_080864C0: .4byte 0x030046A4
_080864C4:
	ldrb r0, [r6, #4]
	b _080864CA
_080864C8:
	ldrb r0, [r6]
_080864CA:
	subs r1, r1, r0
_080864CC:
	movs r2, #2
	ldrsh r0, [r5, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080864D8
	rsbs r0, r0, #0
_080864D8:
	cmp r0, #0x7f
	ble _08086408
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r5, #4]
	mov r6, r8
	subs r1, r1, r6
	strh r1, [r0, #4]
	mov r6, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0808650E
	cmp r1, #0
	blt _0808650E
	ldr r0, _08086514 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808650E
	ldr r0, _08086518 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808651C
_0808650E:
	movs r4, #0
	b _0808652A
	.align 2, 0
_08086514: .4byte 0x030046A8
_08086518: .4byte 0x030046AC
_0808651C:
	ldr r0, _0808653C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808652A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08086540
	adds r0, #4
	b _0808654C
	.align 2, 0
_0808653C: .4byte 0x030046A4
_08086540:
	ldr r0, _08086560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808654C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086564
	cmp r2, #2
	beq _08086568
	b _0808656C
	.align 2, 0
_08086560: .4byte 0x030046A4
_08086564:
	ldrb r0, [r6, #4]
	b _0808656A
_08086568:
	ldrb r0, [r6]
_0808656A:
	subs r1, r1, r0
_0808656C:
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086578
	rsbs r0, r0, #0
_08086578:
	cmp r0, #0x7f
	bgt _0808657E
	b _08086408
_0808657E:
	movs r0, #0
_08086580:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
