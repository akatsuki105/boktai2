	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _080EDD10 @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	cmp r1, #0
	beq _080EDD24
	movs r4, #1
_080EDCF8:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r1, r5
	ldr r0, [r0]
	ands r0, r4
	cmp r0, #0
	bne _080EDD14
	cmp r3, #0
	bne _080EDD14
	adds r0, r1, #0
	b _080EDD26
	.align 2, 0
_080EDD10: .4byte 0x03002C60
_080EDD14:
	ldrh r0, [r1]
	cmp r0, r3
	bne _080EDD1C
	movs r3, #0
_080EDD1C:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080EDCF8
_080EDD24:
	movs r0, #0
_080EDD26:
	pop {r4, r5}
	pop {r1}
	bx r1
