	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08150680 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150684
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150686
	.align 2, 0
_08150680: .4byte 0x0000046C
_08150684:
	movs r0, #0
_08150686:
	cmp r0, #0
	beq _0815071C
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
	ldr r3, _08150748 @ =FUN_0814dd38
	movs r2, #0x24
	ldr r0, _0815074C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08150750 @ =0x0000046B
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
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x68
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x78
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xc
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _08150754 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
_0815071C:
	ldr r2, _08150750 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08150764
	ldr r3, _08150758 @ =0x000006CE
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _0815075C @ =0x000006CA
	adds r0, r7, r4
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _08150760 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl enemy_dog_0814b500
	b _0815076E
	.align 2, 0
_08150748: .4byte FUN_0814dd38
_0815074C: .4byte 0x0000046D
_08150750: .4byte 0x0000046B
_08150754: .4byte 0x000006D7
_08150758: .4byte 0x000006CE
_0815075C: .4byte 0x000006CA
_08150760: .4byte 0xFFFFFEFF
_08150764:
	ldr r2, _08150778 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0815076E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150778: .4byte 0x00000484
