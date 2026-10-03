	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BB04C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BB050 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BB058
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_080ba710
	ldr r1, _080BB054 @ =FUN_080bb070
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BB068
	.align 2, 0
_080BB04C: .4byte 0x00001278
_080BB050: .4byte 0x000012EF
_080BB054: .4byte FUN_080bb070
_080BB058:
	cmp r0, #0
	bne _080BB068
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BB068:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
