	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0C4C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0C50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0C52
	.align 2, 0
_081A0C4C: .4byte 0x0000046C
_081A0C50:
	movs r0, #0
_081A0C52:
	cmp r0, #0
	beq _081A0C9C
	ldr r4, _081A0D04 @ =FUN_0819b230
	movs r3, #0x29
	ldr r7, _081A0D08 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0D0C @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _081A0D10 @ =0x00000EC2
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0D14 @ =0x00000EBA
	adds r0, r5, r2
	strh r1, [r0]
_081A0C9C:
	ldr r4, _081A0D0C @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0D28
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _081A0D18 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r2, _081A0D1C @ =FUN_0819bd2c
	movs r1, #0x22
	adds r4, #2
	adds r0, r6, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081A0D0C @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #4
	subs r7, #0xeb
	adds r0, r6, r7
	strb r3, [r0]
	ldr r2, _081A0D20 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A0D24 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	b _081A0D32
	.align 2, 0
_081A0D04: .4byte FUN_0819b230
_081A0D08: .4byte 0x0000046D
_081A0D0C: .4byte 0x0000046B
_081A0D10: .4byte 0x00000EC2
_081A0D14: .4byte 0x00000EBA
_081A0D18: .4byte 0xFFFFFEFF
_081A0D1C: .4byte FUN_0819bd2c
_081A0D20: .4byte 0x00000469
_081A0D24: .4byte 0x00000484
_081A0D28:
	ldr r4, _081A0D38 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0D32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0D38: .4byte 0x00000484
