	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080D66C0 @ =0x000003F3
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _080D665E
	b _080D67AE
_080D665E:
	ldr r2, _080D66C4 @ =0x000003BD
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, r3, #7
	movs r0, #7
	ands r2, r0
	adds r1, r3, #0
	adds r1, #9
	ands r1, r0
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r3
	beq _080D6688
	cmp r0, r2
	beq _080D6688
	cmp r0, r1
	beq _080D6688
	b _080D67DC
_080D6688:
	ldr r1, _080D66C4 @ =0x000003BD
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _080D66C8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D66CC
	asrs r2, r0, #0xc
	b _080D66D2
	.align 2, 0
_080D66C0: .4byte 0x000003F3
_080D66C4: .4byte 0x000003BD
_080D66C8: .4byte gSineTable
_080D66CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D66D2:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D66FC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6700
	asrs r2, r0, #0xc
	b _080D6706
	.align 2, 0
_080D66FC: .4byte 0xFFFF0000
_080D6700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6706:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6748 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6742
	cmp r1, #0
	blt _080D6742
	ldr r0, _080D674C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6742
	ldr r0, _080D6750 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6754
_080D6742:
	movs r4, #0
	b _080D6762
	.align 2, 0
_080D6748: .4byte 0xFFFF0000
_080D674C: .4byte 0x030046A8
_080D6750: .4byte 0x030046AC
_080D6754:
	ldr r0, _080D6774 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6762:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D6778
	adds r0, #4
	b _080D6784
	.align 2, 0
_080D6774: .4byte 0x030046A4
_080D6778:
	ldr r0, _080D6798 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6784:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D679C
	cmp r2, #2
	beq _080D67A0
	b _080D67A4
	.align 2, 0
_080D6798: .4byte 0x030046A4
_080D679C:
	ldrb r0, [r6, #4]
	b _080D67A2
_080D67A0:
	ldrb r0, [r6]
_080D67A2:
	subs r1, r1, r0
_080D67A4:
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #0xc8
	cmp r1, r0
	blo _080D67B2
_080D67AE:
	movs r0, #1
	b _080D67FA
_080D67B2:
	ldr r4, _080D67D8 @ =0x000003BD
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl PlayerLink_SetAnimFacing
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	b _080D67F6
	.align 2, 0
_080D67D8: .4byte 0x000003BD
_080D67DC:
	adds r0, r3, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl PlayerLink_SetAnimFacing
	movs r6, #0xdf
	lsls r6, r6, #2
	adds r0, r5, r6
_080D67F6:
	strb r4, [r0]
	movs r0, #0
_080D67FA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
