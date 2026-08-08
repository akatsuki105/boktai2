	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _080EE364 @ =0x00000252
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _080EE368 @ =0x000001DF
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080EE336
	adds r0, r1, #0
	cmp r0, #9
	beq _080EE336
	cmp r0, #0x16
	beq _080EE336
	adds r6, r7, #0
	adds r6, #8
	subs r2, #0xc
	adds r4, r7, r2
	ldrb r1, [r4]
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r6, #0
	bl FUN_08234f90
	adds r5, r7, #0
	adds r5, #0x9c
	ldrb r1, [r4]
	ldr r2, _080EE36C @ =0x00000251
	adds r0, r7, r2
	ldrb r2, [r0]
	mov r0, r8
	ldrb r3, [r0]
	adds r0, r5, #0
	bl FUN_08234de8
	ldr r1, _080EE370 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r1, r6, #0
	bl FUN_082362fc
	str r5, [r7, #0x24]
_080EE336:
	adds r0, r7, #0
	adds r0, #8
	ldrh r1, [r7, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _080EE360
	cmp r1, #0
	blt _080EE360
	ldr r0, _080EE374 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080EE360
	ldr r0, _080EE378 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EE37C
_080EE360:
	movs r1, #0
	b _080EE38A
	.align 2, 0
_080EE364: .4byte 0x00000252
_080EE368: .4byte 0x000001DF
_080EE36C: .4byte 0x00000251
_080EE370: .4byte 0x000004A4
_080EE374: .4byte 0x030046A8
_080EE378: .4byte 0x030046AC
_080EE37C:
	ldr r0, _080EE3A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080EE38A:
	ldr r2, _080EE3A8 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r4, [r0]
	mov r5, r8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EE3AC
	adds r0, #4
	b _080EE3B8
	.align 2, 0
_080EE3A4: .4byte 0x030046A4
_080EE3A8: .4byte 0x00000256
_080EE3AC:
	ldr r0, _080EE3CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EE3B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080EE3D0
	cmp r2, #2
	beq _080EE3D4
	b _080EE3D8
	.align 2, 0
_080EE3CC: .4byte 0x030046A4
_080EE3D0:
	ldrb r0, [r5, #4]
	b _080EE3D6
_080EE3D4:
	ldrb r0, [r5]
_080EE3D6:
	subs r1, r1, r0
_080EE3D8:
	strh r1, [r7, #0xa]
	ldr r1, _080EE3F4 @ =0x0000025D
	adds r0, r7, r1
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0
	bne _080EE3F8
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080EE402
	.align 2, 0
_080EE3F4: .4byte 0x0000025D
_080EE3F8:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080EE402:
	ldr r2, _080EE494 @ =0x00000564
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r7, #5]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #8
	bl ClearMemory
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	movs r2, #0x80
	lsls r2, r2, #0xe
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r4, r7, r1
	cmp r0, #0
	beq _080EE470
	ldr r1, _080EE498 @ =0xFEFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, _080EE49C @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080EE4A0 @ =0x0000021E
	adds r0, r7, r1
	strh r5, [r0]
	subs r2, #0x1a
	adds r0, r7, r2
	strh r5, [r0]
_080EE470:
	ldr r1, _080EE4A4 @ =0x0000047A
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #0
	bne _080EE4A8
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080EE4B4
	.align 2, 0
_080EE494: .4byte 0x00000564
_080EE498: .4byte 0xFEFFFFFF
_080EE49C: .4byte 0xFFFFFDFF
_080EE4A0: .4byte 0x0000021E
_080EE4A4: .4byte 0x0000047A
_080EE4A8:
	ldr r2, [r7, #0x44]
	ldr r0, _080EE508 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080EE4B4:
	ldr r1, _080EE50C @ =0xFDFF7FFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r1, _080EE510 @ =0xFFFFBE3F
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r0, #0xd8
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080EE514 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _080EE518 @ =0x00000494
	adds r0, r7, r2
	strh r1, [r0]
	subs r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #2
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #0
	bne _080EE51C
	ldr r0, [r7, #0x44]
	strb r1, [r0, #7]
	b _080EE522
	.align 2, 0
_080EE508: .4byte 0x03003584
_080EE50C: .4byte 0xFDFF7FFF
_080EE510: .4byte 0xFFFFBE3F
_080EE514: .4byte 0x0000FFFB
_080EE518: .4byte 0x00000494
_080EE51C:
	ldr r0, [r7, #0x44]
	adds r0, #0x3a
	strb r1, [r0]
_080EE522:
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
