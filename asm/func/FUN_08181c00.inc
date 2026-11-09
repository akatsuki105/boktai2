	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181C20 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181C24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181C26
	.align 2, 0
_08181C20: .4byte 0x0000046C
_08181C24:
	movs r0, #0
_08181C26:
	cmp r0, #0
	beq _08181C72
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181D08 @ =FUN_0817fee4
	movs r2, #0x24
	ldr r0, _08181D0C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181D10 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181D14 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181D18 @ =0x0000088A
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _08181D1C @ =0x0000087E
	adds r0, r7, r2
	strh r1, [r0]
_08181C72:
	ldr r3, _08181D10 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08181D64
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08181D20 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r1, _08181D24 @ =FUN_0817fc84
	ldr r2, _08181D0C @ =0x0000046D
	adds r0, r6, r2
	movs r4, #1
	strb r4, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0xe8
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0x25
	adds r0, r6, r2
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	mov ip, r2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08181D28 @ =0x0000046A
	adds r0, r6, r1
	mov r2, ip
	strb r2, [r0]
	adds r1, #0x1a
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08181D2C @ =0x0000046C
	adds r0, r6, r2
	strb r4, [r0]
	ldr r1, _08181D30 @ =0x0000089C
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _08181D34 @ =0x0000089F
	adds r0, r7, r2
	movs r2, #0x1e
	strb r2, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r3, _08181D38 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181D3C
	movs r0, #0xf
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	b _08181D44
	.align 2, 0
_08181D08: .4byte FUN_0817fee4
_08181D0C: .4byte 0x0000046D
_08181D10: .4byte 0x0000046B
_08181D14: .4byte 0x00000553
_08181D18: .4byte 0x0000088A
_08181D1C: .4byte 0x0000087E
_08181D20: .4byte 0xFFFFFEFF
_08181D24: .4byte FUN_0817fc84
_08181D28: .4byte 0x0000046A
_08181D2C: .4byte 0x0000046C
_08181D30: .4byte 0x0000089C
_08181D34: .4byte 0x0000089F
_08181D38: .4byte 0x00000546
_08181D3C:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
_08181D44:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r2, _08181D60 @ =0x000008AA
	adds r0, r7, r2
	strh r1, [r0]
	b _08181D6E
	.align 2, 0
_08181D60: .4byte 0x000008AA
_08181D64:
	ldr r3, _08181D74 @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181D6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181D74: .4byte 0x00000484
