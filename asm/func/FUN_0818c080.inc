	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818C0A0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C0A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C0A6
	.align 2, 0
_0818C0A0: .4byte 0x0000046C
_0818C0A4:
	movs r0, #0
_0818C0A6:
	cmp r0, #0
	beq _0818C0D8
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r7, _0818C108 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818C10C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0818C0D8:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r7, _0818C110 @ =0x00000484
	adds r0, r5, r7
	ldr r0, [r0]
	cmp r0, #0x63
	bgt _0818C114
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0818C12A
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0x18
	movs r3, #0
	bl FUN_0818faf0
	b _0818C12A
	.align 2, 0
_0818C108: .4byte 0x0000046D
_0818C10C: .4byte 0x0000046B
_0818C110: .4byte 0x00000484
_0818C114:
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	bne _0818C12A
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0x2c
	movs r3, #1
	bl FUN_0818faf0
_0818C12A:
	ldr r0, _0818C198 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0xc8
	ble _0818C1B0
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _0818C19C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0818C1A0 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r7, _0818C1A4 @ =0x00000553
	adds r0, r5, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r2, [r0]
	movs r4, #0x11
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r4, [r0]
	ldr r4, _0818C198 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	ldr r2, _0818C1A8 @ =0x00000D4F
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _0818C1AC @ =0x00000D4E
	adds r1, r6, r4
	movs r0, #3
	strb r0, [r1]
	b _0818C1B4
	.align 2, 0
_0818C198: .4byte 0x00000484
_0818C19C: .4byte 0x0000046D
_0818C1A0: .4byte 0x0000046B
_0818C1A4: .4byte 0x00000553
_0818C1A8: .4byte 0x00000D4F
_0818C1AC: .4byte 0x00000D4E
_0818C1B0:
	adds r0, #1
	str r0, [r1]
_0818C1B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
