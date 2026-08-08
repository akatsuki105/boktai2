	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r0, _080F5220 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5224
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5226
	.align 2, 0
_080F5220: .4byte 0x0000046D
_080F5224:
	movs r0, #0
_080F5226:
	cmp r0, #0
	bne _080F522C
	b _080F54DC
_080F522C:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _080F5268 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F526C @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _080F5270 @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	movs r2, #1
	ldr r7, _080F5274 @ =0x0000025D
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F5278
	ldr r1, [r6, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080F5282
	.align 2, 0
_080F5268: .4byte 0xFFFEBE3F
_080F526C: .4byte 0x0000021E
_080F5270: .4byte 0x00000202
_080F5274: .4byte 0x0000025D
_080F5278:
	ldr r1, [r6, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080F5282:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r1, _080F5340 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080F5318
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #8]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _080F5344 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl FUN_082318ac
_080F5318:
	ldr r1, _080F5348 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _080F5350
	ldr r0, _080F534C @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _080F5362
	.align 2, 0
_080F5340: .4byte 0x0000046B
_080F5344: .4byte 0xFFFF0000
_080F5348: .4byte 0x000001DF
_080F534C: .4byte 0x030046A0
_080F5350:
	ldr r0, _080F53D0 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_080F5362:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _080F53D4 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _080F53D8 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _080F53DC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _080F53E0 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r0, _080F53E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F53E8
	movs r0, #1
	b _080F53EA
	.align 2, 0
_080F53D0: .4byte 0x030046A0
_080F53D4: .4byte FUN_080e48d0
_080F53D8: .4byte 0x0000046D
_080F53DC: .4byte 0x00000469
_080F53E0: .4byte 0x00000484
_080F53E4: .4byte 0x030047A4
_080F53E8:
	movs r0, #0
_080F53EA:
	cmp r0, #0
	bne _080F540A
	movs r1, #0x80
	lsls r1, r1, #4
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F540A
	ldr r0, _080F542C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl FUN_080ec5b4
_080F540A:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_080136b4
	ldr r2, _080F5430 @ =0x000001DF
	adds r0, r6, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080F54DC
	lsls r0, r0, #2
	ldr r1, _080F5434 @ =_080F5438
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F542C: .4byte 0x03002B28
_080F5430: .4byte 0x000001DF
_080F5434: .4byte _080F5438
_080F5438: @ jump table
	.4byte _080F54B8 @ case 0
	.4byte _080F54DC @ case 1
	.4byte _080F54C0 @ case 2
	.4byte _080F54B0 @ case 3
	.4byte _080F54DC @ case 4
	.4byte _080F54DC @ case 5
	.4byte _080F54DC @ case 6
	.4byte _080F54DC @ case 7
	.4byte _080F54DC @ case 8
	.4byte _080F54CA @ case 9
	.4byte _080F54CA @ case 10
	.4byte _080F54DC @ case 11
	.4byte _080F54DC @ case 12
	.4byte _080F54DC @ case 13
	.4byte _080F54DC @ case 14
	.4byte _080F54DC @ case 15
	.4byte _080F54DC @ case 16
	.4byte _080F54DC @ case 17
	.4byte _080F54DC @ case 18
	.4byte _080F54DC @ case 19
	.4byte _080F54D4 @ case 20
	.4byte _080F54DC @ case 21
	.4byte _080F54DC @ case 22
	.4byte _080F54DC @ case 23
	.4byte _080F54DC @ case 24
	.4byte _080F54DC @ case 25
	.4byte _080F54DC @ case 26
	.4byte _080F54B0 @ case 27
	.4byte _080F54DC @ case 28
	.4byte _080F54C0 @ case 29
_080F54B0:
	movs r0, #0xd4
	bl PlaySound_082406e0
	b _080F54DC
_080F54B8:
	movs r0, #0xfd
	bl PlaySound_082406e0
	b _080F54DC
_080F54C0:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080e81dc
	b _080F54DC
_080F54CA:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080F54DC
_080F54D4:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080F54DC:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
