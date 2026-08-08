	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	bl FUN_080edd94
	b _080EDEA8
_080EDE6E:
	movs r0, #1
	b _080EDEB0
_080EDE72:
	ldr r1, _080EDEB8 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, r7
	bne _080EDEA2
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, r6
	bne _080EDEA2
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EDEA2
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	bne _080EDE6E
_080EDEA2:
	ldrh r0, [r4]
	bl FUN_080edce8
_080EDEA8:
	adds r4, r0, #0
	cmp r4, #0
	bne _080EDE72
	movs r0, #0
_080EDEB0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080EDEB8: .4byte 0x000001DF
