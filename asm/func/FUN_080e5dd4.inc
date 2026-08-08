	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _080E5E0C @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080E5E04
	cmp r0, #0x17
	beq _080E5E04
	cmp r0, #9
	beq _080E5E04
	cmp r0, #0x19
	beq _080E5E04
	cmp r0, #0x1a
	beq _080E5E04
	cmp r0, #0xe
	beq _080E5E04
	cmp r0, #0x1b
	beq _080E5E04
	cmp r0, #0x18
	beq _080E5E04
	cmp r0, #0x1f
	bne _080E5E14
_080E5E04:
	ldr r2, _080E5E10 @ =0x0000044C
	adds r1, r5, r2
	movs r0, #1
	b _080E5E28
	.align 2, 0
_080E5E0C: .4byte 0x000001DF
_080E5E10: .4byte 0x0000044C
_080E5E14:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #8
	movs r2, #0
	bl FUN_0801385c
	ldr r2, _080E5E74 @ =0x0000044C
	adds r1, r5, r2
_080E5E28:
	strb r0, [r1]
	ldr r1, _080E5E78 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080E5E54
	cmp r0, #0x1c
	beq _080E5E54
	cmp r0, #5
	beq _080E5E54
	cmp r0, #6
	beq _080E5E54
	cmp r0, #7
	beq _080E5E54
	cmp r0, #1
	beq _080E5E54
	cmp r0, #3
	beq _080E5E54
	cmp r0, #0x1e
	beq _080E5E54
	cmp r0, #0xa
	bne _080E5E80
_080E5E54:
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #8
	movs r4, #0
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
	ldr r1, _080E5E7C @ =0x0000044D
	adds r0, r5, r1
	strb r4, [r0]
	b _080E5E88
	.align 2, 0
_080E5E74: .4byte 0x0000044C
_080E5E78: .4byte 0x000001DF
_080E5E7C: .4byte 0x0000044D
_080E5E80:
	ldr r2, _080E5E90 @ =0x0000044D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080E5E88:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5E90: .4byte 0x0000044D
