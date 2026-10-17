	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ced00
	adds r1, r0, #0
	ldr r2, _080D1A64 @ =0x00000A8D
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _080D1A6C
	adds r1, #1
	ldr r2, _080D1A68 @ =0x00000951
	adds r0, r4, r2
	strb r1, [r0]
	b _080D1A74
	.align 2, 0
_080D1A64: .4byte 0x00000A8D
_080D1A68: .4byte 0x00000951
_080D1A6C:
	ldr r0, _080D1A7C @ =0x00000951
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080D1A74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1A7C: .4byte 0x00000951
