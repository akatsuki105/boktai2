	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _081807FC @ =0x0000046D
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180800
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180802
	.align 2, 0
_081807FC: .4byte 0x0000046D
_08180800:
	movs r0, #0
_08180802:
	cmp r0, #0
	bne _081808A8
	movs r2, #0x10
	ldr r4, _0818081C @ =0x00000898
	adds r1, r5, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08180820
	movs r0, #1
	b _08180822
	.align 2, 0
_0818081C: .4byte 0x00000898
_08180820:
	movs r0, #0
_08180822:
	cmp r0, #0
	beq _081808A0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r2, _08180870 @ =0x000008A4
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0818088E
	movs r2, #0x11
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _08180874 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _08180878
	asrs r0, r0, #5
	b _0818087E
	.align 2, 0
_08180870: .4byte 0x000008A4
_08180874: .4byte 0x00000484
_08180878:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0818087E:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _081808A8
_0818088E:
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	adds r0, r3, #0
	bl cheye_0817c5e0
	b _081808A8
_081808A0:
	adds r0, r3, #0
	movs r1, #1
	bl Enemy_PlayAnim
_081808A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
