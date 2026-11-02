	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E08A8 @ =0x000003E9
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E086E
	ldr r3, _081E08AC @ =0x000003BE
	adds r1, r5, r3
	movs r3, #0
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081E08B0 @ =0x000003EA
	adds r0, r5, r1
	strh r2, [r0]
	strb r3, [r4]
_081E086E:
	ldr r3, _081E08B0 @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0x3c
	bhi _081E087A
	b _081E09CA
_081E087A:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r6, r5, r4
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E0924
	ldr r1, _081E08AC @ =0x000003BE
	adds r7, r5, r1
	ldrh r4, [r7]
	subs r3, r0, r4
	cmp r3, #0
	bge _081E08BC
	adds r3, r3, r4
	ldr r2, _081E08B4 @ =0x030046A0
	ldr r1, [r2]
	ldr r4, _081E08B8 @ =0x00000912
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r6]
	subs r0, r0, r3
	b _081E08D0
	.align 2, 0
_081E08A8: .4byte 0x000003E9
_081E08AC: .4byte 0x000003BE
_081E08B0: .4byte 0x000003EA
_081E08B4: .4byte 0x030046A0
_081E08B8: .4byte 0x00000912
_081E08BC:
	ldr r2, _081E0910 @ =0x030046A0
	ldr r1, [r2]
	ldr r0, _081E0914 @ =0x00000912
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r1, [r7]
	subs r0, r0, r1
_081E08D0:
	strh r0, [r6]
	adds r3, r2, #0
	ldr r0, [r3]
	ldr r2, _081E0914 @ =0x00000912
	adds r1, r0, r2
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _081E08E6
	movs r0, #0
	strh r0, [r1]
_081E08E6:
	ldr r0, [r3]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _081E0918 @ =0x0000270F
	cmp r0, r1
	ble _081E08F6
	strh r1, [r2]
_081E08F6:
	ldr r3, _081E091C @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E0990
	ldr r0, _081E0920 @ =0x000002A5
	bl PlaySound_082406e0
	b _081E0990
	.align 2, 0
_081E0910: .4byte 0x030046A0
_081E0914: .4byte 0x00000912
_081E0918: .4byte 0x0000270F
_081E091C: .4byte 0x000003EA
_081E0920: .4byte 0x000002A5
_081E0924:
	ldr r0, _081E0958 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E095C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0990
	ldr r0, _081E0960 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r4, r0, r1
	cmp r0, #0
	bne _081E0940
	movs r4, #0
_081E0940:
	movs r0, #0xdd
	bl PlaySound_082406e0
	cmp r4, #0
	beq _081E0950
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E0968
_081E0950:
	ldr r1, _081E0964 @ =FUN_081e03d8
	movs r2, #3
	b _081E096C
	.align 2, 0
_081E0958: .4byte 0x030044E0
_081E095C: .4byte 0x0000030F
_081E0960: .4byte 0x03002C68
_081E0964: .4byte FUN_081e03d8
_081E0968:
	ldr r1, _081E0988 @ =FUN_081e06d8
	movs r2, #2
_081E096C:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r4, _081E098C @ =0x000003E9
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E09F8
	.align 2, 0
_081E0988: .4byte FUN_081e06d8
_081E098C: .4byte 0x000003E9
_081E0990:
	movs r2, #1
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E09A6
	movs r0, #1
	b _081E09A8
_081E09A6:
	movs r0, #0
_081E09A8:
	cmp r0, #0
	bne _081E09CA
	ldr r0, _081E0A00 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A04 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E09CA
	ldr r4, _081E0A08 @ =0x000003BE
	adds r1, r5, r4
	ldrh r0, [r1]
	lsls r0, r0, #3
	strh r0, [r1]
	movs r1, #1
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081E09CA:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl Entity501B_SetNumber
	ldr r0, _081E0A0C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _081E0A10 @ =0x00000912
	adds r0, r0, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	adds r0, r5, #0
	movs r1, #1
	bl Entity501B_SetNumber
	ldr r0, _081E0A14 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E09F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A00: .4byte 0x030044E0
_081E0A04: .4byte 0x0000030F
_081E0A08: .4byte 0x000003BE
_081E0A0C: .4byte 0x030046A0
_081E0A10: .4byte 0x00000912
_081E0A14: .4byte 0x000003EA
