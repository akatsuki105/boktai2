	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08092e20
	adds r1, r0, #0
	cmp r1, #0
	blt _0809314A
	ldr r2, _08093150 @ =0x00003F9D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08093154 @ =FUN_08093158
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809314A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093150: .4byte 0x00003F9D
_08093154: .4byte FUN_08093158
