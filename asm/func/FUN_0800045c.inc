	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	b _080005A8
_0800046E:
	mov r1, sl
	lsls r0, r1, #1
	adds r1, r5, #0
	adds r1, #0x94
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r2, sl
	lsls r0, r2, #4
	adds r0, #0xa4
	adds r3, r5, r0
	cmp r1, #6
	bls _08000488
	b _080005A4
_08000488:
	lsls r0, r1, #2
	ldr r1, _08000494 @ =_08000498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08000494: .4byte _08000498
_08000498: @ jump table
	.4byte _080004B4 @ case 0
	.4byte _080004C2 @ case 1
	.4byte _080004F2 @ case 2
	.4byte _08000520 @ case 3
	.4byte _080005A4 @ case 4
	.4byte _080005A4 @ case 5
	.4byte _08000598 @ case 6
_080004B4:
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	b _080005A4
_080004C2:
	adds r1, r5, #0
	adds r1, #0x70
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldrh r1, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	strh r1, [r0]
	subs r0, #2
	strh r2, [r0]
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #7
	str r0, [r5, #0x40]
	movs r2, #4
	ldrsh r0, [r3, r2]
	lsls r0, r0, #7
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x20]
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x24]
	str r0, [r5, #0x4c]
	b _080005A4
_080004F2:
	adds r0, r5, #0
	adds r0, #0x78
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x7c
	strh r0, [r2]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r3, r5, #0
	adds r3, #0x7e
	strh r0, [r3]
	adds r0, r5, #0
	adds r0, #0x88
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x1b]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	b _0800058E
_08000520:
	adds r1, r5, #0
	adds r1, #0x78
	movs r0, #1
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x7c
	ldrh r0, [r4]
	adds r2, r5, #0
	adds r2, #0x80
	strh r0, [r2]
	movs r0, #0x7e
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #0x82
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	ldrh r0, [r3]
	adds r6, r5, #0
	adds r6, #0x7a
	strh r0, [r6]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x84
	strh r0, [r1]
	ldrh r0, [r3, #4]
	lsls r0, r0, #8
	adds r7, r5, #0
	adds r7, #0x86
	strh r0, [r7]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r6]
	bl Div
	adds r1, r5, #0
	adds r1, #0x88
	strh r0, [r1]
	ldrh r0, [r7]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r6]
	bl Div
	adds r1, r5, #0
	adds r1, #0x8a
	strh r0, [r1]
	ldrb r0, [r5, #0x1b]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	mov r3, sb
_0800058E:
	ldrh r2, [r3]
	lsrs r2, r2, #8
	bl FUN_0822f178
	b _080005A4
_08000598:
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [r5, #0x58]
	movs r2, #2
	ldrsh r0, [r3, r2]
	str r0, [r5, #0x5c]
_080005A4:
	movs r3, #1
	add sl, r3
_080005A8:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r0, [r0]
	cmp sl, r0
	bhs _080005B4
	b _0800046E
_080005B4:
	adds r1, r5, #0
	adds r1, #0x90
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
