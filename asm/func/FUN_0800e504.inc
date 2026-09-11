	push {lr}
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0xec
	ldr r2, [r0]
	adds r1, #0xf0
	ldr r1, [r1]
	cmp r2, #0
	beq _0800E51E
	adds r0, r2, #0
	adds r0, #0xf0
	str r1, [r0]
	b _0800E520
_0800E51E:
	str r1, [r3, #0x1c]
_0800E520:
	cmp r1, #0
	beq _0800E52A
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E52A:
	movs r0, #0
	pop {r1}
	bx r1
