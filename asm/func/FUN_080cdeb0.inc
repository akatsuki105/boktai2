	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	movs r5, #0
_080CDEBA:
	cmp r5, #1
	beq _080CDECE
	cmp r5, #1
	bgt _080CDEC8
	cmp r5, #0
	beq _080CDF1C
	b _080CDFBC
_080CDEC8:
	cmp r5, #2
	beq _080CDF8C
	b _080CDFBC
_080CDECE:
	ldr r0, _080CDEF0 @ =0x0000043E
	adds r2, r4, r0
	ldrh r1, [r2]
	cmp r1, #0
	beq _080CDEF8
	ldr r0, [r4, #0x1c]
	ands r0, r5
	cmp r0, #0
	beq _080CDEE4
	subs r0, r1, #1
	strh r0, [r2]
_080CDEE4:
	movs r6, #2
	ldr r2, _080CDEF4 @ =0x00000956
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080CDFBC
	.align 2, 0
_080CDEF0: .4byte 0x0000043E
_080CDEF4: .4byte 0x00000956
_080CDEF8:
	ldr r7, _080CDF18 @ =0x00000956
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDFBC
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDF10
	movs r6, #2
_080CDF10:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDFBC
	.align 2, 0
_080CDF18: .4byte 0x00000956
_080CDF1C:
	ldr r0, _080CDF40 @ =0x0000043C
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	ldr r0, _080CDF44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CDF48
	subs r1, #2
	b _080CDF4C
	.align 2, 0
_080CDF40: .4byte 0x0000043C
_080CDF44: .4byte 0x03002C68
_080CDF48:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CDF4C:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CDFBC
	movs r7, #0xa3
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	ldr r2, _080CDF84 @ =0x00000984
	adds r0, r4, r2
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	ldr r7, _080CDF88 @ =0x0000097C
	adds r3, r4, r7
	bl MosaicFader_Start
	b _080CDFBC
	.align 2, 0
_080CDF84: .4byte 0x00000984
_080CDF88: .4byte 0x0000097C
_080CDF8C:
	movs r0, #0x88
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CDFBC
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CDFD0 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_080CDFBC:
	adds r5, #1
	cmp r5, #2
	bgt _080CDFC4
	b _080CDEBA
_080CDFC4:
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDFD0: .4byte 0x00000456
