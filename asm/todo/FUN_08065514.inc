	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r5, r0
	str r0, [sp, #4]
	ldr r1, _080655A4 @ =0x0000DA6D
	bl FUN_0822b16c
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sl, r1
	ldr r1, _080655A8 @ =0x0000D495
	mov r0, sl
	bl FUN_0822b16c
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r2, r2, r5
	mov sb, r2
	ldr r1, _080655AC @ =0x00002499
	mov r0, sb
	bl FUN_0822b16c
	ldr r4, _080655B0 @ =0x0000922E
	ldr r1, _080655B4 @ =0x00005BB7
	adds r0, r4, #0
	bl FUN_082310cc
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r3, r3, r5
	mov r8, r3
	str r0, [r3]
	ldr r1, _080655B8 @ =0x0000AF44
	adds r0, r4, #0
	bl FUN_082310cc
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	ldr r1, _080655BC @ =0x00003D95
	adds r0, r4, #0
	bl FUN_082310cc
	adds r1, r0, #0
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	adds r7, r5, #0
	adds r7, #0xe8
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080655C0
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r2, sl
	str r2, [r0]
	ldr r6, [r6]
	b _080655F2
	.align 2, 0
_080655A4: .4byte 0x0000DA6D
_080655A8: .4byte 0x0000D495
_080655AC: .4byte 0x00002499
_080655B0: .4byte 0x0000922E
_080655B4: .4byte 0x00005BB7
_080655B8: .4byte 0x0000AF44
_080655BC: .4byte 0x00003D95
_080655C0:
	cmp r0, #4
	bne _080655E4
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r3, sb
	str r3, [r0]
	adds r6, r1, #0
	bl GetPlayerCoffinID
	ldr r2, _080655E0 @ =0x00000387
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	mov r8, r1
	b _080655F6
	.align 2, 0
_080655E0: .4byte 0x00000387
_080655E4:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [sp, #4]
	str r1, [r0]
	mov r2, r8
	ldr r6, [r2]
_080655F2:
	movs r3, #0
	mov r8, r3
_080655F6:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _08065674 @ =0x00001001
	adds r0, r7, #0
	bl FUN_0822a470
	ldrh r1, [r5, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldrh r0, [r5, #0x2e]
	movs r3, #0x83
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r1, [r5, #0x30]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	ldr r1, _08065678 @ =0x000003F6
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	mov r2, r8
	ldr r3, _0806567C @ =0x000002E6
	adds r0, r5, r3
	ldrb r3, [r0]
	ldr r1, _08065680 @ =0x000002E7
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08065684
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _0806568C
	.align 2, 0
_08065674: .4byte 0x00001001
_08065678: .4byte 0x000003F6
_0806567C: .4byte 0x000002E6
_08065680: .4byte 0x000002E7
_08065684:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806568C:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080656B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080656B8
_080656B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080656B8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080656F0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08065728
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080656F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080656E8
	ldrb r0, [r4, #5]
_080656E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08065704
	.align 2, 0
_080656F0: .4byte 0x0000FFFF
_080656F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08065704
	strh r1, [r4, #8]
_08065704:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08065728
	movs r0, #1
	strb r0, [r4, #7]
_08065728:
	ldr r3, _08065740 @ =0x00000382
	adds r1, r5, r3
	movs r0, #0xbe
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065740: .4byte 0x00000382
