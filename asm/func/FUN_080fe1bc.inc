	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r5, _080FE1DC @ =0x0000046D
	adds r2, r4, r5
	ldrb r0, [r2]
	cmp r0, #0
	beq _080FE1E0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _080FE1E2
	.align 2, 0
_080FE1DC: .4byte 0x0000046D
_080FE1E0:
	movs r0, #0
_080FE1E2:
	cmp r0, #0
	bne _080FE26C
	movs r2, #2
	ldr r0, _080FE1FC @ =0x0000065C
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _080FE200
	movs r0, #1
	b _080FE202
	.align 2, 0
_080FE1FC: .4byte 0x0000065C
_080FE200:
	movs r0, #0
_080FE202:
	cmp r0, #0
	beq _080FE264
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _080FE258 @ =0x0000FFFF
	cmp r1, r0
	bls _080FE21C
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_080FE21C:
	adds r0, r4, #0
	bl FUN_080ffda8
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r0, [r5]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r5]
	movs r1, #0xf
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _080FE25C @ =0x0000046A
	adds r0, r4, r2
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	ldr r0, _080FE260 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080FE26C
	.align 2, 0
_080FE258: .4byte 0x0000FFFF
_080FE25C: .4byte 0x0000046A
_080FE260: .4byte 0x0000046C
_080FE264:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
_080FE26C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
