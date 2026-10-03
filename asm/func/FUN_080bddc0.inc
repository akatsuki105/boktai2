	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE00 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE04 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE14
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _080BDE08 @ =0x00001788
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BDE0C @ =0x00001789
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BDE10 @ =0x0000178A
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bd964
	b _080BDE24
	.align 2, 0
_080BDE00: .4byte 0x000015D8
_080BDE04: .4byte 0x00001656
_080BDE08: .4byte 0x00001788
_080BDE0C: .4byte 0x00001789
_080BDE10: .4byte 0x0000178A
_080BDE14:
	cmp r0, #0
	bne _080BDE24
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDE24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
