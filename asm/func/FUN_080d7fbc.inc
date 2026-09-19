	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D7FCE
	b _080D80D2
_080D7FCE:
	ldr r2, _080D8038 @ =0x00000381
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #2
	beq _080D80D2
	cmp r1, #4
	beq _080D80D2
	cmp r1, #3
	bne _080D8054
	subs r2, #0x29
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _080D803C @ =FUN_080d7374
	str r0, [r1]
	ldr r0, _080D8040 @ =0x00000359
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0xe8
	str r0, [r4, #0x4c]
	ldr r2, _080D8044 @ =0x000004CC
	adds r1, r4, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r4, r2
	str r0, [r1]
	ldr r0, _080D8048 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080D804C @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	ldr r2, _080D8050 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	b _080D80B2
	.align 2, 0
_080D8038: .4byte 0x00000381
_080D803C: .4byte FUN_080d7374
_080D8040: .4byte 0x00000359
_080D8044: .4byte 0x000004CC
_080D8048: .4byte 0x0000094C
_080D804C: .4byte 0x0000FFFF
_080D8050: .4byte 0x0000095E
_080D8054:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _080D80D8 @ =FUN_080d6b24
	str r0, [r1]
	ldr r1, _080D80DC @ =0x00000359
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r0, [r4, #0x50]
	str r2, [r4, #0x4c]
	ldr r2, _080D80E0 @ =0x000004CC
	adds r1, r4, r2
	adds r0, #0x20
	str r0, [r1]
	ldr r0, _080D80E4 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080D80E8 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, _080D80EC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080ced00
	adds r0, #1
	ldr r2, _080D80F0 @ =0x00000951
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, #1
	subs r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_080D80B2:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r4, #0
	bl FUN_080cec70
	ldr r2, _080D80F4 @ =0x00000282
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
_080D80D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D80D8: .4byte FUN_080d6b24
_080D80DC: .4byte 0x00000359
_080D80E0: .4byte 0x000004CC
_080D80E4: .4byte 0x0000094C
_080D80E8: .4byte 0x0000FFFF
_080D80EC: .4byte 0x0000095E
_080D80F0: .4byte 0x00000951
_080D80F4: .4byte 0x00000282
