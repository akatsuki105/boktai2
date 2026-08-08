	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r5, r4, r1
	ldr r1, [r5]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _08220D10
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r2, #8]
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #1
	bl FUN_0821c400
_08220D10:
	movs r0, #0x80
	lsls r0, r0, #9
	adds r2, r4, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08220D30
	cmp r0, #1
	beq _08220DC4
	b _08220DD6
_08220D30:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #4
	bne _08220D60
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08220D60
	ldr r0, _08220D5C @ =0x0000035E
	bl PlaySound_082406e0
	b _08220D7E
	.align 2, 0
_08220D5C: .4byte 0x0000035E
_08220D60:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #6
	bne _08220D7E
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08220D7E
	ldr r0, _08220DBC @ =0x0000035F
	bl PlaySound_082406e0
_08220D7E:
	ldr r2, _08220DC0 @ =0x000002D9
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08220DD6
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #1
	bl FUN_08022488
	movs r1, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	subs r2, #0x14
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	b _08220DD6
	.align 2, 0
_08220DBC: .4byte 0x0000035F
_08220DC0: .4byte 0x000002D9
_08220DC4:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08220DD6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
