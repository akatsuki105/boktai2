	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806FEFE
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806FF02
_0806FEFE:
	movs r6, #0x30
	b _0806FF04
_0806FF02:
	movs r6, #0x40
_0806FF04:
	ldr r3, _0806FF18 @ =0x0000037D
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	beq _0806FF58
	cmp r0, #1
	bgt _0806FF1C
	cmp r0, #0
	beq _0806FF28
	b _08070096
	.align 2, 0
_0806FF18: .4byte 0x0000037D
_0806FF1C:
	cmp r0, #4
	beq _0806FFB0
	cmp r0, #6
	bne _0806FF26
	b _08070034
_0806FF26:
	b _08070096
_0806FF28:
	adds r0, r5, #0
	bl FUN_0806f780
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _0806FF4C
	b _08070096
_0806FF4C:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08070096
_0806FF58:
	adds r0, r5, #0
	bl FUN_0806f780
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0806FFA0
	adds r0, r5, #0
	bl FUN_0806fad8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08070096
_0806FFA0:
	ldr r0, _0806FFAC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08070096
	.align 2, 0
_0806FFAC: .4byte 0x0000037E
_0806FFB0:
	ldr r2, _0807002C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0806FFD2
	ldr r0, _08070030 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0806FFD2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #1
	bne _08070016
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _08070016
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08070016
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_0806185c
_08070016:
	adds r0, r5, #0
	bl FUN_0806fd58
	cmp r0, #0
	beq _08070096
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08070096
	.align 2, 0
_0807002C: .4byte 0x000003D1
_08070030: .4byte 0x00000A76
_08070034:
	ldr r3, _08070068 @ =0x000003D1
	adds r0, r5, r3
	movs r3, #0
	strb r3, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070056
	ldr r2, _0807006C @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08070056:
	ldr r0, _0807006C @ =0x00000A76
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08070070
	strb r3, [r2]
	strb r3, [r4]
	b _08070096
	.align 2, 0
_08070068: .4byte 0x000003D1
_0807006C: .4byte 0x00000A76
_08070070:
	ldr r1, _0807009C @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _080700A0 @ =0x00000A88
	adds r0, r5, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _08070096
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08070096:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807009C: .4byte 0x0000037E
_080700A0: .4byte 0x00000A88
