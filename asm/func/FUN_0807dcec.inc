	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807DD14 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807DDB2
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807DD1C
	bl fetch_082316e4
	ldr r2, _0807DD18 @ =0x00000434
	adds r1, r4, r2
	b _0807DD24
	.align 2, 0
_0807DD14: .4byte 0x03002BE0
_0807DD18: .4byte 0x00000434
_0807DD1C:
	ldr r0, _0807DD44 @ =0x00000434
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #2
_0807DD24:
	strh r0, [r1]
	ldr r1, _0807DD44 @ =0x00000434
	adds r0, r4, r1
	bl FUN_0809c544
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0807DD48
	bl fetch_082316e4
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r4, r2
	b _0807DD52
	.align 2, 0
_0807DD44: .4byte 0x00000434
_0807DD48:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xb4
	lsls r0, r0, #2
_0807DD52:
	strh r0, [r1]
	ldr r2, _0807DDA0 @ =0x00000436
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	bl FUN_0807d180
	movs r2, #0x96
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807DDA8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807DDA4 @ =FUN_08078060
	b _0807DDB0
	.align 2, 0
_0807DDA0: .4byte 0x00000436
_0807DDA4: .4byte FUN_08078060
_0807DDA8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807DDB8 @ =FUN_08077cbc
_0807DDB0:
	str r0, [r1]
_0807DDB2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DDB8: .4byte FUN_08077cbc
