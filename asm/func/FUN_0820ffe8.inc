	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _08210034 @ =0x00000D8A
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08210008
	ldr r1, _08210038 @ =0x00000D88
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0821003C @ =0x00000D89
	adds r0, r4, r3
	strb r1, [r0]
	strb r1, [r2]
_08210008:
	ldr r0, _0821003C @ =0x00000D89
	adds r1, r4, r0
	ldrb r0, [r1]
	movs r2, #0
	cmp r0, #0
	bne _08210016
	movs r2, #1
_08210016:
	adds r0, #1
	movs r7, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r5, [r0]
	cmp r5, #1
	bne _08210028
	b _082101E4
_08210028:
	cmp r5, #1
	bgt _08210040
	cmp r5, #0
	beq _0821004E
	b _08210528
	.align 2, 0
_08210034: .4byte 0x00000D8A
_08210038: .4byte 0x00000D88
_0821003C: .4byte 0x00000D89
_08210040:
	cmp r5, #2
	bne _08210046
	b _082102F0
_08210046:
	cmp r5, #3
	bne _0821004C
	b _082103F8
_0821004C:
	b _08210528
_0821004E:
	ldr r1, _08210064 @ =0x00000D88
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0821005A
	b _08210528
_0821005A:
	lsls r0, r0, #2
	ldr r1, _08210068 @ =_0821006C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08210064: .4byte 0x00000D88
_08210068: .4byte _0821006C
_0821006C: @ jump table
	.4byte _08210080 @ case 0
	.4byte _082100C8 @ case 1
	.4byte _08210110 @ case 2
	.4byte _08210158 @ case 3
	.4byte _082101A0 @ case 4
_08210080:
	cmp r2, #0
	beq _082100A6
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0820ff98
	ldr r2, _082100C0 @ =0x00000CD4
	adds r0, r4, r2
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082100A6:
	ldr r3, _082100C0 @ =0x00000CD4
	adds r0, r4, r3
	bl FUN_08055d20
	cmp r0, #0
	bne _082100B4
	b _08210528
_082100B4:
	ldr r0, _082100C4 @ =0x00000D89
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _082104D0
	.align 2, 0
_082100C0: .4byte 0x00000CD4
_082100C4: .4byte 0x00000D89
_082100C8:
	cmp r2, #0
	beq _082100E6
	ldr r3, _08210104 @ =0x00000CD4
	adds r0, r4, r3
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x70
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082100E6:
	ldr r1, _08210104 @ =0x00000CD4
	adds r0, r4, r1
	bl FUN_08055d20
	cmp r0, #0
	bne _082100F4
	b _08210528
_082100F4:
	ldr r2, _08210108 @ =0x00000D89
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	ldr r3, _0821010C @ =0x00000D88
	adds r1, r4, r3
	b _082104D4
	.align 2, 0
_08210104: .4byte 0x00000CD4
_08210108: .4byte 0x00000D89
_0821010C: .4byte 0x00000D88
_08210110:
	cmp r2, #0
	beq _0821012E
	ldr r1, _0821014C @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x75
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821012E:
	ldr r2, _0821014C @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	bne _0821013C
	b _08210528
_0821013C:
	ldr r3, _08210150 @ =0x00000D89
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08210154 @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_0821014C: .4byte 0x00000CD4
_08210150: .4byte 0x00000D89
_08210154: .4byte 0x00000D88
_08210158:
	cmp r2, #0
	beq _08210176
	ldr r1, _08210194 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x70
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_08210176:
	ldr r2, _08210194 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	bne _08210184
	b _08210528
_08210184:
	ldr r3, _08210198 @ =0x00000D89
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0821019C @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_08210194: .4byte 0x00000CD4
_08210198: .4byte 0x00000D89
_0821019C: .4byte 0x00000D88
_082101A0:
	cmp r2, #0
	beq _082101BE
	ldr r1, _082101E0 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x7a
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082101BE:
	ldr r2, _082101E0 @ =0x00000CD4
	adds r5, r4, r2
	adds r0, r5, #0
	bl FUN_08055d20
	cmp r0, #0
	bne _082101CE
	b _08210528
_082101CE:
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x7a
	b _082103EA
	.align 2, 0
_082101E0: .4byte 0x00000CD4
_082101E4:
	ldr r3, _082101F8 @ =0x00000D88
	adds r0, r4, r3
	ldrb r1, [r0]
	cmp r1, #1
	beq _08210250
	cmp r1, #1
	bgt _082101FC
	cmp r1, #0
	beq _08210206
	b _08210528
	.align 2, 0
_082101F8: .4byte 0x00000D88
_082101FC:
	cmp r1, #2
	beq _08210294
	cmp r1, #3
	beq _082102B0
	b _08210528
_08210206:
	cmp r2, #0
	beq _0821022A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0820ff98
	ldr r1, _08210244 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821022A:
	ldr r2, _08210244 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	bne _08210238
	b _08210528
_08210238:
	ldr r3, _08210248 @ =0x00000D89
	adds r0, r4, r3
	strb r7, [r0]
	ldr r0, _0821024C @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_08210244: .4byte 0x00000CD4
_08210248: .4byte 0x00000D89
_0821024C: .4byte 0x00000D88
_08210250:
	cmp r2, #0
	beq _0821026C
	ldr r1, _08210288 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x84
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821026C:
	ldr r2, _08210288 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	bne _0821027A
	b _08210528
_0821027A:
	ldr r3, _0821028C @ =0x00000D89
	adds r0, r4, r3
	strb r7, [r0]
	ldr r0, _08210290 @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_08210288: .4byte 0x00000CD4
_0821028C: .4byte 0x00000D89
_08210290: .4byte 0x00000D88
_08210294:
	cmp r2, #0
	bne _0821029A
	b _082104BE
_0821029A:
	ldr r2, _082102AC @ =0x00000CD4
	adds r0, r4, r2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x93
	b _082104B6
	.align 2, 0
_082102AC: .4byte 0x00000CD4
_082102B0:
	cmp r2, #0
	beq _082102CC
	ldr r3, _082102EC @ =0x00000CD4
	adds r0, r4, r3
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x84
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082102CC:
	ldr r0, _082102EC @ =0x00000CD4
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_08055d20
	cmp r0, #0
	bne _082102DC
	b _08210528
_082102DC:
	movs r0, #2
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x84
	b _082103EA
	.align 2, 0
_082102EC: .4byte 0x00000CD4
_082102F0:
	ldr r1, _08210304 @ =0x00000D88
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08210334
	cmp r0, #1
	bgt _08210308
	cmp r0, #0
	beq _08210312
	b _08210528
	.align 2, 0
_08210304: .4byte 0x00000D88
_08210308:
	cmp r0, #2
	beq _08210374
	cmp r0, #3
	beq _082103B4
	b _08210528
_08210312:
	cmp r2, #0
	bne _08210318
	b _082104BE
_08210318:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0820ff98
	ldr r2, _08210330 @ =0x00000CD4
	adds r0, r4, r2
	str r5, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	b _082104B6
	.align 2, 0
_08210330: .4byte 0x00000CD4
_08210334:
	cmp r2, #0
	beq _0821034E
	ldr r3, _08210368 @ =0x00000CD4
	adds r0, r4, r3
	str r5, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x98
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821034E:
	ldr r1, _08210368 @ =0x00000CD4
	adds r0, r4, r1
	bl FUN_08055d20
	cmp r0, #0
	bne _0821035C
	b _08210528
_0821035C:
	ldr r2, _0821036C @ =0x00000D89
	adds r0, r4, r2
	strb r7, [r0]
	ldr r3, _08210370 @ =0x00000D88
	adds r1, r4, r3
	b _082104D4
	.align 2, 0
_08210368: .4byte 0x00000CD4
_0821036C: .4byte 0x00000D89
_08210370: .4byte 0x00000D88
_08210374:
	cmp r2, #0
	beq _0821038E
	ldr r1, _082103A8 @ =0x00000CD4
	adds r0, r4, r1
	str r5, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xa2
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821038E:
	ldr r2, _082103A8 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	bne _0821039C
	b _08210528
_0821039C:
	ldr r3, _082103AC @ =0x00000D89
	adds r0, r4, r3
	strb r7, [r0]
	ldr r0, _082103B0 @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_082103A8: .4byte 0x00000CD4
_082103AC: .4byte 0x00000D89
_082103B0: .4byte 0x00000D88
_082103B4:
	cmp r2, #0
	beq _082103CE
	ldr r1, _082103F4 @ =0x00000CD4
	adds r0, r4, r1
	str r5, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x9d
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082103CE:
	ldr r2, _082103F4 @ =0x00000CD4
	adds r6, r4, r2
	adds r0, r6, #0
	bl FUN_08055d20
	cmp r0, #0
	bne _082103DE
	b _08210528
_082103DE:
	str r5, [sp]
	str r7, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0x9d
_082103EA:
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
	b _08210528
	.align 2, 0
_082103F4: .4byte 0x00000CD4
_082103F8:
	ldr r3, _0821040C @ =0x00000D88
	adds r0, r4, r3
	ldrb r1, [r0]
	cmp r1, #1
	beq _08210464
	cmp r1, #1
	bgt _08210410
	cmp r1, #0
	beq _0821041A
	b _08210528
	.align 2, 0
_0821040C: .4byte 0x00000D88
_08210410:
	cmp r1, #2
	beq _082104A4
	cmp r1, #3
	beq _082104E8
	b _08210528
_0821041A:
	cmp r2, #0
	beq _0821043E
	adds r0, r4, #0
	movs r1, #8
	bl FUN_0820ff98
	ldr r1, _08210458 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_0821043E:
	ldr r2, _08210458 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	beq _08210528
	ldr r3, _0821045C @ =0x00000D89
	adds r0, r4, r3
	strb r7, [r0]
	ldr r0, _08210460 @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_08210458: .4byte 0x00000CD4
_0821045C: .4byte 0x00000D89
_08210460: .4byte 0x00000D88
_08210464:
	cmp r2, #0
	beq _08210480
	ldr r1, _08210498 @ =0x00000CD4
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x52
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_08210480:
	ldr r2, _08210498 @ =0x00000CD4
	adds r0, r4, r2
	bl FUN_08055d20
	cmp r0, #0
	beq _08210528
	ldr r3, _0821049C @ =0x00000D89
	adds r0, r4, r3
	strb r7, [r0]
	ldr r0, _082104A0 @ =0x00000D88
	adds r1, r4, r0
	b _082104D4
	.align 2, 0
_08210498: .4byte 0x00000CD4
_0821049C: .4byte 0x00000D89
_082104A0: .4byte 0x00000D88
_082104A4:
	cmp r2, #0
	beq _082104BE
	ldr r2, _082104DC @ =0x00000CD4
	adds r0, r4, r2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x5c
_082104B6:
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_082104BE:
	ldr r3, _082104DC @ =0x00000CD4
	adds r0, r4, r3
	bl FUN_08055d20
	cmp r0, #0
	beq _08210528
	ldr r1, _082104E0 @ =0x00000D89
	adds r0, r4, r1
	strb r7, [r0]
_082104D0:
	ldr r2, _082104E4 @ =0x00000D88
	adds r1, r4, r2
_082104D4:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08210528
	.align 2, 0
_082104DC: .4byte 0x00000CD4
_082104E0: .4byte 0x00000D89
_082104E4: .4byte 0x00000D88
_082104E8:
	cmp r2, #0
	beq _08210504
	ldr r3, _08210538 @ =0x00000CD4
	adds r0, r4, r3
	movs r1, #2
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x57
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_08210504:
	ldr r0, _08210538 @ =0x00000CD4
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_08055d20
	cmp r0, #0
	beq _08210528
	movs r0, #2
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x57
	movs r2, #0
	movs r3, #1
	bl FUN_08055b5c
_08210528:
	ldr r1, _08210538 @ =0x00000CD4
	adds r0, r4, r1
	bl FUN_08055c04
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08210538: .4byte 0x00000CD4
