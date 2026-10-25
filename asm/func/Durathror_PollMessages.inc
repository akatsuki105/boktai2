	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r5
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r6, #0
	ldr r0, _08038F24 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080390DC
	.align 2, 0
_08038F24: .4byte 0x03002B4C
_08038F28:
	ldr r0, _08038F58 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #0x16
	bls _08038F4E
	b _080390D2
_08038F4E:
	lsls r0, r0, #2
	ldr r1, _08038F5C @ =_08038F60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038F58: .4byte 0x03002B4C
_08038F5C: .4byte _08038F60
_08038F60: @ jump table
	.4byte _08038FBC @ case 0
	.4byte _08039000 @ case 1
	.4byte _08038FD4 @ case 2
	.4byte _080390D2 @ case 3
	.4byte _080390D2 @ case 4
	.4byte _0803905E @ case 5
	.4byte _080390D2 @ case 6
	.4byte _08039086 @ case 7
	.4byte _0803908E @ case 8
	.4byte _08039096 @ case 9
	.4byte _0803903C @ case 10
	.4byte _080390D2 @ case 11
	.4byte _080390D2 @ case 12
	.4byte _080390D2 @ case 13
	.4byte _080390D2 @ case 14
	.4byte _080390D2 @ case 15
	.4byte _080390D2 @ case 16
	.4byte _080390D2 @ case 17
	.4byte _080390D2 @ case 18
	.4byte _080390D2 @ case 19
	.4byte _080390D2 @ case 20
	.4byte _080390D2 @ case 21
	.4byte _080390B2 @ case 22
_08038FBC:
	movs r2, #2
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	b _080390CA
_08038FD4:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #1
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _080390D2
_08039000:
	ldrh r0, [r4, #8]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r4, #0xc]
	adds r2, r5, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r0, #0xa8
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r0, _08039038 @ =0x000002A2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r2]
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	b _080390A4
	.align 2, 0
_08039038: .4byte 0x000002A2
_0803903C:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	b _080390C6
_0803905E:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #3
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _080390CA
_08039086:
	movs r1, #2
	movs r2, #0
	movs r3, #4
	b _080390B8
_0803908E:
	movs r1, #2
	movs r2, #0
	movs r3, #5
	b _080390B8
_08039096:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl Boss_ShowEmote
_080390A4:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl MsgQueue_EndWait
	b _080390D2
_080390B2:
	movs r1, #2
	movs r2, #0
	movs r3, #6
_080390B8:
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
_080390C6:
	adds r0, #0x16
	str r2, [r0]
_080390CA:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_080390D2:
	adds r6, #1
	ldr r0, _080390F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_080390DC:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _080390E8
	b _08038F28
_080390E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080390F4: .4byte 0x03002B4C
