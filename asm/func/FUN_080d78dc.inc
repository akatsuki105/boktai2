	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D790A
	cmp r1, #0
	blt _080D790A
	ldr r0, _080D7910 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D790A
	ldr r0, _080D7914 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7918
_080D790A:
	movs r4, #0
	b _080D7926
	.align 2, 0
_080D7910: .4byte 0x030046A8
_080D7914: .4byte 0x030046AC
_080D7918:
	ldr r0, _080D7938 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7926:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D793C
	adds r0, #4
	b _080D7948
	.align 2, 0
_080D7938: .4byte 0x030046A4
_080D793C:
	ldr r0, _080D7978 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7948:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D79B0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D79B0
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _080D797C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080D7980 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D7984
	movs r0, #1
	b _080D7986
	.align 2, 0
_080D7978: .4byte 0x030046A4
_080D797C: .4byte 0x030046A0
_080D7980: .4byte 0x00000934
_080D7984:
	movs r0, #0
_080D7986:
	cmp r0, #0
	beq _080D7996
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D79A0
_080D7996:
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #0
	bl PlayerLink_SetAction
_080D79A0:
	ldr r4, _080D79AC @ =0x00000376
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b _080D7B40
	.align 2, 0
_080D79AC: .4byte 0x00000376
_080D79B0:
	movs r7, #0
	mov r8, r7
	ldr r1, _080D79CC @ =0x00000376
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D79EC
	ldr r0, _080D79D0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D79D4
	movs r1, #1
	rsbs r1, r1, #0
	b _080D79D8
	.align 2, 0
_080D79CC: .4byte 0x00000376
_080D79D0: .4byte 0x03002C68
_080D79D4:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D79D8:
	ldr r4, _080D7ADC @ =0x0000045A
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D79EC
	mov r8, r1
_080D79EC:
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D7A08
	adds r0, r5, #0
	bl FUN_080cfdec
	ldr r4, _080D7AE0 @ =0x00000376
	adds r2, r5, r4
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080D7A08:
	movs r7, #0xd8
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r3, [r0]
	cmp r3, #0
	bne _080D7A84
	ldr r1, _080D7AE4 @ =0x0000043E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7A3E
	movs r4, #0xf6
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D7A3E
	ldr r7, _080D7AE0 @ =0x00000376
	adds r1, r5, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r3, [r2]
_080D7A3E:
	ldr r1, _080D7AE8 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7A84
	ldr r4, _080D7AEC @ =0x000004C7
	adds r2, r5, r4
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D7A84
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r7, _080D7AF0 @ =0x000003DA
	adds r6, r5, r7
	ldrh r4, [r6]
	adds r4, #1
	strh r4, [r6]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r1, [r2]
	movs r0, #0x3c
	bl Div
	cmp r4, r0
	blt _080D7A84
	ldr r1, _080D7AE0 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	movs r0, #0
	strh r0, [r6]
_080D7A84:
	ldr r2, _080D7AE0 @ =0x00000376
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B00
	ldr r4, _080D7AF4 @ =0x00000446
	adds r0, r5, r4
	ldrh r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _080D7AA6
	ldr r7, _080D7AF8 @ =0x00000442
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7AA6
	movs r6, #1
_080D7AA6:
	cmp r6, #0
	bne _080D7B00
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _080D7AE0 @ =0x00000376
	adds r4, r5, r2
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0x2c
	movs r7, #0x97
	lsls r7, r7, #4
	adds r2, r5, r7
	str r2, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r2, [r1]
	ldrh r0, [r4]
	cmp r2, r0
	bhs _080D7AFC
	strh r6, [r1]
	b _080D7B00
	.align 2, 0
_080D7ADC: .4byte 0x0000045A
_080D7AE0: .4byte 0x00000376
_080D7AE4: .4byte 0x0000043E
_080D7AE8: .4byte 0x000004C5
_080D7AEC: .4byte 0x000004C7
_080D7AF0: .4byte 0x000003DA
_080D7AF4: .4byte 0x00000446
_080D7AF8: .4byte 0x00000442
_080D7AFC:
	subs r0, r2, r0
	strh r0, [r1]
_080D7B00:
	ldr r1, _080D7B38 @ =0x00000376
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	mov r2, r8
	cmp r2, #0
	beq _080D7B26
	ldrh r0, [r5, #0x24]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	ldr r7, _080D7B3C @ =0x00000366
	adds r2, r5, r7
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #0xa
	bl FUN_0809c344
_080D7B26:
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B40
	movs r0, #0
	b _080D7B42
	.align 2, 0
_080D7B38: .4byte 0x00000376
_080D7B3C: .4byte 0x00000366
_080D7B40:
	movs r0, #1
_080D7B42:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
