	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	movs r7, #0
	ldr r0, _080CA500 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080CA67E
	.align 2, 0
_080CA500: .4byte 0x03002B4C
_080CA504:
	ldr r0, _080CA538 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	subs r0, #0x12
	cmp r0, #0x1a
	bls _080CA52C
	b _080CA672
_080CA52C:
	lsls r0, r0, #2
	ldr r1, _080CA53C @ =_080CA540
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CA538: .4byte 0x03002B4C
_080CA53C: .4byte _080CA540
_080CA540: @ jump table
	.4byte _080CA5F0 @ case 0
	.4byte _080CA672 @ case 1
	.4byte _080CA672 @ case 2
	.4byte _080CA672 @ case 3
	.4byte _080CA672 @ case 4
	.4byte _080CA672 @ case 5
	.4byte _080CA672 @ case 6
	.4byte _080CA672 @ case 7
	.4byte _080CA672 @ case 8
	.4byte _080CA672 @ case 9
	.4byte _080CA672 @ case 10
	.4byte _080CA672 @ case 11
	.4byte _080CA672 @ case 12
	.4byte _080CA672 @ case 13
	.4byte _080CA672 @ case 14
	.4byte _080CA672 @ case 15
	.4byte _080CA672 @ case 16
	.4byte _080CA672 @ case 17
	.4byte _080CA672 @ case 18
	.4byte _080CA672 @ case 19
	.4byte _080CA5AC @ case 20
	.4byte _080CA5B8 @ case 21
	.4byte _080CA5E4 @ case 22
	.4byte _080CA5FC @ case 23
	.4byte _080CA62C @ case 24
	.4byte _080CA648 @ case 25
	.4byte _080CA654 @ case 26
_080CA5AC:
	ldr r0, _080CA5B4 @ =0x000025C6
	adds r1, r6, r0
	b _080CA66E
	.align 2, 0
_080CA5B4: .4byte 0x000025C6
_080CA5B8:
	ldr r1, _080CA5DC @ =0x000008F4
	adds r0, r6, r1
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080CA5E0 @ =FUN_080c5c04
	movs r0, #0x2b
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080CA672
	.align 2, 0
_080CA5DC: .4byte 0x000008F4
_080CA5E0: .4byte FUN_080c5c04
_080CA5E4:
	ldr r2, _080CA5EC @ =FUN_080c5c58
	movs r0, #0x2c
	b _080CA658
	.align 2, 0
_080CA5EC: .4byte FUN_080c5c58
_080CA5F0:
	ldr r2, _080CA5F8 @ =FUN_080c5dd0
	movs r0, #0x2d
	b _080CA658
	.align 2, 0
_080CA5F8: .4byte FUN_080c5dd0
_080CA5FC:
	ldr r2, _080CA624 @ =0x000025FD
	adds r0, r6, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _080CA628 @ =FUN_080c6170
	movs r0, #0x33
	adds r3, r5, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080CA634
	.align 2, 0
_080CA624: .4byte 0x000025FD
_080CA628: .4byte FUN_080c6170
_080CA62C:
	ldr r2, _080CA644 @ =0x000025BC
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
_080CA634:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl MsgQueue_EndWait
	b _080CA672
	.align 2, 0
_080CA644: .4byte 0x000025BC
_080CA648:
	ldr r2, _080CA650 @ =FUN_080c60f4
	movs r0, #0x32
	b _080CA658
	.align 2, 0
_080CA650: .4byte FUN_080c60f4
_080CA654:
	ldr r2, _080CA694 @ =FUN_080c6414
	movs r0, #0x37
_080CA658:
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
_080CA66E:
	movs r0, #1
	strb r0, [r1]
_080CA672:
	adds r7, #1
	ldr r0, _080CA698 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
_080CA67E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080CA68A
	b _080CA504
_080CA68A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA694: .4byte FUN_080c6414
_080CA698: .4byte 0x03002B4C
