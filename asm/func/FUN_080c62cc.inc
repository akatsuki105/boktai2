	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C6312
	movs r4, #0
	strb r4, [r7]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl MsgQueue_EndWait
	ldr r0, _080C634C @ =0x00000225
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C6312:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	cmp r0, #3
	ble _080C6340
	ldr r2, _080C6350 @ =FUN_080c6354
	movs r0, #0x36
	adds r3, r6, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	strb r0, [r7]
_080C6340:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C634C: .4byte 0x00000225
_080C6350: .4byte FUN_080c6354
