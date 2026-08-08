	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08213DC4 @ =0x0000C486
	bl FUN_08047dc0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	bl FUN_08047a28
	movs r0, #2
	movs r1, #3
	movs r2, #0x20
	movs r3, #6
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08213DC4: .4byte 0x0000C486
