	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08163E94 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163E22
	movs r0, #0
	strb r0, [r1]
_08163E22:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08163E84
	ldr r3, _08163E98 @ =FUN_08162efc
	movs r1, #0x26
	ldr r2, _08163E9C @ =0x0000046D
	adds r0, r4, r2
	movs r2, #1
	strb r2, [r0]
	ldr r6, _08163EA0 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08163EA4 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r2, [r0]
_08163E84:
	ldr r0, _08163EA8 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08163E94: .4byte 0x0000046C
_08163E98: .4byte FUN_08162efc
_08163E9C: .4byte 0x0000046D
_08163EA0: .4byte 0x0000046B
_08163EA4: .4byte 0x00000469
_08163EA8: .4byte 0x00000484
