	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x60
	adds r4, r0, #0
	adds r4, #0x24
	movs r6, #0x1f
_08015480:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801548C
	adds r0, r5, #0
	bl FUN_0822a4e0
_0801548C:
	adds r5, #0x78
	adds r4, #0x78
	subs r6, #1
	cmp r6, #0
	bge _08015480
	movs r1, #0
	ldr r0, _080154A4 @ =0x03000060
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080154A4: .4byte 0x03000060
