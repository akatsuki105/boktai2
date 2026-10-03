	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D6E6
	movs r0, #0
	strb r0, [r1]
	bl ClearBGTilemapBuffer
_0804D6E6:
	ldr r0, _0804D704 @ =0x03004508
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	adds r0, r4, #0
	bl FUN_0804bb68
	adds r2, r4, #0
	adds r2, #0x31
	movs r1, #1
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804D704: .4byte 0x03004508
