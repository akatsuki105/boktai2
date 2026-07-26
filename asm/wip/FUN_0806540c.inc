	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0806547C @ =0x0000CB05
	ldr r1, _08065480 @ =0x0000DE23
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	beq _0806550A
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822f3fc
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08065484
	bl fetch_082316e4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _0806548C
	.align 2, 0
_0806547C: .4byte 0x0000CB05
_08065480: .4byte 0x0000DE23
_08065484:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
_0806548C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080654B4
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080654AC @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080654B0 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080654C2
	.align 2, 0
_080654AC: .4byte 0x000002E6
_080654B0: .4byte 0x000002E7
_080654B4:
	ldr r1, _080654F4 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080654F8 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080654C2:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080654F4 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	str r1, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _080654F8 @ =0x000002E7
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080654FC
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _08065508
	.align 2, 0
_080654F4: .4byte 0x000002E6
_080654F8: .4byte 0x000002E7
_080654FC:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08065508:
	str r1, [r0]
_0806550A:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
