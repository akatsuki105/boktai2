	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r3, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	adds r2, r0, #0
	ands r2, r3
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r2, #0
	beq _08220C40
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, [r2, #8]
	subs r1, #0xbc
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #0xed
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl FUN_0821c400
	ldr r0, _08220C74 @ =0x0000035F
	bl PlaySound_082406e0
_08220C40:
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe7
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	bne _08220C60
	ldr r0, _08220C78 @ =0x0000035E
	bl PlaySound_082406e0
_08220C60:
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08220C7C
	cmp r0, #0x63
	beq _08220CB0
	b _08220CBA
	.align 2, 0
_08220C74: .4byte 0x0000035F
_08220C78: .4byte 0x0000035E
_08220C7C:
	movs r2, #2
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r1, _08220CAC @ =0x000002D9
	adds r0, r4, r1
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08220CBA
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08221268
	b _08220CBA
	.align 2, 0
_08220CAC: .4byte 0x000002D9
_08220CB0:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_08220CBA:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
