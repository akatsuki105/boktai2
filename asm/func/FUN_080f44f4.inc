	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080F450C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F4510
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F4512
	.align 2, 0
_080F450C: .4byte 0x0000046D
_080F4510:
	movs r0, #0
_080F4512:
	cmp r0, #0
	bne _080F4518
	b _080F469C
_080F4518:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _080F455C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F4560 @ =0x0000021E
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	subs r2, #0x1e
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080efc44
	ldr r1, _080F4564 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080F45FC
	lsls r0, r0, #2
	ldr r1, _080F4568 @ =_080F456C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F455C: .4byte 0xFFFEBE3F
_080F4560: .4byte 0x0000021E
_080F4564: .4byte 0x000001DF
_080F4568: .4byte _080F456C
_080F456C: @ jump table
	.4byte _080F45EC @ case 0
	.4byte _080F45FC @ case 1
	.4byte _080F45F4 @ case 2
	.4byte _080F45E4 @ case 3
	.4byte _080F45FC @ case 4
	.4byte _080F45FC @ case 5
	.4byte _080F45FC @ case 6
	.4byte _080F45FC @ case 7
	.4byte _080F45FC @ case 8
	.4byte _080F45FC @ case 9
	.4byte _080F45FC @ case 10
	.4byte _080F45FC @ case 11
	.4byte _080F45FC @ case 12
	.4byte _080F45FC @ case 13
	.4byte _080F45FC @ case 14
	.4byte _080F45FC @ case 15
	.4byte _080F45FC @ case 16
	.4byte _080F45FC @ case 17
	.4byte _080F45FC @ case 18
	.4byte _080F45FC @ case 19
	.4byte _080F45FC @ case 20
	.4byte _080F45FC @ case 21
	.4byte _080F45FC @ case 22
	.4byte _080F45FC @ case 23
	.4byte _080F45FC @ case 24
	.4byte _080F45FC @ case 25
	.4byte _080F45FC @ case 26
	.4byte _080F45E4 @ case 27
	.4byte _080F45FC @ case 28
	.4byte _080F45F4 @ case 29
_080F45E4:
	movs r0, #0xd4
	bl PlaySound_082406e0
	b _080F45FC
_080F45EC:
	movs r0, #0xfd
	bl PlaySound_082406e0
	b _080F45FC
_080F45F4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080e81dc
_080F45FC:
	adds r3, r4, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _080F462C @ =0x0000025D
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080F4630
	ldr r2, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F463E
	.align 2, 0
_080F462C: .4byte 0x0000025D
_080F4630:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F463E:
	movs r3, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x1a
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, _080F4678 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _080F467C
	ldr r0, [r4, #0x44]
	strb r3, [r0, #7]
	b _080F4682
	.align 2, 0
_080F4678: .4byte 0x0000046C
_080F467C:
	ldr r0, [r4, #0x44]
	adds r0, #0x3a
	strb r3, [r0]
_080F4682:
	movs r2, #0x80
	lsls r2, r2, #0xc
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
_080F469C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
