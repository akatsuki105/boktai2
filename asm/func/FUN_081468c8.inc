	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081468E0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081468E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081468E6
	.align 2, 0
_081468E0: .4byte 0x0000046C
_081468E4:
	movs r0, #0
_081468E6:
	cmp r0, #0
	beq _08146918
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0814694C @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08146950 @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
_08146918:
	ldr r5, _08146950 @ =0x0000046B
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814695C
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08146954 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	subs r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _08146958 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0814696A
	.align 2, 0
_0814694C: .4byte 0x0000046D
_08146950: .4byte 0x0000046B
_08146954: .4byte 0x00000469
_08146958: .4byte 0x00000484
_0814695C:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0814696A:
	pop {r4, r5}
	pop {r0}
	bx r0
