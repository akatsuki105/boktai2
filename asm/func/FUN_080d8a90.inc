	push {lr}
	cmp r0, #1
	beq _080D8AE6
	cmp r0, #1
	bgt _080D8AA0
	cmp r0, #0
	beq _080D8AAA
	b _080D8B54
_080D8AA0:
	cmp r0, #2
	beq _080D8B00
	cmp r0, #3
	beq _080D8B18
	b _080D8B54
_080D8AAA:
	cmp r3, #1
	beq _080D8ACA
	cmp r3, #1
	bgt _080D8AB8
	cmp r3, #0
	beq _080D8AC2
	b _080D8B54
_080D8AB8:
	cmp r3, #2
	beq _080D8AD4
	cmp r3, #3
	beq _080D8ADE
	b _080D8B54
_080D8AC2:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x6a
	b _080D8B52
_080D8ACA:
	movs r0, #0x24
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x18
	b _080D8B52
_080D8AD4:
	movs r0, #0x56
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0x4a
	b _080D8B52
_080D8ADE:
	movs r0, #0x20
	str r0, [r1]
	subs r0, #0x80
	b _080D8B52
_080D8AE6:
	cmp r3, #0
	beq _080D8AEE
	cmp r3, #3
	bne _080D8AF6
_080D8AEE:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8B52
_080D8AF6:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8B52
_080D8B00:
	cmp r3, #0
	beq _080D8B08
	cmp r3, #3
	bne _080D8B0C
_080D8B08:
	movs r0, #0
	b _080D8B10
_080D8B0C:
	movs r0, #8
	rsbs r0, r0, #0
_080D8B10:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8B52
_080D8B18:
	cmp r3, #1
	beq _080D8B38
	cmp r3, #1
	bgt _080D8B26
	cmp r3, #0
	beq _080D8B30
	b _080D8B54
_080D8B26:
	cmp r3, #2
	beq _080D8B42
	cmp r3, #3
	beq _080D8B4C
	b _080D8B54
_080D8B30:
	movs r0, #0xa
	str r0, [r1]
	str r3, [r2]
	b _080D8B54
_080D8B38:
	movs r0, #0xe
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #2
	b _080D8B52
_080D8B42:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0xe
	b _080D8B52
_080D8B4C:
	movs r0, #8
	str r0, [r1]
	subs r0, #0xc
_080D8B52:
	str r0, [r2]
_080D8B54:
	pop {r0}
	bx r0
