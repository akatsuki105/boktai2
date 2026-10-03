	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C90C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0xde
	bl PlaySound_082406e0
_0804C90C:
	ldr r1, [r4, #0x44]
	cmp r1, #0x59
	bls _0804C93A
	adds r0, r4, #0
	bl FUN_0804bb30
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804C92E
	movs r2, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	b _0804C936
_0804C92E:
	movs r1, #6
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
_0804C936:
	movs r1, #1
	strb r1, [r5]
_0804C93A:
	pop {r4, r5}
	pop {r1}
	bx r1
