	push {r4, r5, r6, lr}
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r0, r3
	movs r3, #0
	strb r3, [r1]
	ldr r4, _08192178 @ =0x00000469
	adds r1, r0, r4
	strb r2, [r1]
	ldr r6, _0819217C @ =0x0000046A
	adds r1, r0, r6
	strb r3, [r1]
	ldr r2, _08192180 @ =0x00000484
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #3
	adds r1, r0, r4
	movs r2, #1
	strb r2, [r1]
	ldr r5, _08192184 @ =Enemy_ClearStateBegun
	movs r4, #0x10
	adds r6, #3
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _08192188 @ =0x0000046B
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #0xe6
	adds r1, r0, r6
	strb r4, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r5, [r1]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192178: .4byte 0x00000469
_0819217C: .4byte 0x0000046A
_08192180: .4byte 0x00000484
_08192184: .4byte Enemy_ClearStateBegun
_08192188: .4byte 0x0000046B
