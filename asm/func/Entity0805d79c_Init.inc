	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r1, _0805D798 @ =0x0000848F
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0xdb
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D77E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805d79c_InitElem
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D77E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D798: .4byte 0x0000848F
