	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r7, [r0]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	ldr r3, _081AC8B8 @ =0x00000472
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _081AC86E
	ldr r0, [r2, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081AC86E:
	movs r0, #0
	mov r8, r0
	ldr r1, _081AC8BC @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081AC968
	movs r3, #0
	mov sb, r3
	ldr r0, _081AC8C0 @ =0x00000705
	adds r3, r7, r0
	ldr r1, _081AC8C4 @ =0x00000674
	adds r6, r7, r1
	movs r2, #1
	mov sl, r2
_081AC88E:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AC8B2
	cmp r1, #0
	blt _081AC8B2
	ldr r0, _081AC8C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AC8B2
	ldr r0, _081AC8CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AC8D0
_081AC8B2:
	movs r4, #0
	b _081AC8DE
	.align 2, 0
_081AC8B8: .4byte 0x00000472
_081AC8BC: .4byte 0x00000CAA
_081AC8C0: .4byte 0x00000705
_081AC8C4: .4byte 0x00000674
_081AC8C8: .4byte 0x030046A8
_081AC8CC: .4byte 0x030046AC
_081AC8D0:
	ldr r0, _081AC8F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AC8DE:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp]
	bl Map_FindTileOverride
	ldr r3, [sp]
	cmp r0, #0
	beq _081AC8F8
	adds r0, #4
	b _081AC904
	.align 2, 0
_081AC8F4: .4byte 0x030046A4
_081AC8F8:
	ldr r0, _081AC918 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AC904:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AC91C
	cmp r2, #2
	beq _081AC920
	b _081AC924
	.align 2, 0
_081AC918: .4byte 0x030046A4
_081AC91C:
	ldrb r0, [r5, #4]
	b _081AC922
_081AC920:
	ldrb r0, [r5]
_081AC922:
	subs r1, r1, r0
_081AC924:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _081AC940
	ldrb r0, [r3]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _081AC93A
	movs r0, #1
	b _081AC93C
_081AC93A:
	movs r0, #0
_081AC93C:
	cmp r0, #0
	beq _081AC950
_081AC940:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	add r1, sb
	ldr r0, [r1]
	mov r2, sl
	orrs r0, r2
	str r0, [r1]
_081AC950:
	movs r0, #0xd0
	add sb, r0
	adds r3, #0xd0
	adds r6, #0xd0
	movs r1, #1
	add r8, r1
	ldr r2, _081AC978 @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _081AC88E
_081AC968:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AC978: .4byte 0x00000CAA
