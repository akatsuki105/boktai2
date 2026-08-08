	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080F46BC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F46C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F46C2
	.align 2, 0
_080F46BC: .4byte 0x0000046D
_080F46C0:
	movs r0, #0
_080F46C2:
	cmp r0, #0
	beq _080F47B8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _080F4708 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F470C @ =0x0000021E
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
	bl FUN_080ef86c
	ldr r1, _080F4710 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #6
	bhi _080F4756
	lsls r0, r0, #2
	ldr r1, _080F4714 @ =_080F4718
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F4708: .4byte 0xFFFEBE3F
_080F470C: .4byte 0x0000021E
_080F4710: .4byte 0x000001DF
_080F4714: .4byte _080F4718
_080F4718: @ jump table
	.4byte _080F473C @ case 0
	.4byte _080F4756 @ case 1
	.4byte _080F4744 @ case 2
	.4byte _080F4734 @ case 3
	.4byte _080F474E @ case 4
	.4byte _080F474E @ case 5
	.4byte _080F474E @ case 6
_080F4734:
	movs r0, #0xd4
	bl PlaySound_082406e0
	b _080F4756
_080F473C:
	movs r0, #0xfd
	bl PlaySound_082406e0
	b _080F4756
_080F4744:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080e81dc
	b _080F4756
_080F474E:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080F4756:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080F4778 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F477C
	ldr r2, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F478A
	.align 2, 0
_080F4778: .4byte 0x0000025D
_080F477C:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F478A:
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080F47C0 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x1a
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, _080F47C4 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
_080F47B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F47C0: .4byte 0x00000469
_080F47C4: .4byte 0x0000046C
