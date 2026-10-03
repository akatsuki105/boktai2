	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080B125C @ =0x000004FE
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #5
	bhi _080B127C
	mov r2, sb
	ldrh r0, [r2]
	movs r4, #6
	subs r4, r4, r0
	ldr r5, _080B1260 @ =0x03002C00
	ldr r0, [r5]
	adds r0, #0x48
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r6, r4, #1
	muls r0, r6, r0
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080B1264 @ =0xFFFF0000
	mov r8, r1
	ldr r1, [sp]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r0, [r5]
	adds r0, #0x4c
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	ldr r2, _080B1268 @ =0x00000514
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	ldr r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r2, [r0]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B1272
	adds r0, r2, #0
	cmp r0, #0
	beq _080B1272
	cmp r0, #4
	bls _080B126C
	adds r2, #1
	b _080B126E
	.align 2, 0
_080B125C: .4byte 0x000004FE
_080B1260: .4byte 0x03002C00
_080B1264: .4byte 0xFFFF0000
_080B1268: .4byte 0x00000514
_080B126C:
	subs r2, #1
_080B126E:
	movs r0, #7
	ands r2, r0
_080B1272:
	mov r0, sp
	adds r1, r2, #0
	bl FUN_08086590
	b _080B13E6
_080B127C:
	cmp r1, #6
	bne _080B12C4
	ldr r1, _080B12BC @ =0x03002C00
	ldr r0, [r1]
	ldr r3, _080B12C0 @ =0x000001F5
	adds r2, r0, r3
	movs r0, #0xb
	strb r0, [r2]
	ldr r2, [r1]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	adds r3, #0xb
	adds r2, r2, r3
	movs r0, #0
	strb r0, [r2]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xf9
	bl PlaySound_082406e0
	b _080B13E6
	.align 2, 0
_080B12BC: .4byte 0x03002C00
_080B12C0: .4byte 0x000001F5
_080B12C4:
	cmp r1, #0x45
	bhi _080B1304
	ldr r2, _080B12F8 @ =0x00000C16
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	beq _080B12E6
	cmp r1, #0x14
	bne _080B12E6
	ldr r1, _080B12FC @ =FUN_080adb5c
	adds r0, r7, #0
	bl EntityCBB0_SetState
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080B12E6:
	ldr r3, _080B1300 @ =0x000004FE
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0x46
	subs r0, r0, r1
	asrs r0, r0, #1
	bl FUN_0823b9cc
	b _080B13E6
	.align 2, 0
_080B12F8: .4byte 0x00000C16
_080B12FC: .4byte FUN_080adb5c
_080B1300: .4byte 0x000004FE
_080B1304:
	ldr r1, _080B1348 @ =0x00000C16
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B1354
	movs r4, #0
	ldrb r2, [r7, #0x1e]
	cmp r0, r2
	bge _080B132A
	ldr r3, _080B134C @ =0x00000BE8
	adds r5, r7, r3
_080B131A:
	ldm r5!, {r0}
	movs r1, #1
	bl Generator_SetState
	adds r4, #1
	ldrb r0, [r7, #0x1e]
	cmp r4, r0
	blt _080B131A
_080B132A:
	ldr r0, _080B1350 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	movs r0, #0xfa
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #2
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B1348: .4byte 0x00000C16
_080B134C: .4byte 0x00000BE8
_080B1350: .4byte 0x03002BE0
_080B1354:
	cmp r0, #1
	bne _080B13AE
	ldr r4, _080B139C @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r3, #0
	ldrb r0, [r7, #0x1e]
	cmp r3, r0
	bge _080B138C
	ldr r1, _080B13A0 @ =0x00000BE8
	adds r2, r7, r1
	adds r1, r0, #0
_080B1378:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1384
	movs r3, #1
_080B1384:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1378
_080B138C:
	cmp r3, #0
	beq _080B13A4
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B139C: .4byte 0x03002BE0
_080B13A0: .4byte 0x00000BE8
_080B13A4:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B13E6
_080B13AE:
	ldr r4, _080B13F4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _080B13F8 @ =0x03002C00
	ldr r0, [r0]
	ldr r2, _080B13FC @ =0x000001F5
	adds r1, r0, r2
	movs r0, #0xd
	strb r0, [r1]
	ldr r3, _080B1400 @ =0x00000C6C
	adds r0, r7, r3
	movs r1, #1
	bl FUN_080af374
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B13E6:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B13F4: .4byte 0x03002BE0
_080B13F8: .4byte 0x03002C00
_080B13FC: .4byte 0x000001F5
_080B1400: .4byte 0x00000C6C
