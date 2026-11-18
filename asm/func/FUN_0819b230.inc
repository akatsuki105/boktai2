	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819B250 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B254
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B256
	.align 2, 0
_0819B250: .4byte 0x0000046D
_0819B254:
	movs r0, #0
_0819B256:
	cmp r0, #0
	beq _0819B29E
	ldr r0, _0819B32C @ =0x00000ECE
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819B330 @ =0x00000C98
	adds r2, r4, r1
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819B334 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r2]
	ldr r0, _0819B338 @ =0x00000A4C
	adds r2, r4, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819B33C @ =0x00000A5C
	adds r0, r4, r1
	strb r3, [r0]
	ldr r2, _0819B340 @ =0x00000E41
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, #0x6a
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0819B344 @ =0x00000CBB
	adds r0, r4, r1
	strb r3, [r0]
_0819B29E:
	ldr r2, _0819B338 @ =0x00000A4C
	adds r5, r4, r2
	ldr r1, _0819B33C @ =0x00000A5C
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0819f150
	adds r0, r6, #0
	bl FUN_0819fdf0
	mov r3, sp
	ldr r0, _0819B330 @ =0x00000C98
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, _0819B348 @ =0x00000EAB
	adds r4, r4, r2
	ldrb r1, [r4]
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0819B324
	ldr r3, _0819B34C @ =FUN_0819b35c
	movs r2, #0x2a
	ldr r0, _0819B350 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819B354 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819B358 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
_0819B324:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819B32C: .4byte 0x00000ECE
_0819B330: .4byte 0x00000C98
_0819B334: .4byte 0xFFFFFF00
_0819B338: .4byte 0x00000A4C
_0819B33C: .4byte 0x00000A5C
_0819B340: .4byte 0x00000E41
_0819B344: .4byte 0x00000CBB
_0819B348: .4byte 0x00000EAB
_0819B34C: .4byte FUN_0819b35c
_0819B350: .4byte 0x0000046D
_0819B354: .4byte 0x0000046B
_0819B358: .4byte 0x00000553
