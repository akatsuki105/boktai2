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
	beq _0805B4F0
	movs r0, #0
	strb r0, [r6, #1]
_0805B4F0:
	adds r0, r6, #0
	bl Entity0805b790_TurnToTarget
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B518 @ =gSineTable
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
	blt _0805B51C
	asrs r1, r0, #0xc
	b _0805B522
	.align 2, 0
_0805B518: .4byte gSineTable
_0805B51C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B522:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805B53C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B540
	asrs r0, r0, #0xc
	b _0805B546
	.align 2, 0
_0805B53C: .4byte gSineTable
_0805B540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B546:
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
	blt _0805B5AA
	cmp r1, #0
	blt _0805B5AA
	ldr r0, _0805B5B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B5AA
	ldr r0, _0805B5B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B5B8
_0805B5AA:
	movs r4, #0
	b _0805B5C6
	.align 2, 0
_0805B5B0: .4byte 0x030046A8
_0805B5B4: .4byte 0x030046AC
_0805B5B8:
	ldr r0, _0805B5D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B5C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B5DC
	adds r0, #4
	b _0805B5E8
	.align 2, 0
_0805B5D8: .4byte 0x030046A4
_0805B5DC:
	ldr r0, _0805B5FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B5E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B600
	cmp r2, #2
	beq _0805B604
	b _0805B608
	.align 2, 0
_0805B5FC: .4byte 0x030046A4
_0805B600:
	ldrb r0, [r5, #4]
	b _0805B606
_0805B604:
	ldrb r0, [r5]
_0805B606:
	subs r1, r1, r0
_0805B608:
	cmp r8, r1
	bhi _0805B61A
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B630
_0805B61A:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B62C
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl Entity0805b790_ReleaseElem
	b _0805B630
_0805B62C:
	adds r0, #1
	strh r0, [r6, #4]
_0805B630:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
