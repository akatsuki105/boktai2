	push {lr}
	adds r1, r0, #0
	ldr r2, _080D0C50 @ =0x000003BD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D0C4A
	cmp r0, #5
	bne _080D0C54
_080D0C4A:
	ldrh r1, [r1, #0x2c]
	b _080D0C56
	.align 2, 0
_080D0C50: .4byte 0x000003BD
_080D0C54:
	ldrh r1, [r1, #0x30]
_080D0C56:
	movs r0, #0xff
	ands r0, r1
	subs r0, #0x1f
	cmp r0, #0xc2
	bhi _080D0C64
	movs r0, #1
	b _080D0C66
_080D0C64:
	movs r0, #0
_080D0C66:
	pop {r1}
	bx r1
	.align 2, 0
