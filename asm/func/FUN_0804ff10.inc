	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x29
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804FF50
	movs r4, #0
	strb r4, [r6]
	bl MosaicFader_Stop
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0804fb04
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #1
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	movs r2, #4
	ldr r1, _0804FF70 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0804fbd0
_0804FF50:
	movs r2, #0x80
	ldr r1, [r5, #0x20]
	ands r2, r1
	cmp r2, #0
	beq _0804FF74
	bl FUN_0809c58c
	movs r1, #6
	adds r0, r5, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
	b _0804FF8E
	.align 2, 0
_0804FF70: .4byte 0x030044BC
_0804FF74:
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	bne _0804FF98
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x20]
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x28
	strb r1, [r0]
	strb r1, [r6]
_0804FF8E:
	str r2, [r5, #0x24]
	adds r0, r5, #0
	bl FUN_0804fbe0
	b _0804FF9E
_0804FF98:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_0804FF9E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
