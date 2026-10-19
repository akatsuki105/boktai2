	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r7, r2, #0
	adds r6, r4, #0
	adds r6, #0x5c
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820B968
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
_0820B968:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B9D4
	cmp r7, #0x3f
	ble _0820B990
	movs r0, #1
	strb r0, [r4, #7]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	b _0820B9A6
_0820B990:
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x24
	adds r2, r4, #0
	adds r2, #0x2c
	movs r3, #6
	str r3, [sp]
	adds r3, r7, #0
	bl LerpVec3
_0820B9A6:
	ldr r5, _0820B9DC @ =0x0203B400
	ldr r2, _0820B9E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0820B9E4 @ =0x000003FF
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
_0820B9D4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820B9DC: .4byte 0x0203B400
_0820B9E0: .4byte 0x030046B8
_0820B9E4: .4byte 0x000003FF
