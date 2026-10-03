	push {lr}
	adds r3, r1, #0
	cmp r2, #8
	bhi _080455F4
	lsls r0, r2, #2
	ldr r1, _08045544 @ =_08045548
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08045544: .4byte _08045548
_08045548: @ jump table
	.4byte _0804556C @ case 0
	.4byte _080455F4 @ case 1
	.4byte _08045584 @ case 2
	.4byte _08045598 @ case 3
	.4byte _080455B0 @ case 4
	.4byte _080455BC @ case 5
	.4byte _080455C8 @ case 6
	.4byte _080455D4 @ case 7
	.4byte _080455EC @ case 8
_0804556C:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045580 @ =0x00000177
	adds r1, r3, r2
	movs r0, #1
	b _080455F2
	.align 2, 0
_08045580: .4byte 0x00000177
_08045584:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045594 @ =0x00000177
	adds r1, r3, r2
	b _080455F2
	.align 2, 0
_08045594: .4byte 0x00000177
_08045598:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _080455AC @ =0x00000177
	adds r1, r3, r2
	movs r0, #2
	b _080455F2
	.align 2, 0
_080455AC: .4byte 0x00000177
_080455B0:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #1
	b _080455DE
_080455BC:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #3
	b _080455DE
_080455C8:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #5
	b _080455DE
_080455D4:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #4
_080455DE:
	strb r0, [r2]
	ldr r2, _080455E8 @ =0x00000177
	adds r0, r3, r2
	strb r1, [r0]
	b _080455F4
	.align 2, 0
_080455E8: .4byte 0x00000177
_080455EC:
	ldr r0, _080455F8 @ =0x00000177
	adds r1, r3, r0
	movs r0, #0x7f
_080455F2:
	strb r0, [r1]
_080455F4:
	pop {r0}
	bx r0
	.align 2, 0
_080455F8: .4byte 0x00000177
