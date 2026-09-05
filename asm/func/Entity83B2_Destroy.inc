	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x20]
	movs r5, #0
	b _08009752
_08009746:
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0822a4e0
	adds r5, #1
	adds r4, #0x6c
_08009752:
	ldrb r0, [r6, #0x18]
	cmp r5, r0
	blt _08009746
	ldr r0, [r6, #0x20]
	cmp r0, #0
	beq _08009762
	bl Free
_08009762:
	ldr r1, _08009770 @ =0x0300003C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009770: .4byte 0x0300003C
