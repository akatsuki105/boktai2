	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815C4E4
	movs r0, #1
	b _0815C4E6
_0815C4E4:
	movs r0, #0
_0815C4E6:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815C594
	adds r0, r7, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	movs r6, #3
	movs r4, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r6, [r0]
	ldr r5, _0815C578 @ =0x00000469
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _0815C57C @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r1, [r0]
	adds r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r3, _0815C580 @ =FUN_080e6834
	movs r2, #0xe
	adds r5, #1
	adds r0, r7, r5
	strb r4, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	mov r8, r5
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl Cockatrice_SetHopVel
	ldr r3, _0815C584 @ =Cockatrice_StateDescend
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0815C588 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _0815C58C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0815C590 @ =0x00000552
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	b _0815C616
	.align 2, 0
_0815C578: .4byte 0x00000469
_0815C57C: .4byte 0x0000046A
_0815C580: .4byte FUN_080e6834
_0815C584: .4byte Cockatrice_StateDescend
_0815C588: .4byte 0x00000554
_0815C58C: .4byte 0x00000551
_0815C590: .4byte 0x00000552
_0815C594:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815C620 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0815C624 @ =0x0000046A
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _0815C628 @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	adds r6, #4
	adds r0, r7, r6
	strb r2, [r0]
	ldr r3, _0815C62C @ =Enemy_WaitPendingState
	movs r1, #0xe
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r6, #1
	adds r0, r7, r6
	strb r5, [r0]
	ldr r2, _0815C630 @ =0x00000553
	adds r0, r7, r2
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r4, #0
	strh r5, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0815C634 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0815C638 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
_0815C616:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C620: .4byte 0x00000469
_0815C624: .4byte 0x0000046A
_0815C628: .4byte 0x00000484
_0815C62C: .4byte Enemy_WaitPendingState
_0815C630: .4byte 0x00000553
_0815C634: .4byte 0x00000551
_0815C638: .4byte 0x00000552
