	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r6, [sp, #0x14]
	adds r0, r5, #0
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r5, r0, #6
	subs r0, r1, #1
	cmp r0, #0x1d
	bhi _080D8DC6
	lsls r0, r0, #2
	ldr r1, _080D8CE4 @ =_080D8CE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8CE4: .4byte _080D8CE8
_080D8CE8: @ jump table
	.4byte _080D8D6E @ case 0
	.4byte _080D8DC6 @ case 1
	.4byte _080D8D7C @ case 2
	.4byte _080D8D60 @ case 3
	.4byte _080D8D9C @ case 4
	.4byte _080D8D9C @ case 5
	.4byte _080D8D9C @ case 6
	.4byte _080D8DC6 @ case 7
	.4byte _080D8DC6 @ case 8
	.4byte _080D8D8A @ case 9
	.4byte _080D8DC6 @ case 10
	.4byte _080D8DC6 @ case 11
	.4byte _080D8DC6 @ case 12
	.4byte _080D8DC6 @ case 13
	.4byte _080D8DC6 @ case 14
	.4byte _080D8DC6 @ case 15
	.4byte _080D8DC6 @ case 16
	.4byte _080D8DC6 @ case 17
	.4byte _080D8DC6 @ case 18
	.4byte _080D8DC6 @ case 19
	.4byte _080D8DAA @ case 20
	.4byte _080D8DC6 @ case 21
	.4byte _080D8DC6 @ case 22
	.4byte _080D8DC6 @ case 23
	.4byte _080D8DC6 @ case 24
	.4byte _080D8DC6 @ case 25
	.4byte _080D8DB8 @ case 26
	.4byte _080D8D60 @ case 27
	.4byte _080D8DC6 @ case 28
	.4byte _080D8D7C @ case 29
_080D8D60:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d88ec
	b _080D8DD2
_080D8D6E:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8954
	b _080D8DD2
_080D8D7C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8990
	b _080D8DD2
_080D8D8A:
	ldr r0, [sp, #0x18]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d89cc
	b _080D8DD2
_080D8D9C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8a90
	b _080D8DD2
_080D8DAA:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8b58
	b _080D8DD2
_080D8DB8:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c20
	b _080D8DD2
_080D8DC6:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c70
_080D8DD2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
