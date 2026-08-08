	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl FUN_0823174c
	adds r4, r0, #0
	movs r0, #0x64
	movs r1, #0
	bl FUN_0823174c
	adds r5, r0, #0
	cmp r4, #0
	beq _080EDA1E
	adds r0, r4, #0
	bl FUN_080edda0
	adds r2, r0, #0
	cmp r2, #0
	beq _080EDA1E
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r3, _080EDA0C @ =0x00000474
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EDA10
	movs r0, #1
	b _080EDA12
	.align 2, 0
_080EDA0C: .4byte 0x00000474
_080EDA10:
	movs r0, #0
_080EDA12:
	cmp r0, #0
	beq _080EDA1E
	adds r0, r2, #0
	adds r1, r5, #0
	bl FUN_080ecbe8
_080EDA1E:
	pop {r4, r5}
	pop {r0}
	bx r0
