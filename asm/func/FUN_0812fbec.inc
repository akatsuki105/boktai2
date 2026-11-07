	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0812FC04 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FC08
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FC0A
	.align 2, 0
_0812FC04: .4byte 0x0000046C
_0812FC08:
	movs r0, #0
_0812FC0A:
	cmp r0, #0
	beq _0812FC48
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0812FC40 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812FC44 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	b _0812FCCE
	.align 2, 0
_0812FC40: .4byte 0x0000046D
_0812FC44: .4byte 0x0000046B
_0812FC48:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0812FCCE
	ldr r2, _0812FCB8 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812FCC4
	movs r1, #7
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812FCBC @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _0812FCC0 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _0812FCCE
	.align 2, 0
_0812FCB8: .4byte 0x0000046B
_0812FCBC: .4byte 0x00000484
_0812FCC0: .4byte 0x0000046D
_0812FCC4:
	ldr r4, _0812FCD4 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FCCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812FCD4: .4byte 0x00000484
