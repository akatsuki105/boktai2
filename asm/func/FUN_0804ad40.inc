	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AD98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804aa98
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	adds r2, r0, #0
	str r2, [r5]
	cmp r2, #0
	blt _0804AD90
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
_0804AD90:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804AD98:
	ldr r2, [r4, #0x34]
	cmp r2, #0x1e
	bls _0804ADCC
	ldr r0, _0804ADC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804ADCC
	adds r1, r4, #0
	adds r1, #0x2f
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	movs r1, #4
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x34]
	b _0804ADD0
	.align 2, 0
_0804ADC8: .4byte 0x030044E0
_0804ADCC:
	adds r0, r2, #1
	str r0, [r4, #0x34]
_0804ADD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
