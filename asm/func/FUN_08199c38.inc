	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	ldr r1, _08199C60 @ =0x00000111
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199C64
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08199C66
	.align 2, 0
_08199C60: .4byte 0x00000111
_08199C64:
	movs r0, #0
_08199C66:
	cmp r0, #0
	beq _08199C74
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _08199C94 @ =FUN_08198720
	str r0, [r1]
_08199C74:
	adds r0, r4, #0
	bl FUN_08198588
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199C8C
	adds r0, r4, #0
	bl _call_via_r1
_08199C8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08199C94: .4byte FUN_08198720
