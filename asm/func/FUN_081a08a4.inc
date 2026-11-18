	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A08C4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A08C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A08CA
	.align 2, 0
_081A08C4: .4byte 0x0000046C
_081A08C8:
	movs r0, #0
_081A08CA:
	cmp r0, #0
	beq _081A0922
	ldr r4, _081A0980 @ =FUN_0819c7e4
	movs r3, #0x34
	ldr r7, _081A0984 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0988 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r7, _081A098C @ =0x00000E48
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081A0990 @ =0x00000EBE
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0994 @ =0x00000EB6
	adds r0, r5, r2
	strh r1, [r0]
_081A0922:
	ldr r3, _081A0988 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A09A8
	ldr r2, _081A0998 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r4, _081A0984 @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081A0988 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #5
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A099C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A09A0 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A09A4 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A09B2
	.align 2, 0
_081A0980: .4byte FUN_0819c7e4
_081A0984: .4byte 0x0000046D
_081A0988: .4byte 0x0000046B
_081A098C: .4byte 0x00000E48
_081A0990: .4byte 0x00000EBE
_081A0994: .4byte 0x00000EB6
_081A0998: .4byte FUN_0819bd2c
_081A099C: .4byte 0x00000469
_081A09A0: .4byte 0x0000046A
_081A09A4: .4byte 0x00000484
_081A09A8:
	ldr r0, _081A09B8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A09B2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A09B8: .4byte 0x00000484
