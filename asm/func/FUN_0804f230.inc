	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	bl FUN_0804e474
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	beq _0804F260
	movs r0, #0
	strb r0, [r6, #0x1a]
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #7
	bl TextPanel_SetMessage
	movs r0, #0xff
	strb r0, [r6, #0x1c]
_0804F260:
	ldrb r0, [r6, #0x1c]
	cmp r7, r0
	bne _0804F268
	b _0804F380
_0804F268:
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r1, r1, r6
	mov r8, r1
	cmp r7, #0
	beq _0804F35C
	ldr r5, _0804F34C @ =0x03005800
	ldr r0, [r5]
	ldrb r0, [r0, #2]
	cmp r7, r0
	bne _0804F35C
	bl FUN_0804e438
	cmp r0, #0
	beq _0804F33A
	movs r4, #0
	ldr r0, [r5]
	ldrb r1, [r0, #2]
	movs r0, #1
	ands r1, r0
	ldr r0, _0804F350 @ =0x0000053C
	adds r0, r0, r6
	mov sb, r0
	movs r0, #0xd2
	lsls r0, r0, #2
	adds r0, r0, r6
	mov sl, r0
	cmp r1, #0
	bne _0804F2B8
	adds r2, r5, #0
	movs r1, #1
_0804F2A6:
	adds r4, #1
	cmp r4, #3
	bgt _0804F2B8
	ldr r0, [r2]
	ldrb r0, [r0, #2]
	asrs r0, r4
	ands r0, r1
	cmp r0, #0
	beq _0804F2A6
_0804F2B8:
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r1, r1, r6
	mov r8, r1
	mov r0, sb
	movs r1, #0x18
	bl ClearMemory
	ldr r5, _0804F34C @ =0x03005800
	lsls r4, r4, #5
	adds r4, #0x14
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #6
	mov r1, sb
	movs r2, #0xb
	bl Crossover_DecodeText
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #6
	ldrb r2, [r0, #0xb]
	ldrb r0, [r0, #0xc]
	lsls r0, r0, #8
	orrs r2, r0
	ldr r0, _0804F354 @ =0x00000664
	adds r1, r6, r0
	movs r3, #0
	str r3, [sp]
	movs r0, #0x88
	str r0, [sp, #4]
	movs r0, #0x46
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r0, sl
	movs r3, #5
	bl MainSprite_SetNumber
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xd4
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r4, #4
_0804F314:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0804F314
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r2, #0x9f
	lsls r2, r2, #2
	add r2, r8
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, _0804F358 @ =0x000001EF
	bl PlaySound_082406e0
_0804F33A:
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #8
	bl TextPanel_SetMessage
	b _0804F37E
	.align 2, 0
_0804F348: .4byte 0x0000055C
_0804F34C: .4byte 0x03005800
_0804F350: .4byte 0x0000053C
_0804F354: .4byte 0x00000664
_0804F358: .4byte 0x000001EF
_0804F35C:
	ldr r1, _0804F3AC @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #7
	bl TextPanel_SetMessage
	movs r1, #1
	mov r2, r8
	adds r2, #0x90
	movs r4, #4
_0804F370:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r2, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0804F370
_0804F37E:
	strb r7, [r6, #0x1c]
_0804F380:
	ldr r0, _0804F3B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804F394
	cmp r7, #0
	beq _0804F394
	bl FUN_0804e4c4
_0804F394:
	ldr r0, _0804F3B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F3C2
	cmp r7, #0
	beq _0804F3B4
	bl FUN_0804e4ac
	b _0804F3C2
	.align 2, 0
_0804F3AC: .4byte 0x0000055C
_0804F3B0: .4byte 0x030044E0
_0804F3B4:
	bl FUN_0804e4c4
	movs r0, #7
	strb r0, [r6, #0x19]
	movs r0, #1
	strb r0, [r6, #0x1a]
	str r7, [r6, #0x20]
_0804F3C2:
	ldr r0, [r6, #0x20]
	adds r0, #1
	str r0, [r6, #0x20]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
