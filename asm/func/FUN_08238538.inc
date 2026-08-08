	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0823854C @ =0x03000820
	ldr r4, [r0]
	cmp r4, #0
	bne _08238550
	movs r0, #1
	rsbs r0, r0, #0
	b _0823858A
	.align 2, 0
_0823854C: .4byte 0x03000820
_08238550:
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_082381b4
	adds r5, r0, #0
	cmp r5, #0
	bne _08238562
	movs r0, #0
	b _0823858A
_08238562:
	ldrb r6, [r5, #0xf]
	adds r1, r5, #0
	adds r1, #0x10
	adds r3, r7, #0
	adds r4, #0xc0
	cmp r6, #0
	beq _08238580
	adds r2, r6, #0
_08238572:
	ldrb r0, [r1]
	strb r0, [r3]
	adds r1, #1
	adds r3, #1
	subs r2, #1
	cmp r2, #0
	bne _08238572
_08238580:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08238178
	adds r0, r6, #0
_0823858A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
