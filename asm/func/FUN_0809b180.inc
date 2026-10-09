	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0809B1AC @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r6, #0
	bl FUN_0808b4c0
	ldr r0, _0809B1B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0809B1B8
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809B1B4 @ =FUN_0809b2b8
	b _0809B208
	.align 2, 0
_0809B1AC: .4byte 0x00001084
_0809B1B0: .4byte 0x030044E0
_0809B1B4: .4byte FUN_0809b2b8
_0809B1B8:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809B21C
	ldr r0, _0809B1E0 @ =0x00000F56
	adds r2, r6, r0
	ldr r1, _0809B1E4 @ =0x00000F57
	adds r0, r6, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	cmp r0, r1
	beq _0809B1E8
	strb r1, [r2]
	adds r0, r6, #0
	bl FUN_0809a67c
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _0809B1EE
	.align 2, 0
_0809B1E0: .4byte 0x00000F56
_0809B1E4: .4byte 0x00000F57
_0809B1E8:
	ldr r0, _0809B210 @ =0x00000119
	bl PlaySound_082406e0
_0809B1EE:
	ldr r1, _0809B214 @ =FUN_0809b2b8
	movs r4, #2
	rsbs r4, r4, #0
	ldr r0, _0809B218 @ =0x0000108C
	adds r2, r6, r0
	movs r3, #9
_0809B1FA:
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B1FA
_0809B208:
	adds r0, r6, #0
	bl FUN_0808a33c
	b _0809B2AC
	.align 2, 0
_0809B210: .4byte 0x00000119
_0809B214: .4byte FUN_0809b2b8
_0809B218: .4byte 0x0000108C
_0809B21C:
	adds r0, r6, #0
	bl FUN_0808b6a4
	adds r1, r0, #0
	movs r2, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809B244
	ldr r1, _0809B240 @ =0x00000F57
	adds r4, r6, r1
	ldrb r1, [r4]
	adds r0, r6, #0
	bl FUN_0809a978
	strb r0, [r4]
	b _0809B260
	.align 2, 0
_0809B240: .4byte 0x00000F57
_0809B244:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809B25C
	ldr r0, _0809B28C @ =0x00000F57
	adds r4, r6, r0
	ldrb r1, [r4]
	adds r0, r6, #0
	bl FUN_0809a93c
	strb r0, [r4]
	movs r2, #1
_0809B25C:
	cmp r2, #0
	beq _0809B2AC
_0809B260:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r5, #0
	ldr r1, _0809B290 @ =0x00001084
	adds r4, r6, r1
_0809B26C:
	ldr r1, _0809B294 @ =0x00000F58
	adds r0, r6, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809B2A6
	subs r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r5, r0
	bne _0809B29C
	adds r0, r4, #0
	ldr r1, _0809B298 @ =0x000002A5
	bl MainSprite_SetPltt
	b _0809B2A4
	.align 2, 0
_0809B28C: .4byte 0x00000F57
_0809B290: .4byte 0x00001084
_0809B294: .4byte 0x00000F58
_0809B298: .4byte 0x000002A5
_0809B29C:
	adds r0, r4, #0
	ldr r1, _0809B2B4 @ =0x000002A6
	bl MainSprite_SetPltt
_0809B2A4:
	adds r4, #0x60
_0809B2A6:
	adds r5, #1
	cmp r5, #9
	ble _0809B26C
_0809B2AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2B4: .4byte 0x000002A6
