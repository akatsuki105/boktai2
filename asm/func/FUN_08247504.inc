	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x1c
	movs r5, #3
_0824750E:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge _0824750E
	ldr r0, _08247534 @ =0x030026B0
	ldr r0, [r0]
	cmp r0, #0
	beq _0824752A
	adds r1, r6, #0
	bl FUN_082466a8
_0824752A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08247534: .4byte 0x030026B0
