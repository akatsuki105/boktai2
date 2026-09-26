	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	ldr r4, [sp, #0x10]
	strb r4, [r6, #0x18]
	str r1, [r6, #0x1c]
	adds r1, r3, #0
	bl FUN_080abb20
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080ab8f8
	adds r0, r6, #0
	bl FUN_080ab6f8
	cmp r4, #0
	bne _080ABCFE
	movs r0, #0xe7
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080ABD04
_080ABCFE:
	ldr r0, _080ABD10 @ =0x0000039D
	bl PlaySound_082406e0
_080ABD04:
	ldr r0, [sp, #0x14]
	strb r0, [r6, #0x1a]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080ABD10: .4byte 0x0000039D
