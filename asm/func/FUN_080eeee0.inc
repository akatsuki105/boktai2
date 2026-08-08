	push {r4, r5, lr}
	ldr r0, _080EEEFC @ =0x03002C5C
	ldr r4, [r0]
	cmp r4, #0
	beq _080EEF60
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080EEF00
	movs r0, #1
	b _080EEF02
	.align 2, 0
_080EEEFC: .4byte 0x03002C5C
_080EEF00:
	movs r0, #0
_080EEF02:
	cmp r0, #0
	beq _080EEF60
	ldr r0, _080EEF18 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080EEF1C
	movs r0, #1
	b _080EEF1E
	.align 2, 0
_080EEF18: .4byte 0x030047A4
_080EEF1C:
	movs r0, #0
_080EEF1E:
	cmp r0, #0
	beq _080EEF2A
	movs r0, #0xb
	bl FUN_080ecf60
	b _080EEF54
_080EEF2A:
	movs r5, #0x80
	lsls r5, r5, #0xa
	movs r0, #0xb
	adds r1, r5, #0
	bl FUN_080ede14
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EEF60
	movs r0, #0x17
	adds r1, r5, #0
	bl FUN_080ede14
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EEF60
	movs r0, #0x1b
	adds r1, r5, #0
	bl FUN_080ede14
	lsls r0, r0, #0x18
_080EEF54:
	cmp r0, #0
	bne _080EEF60
	ldr r1, _080EEF68 @ =0xFFFDDFFF
	ldr r0, [r4, #0x2c]
	ands r0, r1
	str r0, [r4, #0x2c]
_080EEF60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080EEF68: .4byte 0xFFFDDFFF
