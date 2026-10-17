	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080D236C @ =0x000009C8
	adds r4, r5, r0
	ldr r1, _080D2370 @ =0x00000A68
	adds r2, r5, r1
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2374 @ =0x00000A6A
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0x96
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _080D2378 @ =0x00000A8C
	adds r1, r5, r6
	strb r0, [r1]
	ldr r2, _080D237C @ =gSineTable
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xcc
	muls r0, r1, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080D2380
	asrs r1, r0, #0xc
	b _080D2386
	.align 2, 0
_080D236C: .4byte 0x000009C8
_080D2370: .4byte 0x00000A68
_080D2374: .4byte 0x00000A6A
_080D2378: .4byte 0x00000A8C
_080D237C: .4byte gSineTable
_080D2380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2386:
	adds r3, r4, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xcc
	muls r0, r1, r0
	mov r8, r3
	mov sl, r2
	cmp r0, #0
	blt _080D23BC
	asrs r1, r0, #0xc
	b _080D23C2
_080D23BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D23C2:
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_080d1b38
	mov sb, r0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bne _080D23F6
	movs r0, #0x80
	lsls r0, r0, #0xb
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_080D23F6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, r8
	movs r2, #0xe0
	bl FUN_080d2258
	adds r7, r0, #0
	cmp r7, #0
	beq _080D24DE
	adds r0, r4, #0
	adds r0, #0xc5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	cmp r1, #2
	beq _080D2422
	cmp r1, #4
	bne _080D247E
_080D2422:
	cmp r7, #2
	bne _080D247E
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2446
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D2462
_080D2446:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbe
	strh r7, [r0]
	adds r1, #4
	movs r0, #3
	strh r0, [r1]
	b _080D25A2
_080D2462:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r1, #2
	movs r0, #6
	strh r0, [r1]
	b _080D25A2
_080D247E:
	adds r1, r4, #0
	adds r1, #0xba
	movs r6, #0
	movs r0, #0x1a
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D24A6
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D24C2
_080D24A6:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r6, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r6, [r0]
	b _080D25A2
_080D24C2:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D25A2
_080D24DE:
	mov r3, sl
	ldrb r1, [r3]
	movs r2, #0xa8
	lsls r2, r2, #1
	mov r0, r8
	bl FUN_080d2258
	cmp r0, #0
	beq _080D2548
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2510
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D252C
_080D2510:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r7, [r0]
	b _080D259E
_080D252C:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D259E
_080D2548:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1c
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2568
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2584
_080D2568:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	b _080D259C
_080D2584:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r1, #2
	movs r0, #5
_080D259C:
	strh r0, [r1]
_080D259E:
	adds r3, r4, #0
	adds r3, #0xc5
_080D25A2:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D25BC
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	mov r3, sb
	orrs r3, r0
	mov sb, r3
	adds r0, r5, #0
	bl FUN_080cec18
_080D25BC:
	adds r0, r4, #0
	adds r0, #0x48
	mov r6, sb
	str r6, [sp]
	adds r1, r4, #0
	adds r1, #0xb6
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	movs r3, #2
	bl Hitbox_SetAttack
	mov r1, sl
	ldrb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x8a
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
