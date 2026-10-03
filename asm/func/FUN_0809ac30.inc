	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0809AC50 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r5, #0
	bl FUN_0808b4c0
	ldr r1, _0809AC54 @ =0x00003AE4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AC5C
	ldr r1, _0809AC58 @ =FUN_0809ae0c
	b _0809AD04
	.align 2, 0
_0809AC50: .4byte 0x00001084
_0809AC54: .4byte 0x00003AE4
_0809AC58: .4byte FUN_0809ae0c
_0809AC5C:
	ldr r2, _0809AC8C @ =0x000009F8
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AC9C
	ldr r0, _0809AC90 @ =0x00000FCC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809AC94 @ =0x0000102C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809AC98 @ =0x000009F4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0809ADFC
	.align 2, 0
_0809AC8C: .4byte 0x000009F8
_0809AC90: .4byte 0x00000FCC
_0809AC94: .4byte 0x0000102C
_0809AC98: .4byte 0x000009F4
_0809AC9C:
	ldr r2, _0809ACCC @ =0x00000FCC
	adds r1, r5, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0809ACD0 @ =0x0000102C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r7, _0809ACD4 @ =0x030044E0
	ldrh r2, [r7, #2]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809ACE0
	ldr r0, _0809ACD8 @ =0x00000119
	bl PlaySound_082406e0
	ldr r1, _0809ACDC @ =FUN_0809ae0c
	b _0809AD04
	.align 2, 0
_0809ACCC: .4byte 0x00000FCC
_0809ACD0: .4byte 0x0000102C
_0809ACD4: .4byte 0x030044E0
_0809ACD8: .4byte 0x00000119
_0809ACDC: .4byte FUN_0809ae0c
_0809ACE0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0809AD18
	ldr r1, _0809AD0C @ =0x00000F56
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0809AD10 @ =0x00000F57
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0809a9b0
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809AD14 @ =FUN_0809b12c
_0809AD04:
	adds r0, r5, #0
	bl FUN_0808a33c
	b _0809AE02
	.align 2, 0
_0809AD0C: .4byte 0x00000F56
_0809AD10: .4byte 0x00000F57
_0809AD14: .4byte FUN_0809b12c
_0809AD18:
	ldr r0, _0809AD3C @ =0x0000400C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809ADEC
	movs r3, #0
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _0809AD44
	ldr r1, _0809AD40 @ =0x00003AE5
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #1
	b _0809ADA2
	.align 2, 0
_0809AD3C: .4byte 0x0000400C
_0809AD40: .4byte 0x00003AE5
_0809AD44:
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0809AD5C
	ldr r2, _0809AD58 @ =0x00003AE5
	adds r0, r5, r2
	strb r3, [r0]
	b _0809ADA0
	.align 2, 0
_0809AD58: .4byte 0x00003AE5
_0809AD5C:
	ldrh r1, [r7]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809AD84
	ldr r0, _0809AD80 @ =0x00003AE5
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0809ADA2
	strb r3, [r1]
	movs r3, #1
	b _0809ADA2
	.align 2, 0
_0809AD80: .4byte 0x00003AE5
_0809AD84:
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0809ADA2
	ldr r2, _0809ADBC @ =0x00003AE5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0809ADA2
	strb r3, [r1]
_0809ADA0:
	movs r3, #2
_0809ADA2:
	cmp r3, #1
	bne _0809ADC4
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _0809ADC0 @ =0x00000F56
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_0809a93c
	b _0809ADDC
	.align 2, 0
_0809ADBC: .4byte 0x00003AE5
_0809ADC0: .4byte 0x00000F56
_0809ADC4:
	cmp r3, #2
	bne _0809ADF0
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809ADE8 @ =0x00000F56
	adds r4, r5, r1
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_0809a978
_0809ADDC:
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_0809a67c
	b _0809AE02
	.align 2, 0
_0809ADE8: .4byte 0x00000F56
_0809ADEC:
	subs r0, #1
	strb r0, [r1]
_0809ADF0:
	ldr r2, _0809AE08 @ =0x000009F4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_0809ADFC:
	adds r0, r5, #0
	bl FUN_0808c028
_0809AE02:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE08: .4byte 0x000009F4
