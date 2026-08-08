	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x25
	ldrb r0, [r7]
	bl IsWeaponAlreadyFound
	cmp r0, #0
	beq _082105DC
	ldr r0, _082105C8 @ =0x00000D8C
	adds r5, r6, r0
	ldr r0, [r5]
	bl FUN_080478f0
	ldr r1, _082105CC @ =0x00000D9C
	adds r4, r6, r1
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r7]
	bl FUN_08047a28
	movs r0, #0
	adds r1, r4, #0
	bl FUN_08047c84
	bl FUN_08049e5c
	ldrb r1, [r7]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _082105D0 @ =0x08DA9E68
	adds r0, r0, r4
	ldr r1, [r5]
	bl FUN_08094d48
	ldr r0, _082105D4 @ =0x00000C8A
	adds r2, r6, r0
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r1, _082105D8 @ =0x00000C08
	adds r4, r6, r1
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r1, r6, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _08210604
	.align 2, 0
_082105C8: .4byte 0x00000D8C
_082105CC: .4byte 0x00000D9C
_082105D0: .4byte 0x08DA9E68
_082105D4: .4byte 0x00000C8A
_082105D8: .4byte 0x00000C08
_082105DC:
	movs r1, #0xd9
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #0
	bl FUN_08047a28
	movs r0, #1
	bl FUN_080477e4
	bl FUN_08049e5c
	ldr r0, _0821060C @ =0x00000C8A
	adds r2, r6, r0
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
_08210604:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821060C: .4byte 0x00000C8A
