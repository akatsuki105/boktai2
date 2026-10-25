	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C7662
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r0, #0x80
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, _080C76AC @ =0x000008F2
	adds r1, r7, r3
	movs r0, #0xc0
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r3, _080C76B0 @ =0x000025CA
	adds r0, r7, r3
	strh r4, [r0]
_080C7662:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C7678
	b _080C788C
_080C7678:
	ldr r1, _080C76B4 @ =0x0000191C
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080C76BC
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r4, #1
	str r4, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r3, _080C76B8 @ =0x000025E8
	adds r0, r7, r3
	b _080C76E2
	.align 2, 0
_080C76AC: .4byte 0x000008F2
_080C76B0: .4byte 0x000025CA
_080C76B4: .4byte 0x0000191C
_080C76B8: .4byte 0x000025E8
_080C76BC:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080C76E4
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C777C @ =0x000025E8
	adds r0, r7, r2
_080C76E2:
	strh r4, [r0]
_080C76E4:
	ldr r3, _080C777C @ =0x000025E8
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C7718
	adds r0, #1
	movs r5, #0
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C7718
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	strh r5, [r4]
_080C7718:
	adds r0, r7, #0
	bl FUN_080c4990
	mov r2, r8
	cmp r2, #0x1e
	beq _080C7726
	b _080C788C
_080C7726:
	ldr r3, _080C7780 @ =0x0000190A
	adds r2, r7, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r4, #0
	strb r0, [r2]
	adds r3, #1
	adds r1, r7, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080C77FC
	strb r4, [r2]
	ldr r1, _080C777C @ =0x000025E8
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080C7784 @ =0x0000260C
	adds r0, r7, r2
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C77A8
	ldr r3, _080C7788 @ =0x000025EC
	adds r0, r7, r3
	strh r4, [r0]
	ldr r2, _080C778C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C7790 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C7794 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C779C
	ldr r1, _080C7798 @ =FUN_080c86ac
	movs r0, #0x14
	b _080C77CE
	.align 2, 0
_080C777C: .4byte 0x000025E8
_080C7780: .4byte 0x0000190A
_080C7784: .4byte 0x0000260C
_080C7788: .4byte 0x000025EC
_080C778C: .4byte 0x030046B8
_080C7790: .4byte 0x000003FF
_080C7794: .4byte 0x0203B400
_080C7798: .4byte FUN_080c86ac
_080C779C:
	ldr r1, _080C77A4 @ =FUN_080c898c
	movs r0, #0x17
	b _080C77CE
	.align 2, 0
_080C77A4: .4byte FUN_080c898c
_080C77A8:
	cmp r3, #1
	bne _080C77E8
	ldr r2, _080C77C0 @ =0x000025C9
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C77C8
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080C77C4 @ =FUN_080c7e54
	movs r0, #0xb
	b _080C77CE
	.align 2, 0
_080C77C0: .4byte 0x000025C9
_080C77C4: .4byte FUN_080c7e54
_080C77C8:
	strb r3, [r1]
	ldr r1, _080C77E4 @ =FUN_080c81e0
	movs r0, #0xf
_080C77CE:
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _080C788C
	.align 2, 0
_080C77E4: .4byte FUN_080c81e0
_080C77E8:
	ldr r1, _080C77F8 @ =FUN_080c8cc8
	movs r0, #0x1b
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	b _080C787E
	.align 2, 0
_080C77F8: .4byte FUN_080c8cc8
_080C77FC:
	ldr r3, _080C7840 @ =0x0000260C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C7874
	ldr r2, _080C7844 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C7848 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C784C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080C7858
	ldr r1, _080C7850 @ =FUN_080c718c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	ldr r2, _080C7854 @ =0x000025FA
	adds r0, r7, r2
	strb r4, [r0]
	b _080C788C
	.align 2, 0
_080C7840: .4byte 0x0000260C
_080C7844: .4byte 0x030046B8
_080C7848: .4byte 0x000003FF
_080C784C: .4byte 0x0203B400
_080C7850: .4byte FUN_080c718c
_080C7854: .4byte 0x000025FA
_080C7858:
	ldr r1, _080C7870 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080C788C
	.align 2, 0
_080C7870: .4byte FUN_080c6c8c
_080C7874:
	ldr r1, _080C7898 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
_080C787E:
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C788C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7898: .4byte FUN_080c6c8c
