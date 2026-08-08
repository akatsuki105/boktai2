	push {lr}
	adds r1, r0, #0
	ldr r2, _080674F4 @ =0x000003BD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _080674EE
	cmp r0, #5
	bne _080674F8
_080674EE:
	ldrh r1, [r1, #0x2c]
	b _080674FA
	.align 2, 0
_080674F4: .4byte 0x000003BD
_080674F8:
	ldrh r1, [r1, #0x30]
_080674FA:
	movs r0, #0xff
	ands r0, r1
	subs r0, #0x1f
	cmp r0, #0xc2
	bhi _08067508
	movs r0, #1
	b _0806750A
_08067508:
	movs r0, #0
_0806750A:
	pop {r1}
	bx r1
	.align 2, 0
