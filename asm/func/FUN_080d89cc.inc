	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	movs r5, #0
	cmp r0, #0
	beq _080D89E8
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	ble _080D89E8
	movs r5, #1
_080D89E8:
	cmp r4, #1
	beq _080D8A78
	cmp r4, #1
	bgt _080D89F6
	cmp r4, #0
	beq _080D8A00
	b _080D8A8A
_080D89F6:
	cmp r4, #2
	beq _080D8A82
	cmp r4, #3
	beq _080D8A82
	b _080D8A8A
_080D8A00:
	cmp r5, #0
	bne _080D8A3E
	cmp r3, #1
	beq _080D8A24
	cmp r3, #1
	bgt _080D8A12
	cmp r3, #0
	beq _080D8A1C
	b _080D8A8A
_080D8A12:
	cmp r3, #2
	beq _080D8A2C
	cmp r3, #3
	beq _080D8A36
	b _080D8A8A
_080D8A1C:
	movs r0, #0x40
	str r0, [r1]
	str r3, [r2]
	b _080D8A8A
_080D8A24:
	movs r0, #0xc
	str r0, [r1]
	movs r0, #0x20
	b _080D8A88
_080D8A2C:
	movs r0, #0x1c
	rsbs r0, r0, #0
	str r0, [r1]
	str r5, [r2]
	b _080D8A8A
_080D8A36:
	movs r0, #0x1c
	str r0, [r1]
	subs r0, #0x3c
	b _080D8A88
_080D8A3E:
	cmp r3, #1
	beq _080D8A5E
	cmp r3, #1
	bgt _080D8A4C
	cmp r3, #0
	beq _080D8A56
	b _080D8A8A
_080D8A4C:
	cmp r3, #2
	beq _080D8A66
	cmp r3, #3
	beq _080D8A70
	b _080D8A8A
_080D8A56:
	movs r0, #0xc0
	str r0, [r1]
	movs r0, #0xa
	b _080D8A88
_080D8A5E:
	movs r0, #0x1e
	str r0, [r1]
	movs r0, #0xc0
	b _080D8A88
_080D8A66:
	movs r0, #0x1a
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x2a
	b _080D8A88
_080D8A70:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x70
	b _080D8A88
_080D8A78:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8A88
_080D8A82:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8A88:
	str r0, [r2]
_080D8A8A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
