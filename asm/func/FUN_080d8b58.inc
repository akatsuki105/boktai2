	push {lr}
	cmp r0, #1
	beq _080D8BAC
	cmp r0, #1
	bgt _080D8B68
	cmp r0, #0
	beq _080D8B72
	b _080D8C1A
_080D8B68:
	cmp r0, #2
	beq _080D8BC6
	cmp r0, #3
	beq _080D8BDE
	b _080D8C1A
_080D8B72:
	cmp r3, #1
	beq _080D8B92
	cmp r3, #1
	bgt _080D8B80
	cmp r3, #0
	beq _080D8B8A
	b _080D8C1A
_080D8B80:
	cmp r3, #2
	beq _080D8B9A
	cmp r3, #3
	beq _080D8BA4
	b _080D8C1A
_080D8B8A:
	movs r0, #0xdc
	str r0, [r1]
	movs r0, #0x20
	b _080D8C18
_080D8B92:
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0xd2
	b _080D8C18
_080D8B9A:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x4e
	b _080D8C18
_080D8BA4:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x60
	b _080D8C18
_080D8BAC:
	cmp r3, #0
	beq _080D8BB4
	cmp r3, #3
	bne _080D8BBC
_080D8BB4:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8C18
_080D8BBC:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8C18
_080D8BC6:
	cmp r3, #0
	beq _080D8BCE
	cmp r3, #3
	bne _080D8BD2
_080D8BCE:
	movs r0, #0
	b _080D8BD6
_080D8BD2:
	movs r0, #8
	rsbs r0, r0, #0
_080D8BD6:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8C18
_080D8BDE:
	cmp r3, #1
	beq _080D8BFE
	cmp r3, #1
	bgt _080D8BEC
	cmp r3, #0
	beq _080D8BF6
	b _080D8C1A
_080D8BEC:
	cmp r3, #2
	beq _080D8C08
	cmp r3, #3
	beq _080D8C12
	b _080D8C1A
_080D8BF6:
	movs r0, #2
	str r0, [r1]
	movs r0, #0xa
	b _080D8C18
_080D8BFE:
	movs r0, #8
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0xe
	b _080D8C18
_080D8C08:
	movs r0, #0xa
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #8
	b _080D8C18
_080D8C12:
	movs r0, #6
	str r0, [r1]
	movs r0, #5
_080D8C18:
	str r0, [r2]
_080D8C1A:
	pop {r0}
	bx r0
	.align 2, 0
