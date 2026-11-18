	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r3, _081A059C @ =0x0000046C
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A05A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A05A2
	.align 2, 0
_081A059C: .4byte 0x0000046C
_081A05A0:
	movs r0, #0
_081A05A2:
	cmp r0, #0
	beq _081A05EE
	ldr r4, _081A0650 @ =FUN_0819c4a4
	movs r3, #0x21
	ldr r0, _081A0654 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0658 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081A065C @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A05EE:
	adds r0, r5, #0
	bl FUN_0819ef24
	ldr r1, _081A0658 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A066C
	ldr r2, _081A0660 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r3, _081A0654 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A0658 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A0664 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081A0668 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	b _081A0676
	.align 2, 0
_081A0650: .4byte FUN_0819c4a4
_081A0654: .4byte 0x0000046D
_081A0658: .4byte 0x0000046B
_081A065C: .4byte 0x00000E48
_081A0660: .4byte FUN_0819bd2c
_081A0664: .4byte 0x00000469
_081A0668: .4byte 0x0000046C
_081A066C:
	ldr r6, _081A067C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0676:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A067C: .4byte 0x00000484
