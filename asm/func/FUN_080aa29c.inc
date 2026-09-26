	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0xe4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, _080AA30C @ =0x0000034A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x12
	bl Div
	ldr r6, _080AA310 @ =0x0203B400
	ldr r5, _080AA314 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _080AA318 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	lsls r0, r0, #6
	movs r3, #0x3f
	ands r1, r3
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _080AA31C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA320
	asrs r0, r0, #0xc
	b _080AA326
	.align 2, 0
_080AA30C: .4byte 0x0000034A
_080AA310: .4byte 0x0203B400
_080AA314: .4byte 0x030046B8
_080AA318: .4byte 0x000003FF
_080AA31C: .4byte 0x085B0A08
_080AA320:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA326:
	adds r5, r0, #0
	ldr r1, _080AA344 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080AA348
	asrs r2, r0, #0xd
	b _080AA34E
	.align 2, 0
_080AA344: .4byte 0x085B0A08
_080AA348:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_080AA34E:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, _080AA3D4 @ =0x03003540
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r7, #0x1c]
	subs r0, #0x4b
	subs r1, r5, r2
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r7, #0x1c]
	ldr r1, _080AA3D8 @ =0x00000352
	adds r0, r1, #0
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r7, #0x20]
	subs r0, #0x4b
	adds r1, r5, r2
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldrh r1, [r2]
	lsls r1, r1, #1
	movs r0, #0xb0
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r3, [r0]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r5, r1, #0
	cmp r3, #0
	blt _080AA3CE
	cmp r2, #0
	blt _080AA3CE
	ldr r0, _080AA3DC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080AA3CE
	ldr r0, _080AA3E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _080AA3E4
_080AA3CE:
	movs r4, #0
	b _080AA3F2
	.align 2, 0
_080AA3D4: .4byte 0x03003540
_080AA3D8: .4byte 0x00000352
_080AA3DC: .4byte 0x030046A8
_080AA3E0: .4byte 0x030046AC
_080AA3E4:
	ldr r0, _080AA404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080AA3F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA408
	adds r0, #4
	b _080AA414
	.align 2, 0
_080AA404: .4byte 0x030046A4
_080AA408:
	ldr r0, _080AA438 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA414:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AA43C
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #1
	movs r1, #0xae
	lsls r1, r1, #1
	add r1, r8
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	b _080AA4D0
	.align 2, 0
_080AA438: .4byte 0x030046A4
_080AA43C:
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080AA460
	cmp r1, #0
	blt _080AA460
	ldr r0, _080AA464 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080AA460
	ldr r0, _080AA468 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080AA46C
_080AA460:
	movs r4, #0
	b _080AA47A
	.align 2, 0
_080AA464: .4byte 0x030046A8
_080AA468: .4byte 0x030046AC
_080AA46C:
	ldr r0, _080AA48C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080AA47A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA490
	adds r0, #4
	b _080AA49C
	.align 2, 0
_080AA48C: .4byte 0x030046A4
_080AA490:
	ldr r0, _080AA4B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA49C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080AA4B4
	cmp r3, #2
	beq _080AA4B8
	b _080AA4BC
	.align 2, 0
_080AA4B0: .4byte 0x030046A4
_080AA4B4:
	ldrb r0, [r5, #4]
	b _080AA4BA
_080AA4B8:
	ldrb r0, [r5]
_080AA4BA:
	subs r2, r2, r0
_080AA4BC:
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r2, [r0]
_080AA4D0:
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
