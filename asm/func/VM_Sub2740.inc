	push {r4, lr}
	ldr r0, _08009A34 @ =0x0300003C
	ldr r4, [r0]
	cmp r4, #0
	beq _08009A2E
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _08009A2E
	adds r1, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	blt _08009A38
_08009A2E:
	movs r0, #1
	rsbs r0, r0, #0
	b _08009A52
	.align 2, 0
_08009A34: .4byte 0x0300003C
_08009A38:
	adds r0, r4, #0
	bl FUN_080093ec
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	movs r0, #0x6c
	muls r1, r0, r1
	ldr r0, [r4, #0x20]
	adds r0, r0, r1
	movs r1, #0
	bl FUN_080091c4
	movs r0, #0
_08009A52:
	pop {r4}
	pop {r1}
	bx r1
