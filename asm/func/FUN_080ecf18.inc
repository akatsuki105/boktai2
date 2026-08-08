	push {r4, r5, r6, lr}
	bl FUN_080ef840
	ldr r0, _080ECF5C @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	movs r3, #0
	cmp r1, #0
	beq _080ECF54
	movs r5, #0xc2
	lsls r5, r5, #1
	movs r4, #0x80
	lsls r4, r4, #0xa
_080ECF32:
	adds r0, r1, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	ble _080ECF4C
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r0, r1, r6
	ldr r0, [r0]
	ands r0, r4
	cmp r0, #0
	bne _080ECF4C
	adds r3, #1
_080ECF4C:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080ECF32
_080ECF54:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080ECF5C: .4byte 0x03002C60
