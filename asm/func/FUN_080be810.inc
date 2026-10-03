	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BE850 @ =0x00001655
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080BE90C
	adds r1, #5
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BE854
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BE86C
	.align 2, 0
_080BE850: .4byte 0x00001655
_080BE854:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BE86C:
	str r0, [r1]
	ldr r0, _080BE890 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080BE89C
	ldr r0, _080BE894 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080BE898
	movs r0, #2
	b _080BE8BE
	.align 2, 0
_080BE890: .4byte 0x030044E0
_080BE894: .4byte 0x00001654
_080BE898:
	subs r0, #1
	b _080BE8BE
_080BE89C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080BE8D0
	ldr r0, _080BE8B8 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bne _080BE8BC
	strb r2, [r1]
	b _080BE8C0
	.align 2, 0
_080BE8B8: .4byte 0x00001654
_080BE8BC:
	adds r0, #1
_080BE8BE:
	strb r0, [r1]
_080BE8C0:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080be0d8
	b _080BE92A
_080BE8D0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BE92A
	ldr r0, _080BE900 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BE904 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BE908 @ =FUN_080be948
	adds r0, r4, #0
	bl Entity744F_SetState
	b _080BE936
	.align 2, 0
_080BE900: .4byte 0x00000119
_080BE904: .4byte 0x0000FFFF
_080BE908: .4byte FUN_080be948
_080BE90C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BE940 @ =0x0000165A
	adds r0, r4, r1
	strb r3, [r0]
_080BE92A:
	ldr r1, _080BE944 @ =0x0000189C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BE936:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE940: .4byte 0x0000165A
_080BE944: .4byte 0x0000189C
