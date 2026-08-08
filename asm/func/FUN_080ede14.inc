	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	bl FUN_080edd94
	b _080EDE4E
_080EDE20:
	movs r0, #1
	b _080EDE56
_080EDE24:
	ldr r1, _080EDE5C @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, r6
	bne _080EDE48
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EDE48
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	bne _080EDE20
_080EDE48:
	ldrh r0, [r4]
	bl FUN_080edce8
_080EDE4E:
	adds r4, r0, #0
	cmp r4, #0
	bne _080EDE24
	movs r0, #0
_080EDE56:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080EDE5C: .4byte 0x000001DF
