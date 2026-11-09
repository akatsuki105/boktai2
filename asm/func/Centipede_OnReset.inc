	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	ldr r0, _081374BC @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r4, #0
	strh r0, [r2]
	ldr r1, _081374C0 @ =0x00000ADD
	adds r0, r6, r1
	strb r3, [r0]
	ldr r2, _081374C4 @ =0x00000ADE
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081374C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081374CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081374D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081374D4 @ =0x00000B49
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _081374D8 @ =0x00000AD9
	adds r0, r6, r1
	strb r3, [r0]
	adds r2, #0xb
	adds r0, r6, r2
	strh r4, [r0]
	ldr r3, _081374DC @ =0x00000B8C
	adds r1, r6, r3
	ldr r4, _081374E0 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081374E4
	ldr r2, [r5, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081374EE
	.align 2, 0
_081374BC: .4byte 0x0000FFFD
_081374C0: .4byte 0x00000ADD
_081374C4: .4byte 0x00000ADE
_081374C8: .4byte 0x030046B8
_081374CC: .4byte 0x000003FF
_081374D0: .4byte 0x0203B400
_081374D4: .4byte 0x00000B49
_081374D8: .4byte 0x00000AD9
_081374DC: .4byte 0x00000B8C
_081374E0: .4byte 0x0000025D
_081374E4:
	ldr r2, [r5, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081374EE:
	ldr r1, _08137574 @ =0x00000B8C
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	adds r0, r5, #0
	bl FUN_08138710
	adds r1, r5, #0
	adds r1, #8
	adds r0, r6, #0
	bl FUN_08137360
	adds r0, r5, #0
	bl FUN_081355f0
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _08137578 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r2, [r0]
	ldr r1, _0813757C @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08137574: .4byte 0x00000B8C
_08137578: .4byte 0x00000469
_0813757C: .4byte 0x0000046C
