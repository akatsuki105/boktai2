	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081352EC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081352F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081352F2
	.align 2, 0
_081352EC: .4byte 0x0000046C
_081352F0:
	movs r0, #0
_081352F2:
	cmp r0, #0
	beq _081353A6
	ldr r1, _08135354 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08135358 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0813535C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08135360 @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	ldr r0, _08135364 @ =0x000001DD
	adds r1, r5, r0
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r5, r4
	ldrb r4, [r1]
	lsrs r6, r0, #3
	ldr r2, _08135368 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813536C
	asrs r1, r0, #0xc
	b _08135372
	.align 2, 0
_08135354: .4byte 0x000005A4
_08135358: .4byte 0x0000046D
_0813535C: .4byte 0x0000046B
_08135360: .4byte 0x00000553
_08135364: .4byte 0x000001DD
_08135368: .4byte gSineTable
_0813536C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08135372:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813538A
	asrs r0, r0, #0xc
	b _08135390
_0813538A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08135390:
	strh r0, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_081353A6:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081370f4
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08135438
	adds r0, r5, #0
	bl FUN_081355f0
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08135424 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08135428 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813542C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08135430 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	ldr r0, _08135434 @ =0x000003D7
	bl PlaySound_082406e0
	b _08135442
	.align 2, 0
_08135424: .4byte 0x0000046D
_08135428: .4byte 0x0000046B
_0813542C: .4byte 0x0000046A
_08135430: .4byte 0x00000484
_08135434: .4byte 0x000003D7
_08135438:
	ldr r0, _08135448 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08135442:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08135448: .4byte 0x00000484
