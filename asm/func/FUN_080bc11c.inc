	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC14C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC150 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC158
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_080bb854
	ldr r1, _080BC154 @ =FUN_080bc170
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC168
	.align 2, 0
_080BC14C: .4byte 0x00001278
_080BC150: .4byte 0x000012EF
_080BC154: .4byte FUN_080bc170
_080BC158:
	cmp r0, #0
	bne _080BC168
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC168:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
