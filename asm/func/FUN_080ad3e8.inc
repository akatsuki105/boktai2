	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AD400 @ =0x00000C0B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AD4D8
	lsls r0, r0, #2
	ldr r1, _080AD404 @ =_080AD408
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AD400: .4byte 0x00000C0B
_080AD404: .4byte _080AD408
_080AD408: @ jump table
	.4byte _080AD420 @ case 0
	.4byte _080AD434 @ case 1
	.4byte _080AD458 @ case 2
	.4byte _080AD46C @ case 3
	.4byte _080AD498 @ case 4
	.4byte _080AD4C8 @ case 5
_080AD420:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080AD430 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD430: .4byte 0x0000022D
_080AD434:
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD450 @ =0x0000022D
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080AD454 @ =0x00001426
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	b _080AD484
	.align 2, 0
_080AD450: .4byte 0x0000022D
_080AD454: .4byte 0x00001426
_080AD458:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080AD468 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD468: .4byte 0x0000022D
_080AD46C:
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _080AD48C @ =0x0000022D
	adds r0, r4, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080AD490 @ =0x00001426
	adds r0, r4, r3
	strh r1, [r0]
_080AD484:
	ldr r1, _080AD494 @ =0x00001424
	adds r0, r4, r1
	strh r2, [r0]
	b _080AD4D8
	.align 2, 0
_080AD48C: .4byte 0x0000022D
_080AD490: .4byte 0x00001426
_080AD494: .4byte 0x00001424
_080AD498:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080AD4BC @ =0x0000022D
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD4C0 @ =0x00001426
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _080AD4C4 @ =0x00001424
	adds r0, r4, r2
	strh r3, [r0]
	b _080AD4D8
	.align 2, 0
_080AD4BC: .4byte 0x0000022D
_080AD4C0: .4byte 0x00001426
_080AD4C4: .4byte 0x00001424
_080AD4C8:
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #2
	strb r1, [r0]
	ldr r2, _080AD4E0 @ =0x0000022D
	adds r0, r4, r2
_080AD4D6:
	strb r1, [r0]
_080AD4D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD4E0: .4byte 0x0000022D
