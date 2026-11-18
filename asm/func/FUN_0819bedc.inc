	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, _0819BEFC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BF00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BF02
	.align 2, 0
_0819BEFC: .4byte 0x0000046D
_0819BF00:
	movs r0, #0
_0819BF02:
	cmp r0, #0
	beq _0819BF3C
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	subs r1, #4
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r2, #6]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r3, r4, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819BF3C:
	ldr r2, [r4, #0x44]
	ldrb r0, [r2, #9]
	movs r1, #9
	ldrsb r1, [r2, r1]
	cmp r1, #0x70
	ble _0819BF4E
	subs r0, #8
	strb r0, [r2, #9]
	b _0819BF98
_0819BF4E:
	cmp r1, #0x40
	ble _0819BF6C
	ldrb r0, [r2, #8]
	adds r0, #2
	strb r0, [r2, #8]
	ldr r1, [r4, #0x44]
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Show
	b _0819BF98
_0819BF6C:
	ldrb r1, [r2, #8]
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0x3f
	bgt _0819BF7C
	adds r0, r1, #4
	strb r0, [r2, #8]
	b _0819BF98
_0819BF7C:
	movs r1, #0x40
	strb r1, [r2, #8]
	ldr r0, [r4, #0x44]
	strb r1, [r0, #9]
	ldr r0, _0819BFA0 @ =0x00000E48
	adds r2, r5, r0
	subs r1, #0x85
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819BFA4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0819BF98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819BFA0: .4byte 0x00000E48
_0819BFA4: .4byte 0x0000046B
