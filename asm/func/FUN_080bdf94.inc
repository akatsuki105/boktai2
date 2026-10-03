	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDFC4 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDFC8 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDFD0
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_080bd57c
	ldr r1, _080BDFCC @ =FUN_080bdfe8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDFE0
	.align 2, 0
_080BDFC4: .4byte 0x000015D8
_080BDFC8: .4byte 0x00001656
_080BDFCC: .4byte FUN_080bdfe8
_080BDFD0:
	cmp r0, #0
	bne _080BDFE0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDFE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
