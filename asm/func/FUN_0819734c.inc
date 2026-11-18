	push {r4, r5, lr}
	adds r3, r0, #0
	movs r4, #0
	ldr r1, _08197398 @ =0x00000C9C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _08197376
	ldr r1, _0819739C @ =0x0000056A
	adds r2, r3, r1
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r1, r0, #0
_08197366:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0819736E
	adds r4, #1
_0819736E:
	adds r2, r2, r5
	subs r1, #1
	cmp r1, #0
	bne _08197366
_08197376:
	cmp r4, #0
	bne _081973A8
	movs r0, #1
	adds r1, r3, #0
	adds r1, #0x4a
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _081973A0 @ =0x00000C38
	adds r1, r3, r0
	ldr r0, _081973A4 @ =FUN_08197650
	b _081973CA
	.align 2, 0
_08197398: .4byte 0x00000C9C
_0819739C: .4byte 0x0000056A
_081973A0: .4byte 0x00000C38
_081973A4: .4byte FUN_08197650
_081973A8:
	ldr r1, _081973D4 @ =0x00000C9C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _081973CC
	ldr r0, _081973D8 @ =0x00000C98
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _081973CC
	ldr r0, _081973DC @ =0x00000C54
	adds r1, r3, r0
	ldr r0, _081973E0 @ =FUN_0819734c
_081973CA:
	str r0, [r1]
_081973CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081973D4: .4byte 0x00000C9C
_081973D8: .4byte 0x00000C98
_081973DC: .4byte 0x00000C54
_081973E0: .4byte FUN_0819734c
