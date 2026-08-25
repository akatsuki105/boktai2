	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _080646A8
	adds r0, r5, #0
	bl FUN_08064658
	movs r3, #0xa7
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _080646A0
	mov r1, sp
	ldr r0, _0806469C @ =0x08DA9E68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	b _080646C8
	.align 2, 0
_0806469C: .4byte 0x08DA9E68
_080646A0:
	mov r1, sp
	bl FUN_08242a98
	b _080646C8
_080646A8:
	movs r4, #0xa7
	lsls r4, r4, #4
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	ldr r1, _0806470C @ =0x08DA9E68
	mov r0, sp
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r1, r2
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
_080646C8:
	mov r0, sp
	ldrb r0, [r0]
	ldr r3, _08064710 @ =0x00000A74
	adds r4, r5, r3
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #1]
	ldr r1, _08064714 @ =0x00000A75
	adds r6, r5, r1
	strb r0, [r6]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r2, _08064718 @ =0x00000A78
	adds r0, r5, r2
	strh r1, [r0]
	mov r0, sp
	bl FUN_0807a6cc
	ldr r3, _0806471C @ =0x00000A7A
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	mov r1, sp
	bl Player_EnableWeaponSpecialEffects
	ldrb r0, [r4]
	cmp r0, #0x3d
	bne _08064728
	ldr r4, _08064720 @ =0x00000A98
	adds r1, r5, r4
	ldr r0, _08064724 @ =FUN_08071b14
	str r0, [r1]
	b _08064738
	.align 2, 0
_0806470C: .4byte 0x08DA9E68
_08064710: .4byte 0x00000A74
_08064714: .4byte 0x00000A75
_08064718: .4byte 0x00000A78
_0806471C: .4byte 0x00000A7A
_08064720: .4byte 0x00000A98
_08064724: .4byte FUN_08071b14
_08064728:
	ldr r0, _0806475C @ =0x00000A98
	adds r2, r5, r0
	ldr r1, _08064760 @ =0x085ABAB8
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08064738:
	adds r0, r5, #0
	bl FUN_080643d4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _08064754
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08064754:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806475C: .4byte 0x00000A98
_08064760: .4byte 0x085ABAB8
