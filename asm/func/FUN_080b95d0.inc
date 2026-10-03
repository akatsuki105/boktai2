	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080B95FC
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B95F4
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_080b95bc
	b _080B95FC
_080B95F4:
	ldr r1, _080B9618 @ =0x000002DF
	adds r0, r4, #0
	bl FUN_080b95bc
_080B95FC:
	cmp r5, #0
	beq _080B9624
	adds r0, r6, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B961C
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	b _080B9624
	.align 2, 0
_080B9618: .4byte 0x000002DF
_080B961C:
	ldr r1, _080B9640 @ =0x000002DF
	adds r0, r5, #0
	bl FUN_080b95bc
_080B9624:
	cmp r7, #0
	beq _080B964C
	adds r0, r6, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9644
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r7, #0
	bl FUN_080b95bc
	b _080B964C
	.align 2, 0
_080B9640: .4byte 0x000002DF
_080B9644:
	ldr r1, _080B9654 @ =0x000002DF
	adds r0, r7, #0
	bl FUN_080b95bc
_080B964C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9654: .4byte 0x000002DF
