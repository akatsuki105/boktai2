	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r6, [r5, #0x1a]
	cmp r6, #0
	beq _080B20A4
	cmp r6, #1
	beq _080B2148
	b _080B21CE
_080B20A4:
	adds r0, r5, #0
	bl FUN_080b2060
	cmp r0, #0
	beq _080B20BE
	adds r0, r5, #0
	bl FUN_080b1a88
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ad1ec
	b _080B21CE
_080B20BE:
	movs r0, #0x4f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080B20CE
	bl VM_GetValue
	b _080B20D0
_080B20CE:
	movs r0, #0
_080B20D0:
	cmp r0, #0
	beq _080B2138
	ldr r2, _080B212C @ =0x03002C00
	ldr r0, [r2]
	cmp r0, #0
	beq _080B2138
	ldr r3, _080B2130 @ =0x000001F5
	adds r1, r0, r3
	movs r3, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r3, [r2]
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080B211E
	ldr r1, _080B2134 @ =0x00000BE8
	adds r2, r5, r1
	adds r1, r0, #0
_080B210A:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B2116
	movs r3, #1
_080B2116:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B210A
_080B211E:
	cmp r3, #0
	beq _080B213E
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B21CE
	.align 2, 0
_080B212C: .4byte 0x03002C00
_080B2130: .4byte 0x000001F5
_080B2134: .4byte 0x00000BE8
_080B2138:
	adds r0, r5, #0
	bl FUN_080b1a88
_080B213E:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B21CE
_080B2148:
	adds r0, r5, #0
	bl FUN_080b0e98
	adds r0, r5, #0
	bl FUN_080b1e18
	ldr r3, _080B2190 @ =0x03002C00
	ldr r0, [r3]
	ldr r2, _080B2194 @ =0x000001F5
	adds r1, r0, r2
	movs r4, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r4, [r2]
	ldr r0, [r3]
	strb r6, [r0, #0x1b]
	ldr r0, [r3]
	ldrb r0, [r0, #0x1a]
	cmp r0, #6
	bne _080B219C
	ldr r2, _080B2198 @ =0x00000BF8
	adds r1, r5, r2
	movs r0, #0x50
	b _080B21B2
	.align 2, 0
_080B2190: .4byte 0x03002C00
_080B2194: .4byte 0x000001F5
_080B2198: .4byte 0x00000BF8
_080B219C:
	cmp r0, #7
	bne _080B21AC
	ldr r3, _080B21A8 @ =0x00000BF8
	adds r1, r5, r3
	movs r0, #0x78
	b _080B21B2
	.align 2, 0
_080B21A8: .4byte 0x00000BF8
_080B21AC:
	ldr r0, _080B21D4 @ =0x00000BF8
	adds r1, r5, r0
	movs r0, #0x64
_080B21B2:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080ade88
	adds r0, r5, #0
	bl FUN_080ae394
	adds r0, r5, #0
	bl FUN_080b1b1c
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ad1ec
_080B21CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B21D4: .4byte 0x00000BF8
