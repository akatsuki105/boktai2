	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E0A54 @ =0x000003E9
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E0A32
	ldr r1, _081E0A58 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E0A32:
	ldr r3, _081E0A5C @ =0x000003BA
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0A64
	ldr r1, _081E0A60 @ =FUN_081e084c
	movs r2, #1
	adds r3, #0x16
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _081E0A54 @ =0x000003E9
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r4, r3
	strb r2, [r0]
	b _081E0A8A
	.align 2, 0
_081E0A54: .4byte 0x000003E9
_081E0A58: .4byte 0x000003EA
_081E0A5C: .4byte 0x000003BA
_081E0A60: .4byte FUN_081e084c
_081E0A64:
	ldr r0, _081E0A90 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A94 @ =0x0000030B
	ands r0, r1
	cmp r0, #0
	beq _081E0A74
	movs r0, #1
	strh r0, [r2]
_081E0A74:
	adds r0, r4, #0
	bl FUN_081e02ac
	adds r0, r4, #0
	bl FUN_081e02ec
	ldr r0, _081E0A98 @ =0x000003EA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0A8A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A90: .4byte 0x030044E0
_081E0A94: .4byte 0x0000030B
_081E0A98: .4byte 0x000003EA
