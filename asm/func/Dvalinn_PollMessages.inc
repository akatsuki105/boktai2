	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r4
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r7, r4, r0
	movs r6, #0
	ldr r0, _081FFBA0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r4, r2
	b _081FFD82
	.align 2, 0
_081FFBA0: .4byte 0x03002B4C
_081FFBA4:
	ldr r0, _081FFBD4 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r5, #6]
	cmp r0, #0x33
	bls _081FFBCA
	b _081FFD78
_081FFBCA:
	lsls r0, r0, #2
	ldr r1, _081FFBD8 @ =_081FFBDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FFBD4: .4byte 0x03002B4C
_081FFBD8: .4byte _081FFBDC
_081FFBDC: @ jump table
	.4byte _081FFCAC @ case 0
	.4byte _081FFCC8 @ case 1
	.4byte _081FFD78 @ case 2
	.4byte _081FFD78 @ case 3
	.4byte _081FFD78 @ case 4
	.4byte _081FFD78 @ case 5
	.4byte _081FFD78 @ case 6
	.4byte _081FFD78 @ case 7
	.4byte _081FFD78 @ case 8
	.4byte _081FFD78 @ case 9
	.4byte _081FFD10 @ case 10
	.4byte _081FFD78 @ case 11
	.4byte _081FFD78 @ case 12
	.4byte _081FFD78 @ case 13
	.4byte _081FFD78 @ case 14
	.4byte _081FFD78 @ case 15
	.4byte _081FFD78 @ case 16
	.4byte _081FFD78 @ case 17
	.4byte _081FFD78 @ case 18
	.4byte _081FFD78 @ case 19
	.4byte _081FFD78 @ case 20
	.4byte _081FFD78 @ case 21
	.4byte _081FFD78 @ case 22
	.4byte _081FFD78 @ case 23
	.4byte _081FFD78 @ case 24
	.4byte _081FFD78 @ case 25
	.4byte _081FFD78 @ case 26
	.4byte _081FFD78 @ case 27
	.4byte _081FFD78 @ case 28
	.4byte _081FFD78 @ case 29
	.4byte _081FFD78 @ case 30
	.4byte _081FFD78 @ case 31
	.4byte _081FFD78 @ case 32
	.4byte _081FFD78 @ case 33
	.4byte _081FFD78 @ case 34
	.4byte _081FFD78 @ case 35
	.4byte _081FFD78 @ case 36
	.4byte _081FFD78 @ case 37
	.4byte _081FFD78 @ case 38
	.4byte _081FFD78 @ case 39
	.4byte _081FFD78 @ case 40
	.4byte _081FFD78 @ case 41
	.4byte _081FFD78 @ case 42
	.4byte _081FFD78 @ case 43
	.4byte _081FFD78 @ case 44
	.4byte _081FFD4C @ case 45
	.4byte _081FFD54 @ case 46
	.4byte _081FFD5C @ case 47
	.4byte _081FFD34 @ case 48
	.4byte _081FFD3C @ case 49
	.4byte _081FFD44 @ case 50
	.4byte _081FFD2C @ case 51
_081FFCAC:
	movs r2, #1
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _081FFD78
_081FFCC8:
	ldrh r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r5, #0xa]
	adds r3, r4, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r5, #0xc]
	adds r2, r4, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r0, #0x97
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r0, _081FFD0C @ =0x0000025E
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r2]
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl MsgQueue_EndWait
	b _081FFD78
	.align 2, 0
_081FFD0C: .4byte 0x0000025E
_081FFD10:
	movs r1, #1
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _081FFD78
_081FFD2C:
	movs r3, #1
	movs r1, #0
	movs r2, #8
	b _081FFD62
_081FFD34:
	movs r3, #1
	movs r1, #0
	movs r2, #2
	b _081FFD62
_081FFD3C:
	movs r3, #1
	movs r1, #0
	movs r2, #6
	b _081FFD62
_081FFD44:
	movs r3, #1
	movs r1, #0
	movs r2, #7
	b _081FFD62
_081FFD4C:
	movs r3, #1
	movs r1, #0
	movs r2, #3
	b _081FFD62
_081FFD54:
	movs r3, #1
	movs r1, #0
	movs r2, #4
	b _081FFD62
_081FFD5C:
	movs r3, #1
	movs r1, #0
	movs r2, #5
_081FFD62:
	adds r0, r4, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r3, [r0]
_081FFD78:
	adds r6, #1
	ldr r0, _081FFD98 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_081FFD82:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _081FFD8E
	b _081FFBA4
_081FFD8E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FFD98: .4byte 0x03002B4C
