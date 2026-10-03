	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C8A0
	movs r0, #0
	strb r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804C8A0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x80
	ands r1, r2
	cmp r1, #0
	beq _0804C8B6
	movs r0, #8
	bl FUN_08229f4c
	adds r0, r4, #0
	bl FUN_0804d868
_0804C8B6:
	pop {r4}
	pop {r1}
	bx r1
