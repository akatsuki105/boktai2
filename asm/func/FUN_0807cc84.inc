	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _0807CCEC
	cmp r1, #5
	beq _0807CCEC
	cmp r1, #2
	bne _0807CCC4
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807CCC0 @ =FUN_08075b4c
	b _0807CD16
	.align 2, 0
_0807CCC0: .4byte FUN_08075b4c
_0807CCC4:
	cmp r1, #3
	bne _0807CCE8
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CCE4 @ =FUN_08077100
	b _0807CD16
	.align 2, 0
_0807CCE4: .4byte FUN_08077100
_0807CCE8:
	cmp r1, #4
	beq _0807CCF0
_0807CCEC:
	movs r0, #0
	b _0807CD1A
_0807CCF0:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CD20 @ =FUN_08077a5c
_0807CD16:
	str r0, [r1]
	movs r0, #1
_0807CD1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807CD20: .4byte FUN_08077a5c
