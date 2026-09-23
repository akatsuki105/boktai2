	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08020368 @ =0x000085E6
	bl FUN_08230e70
	cmp r0, #0
	bne _08020370
	b _08020396
	.align 2, 0
_08020368: .4byte 0x000085E6
_0802036C:
	movs r0, #1
	b _08020398
_08020370:
	movs r2, #0
	ldrh r3, [r0, #0x1a]
	cmp r2, r3
	bge _08020396
	ldr r1, _080203A0 @ =0x0000042C
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x3c
_08020382:
	ldrb r0, [r1, #4]
	cmp r0, #2
	bne _0802038E
	ldrh r0, [r1]
	cmp r0, r4
	beq _0802036C
_0802038E:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020382
_08020396:
	movs r0, #0
_08020398:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080203A0: .4byte 0x0000042C
