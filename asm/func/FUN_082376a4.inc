	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r4, r0, #0
	str r1, [sp, #0x20]
	mov sl, r3
	ldr r6, [sp, #0x44]
	cmp r3, #8
	ble _082376C0
	movs r0, #8
	mov sl, r0
_082376C0:
	movs r3, #0
	adds r1, r6, #0
	ldr r0, _082377CC @ =0x0098967F
	ldr r5, [sp, #0x54]
	rsbs r7, r5, #0
	cmp r2, r0
	ble _082376D8
	ldr r5, _082377D0 @ =0xFF676980
_082376D0:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _082376D0
_082376D8:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377D4 @ =0x000F423F
	cmp r2, r0
	ble _082376F2
	ldr r5, _082377D8 @ =0xFFF0BDC0
_082376EA:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _082376EA
_082376F2:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377DC @ =0x0001869F
	cmp r2, r0
	ble _0823770C
	ldr r5, _082377E0 @ =0xFFFE7960
_08237704:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _08237704
_0823770C:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377E4 @ =0x0000270F
	cmp r2, r0
	ble _08237726
	ldr r5, _082377E8 @ =0xFFFFD8F0
_0823771E:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _0823771E
_08237726:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377EC @ =0x000003E7
	cmp r2, r0
	ble _08237740
	ldr r5, _082377F0 @ =0xFFFFFC18
_08237738:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _08237738
_08237740:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #0x63
	ble _08237756
_0823774E:
	adds r1, #1
	subs r2, #0x64
	cmp r2, #0x63
	bgt _0823774E
_08237756:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #9
	ble _0823776C
_08237764:
	adds r1, #1
	subs r2, #0xa
	cmp r2, #9
	bgt _08237764
_0823776C:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #0
	ble _08237782
_0823777A:
	adds r1, #1
	subs r2, #1
	cmp r2, #0
	bgt _0823777A
_08237782:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	mov r0, sl
	subs r0, r3, r0
	mov sb, r0
	ldr r1, [sp, #0x54]
	orrs r7, r1
	lsrs r7, r7, #0x1f
	mov r8, r7
	ldr r7, [sp, #0x48]
	movs r6, #0
	cmp r6, sl
	bge _08237824
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r0, r1
_082377A6:
	mov r0, sb
	adds r2, r0, r6
	mov r1, r8
	cmp r1, #0
	beq _082377F4
	ldr r0, [r5]
	cmp r0, #0
	beq _082377BA
	movs r0, #0
	mov r8, r0
_082377BA:
	mov r1, r8
	cmp r1, #0
	beq _082377F4
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _08237816
	.align 2, 0
_082377CC: .4byte 0x0098967F
_082377D0: .4byte 0xFF676980
_082377D4: .4byte 0x000F423F
_082377D8: .4byte 0xFFF0BDC0
_082377DC: .4byte 0x0001869F
_082377E0: .4byte 0xFFFE7960
_082377E4: .4byte 0x0000270F
_082377E8: .4byte 0xFFFFD8F0
_082377EC: .4byte 0x000003E7
_082377F0: .4byte 0xFFFFFC18
_082377F4:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	lsls r0, r2, #2
	add r0, sp
	ldrh r2, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0
	bl Sprite_SetSprite
	strh r7, [r4, #0x20]
	add r0, sp, #0x4c
	ldrh r0, [r0]
	strh r0, [r4, #0x22]
_08237816:
	ldr r1, [sp, #0x50]
	adds r7, r7, r1
	adds r5, #4
	adds r6, #1
	adds r4, #0x60
	cmp r6, sl
	blt _082377A6
_08237824:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
