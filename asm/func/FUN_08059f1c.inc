	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r1, #0
	movs r0, #0xbc
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r7, #1]
	cmp r0, #0
	beq _08059F52
	movs r0, #0
	strb r0, [r7, #1]
	ldrb r0, [r7, #0xc]
	strb r0, [r7, #0xd]
	movs r0, #0x28
	strh r0, [r7, #0xe]
	adds r2, r7, #0
	adds r2, #0x6c
	subs r0, #0x2d
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	movs r0, #0xb5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08059F52:
	mov r3, sp
	ldrb r4, [r7, #0xc]
	ldrh r5, [r7, #0xe]
	ldr r2, _08059F74 @ =gSineTable
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
	blt _08059F78
	asrs r1, r0, #0xc
	b _08059F7E
	.align 2, 0
_08059F74: .4byte gSineTable
_08059F78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059F7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059F96
	asrs r0, r0, #0xc
	b _08059F9C
_08059F96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059F9C:
	strh r0, [r3, #4]
	mov r5, r8
	adds r5, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, r8
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r2, r8
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r0, r7, #0
	adds r0, #0x6c
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r2, r8
	movs r3, #0x1e
	ldrsh r6, [r2, r3]
	adds r4, r5, #0
	ldrh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r5, #0
	blt _0805A012
	cmp r1, #0
	blt _0805A012
	ldr r0, _0805A018 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0805A012
	ldr r0, _0805A01C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805A020
_0805A012:
	movs r5, #0
	b _0805A02E
	.align 2, 0
_0805A018: .4byte 0x030046A8
_0805A01C: .4byte 0x030046AC
_0805A020:
	ldr r0, _0805A040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_0805A02E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805A044
	adds r0, #4
	b _0805A050
	.align 2, 0
_0805A040: .4byte 0x030046A4
_0805A044:
	ldr r0, _0805A064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805A050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805A068
	cmp r2, #2
	beq _0805A06C
	b _0805A070
	.align 2, 0
_0805A064: .4byte 0x030046A4
_0805A068:
	ldrb r0, [r4, #4]
	b _0805A06E
_0805A06C:
	ldrb r0, [r4]
_0805A06E:
	subs r1, r1, r0
_0805A070:
	cmp r6, r1
	bhi _0805A078
	movs r0, #5
	b _0805A080
_0805A078:
	ldrh r0, [r7, #8]
	cmp r0, #0x7f
	bls _0805A08C
	movs r0, #4
_0805A080:
	movs r1, #0
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	strh r1, [r7, #8]
	b _0805A090
_0805A08C:
	adds r0, #1
	strh r0, [r7, #8]
_0805A090:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
