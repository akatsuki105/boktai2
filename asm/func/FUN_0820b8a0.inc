	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0x5c
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820B8D2
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r5, #4]
	str r1, [r5, #8]
_0820B8D2:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B91E
	ldr r0, [r5, #4]
	ldr r1, [r5, #8]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldr r5, _0820B928 @ =0x0203B400
	ldr r2, _0820B92C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0820B930 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #0x1f
	ands r1, r3
	subs r1, #0x10
	strh r1, [r6, #0x10]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #0x10
	strh r0, [r6, #0x14]
_0820B91E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820B928: .4byte 0x0203B400
_0820B92C: .4byte 0x030046B8
_0820B930: .4byte 0x000003FF
