	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x20
	adds r1, r1, r6
	mov sb, r1
	movs r2, #0
	mov r8, r2
	ldr r0, _0820BAD4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0820BC70
	.align 2, 0
_0820BAD4: .4byte 0x03002B4C
_0820BAD8:
	ldr r0, _0820BB0C @ =0x03002B4C
	ldr r0, [r0]
	mov r7, r8
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sl
	adds r1, r7, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r7, #6]
	cmp r0, #0x20
	bls _0820BB00
	b _0820BC62
_0820BB00:
	lsls r0, r0, #2
	ldr r1, _0820BB10 @ =_0820BB14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820BB0C: .4byte 0x03002B4C
_0820BB10: .4byte _0820BB14
_0820BB14: @ jump table
	.4byte _0820BB98 @ case 0
	.4byte _0820BBA2 @ case 1
	.4byte _0820BBFE @ case 2
	.4byte _0820BBB8 @ case 3
	.4byte _0820BC28 @ case 4
	.4byte _0820BC2C @ case 5
	.4byte _0820BC62 @ case 6
	.4byte _0820BC62 @ case 7
	.4byte _0820BC62 @ case 8
	.4byte _0820BC62 @ case 9
	.4byte _0820BC14 @ case 10
	.4byte _0820BC62 @ case 11
	.4byte _0820BC62 @ case 12
	.4byte _0820BC62 @ case 13
	.4byte _0820BC62 @ case 14
	.4byte _0820BC62 @ case 15
	.4byte _0820BC62 @ case 16
	.4byte _0820BC62 @ case 17
	.4byte _0820BC62 @ case 18
	.4byte _0820BC62 @ case 19
	.4byte _0820BC62 @ case 20
	.4byte _0820BC62 @ case 21
	.4byte _0820BC62 @ case 22
	.4byte _0820BC62 @ case 23
	.4byte _0820BC62 @ case 24
	.4byte _0820BC62 @ case 25
	.4byte _0820BC62 @ case 26
	.4byte _0820BC62 @ case 27
	.4byte _0820BC62 @ case 28
	.4byte _0820BC62 @ case 29
	.4byte _0820BC30 @ case 30
	.4byte _0820BC34 @ case 31
	.4byte _0820BC52 @ case 32
_0820BB98:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820BC5C
_0820BBA2:
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
	b _0820BC60
_0820BBB8:
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
	movs r1, #0
	ldrsh r0, [r3, r1]
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
	b _0820BC5E
_0820BBFE:
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
	b _0820BC5E
_0820BC14:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _0820BC62
_0820BC28:
	movs r1, #4
	b _0820BC54
_0820BC2C:
	movs r1, #5
	b _0820BC54
_0820BC30:
	movs r1, #0x10
	b _0820BC54
_0820BC34:
	ldrh r0, [r7, #8]
	movs r1, #0
	movs r2, #0
	mov r3, sb
	strh r0, [r3, #0xc]
	ldrh r0, [r7, #0xa]
	strh r0, [r3, #0xe]
	ldrh r0, [r7, #0xc]
	strh r0, [r3, #0x10]
	movs r0, #0x11
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r2, [r6, #0x14]
	b _0820BC5E
_0820BC52:
	movs r1, #0x12
_0820BC54:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820BC5C:
	str r0, [r6, #0x14]
_0820BC5E:
	movs r0, #1
_0820BC60:
	strb r0, [r6, #8]
_0820BC62:
	movs r7, #1
	add r8, r7
	ldr r0, _0820BC8C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sl
	adds r0, #6
_0820BC70:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820BC7C
	b _0820BAD8
_0820BC7C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820BC8C: .4byte 0x03002B4C
