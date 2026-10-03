	push {r4, lr}
	adds r2, r0, #0
	ldr r1, _080BBAD8 @ =0x0000140C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBB34
	ldr r3, _080BBADC @ =0x0000140E
	adds r0, r2, r3
	ldrb r3, [r0]
	ldr r0, _080BBAE0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080BBB14
	ldr r4, _080BBAE4 @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BBAEC
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r3
	beq _080BBBA4
	ldr r3, _080BBAE8 @ =0x0000140B
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBBA4
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBAD8: .4byte 0x0000140C
_080BBADC: .4byte 0x0000140E
_080BBAE0: .4byte 0x030046A0
_080BBAE4: .4byte 0x00001409
_080BBAE8: .4byte 0x0000140B
_080BBAEC:
	ldr r0, _080BBB0C @ =0x0000140B
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, r3
	bne _080BBB2C
	ldr r1, _080BBB10 @ =0x0000140F
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080BBBA4
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBB0C: .4byte 0x0000140B
_080BBB10: .4byte 0x0000140F
_080BBB14:
	ldr r3, _080BBB30 @ =0x0000140B
	adds r0, r2, r3
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080BBBA4
_080BBB2C:
	movs r0, #1
	b _080BBBA6
	.align 2, 0
_080BBB30: .4byte 0x0000140B
_080BBB34:
	ldr r4, _080BBB64 @ =0x0000140B
	adds r3, r2, r4
	ldr r0, _080BBB68 @ =0x0000140E
	adds r1, r2, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BBB74
	ldr r1, _080BBB6C @ =0x000012F2
	adds r0, r2, r1
	ldrh r1, [r0]
	strb r1, [r3]
	movs r0, #3
	ands r0, r1
	subs r4, #2
	adds r1, r2, r4
	strb r0, [r1]
	ldrb r0, [r3]
	lsrs r0, r0, #2
	ldr r3, _080BBB70 @ =0x0000140A
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB64: .4byte 0x0000140B
_080BBB68: .4byte 0x0000140E
_080BBB6C: .4byte 0x000012F2
_080BBB70: .4byte 0x0000140A
_080BBB74:
	ldr r4, _080BBB9C @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBBA4
	ldrb r2, [r3]
	ldr r0, _080BBBA0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080BBBA4
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB9C: .4byte 0x00001409
_080BBBA0: .4byte 0x030046A0
_080BBBA4:
	movs r0, #0
_080BBBA6:
	pop {r4}
	pop {r1}
	bx r1
