	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08150554 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150558
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815055A
	.align 2, 0
_08150554: .4byte 0x0000046C
_08150558:
	movs r0, #0
_0815055A:
	cmp r0, #0
	beq _081505FE
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _0815062C @ =FUN_0814deb0
	movs r2, #0x21
	ldr r0, _08150630 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08150634 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #3
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, _08150638 @ =0x00000226
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x66
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x74
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xa
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _0815063C @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08150640 @ =0x000006CC
	adds r0, r7, r2
	ldrh r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
_081505FE:
	ldr r4, _08150634 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08150648
	ldr r1, _08150640 @ =0x000006CC
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, _08150644 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl enemy_dog_0814b500
	b _08150652
	.align 2, 0
_0815062C: .4byte FUN_0814deb0
_08150630: .4byte 0x0000046D
_08150634: .4byte 0x0000046B
_08150638: .4byte 0x00000226
_0815063C: .4byte 0x000006D7
_08150640: .4byte 0x000006CC
_08150644: .4byte 0xFFFFFEFF
_08150648:
	ldr r4, _0815065C @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150652:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815065C: .4byte 0x00000484
