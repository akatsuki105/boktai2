	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08072A08 @ =0x00000213
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08072A02
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08072A02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08072A08: .4byte 0x00000213
