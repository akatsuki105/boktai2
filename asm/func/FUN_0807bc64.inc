	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #2
	bne _0807BCA6
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0807BCA6
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807BCA6
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BCAC @ =FUN_0807304c
	str r0, [r1]
_0807BCA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BCAC: .4byte FUN_0807304c
