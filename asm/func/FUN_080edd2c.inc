	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _080EDD78 @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	cmp r1, #0
	beq _080EDD8C
	movs r4, #1
_080EDD3C:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r1, r5
	ldr r0, [r0]
	ands r0, r4
	cmp r0, #0
	bne _080EDD7C
	cmp r3, #0
	bne _080EDD7C
	adds r5, #0x67
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #4
	beq _080EDD74
	cmp r0, #1
	beq _080EDD74
	cmp r0, #3
	beq _080EDD74
	cmp r0, #5
	beq _080EDD74
	cmp r0, #7
	beq _080EDD74
	cmp r0, #6
	beq _080EDD74
	cmp r0, #0xa
	beq _080EDD74
	cmp r0, #0x15
	bne _080EDD7C
_080EDD74:
	adds r0, r1, #0
	b _080EDD8E
	.align 2, 0
_080EDD78: .4byte 0x03002C60
_080EDD7C:
	ldrh r0, [r1]
	cmp r0, r3
	bne _080EDD84
	movs r3, #0
_080EDD84:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080EDD3C
_080EDD8C:
	movs r0, #0
_080EDD8E:
	pop {r4, r5}
	pop {r1}
	bx r1
