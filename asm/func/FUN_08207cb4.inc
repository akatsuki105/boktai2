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
	ldr r0, _08207CD8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _08207E76
	.align 2, 0
_08207CD8: .4byte 0x03002B4C
_08207CDC:
	ldr r0, _08207D10 @ =0x03002B4C
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
	cmp r0, #0x27
	bls _08207D04
	b _08207E68
_08207D04:
	lsls r0, r0, #2
	ldr r1, _08207D14 @ =_08207D18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08207D10: .4byte 0x03002B4C
_08207D14: .4byte _08207D18
_08207D18: @ jump table
	.4byte _08207DB8 @ case 0
	.4byte _08207DC2 @ case 1
	.4byte _08207E1E @ case 2
	.4byte _08207DD8 @ case 3
	.4byte _08207E34 @ case 4
	.4byte _08207E38 @ case 5
	.4byte _08207E68 @ case 6
	.4byte _08207E68 @ case 7
	.4byte _08207E68 @ case 8
	.4byte _08207E68 @ case 9
	.4byte _08207E3C @ case 10
	.4byte _08207E68 @ case 11
	.4byte _08207E68 @ case 12
	.4byte _08207E68 @ case 13
	.4byte _08207E68 @ case 14
	.4byte _08207E68 @ case 15
	.4byte _08207E68 @ case 16
	.4byte _08207E68 @ case 17
	.4byte _08207E68 @ case 18
	.4byte _08207E68 @ case 19
	.4byte _08207E68 @ case 20
	.4byte _08207E68 @ case 21
	.4byte _08207E68 @ case 22
	.4byte _08207E68 @ case 23
	.4byte _08207E68 @ case 24
	.4byte _08207E68 @ case 25
	.4byte _08207E68 @ case 26
	.4byte _08207E68 @ case 27
	.4byte _08207E68 @ case 28
	.4byte _08207E68 @ case 29
	.4byte _08207E68 @ case 30
	.4byte _08207E68 @ case 31
	.4byte _08207E68 @ case 32
	.4byte _08207E68 @ case 33
	.4byte _08207E68 @ case 34
	.4byte _08207E68 @ case 35
	.4byte _08207E68 @ case 36
	.4byte _08207E50 @ case 37
	.4byte _08207E54 @ case 38
	.4byte _08207E58 @ case 39
_08207DB8:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08207E62
_08207DC2:
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
	b _08207E66
_08207DD8:
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
	b _08207E64
_08207E1E:
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
	b _08207E64
_08207E34:
	movs r1, #4
	b _08207E5A
_08207E38:
	movs r1, #5
	b _08207E5A
_08207E3C:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _08207E68
_08207E50:
	movs r1, #0x10
	b _08207E5A
_08207E54:
	movs r1, #0x11
	b _08207E5A
_08207E58:
	movs r1, #0x12
_08207E5A:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08207E62:
	str r0, [r6, #0x14]
_08207E64:
	movs r0, #1
_08207E66:
	strb r0, [r6, #8]
_08207E68:
	movs r1, #1
	add r8, r1
	ldr r0, _08207E90 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08207E76:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08207E82
	b _08207CDC
_08207E82:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08207E90: .4byte 0x03002B4C
