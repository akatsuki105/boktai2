	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _08062710 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080626AA
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08062468
_080626AA:
	adds r0, r5, #0
	bl FUN_0806241c
	adds r2, r0, #0
	ldr r6, _08062714 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _080626C8
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _080626D6
_080626C8:
	strh r4, [r1]
	ldr r1, _08062718 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080622d0
_080626D6:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r4, [r2]
	cmp r4, #0
	beq _080626E4
	b _0806281A
_080626E4:
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _08062770
	ldr r6, _0806271C @ =0x00000121
	adds r0, r0, r6
	ldr r2, _08062720 @ =0x00000962
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _08062724 @ =0x03003584
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r3, _08062728 @ =0x00000964
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _0806272C
	adds r2, r1, #0
	b _08062742
	.align 2, 0
_08062710: .4byte 0x00000951
_08062714: .4byte 0x0000094C
_08062718: .4byte 0x0000094E
_0806271C: .4byte 0x00000121
_08062720: .4byte 0x00000962
_08062724: .4byte 0x03003584
_08062728: .4byte 0x00000964
_0806272C:
	cmp r1, #0x2f
	bhi _08062734
	movs r2, #0x20
	b _08062742
_08062734:
	cmp r1, #0x4f
	bhi _08062740
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _08062742
_08062740:
	movs r2, #0
_08062742:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080624b0
	ldr r6, _0806276C @ =0x00000964
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _08062766
	b _080628DC
_08062766:
	movs r0, #0
	b _080628DA
	.align 2, 0
_0806276C: .4byte 0x00000964
_08062770:
	ldr r0, _080627AC @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _080627DE
	ldr r1, _080627B0 @ =0x03003584
	ldr r6, _080627B4 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806279E
	movs r0, #0x30
	strh r0, [r3]
_0806279E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _080627B8
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080627CC
	.align 2, 0
_080627AC: .4byte 0x00000964
_080627B0: .4byte 0x03003584
_080627B4: .4byte 0x00000962
_080627B8:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080627CC
	strh r4, [r3]
_080627CC:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080624b0
	b _080628DC
_080627DE:
	ldr r1, _08062800 @ =0x00000962
	adds r0, r5, r1
	strh r4, [r0]
	strh r4, [r3]
	ldr r2, _08062804 @ =0x00000359
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062808
	adds r1, r5, #0
	adds r1, #0xd0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r0, r5, r3
	str r0, [r1]
	b _080628DC
	.align 2, 0
_08062800: .4byte 0x00000962
_08062804: .4byte 0x00000359
_08062808:
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080628DC
_0806281A:
	ldr r3, _08062860 @ =0x00000964
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _080628B2
	ldr r1, _08062864 @ =0x03003584
	ldr r6, _08062868 @ =0x0000095E
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r2, _0806286C @ =0x00000359
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806288A
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062850:
	subs r0, r3, #5
	cmp r0, #1
	bls _0806285A
	cmp r3, #0xd
	bne _08062870
_0806285A:
	ldrh r0, [r4]
	b _08062872
	.align 2, 0
_08062860: .4byte 0x00000964
_08062864: .4byte 0x03003584
_08062868: .4byte 0x0000095E
_0806286C: .4byte 0x00000359
_08062870:
	ldrh r0, [r1]
_08062872:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062850
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _080628D0
_0806288A:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_08062892:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08062892
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080628D0
_080628B2:
	ldr r1, _080628E4 @ =0x03003584
	ldr r3, _080628E8 @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
_080628D0:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
_080628DA:
	strh r0, [r1]
_080628DC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080628E4: .4byte 0x03003584
_080628E8: .4byte 0x0000095E
