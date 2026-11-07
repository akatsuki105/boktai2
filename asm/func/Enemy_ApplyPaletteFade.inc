	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _080EEF8C @ =0x03002C5C
	ldr r0, [r0]
	cmp r0, #0
	beq _080EEFE6
	ldr r3, _080EEF90 @ =0x000001DF
	adds r1, r2, r3
	ldrb r1, [r1]
	cmp r1, #0x17
	beq _080EEF9A
	cmp r1, #0x17
	bgt _080EEF94
	cmp r1, #0xb
	beq _080EEFA2
	b _080EEFE6
	.align 2, 0
_080EEF8C: .4byte 0x03002C5C
_080EEF90: .4byte 0x000001DF
_080EEF94:
	cmp r1, #0x1b
	beq _080EEFA8
	b _080EEFE6
_080EEF9A:
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r3, r0, r4
	b _080EEFAE
_080EEFA2:
	adds r3, r0, #0
	adds r3, #0x64
	b _080EEFAE
_080EEFA8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r3, r0, r1
_080EEFAE:
	ldrh r0, [r3, #0x20]
	cmp r0, #0
	beq _080EEFE6
	ldr r4, _080EEFD0 @ =0x0000025D
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EEFD4
	ldr r1, [r2, #0x44]
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, #0x32]
	ldr r0, [r2, #0x44]
	str r3, [r0, #0x38]
	b _080EEFE6
	.align 2, 0
_080EEFD0: .4byte 0x0000025D
_080EEFD4:
	ldr r0, [r2, #0x44]
	adds r0, #0x20
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r1, r2, r4
	ldrh r1, [r1]
	strh r1, [r0, #0x3a]
	ldr r0, [r2, #0x44]
	str r3, [r0, #0x68]
_080EEFE6:
	pop {r4}
	pop {r0}
	bx r0
