	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0812F3E4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F36A
	movs r0, #0
	strb r0, [r1]
_0812F36A:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldr r1, _0812F3E8 @ =0x0000024E
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	bne _0812F3DC
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r1, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	ldr r2, _0812F3EC @ =0x00000469
	adds r0, r4, r2
	strb r3, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0812F3F0 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r4, r6
	ldr r2, [r0]
	ldr r6, _0812F3E4 @ =0x0000046D
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	ldr r3, _0812F3F4 @ =0x00000553
	adds r0, r4, r3
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0812F3DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F3E4: .4byte 0x0000046D
_0812F3E8: .4byte 0x0000024E
_0812F3EC: .4byte 0x00000469
_0812F3F0: .4byte 0x00000484
_0812F3F4: .4byte 0x00000553
