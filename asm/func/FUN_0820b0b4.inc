	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _0820B0D8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0820B29E
	.align 2, 0
_0820B0D8: .4byte 0x03002B4C
_0820B0DC:
	ldr r0, _0820B110 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r7, #6]
	cmp r0, #0x21
	bls _0820B104
	b _0820B290
_0820B104:
	lsls r0, r0, #2
	ldr r1, _0820B114 @ =_0820B118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820B110: .4byte 0x03002B4C
_0820B114: .4byte _0820B118
_0820B118: @ jump table
	.4byte _0820B1A0 @ case 0
	.4byte _0820B1AA @ case 1
	.4byte _0820B24E @ case 2
	.4byte _0820B208 @ case 3
	.4byte _0820B290 @ case 4
	.4byte _0820B290 @ case 5
	.4byte _0820B290 @ case 6
	.4byte _0820B290 @ case 7
	.4byte _0820B290 @ case 8
	.4byte _0820B290 @ case 9
	.4byte _0820B27E @ case 10
	.4byte _0820B290 @ case 11
	.4byte _0820B290 @ case 12
	.4byte _0820B290 @ case 13
	.4byte _0820B290 @ case 14
	.4byte _0820B290 @ case 15
	.4byte _0820B290 @ case 16
	.4byte _0820B290 @ case 17
	.4byte _0820B290 @ case 18
	.4byte _0820B290 @ case 19
	.4byte _0820B1C2 @ case 20
	.4byte _0820B290 @ case 21
	.4byte _0820B268 @ case 22
	.4byte _0820B290 @ case 23
	.4byte _0820B26C @ case 24
	.4byte _0820B290 @ case 25
	.4byte _0820B290 @ case 26
	.4byte _0820B290 @ case 27
	.4byte _0820B290 @ case 28
	.4byte _0820B290 @ case 29
	.4byte _0820B290 @ case 30
	.4byte _0820B290 @ case 31
	.4byte _0820B290 @ case 32
	.4byte _0820B264 @ case 33
_0820B1A0:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820B276
_0820B1AA:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _0820B290
_0820B1C2:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820B278
_0820B208:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #0x13
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820B278
_0820B24E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820B278
_0820B264:
	movs r1, #0x10
	b _0820B26E
_0820B268:
	movs r1, #0x11
	b _0820B26E
_0820B26C:
	movs r1, #0x12
_0820B26E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820B276:
	str r0, [r6, #0x14]
_0820B278:
	movs r0, #1
	strb r0, [r6, #8]
	b _0820B290
_0820B27E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
_0820B290:
	movs r1, #1
	add r8, r1
	ldr r0, _0820B2B8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820B29E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820B2AA
	b _0820B0DC
_0820B2AA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820B2B8: .4byte 0x03002B4C
