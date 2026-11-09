	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0818DD2C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818DD30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818DD32
	.align 2, 0
_0818DD2C: .4byte 0x0000046C
_0818DD30:
	movs r0, #0
_0818DD32:
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r6, r5, r4
	cmp r0, #0
	beq _0818DDA0
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0818DDFC @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818DE00 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _0818DE04 @ =0x00000F2C
	adds r4, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0818DE08 @ =0x0000FFC0
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r1, _0818DE0C @ =0xFFEFFFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r0, _0818DE10 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818DE14 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0818DDA0:
	ldr r3, _0818DE18 @ =0x0000FFFF
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r7, #0
	bl FUN_0818f008
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0818DDEA
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _0818DE1C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r3, [r0]
_0818DDEA:
	ldr r0, _0818DE1C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818DDFC: .4byte 0x0000046D
_0818DE00: .4byte 0x0000046B
_0818DE04: .4byte 0x00000F2C
_0818DE08: .4byte 0x0000FFC0
_0818DE0C: .4byte 0xFFEFFFFF
_0818DE10: .4byte 0x000003E5
_0818DE14: .4byte 0xFFFF7FFF
_0818DE18: .4byte 0x0000FFFF
_0818DE1C: .4byte 0x00000484
