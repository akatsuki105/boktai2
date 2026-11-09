	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08183294 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08183298
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818329A
	.align 2, 0
_08183294: .4byte 0x0000046C
_08183298:
	movs r0, #0
_0818329A:
	cmp r0, #0
	beq _081832CE
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0818333C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08183340 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08183344 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081832CE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0818335E
	ldr r2, _08183340 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08183354
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _08183348 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0818334C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r3, _08183350 @ =FUN_0818069c
	movs r1, #0x27
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08183340 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0818335E
	.align 2, 0
_0818333C: .4byte 0x0000046D
_08183340: .4byte 0x0000046B
_08183344: .4byte 0x00000553
_08183348: .4byte 0x00000469
_0818334C: .4byte 0x0000046A
_08183350: .4byte FUN_0818069c
_08183354:
	ldr r3, _08183364 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818335E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08183364: .4byte 0x00000484
