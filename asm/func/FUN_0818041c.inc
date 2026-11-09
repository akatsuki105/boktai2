	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _0818043C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180440
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180442
	.align 2, 0
_0818043C: .4byte 0x0000046D
_08180440:
	movs r0, #0
_08180442:
	cmp r0, #0
	beq _0818044E
	adds r0, r4, #0
	movs r1, #0x15
	bl Enemy_PlayAnimNoFacing
_0818044E:
	cmp r5, #0x1e
	ble _0818047E
	ldr r0, _08180484 @ =0x00000147
	bl PlaySound_082406e0
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08180488 @ =0x00000272
	ldr r2, _0818048C @ =0x00000273
	adds r0, r4, #0
	movs r3, #0x20
	bl FUN_0817d71c
	adds r0, r4, #0
	bl FUN_0817e1a0
	ldr r0, _08180490 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0818047E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08180484: .4byte 0x00000147
_08180488: .4byte 0x00000272
_0818048C: .4byte 0x00000273
_08180490: .4byte 0x0000046B
