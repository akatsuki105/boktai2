	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #1
	beq _080CEF8A
	cmp r2, #1
	bgt _080CEF7A
	cmp r2, #0
	beq _080CEF80
	b _080CEFAC
_080CEF7A:
	cmp r2, #2
	beq _080CEF94
	b _080CEFAC
_080CEF80:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF8A:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF94:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #5
	strb r1, [r2]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFA8 @ =FUN_080d6ea0
	b _080CEFBE
	.align 2, 0
_080CEFA8: .4byte FUN_080d6ea0
_080CEFAC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #0
	strb r1, [r2]
_080CEFB6:
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFC8 @ =FUN_080d6b24
_080CEFBE:
	str r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CEFC8: .4byte FUN_080d6b24
