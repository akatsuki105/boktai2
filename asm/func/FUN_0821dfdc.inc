	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r6, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	adds r2, r0, #0
	ands r2, r6
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r2, #0
	beq _0821E016
	adds r0, r4, #0
	bl FUN_0821bef0
	ldr r2, _0821E070 @ =0x00000BCC
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #0x3c
	bl FUN_0821be24
	movs r0, #0xd2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0821E016:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r2, [r0]
	cmp r2, #0
	bne _0821E0A0
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5]
	movs r0, #0xed
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r6, [sp]
	str r2, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
	ldr r1, _0821E074 @ =0x00000BEC
	adds r0, r4, r1
	ldr r2, _0821E078 @ =0x00000BEE
	adds r1, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0821E07C
	adds r0, r4, #0
	bl FUN_0821bf34
	adds r0, r4, #0
	bl FUN_0821bfc8
	b _0821E084
	.align 2, 0
_0821E070: .4byte 0x00000BCC
_0821E074: .4byte 0x00000BEC
_0821E078: .4byte 0x00000BEE
_0821E07C:
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0821E084:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _0821E0A0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_0821ddc4
_0821E0A0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
