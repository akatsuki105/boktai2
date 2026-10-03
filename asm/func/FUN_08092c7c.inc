	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08092CA4 @ =0x00003F9D
	adds r0, r4, r2
	strb r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _08092CA8 @ =FUN_080931cc
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08092CA4: .4byte 0x00003F9D
_08092CA8: .4byte FUN_080931cc
