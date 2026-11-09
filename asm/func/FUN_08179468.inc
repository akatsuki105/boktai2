	push {lr}
	adds r1, r0, #0
	ldr r2, _08179484 @ =0x00000544
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08179498
	cmp r0, #0x3b
	bhi _0817948C
	ldr r0, _08179488 @ =0x00000482
	adds r1, r1, r0
	movs r0, #2
	b _0817949E
	.align 2, 0
_08179484: .4byte 0x00000544
_08179488: .4byte 0x00000482
_0817948C:
	ldr r2, _08179494 @ =0x00000482
	adds r1, r1, r2
	movs r0, #3
	b _0817949E
	.align 2, 0
_08179494: .4byte 0x00000482
_08179498:
	ldr r0, _081794A4 @ =0x00000482
	adds r1, r1, r0
	movs r0, #1
_0817949E:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081794A4: .4byte 0x00000482
