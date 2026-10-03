	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE90 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE94 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE9C
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_080bd624
	ldr r1, _080BDE98 @ =FUN_080bdeb4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDEAC
	.align 2, 0
_080BDE90: .4byte 0x000015D8
_080BDE94: .4byte 0x00001656
_080BDE98: .4byte FUN_080bdeb4
_080BDE9C:
	cmp r0, #0
	bne _080BDEAC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDEAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
