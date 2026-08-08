	push {lr}
	adds r3, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0xf
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E8530
	ldr r0, _080E852C @ =0xFFBFFFFF
	ands r1, r0
	str r1, [r2]
	b _080E8610
	.align 2, 0
_080E852C: .4byte 0xFFBFFFFF
_080E8530:
	ldr r1, _080E8544 @ =0x0000048C
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E8548
	movs r0, #1
	b _080E854A
	.align 2, 0
_080E8544: .4byte 0x0000048C
_080E8548:
	movs r0, #0
_080E854A:
	cmp r0, #0
	bne _080E8610
	ldr r1, _080E8564 @ =0x000001DF
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080E8610
	lsls r0, r0, #2
	ldr r1, _080E8568 @ =_080E856C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E8564: .4byte 0x000001DF
_080E8568: .4byte _080E856C
_080E856C: @ jump table
	.4byte _080E85EC @ case 0
	.4byte _080E8608 @ case 1
	.4byte _080E85F4 @ case 2
	.4byte _080E85E4 @ case 3
	.4byte _080E8610 @ case 4
	.4byte _080E8610 @ case 5
	.4byte _080E8610 @ case 6
	.4byte _080E8610 @ case 7
	.4byte _080E8610 @ case 8
	.4byte _080E85FE @ case 9
	.4byte _080E8610 @ case 10
	.4byte _080E8610 @ case 11
	.4byte _080E8610 @ case 12
	.4byte _080E85FE @ case 13
	.4byte _080E8610 @ case 14
	.4byte _080E8610 @ case 15
	.4byte _080E8610 @ case 16
	.4byte _080E8610 @ case 17
	.4byte _080E8610 @ case 18
	.4byte _080E8610 @ case 19
	.4byte _080E8610 @ case 20
	.4byte _080E8610 @ case 21
	.4byte _080E8610 @ case 22
	.4byte _080E8610 @ case 23
	.4byte _080E8610 @ case 24
	.4byte _080E8610 @ case 25
	.4byte _080E8610 @ case 26
	.4byte _080E85E4 @ case 27
	.4byte _080E8610 @ case 28
	.4byte _080E85F4 @ case 29
_080E85E4:
	movs r0, #0xd4
	bl PlaySound_082406e0
	b _080E8610
_080E85EC:
	movs r0, #0xfd
	bl PlaySound_082406e0
	b _080E8610
_080E85F4:
	adds r0, r3, #0
	movs r1, #1
	bl FUN_080e81dc
	b _080E8610
_080E85FE:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E8610
_080E8608:
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080E8610:
	pop {r0}
	bx r0
