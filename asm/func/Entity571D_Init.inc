	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080bf754
	adds r0, r4, #0
	bl FUN_080bf3fc
	adds r0, r4, #0
	bl FUN_080bf458
	adds r0, r4, #0
	bl FUN_080bf494
	adds r0, r4, #0
	bl FUN_080bf714
	adds r0, r4, #0
	bl FUN_080bf7f8
	ldr r1, _080BFA00 @ =0x000010E1
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BFA04 @ =0x000010E2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BFA08 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	bl FUN_080bf3a0
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BFA0C @ =FUN_080bf828
	adds r0, r4, #0
	bl FUN_080beadc
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080BFA00: .4byte 0x000010E1
_080BFA04: .4byte 0x000010E2
_080BFA08: .4byte 0x0000FFFF
_080BFA0C: .4byte FUN_080bf828
