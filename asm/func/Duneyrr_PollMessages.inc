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
	ldr r0, _08024374 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080244E6
	.align 2, 0
_08024374: .4byte 0x03002B4C
_08024378:
	ldr r0, _080243A8 @ =0x03002B4C
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
	cmp r0, #0xa
	bls _0802439E
	b _080244DA
_0802439E:
	lsls r0, r0, #2
	ldr r1, _080243AC @ =_080243B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080243A8: .4byte 0x03002B4C
_080243AC: .4byte _080243B0
_080243B0: @ jump table
	.4byte _080243DC @ case 0
	.4byte _08024420 @ case 1
	.4byte _080243F4 @ case 2
	.4byte _080244DA @ case 3
	.4byte _080244DA @ case 4
	.4byte _080244DA @ case 5
	.4byte _080244DA @ case 6
	.4byte _08024474 @ case 7
	.4byte _0802448A @ case 8
	.4byte _080244A0 @ case 9
	.4byte _080244BC @ case 10
_080243DC:
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
	b _080244D2
_080243F4:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r5, r3
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
	b _080244DA
_08024420:
	ldrh r0, [r4, #8]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r4, #0xc]
	adds r2, r5, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r4, #0x9e
	lsls r4, r4, #2
	adds r0, r6, r4
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r3, _08024470 @ =0x0000027A
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r2]
	adds r4, #4
	adds r0, r6, r4
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	b _080244B4
	.align 2, 0
_08024470: .4byte 0x0000027A
_08024474:
	movs r1, #2
	movs r2, #0
	movs r3, #3
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080244CE
_0802448A:
	movs r1, #2
	movs r2, #0
	movs r3, #4
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080244CE
_080244A0:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl Boss_ShowEmote
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r5, r3
_080244B4:
	movs r1, #1
	bl MsgQueue_EndWait
	b _080244DA
_080244BC:
	movs r1, #2
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
_080244CE:
	adds r0, #0x16
	str r2, [r0]
_080244D2:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_080244DA:
	adds r7, #1
	ldr r0, _080244FC @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
_080244E6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080244F2
	b _08024378
_080244F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080244FC: .4byte 0x03002B4C
