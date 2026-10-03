	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080BB004 @ =0x00001314
	adds r0, r6, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BAFFC
	ldr r1, _080BB008 @ =0x0000140B
	adds r0, r6, r1
	ldrb r5, [r0]
	adds r1, #3
	adds r0, r6, r1
	ldrb r4, [r0]
	adds r4, r6, r4
	ldr r0, _080BB00C @ =0x000012E4
	adds r4, r4, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_080ba220
	ldr r1, _080BB010 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r2, r1
	ldrh r1, [r2]
	subs r1, r1, r0
	strh r1, [r2]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl SetItem
	ldr r0, _080BB014 @ =0x0000151B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BB018 @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080baa64
_080BAFFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB004: .4byte 0x00001314
_080BB008: .4byte 0x0000140B
_080BB00C: .4byte 0x000012E4
_080BB010: .4byte 0x030046A0
_080BB014: .4byte 0x0000151B
_080BB018: .4byte 0x00000111
