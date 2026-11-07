	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08163B24 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163B28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163B2A
	.align 2, 0
_08163B24: .4byte 0x0000046C
_08163B28:
	movs r0, #0
_08163B2A:
	cmp r0, #0
	beq _08163B70
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r4, #5]
	adds r0, r4, #0
	bl FUN_080e6750
	ldr r2, _08163B88 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08163B54
	movs r0, #4
	ldr r1, _08163B8C @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08163B54:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_08163B70:
	ldr r1, _08163B90 @ =0x0000046B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163B98
	movs r0, #4
	ldr r1, _08163B94 @ =0x0000068E
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08163BA2
	.align 2, 0
_08163B88: .4byte 0x000001DF
_08163B8C: .4byte 0x00000222
_08163B90: .4byte 0x0000046B
_08163B94: .4byte 0x0000068E
_08163B98:
	ldr r2, _08163BA8 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08163BA2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08163BA8: .4byte 0x00000484
