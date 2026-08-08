	push {lr}
	ldr r0, _080EEE8C @ =0x03002C5C
	ldr r0, [r0]
	cmp r0, #0
	beq _080EEED4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r0, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080EEE90
	movs r0, #1
	b _080EEE92
	.align 2, 0
_080EEE8C: .4byte 0x03002C5C
_080EEE90:
	movs r0, #0
_080EEE92:
	cmp r0, #0
	beq _080EEED4
	ldr r0, _080EEEA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080EEEAC
	movs r0, #1
	b _080EEEAE
	.align 2, 0
_080EEEA8: .4byte 0x030047A4
_080EEEAC:
	movs r0, #0
_080EEEAE:
	cmp r0, #0
	beq _080EEEB6
	movs r0, #0xb
	b _080EEECC
_080EEEB6:
	movs r0, #0xb
	bl FUN_080ecf60
	cmp r0, #0
	bne _080EEED8
	movs r0, #0x17
	bl FUN_080ecf60
	cmp r0, #0
	bne _080EEED8
	movs r0, #0x1b
_080EEECC:
	bl FUN_080ecf60
	cmp r0, #0
	bne _080EEED8
_080EEED4:
	movs r0, #1
	b _080EEEDA
_080EEED8:
	movs r0, #0
_080EEEDA:
	pop {r1}
	bx r1
	.align 2, 0
