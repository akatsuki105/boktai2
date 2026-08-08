	push {lr}
	adds r2, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0xf
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r3, r2, r1
	ldr r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080E8384
	ldr r0, _080E8380 @ =0xFFBFFFFF
	ands r1, r0
	str r1, [r3]
	b _080E8502
	.align 2, 0
_080E8380: .4byte 0xFFBFFFFF
_080E8384:
	ldr r3, _080E839C @ =0x000001DF
	adds r0, r2, r3
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bls _080E8392
	b _080E8502
_080E8392:
	lsls r0, r0, #2
	ldr r1, _080E83A0 @ =_080E83A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E839C: .4byte 0x000001DF
_080E83A0: .4byte _080E83A4
_080E83A4: @ jump table
	.4byte _080E8424 @ case 0
	.4byte _080E8470 @ case 1
	.4byte _080E842E @ case 2
	.4byte _080E841C @ case 3
	.4byte _080E844E @ case 4
	.4byte _080E844E @ case 5
	.4byte _080E844E @ case 6
	.4byte _080E8458 @ case 7
	.4byte _080E8464 @ case 8
	.4byte _080E8444 @ case 9
	.4byte _080E8502 @ case 10
	.4byte _080E8502 @ case 11
	.4byte _080E8502 @ case 12
	.4byte _080E8438 @ case 13
	.4byte _080E8502 @ case 14
	.4byte _080E8502 @ case 15
	.4byte _080E847C @ case 16
	.4byte _080E8484 @ case 17
	.4byte _080E848C @ case 18
	.4byte _080E84AA @ case 19
	.4byte _080E8494 @ case 20
	.4byte _080E84A0 @ case 21
	.4byte _080E84B8 @ case 22
	.4byte _080E84FC @ case 23
	.4byte _080E8470 @ case 24
	.4byte _080E8470 @ case 25
	.4byte _080E84E4 @ case 26
	.4byte _080E841C @ case 27
	.4byte _080E8502 @ case 28
	.4byte _080E842E @ case 29
_080E841C:
	movs r0, #0xd7
	bl PlaySound_082406e0
	b _080E8502
_080E8424:
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E8502
_080E842E:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080e81dc
	b _080E8502
_080E8438:
	ldr r0, _080E8440 @ =0x000001D7
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E8440: .4byte 0x000001D7
_080E8444:
	movs r0, #0xe5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E8502
_080E844E:
	movs r0, #0xeb
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080E8502
_080E8458:
	ldr r0, _080E8460 @ =0x000003AF
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E8460: .4byte 0x000003AF
_080E8464:
	ldr r0, _080E846C @ =0x000003D5
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E846C: .4byte 0x000003D5
_080E8470:
	ldr r0, _080E8478 @ =0x00000113
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E8478: .4byte 0x00000113
_080E847C:
	movs r0, #0xe4
	bl PlaySound_082406e0
	b _080E8502
_080E8484:
	movs r0, #0xe8
	bl PlaySound_082406e0
	b _080E8502
_080E848C:
	movs r0, #0xf8
	bl PlaySound_082406e0
	b _080E8502
_080E8494:
	ldr r0, _080E849C @ =0x000003A2
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E849C: .4byte 0x000003A2
_080E84A0:
	movs r0, #0xf0
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080E8502
_080E84AA:
	ldr r0, _080E84B4 @ =0x000003C5
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E84B4: .4byte 0x000003C5
_080E84B8:
	movs r1, #0x80
	lsls r1, r1, #7
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E84D8
	ldr r0, _080E84D4 @ =0x0000021E
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E84D4: .4byte 0x0000021E
_080E84D8:
	ldr r0, _080E84E0 @ =0x000003CA
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E84E0: .4byte 0x000003CA
_080E84E4:
	ldr r0, _080E84F4 @ =0x000003CD
	bl PlaySound_082406e0
	ldr r0, _080E84F8 @ =0x000002D6
	bl PlaySound_082406e0
	b _080E8502
	.align 2, 0
_080E84F4: .4byte 0x000003CD
_080E84F8: .4byte 0x000002D6
_080E84FC:
	ldr r0, _080E8508 @ =0x000001D7
	bl PlaySound_082406e0
_080E8502:
	pop {r0}
	bx r0
	.align 2, 0
_080E8508: .4byte 0x000001D7
