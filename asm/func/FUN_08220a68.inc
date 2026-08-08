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
	beq _08220AB4
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
	movs r1, #0xe
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_08220AB4:
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0, #8]
	subs r1, #0xbc
	ands r0, r1
	cmp r0, #0
	beq _08220AD2
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08220AD2:
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08220AE4
	cmp r0, #0x63
	beq _08220B50
	b _08220B5A
_08220AE4:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #7
	bne _08220B0C
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _08220B0C
	ldr r0, _08220B48 @ =0x0000035E
	bl PlaySound_082406e0
_08220B0C:
	ldr r1, _08220B4C @ =0x000002D9
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08220B5A
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #1
	bl FUN_08022488
	movs r1, #0x63
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
	b _08220B5A
	.align 2, 0
_08220B48: .4byte 0x0000035E
_08220B4C: .4byte 0x000002D9
_08220B50:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_08220B5A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
