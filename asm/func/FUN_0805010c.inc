	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805016C
	movs r6, #0
	strb r6, [r1]
	adds r0, r5, #0
	bl FUN_0804fa04
	adds r1, r0, #0
	cmp r1, #0
	beq _08050158
	adds r0, r5, #0
	adds r0, #0x2c
	movs r7, #1
	strb r7, [r0]
	adds r4, r5, #0
	adds r4, #0x33
	strb r6, [r4]
	ldr r0, _08050154 @ =FUN_0804fb24
	adds r1, r5, #0
	adds r1, #0x3c
	adds r2, r5, #0
	adds r2, #0x48
	adds r3, r5, #0
	adds r3, #0x38
	bl FUN_08051c50
	cmp r0, #0
	beq _0805016C
	strb r7, [r4]
	b _0805016C
	.align 2, 0
_08050154: .4byte FUN_0804fb24
_08050158:
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	str r1, [sp]
	adds r0, r5, #0
	movs r1, #3
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
_0805016C:
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050192
	adds r6, r5, #0
	adds r6, #0x33
	ldrb r0, [r6]
	cmp r0, #0
	beq _08050192
	movs r4, #0
	str r4, [sp, #4]
	add r2, sp, #4
	adds r0, r5, #0
	movs r1, #3
	movs r3, #1
	bl FUN_0804fa44
	strb r4, [r6]
_08050192:
	movs r0, #0x30
	ldr r1, [r5, #0x20]
	ands r0, r1
	cmp r0, #0x30
	bne _080501BA
	movs r0, #0x31
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x20]
	movs r1, #4
	adds r0, r5, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x24]
	b _080501C0
_080501BA:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_080501C0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
