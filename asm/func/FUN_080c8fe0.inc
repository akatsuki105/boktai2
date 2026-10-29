	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C903C
	movs r4, #0
	strb r4, [r1]
	ldr r1, _080C9174 @ =0x0000191E
	adds r0, r7, r1
	strh r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #5
	adds r2, r7, r3
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xc
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C903C:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080C9052
	b _080C925E
_080C9052:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _080C9178 @ =0x0000191C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080C90AA
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r4, #1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xd
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C917C @ =0x000025E8
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080C9174 @ =0x0000191E
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #5
	adds r2, r7, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C90AA:
	ldr r2, _080C917C @ =0x000025E8
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C90DC
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C90DC
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #1
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xc
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	strh r5, [r4]
_080C90DC:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C9136
	ldr r5, _080C9180 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _080C9184 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r6, _080C9188 @ =0x0203B400
	ldr r4, _080C918C @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _080C9190 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	adds r1, #0x80
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r3, [r2]
	movs r0, #0x1f
	ands r3, r0
	adds r3, #0xf1
	movs r0, #0xff
	ands r3, r0
	adds r0, r7, #0
	add r2, sp, #0xc
	bl FUN_080c3db4
_080C9136:
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C914A
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C914A:
	ldr r3, _080C9174 @ =0x0000191E
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C9230
	subs r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080C9194
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _080C9230
	.align 2, 0
_080C9174: .4byte 0x0000191E
_080C9178: .4byte 0x0000191C
_080C917C: .4byte 0x000025E8
_080C9180: .4byte 0xFFFF0000
_080C9184: .4byte 0x0000FFFF
_080C9188: .4byte 0x0203B400
_080C918C: .4byte 0x030046B8
_080C9190: .4byte 0x000003FF
_080C9194:
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _080C9230
	ldr r2, _080C91E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C91EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C91F0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r4, r0, #3
	movs r3, #0xff
	ands r4, r3
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C91F4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C91F8
	asrs r3, r0, #0xc
	b _080C91FE
	.align 2, 0
_080C91E8: .4byte 0x030046B8
_080C91EC: .4byte 0x000003FF
_080C91F0: .4byte 0x0203B400
_080C91F4: .4byte gSineTable
_080C91F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C91FE:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C921E
	asrs r2, r0, #0xc
	b _080C9224
_080C921E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C9224:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080C9230:
	adds r0, r7, #0
	bl Jormungandr_EasePos
	ldr r0, _080C926C @ =0x00000167
	cmp r8, r0
	ble _080C925E
	ldr r1, _080C9270 @ =0x00001918
	adds r0, r7, r1
	movs r2, #0
	movs r3, #0
	strh r3, [r0]
	ldr r1, _080C9274 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C925E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C926C: .4byte 0x00000167
_080C9270: .4byte 0x00001918
_080C9274: .4byte FUN_080c6c8c
