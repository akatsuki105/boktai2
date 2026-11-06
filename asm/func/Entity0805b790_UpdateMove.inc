	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B38C
	movs r0, #0
	strb r0, [r6, #1]
_0805B38C:
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B3B0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3B4
	asrs r1, r0, #0xc
	b _0805B3BA
	.align 2, 0
_0805B3B0: .4byte gSineTable
_0805B3B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B3BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3D2
	asrs r0, r0, #0xc
	b _0805B3D8
_0805B3D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B3D8:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B43C
	cmp r1, #0
	blt _0805B43C
	ldr r0, _0805B440 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B43C
	ldr r0, _0805B444 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B448
_0805B43C:
	movs r4, #0
	b _0805B456
	.align 2, 0
_0805B440: .4byte 0x030046A8
_0805B444: .4byte 0x030046AC
_0805B448:
	ldr r0, _0805B468 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B456:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B46C
	adds r0, #4
	b _0805B478
	.align 2, 0
_0805B468: .4byte 0x030046A4
_0805B46C:
	ldr r0, _0805B48C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B490
	cmp r2, #2
	beq _0805B494
	b _0805B498
	.align 2, 0
_0805B48C: .4byte 0x030046A4
_0805B490:
	ldrb r0, [r5, #4]
	b _0805B496
_0805B494:
	ldrb r0, [r5]
_0805B496:
	subs r1, r1, r0
_0805B498:
	cmp r8, r1
	bhi _0805B4AA
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B4C0
_0805B4AA:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B4BC
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl Entity0805b790_ReleaseElem
	b _0805B4C0
_0805B4BC:
	adds r0, #1
	strh r0, [r6, #4]
_0805B4C0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
