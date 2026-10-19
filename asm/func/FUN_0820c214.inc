	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r7, r4, r0
	movs r6, #0
	ldr r0, _0820C230 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r4, r2
	b _0820C38E
	.align 2, 0
_0820C230: .4byte 0x03002B4C
_0820C234:
	ldr r0, _0820C264 @ =0x03002B4C
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
	cmp r0, #0x28
	bls _0820C25A
	b _0820C384
_0820C25A:
	lsls r0, r0, #2
	ldr r1, _0820C268 @ =_0820C26C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820C264: .4byte 0x03002B4C
_0820C268: .4byte _0820C26C
_0820C26C: @ jump table
	.4byte _0820C310 @ case 0
	.4byte _0820C31A @ case 1
	.4byte _0820C384 @ case 2
	.4byte _0820C384 @ case 3
	.4byte _0820C35C @ case 4
	.4byte _0820C360 @ case 5
	.4byte _0820C384 @ case 6
	.4byte _0820C384 @ case 7
	.4byte _0820C384 @ case 8
	.4byte _0820C384 @ case 9
	.4byte _0820C372 @ case 10
	.4byte _0820C384 @ case 11
	.4byte _0820C384 @ case 12
	.4byte _0820C384 @ case 13
	.4byte _0820C384 @ case 14
	.4byte _0820C384 @ case 15
	.4byte _0820C384 @ case 16
	.4byte _0820C384 @ case 17
	.4byte _0820C384 @ case 18
	.4byte _0820C384 @ case 19
	.4byte _0820C384 @ case 20
	.4byte _0820C384 @ case 21
	.4byte _0820C384 @ case 22
	.4byte _0820C384 @ case 23
	.4byte _0820C384 @ case 24
	.4byte _0820C384 @ case 25
	.4byte _0820C384 @ case 26
	.4byte _0820C384 @ case 27
	.4byte _0820C384 @ case 28
	.4byte _0820C384 @ case 29
	.4byte _0820C384 @ case 30
	.4byte _0820C384 @ case 31
	.4byte _0820C384 @ case 32
	.4byte _0820C384 @ case 33
	.4byte _0820C384 @ case 34
	.4byte _0820C384 @ case 35
	.4byte _0820C384 @ case 36
	.4byte _0820C384 @ case 37
	.4byte _0820C384 @ case 38
	.4byte _0820C384 @ case 39
	.4byte _0820C332 @ case 40
_0820C310:
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r0, [r4, #4]
	b _0820C36A
_0820C31A:
	ldrb r0, [r5, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r4, #0x1b]
	movs r0, #1
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	strb r0, [r4, #8]
	b _0820C384
_0820C332:
	movs r1, #0x10
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	ldrh r1, [r5, #8]
	adds r0, r4, #0
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r5, #0xa]
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
	b _0820C384
_0820C35C:
	movs r1, #4
	b _0820C362
_0820C360:
	movs r1, #5
_0820C362:
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r1, [r4, #4]
_0820C36A:
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0820C384
_0820C372:
	movs r0, #8
	ldrsh r1, [r5, r0]
	movs r0, #0xa
	ldrsh r2, [r5, r0]
	movs r0, #0xc
	ldrsh r3, [r5, r0]
	adds r0, r4, #0
	bl FUN_080415cc
_0820C384:
	adds r6, #1
	ldr r0, _0820C3A0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0820C38E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0820C39A
	b _0820C234
_0820C39A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820C3A0: .4byte 0x03002B4C
