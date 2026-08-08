	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _08065290
	bl fetch_082316e4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	b _080652A4
_08065290:
	ldr r0, _080652B8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x94
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_080652A4:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _080652C0
	ldr r0, _080652BC @ =0x0000038E
	adds r1, r4, r0
	movs r0, #1
	b _080652C6
	.align 2, 0
_080652B8: .4byte 0x030046A0
_080652BC: .4byte 0x0000038E
_080652C0:
	ldr r2, _080652F8 @ =0x0000038E
	adds r1, r4, r2
	movs r0, #0
_080652C6:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08060f00
	ldr r0, _080652FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _08065308
	ldr r3, _08065300 @ =0x08079F1D
	ldr r1, _08065304 @ =0x03002BA0
	movs r2, #0
	adds r0, r1, #4
_080652E4:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080652E4
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	str r3, [r0]
	b _08065320
	.align 2, 0
_080652F8: .4byte 0x0000038E
_080652FC: .4byte 0x030047A4
_08065300: .4byte 0x08079F1D
_08065304: .4byte 0x03002BA0
_08065308:
	movs r3, #0xac
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r1, _08065380 @ =0x085ABB14
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08065320:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r4, #0x18]
	lsls r0, r0, #3
	ldr r1, _08065384 @ =0x030044E0
	adds r0, r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0806521c
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne _080653A8
	ldr r0, _08065388 @ =0x03002B60
	ldrh r1, [r0]
	ldr r2, _0806538C @ =0x00000442
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08065390 @ =0x03002B7C
	ldrh r1, [r0]
	ldr r3, _08065394 @ =0x00000444
	adds r0, r4, r3
	strh r1, [r0]
	ldr r0, _08065398 @ =0x03002B8C
	ldrh r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	ldr r5, _0806539C @ =0x030046A0
	ldr r3, _080653A0 @ =0x03002BA0
	ldr r0, _080653A4 @ =0x0000043C
	adds r1, r4, r0
	movs r2, #2
_0806536E:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0806536E
	b _080653D0
	.align 2, 0
_08065380: .4byte 0x085ABB14
_08065384: .4byte 0x030044E0
_08065388: .4byte 0x03002B60
_0806538C: .4byte 0x00000442
_08065390: .4byte 0x03002B7C
_08065394: .4byte 0x00000444
_08065398: .4byte 0x03002B8C
_0806539C: .4byte 0x030046A0
_080653A0: .4byte 0x03002BA0
_080653A4: .4byte 0x0000043C
_080653A8:
	ldr r1, _080653F4 @ =0x00000442
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080653F8 @ =0x00000444
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080653FC @ =0x00000446
	adds r0, r4, r3
	strh r1, [r0]
	ldr r5, _08065400 @ =0x030046A0
	movs r2, #0
	movs r1, #2
	subs r3, #6
	adds r0, r4, r3
_080653C6:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080653C6
_080653D0:
	ldr r0, [r5]
	ldrh r0, [r0, #0x10]
	ldr r2, _08065404 @ =0x00000456
	adds r1, r4, r2
	strb r0, [r1]
	movs r3, #0x88
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080653EC
	ldr r0, _08065408 @ =0x03002B64
	ldrh r0, [r0]
	strb r0, [r1]
_080653EC:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080653F4: .4byte 0x00000442
_080653F8: .4byte 0x00000444
_080653FC: .4byte 0x00000446
_08065400: .4byte 0x030046A0
_08065404: .4byte 0x00000456
_08065408: .4byte 0x03002B64
