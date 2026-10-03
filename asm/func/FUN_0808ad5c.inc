	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r2, #0
	movs r7, #0
	movs r5, #0
	mov sb, r5
	mov r8, r5
	mov sl, r5
	movs r6, #0
	ldr r1, _0808AD98 @ =0x00000A0A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AE24
	ldr r2, _0808AD9C @ =0x000039CE
	mov sl, r2
	ldr r0, _0808ADA0 @ =0x00000A0D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ADA8
	ldr r2, _0808ADA4 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808ADAC
	.align 2, 0
_0808AD98: .4byte 0x00000A0A
_0808AD9C: .4byte 0x000039CE
_0808ADA0: .4byte 0x00000A0D
_0808ADA4: .4byte 0x00007FFF
_0808ADA8:
	movs r0, #0x1f
	mov r8, r0
_0808ADAC:
	ldr r1, _0808ADC8 @ =0x00000A0C
	adds r0, r4, r1
	ldrb r0, [r0]
	mov sb, r0
	lsls r5, r0, #3
	ldr r0, _0808ADCC @ =0x00000A06
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808ADD0
	movs r7, #0
	movs r5, #0
	b _0808ADEC
	.align 2, 0
_0808ADC8: .4byte 0x00000A0C
_0808ADCC: .4byte 0x00000A06
_0808ADD0:
	subs r1, r5, #1
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	ldr r2, _0808AE14 @ =0x00000A08
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808ADEC:
	movs r6, #0x8c
	ldr r0, _0808AE18 @ =0x00000A0A
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r2, _0808AE1C @ =0x00000A15
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	movs r2, #1
	ldr r0, _0808AE20 @ =0x00000A12
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AEA8
	subs r0, #1
	strh r0, [r1]
	b _0808AEA8
	.align 2, 0
_0808AE14: .4byte 0x00000A08
_0808AE18: .4byte 0x00000A0A
_0808AE1C: .4byte 0x00000A15
_0808AE20: .4byte 0x00000A12
_0808AE24:
	ldr r1, _0808AE48 @ =0x00000A12
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AEA8
	movs r2, #0x1f
	mov sl, r2
	ldr r0, _0808AE4C @ =0x00000A14
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808AE54
	ldr r2, _0808AE50 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808AE5A
	.align 2, 0
_0808AE48: .4byte 0x00000A12
_0808AE4C: .4byte 0x00000A14
_0808AE50: .4byte 0x00007FFF
_0808AE54:
	movs r0, #0xf8
	lsls r0, r0, #2
	mov r8, r0
_0808AE5A:
	movs r1, #0xa
	mov sb, r1
	ldr r0, _0808AE70 @ =0x00000A0E
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808AE74
	movs r7, #0
	movs r5, #0
	b _0808AE92
	.align 2, 0
_0808AE70: .4byte 0x00000A0E
_0808AE74:
	movs r1, #0x4f
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808AE92:
	movs r6, #0x42
	ldr r0, _0808AF4C @ =0x00000A15
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0808AF50 @ =0x00000A12
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r2, #1
_0808AEA8:
	cmp r2, #0
	beq _0808AF68
	ldr r1, _0808AF54 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, sl
	beq _0808AEB8
	mov r4, sl
	strh r4, [r1]
_0808AEB8:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r8
	beq _0808AEC4
	mov r0, r8
	strh r0, [r1]
_0808AEC4:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	movs r3, #2
_0808AED6:
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	subs r6, #1
	subs r3, #1
	cmp r3, #0
	bge _0808AED6
	movs r3, #0
	cmp r3, r7
	bge _0808AEFE
	ldr r1, _0808AF5C @ =0x0000D089
	adds r0, r1, #0
	adds r3, r7, #0
_0808AEF2:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AEF2
	adds r3, r7, #0
_0808AEFE:
	cmp r5, #0
	beq _0808AF12
	adds r0, r5, #0
	adds r0, #0x81
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AF12:
	cmp r3, sb
	bge _0808AF2A
	ldr r1, _0808AF60 @ =0x0000D081
	adds r0, r1, #0
	mov r4, sb
	subs r3, r4, r3
_0808AF1E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AF1E
	mov r3, sb
_0808AF2A:
	ldr r1, _0808AF64 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _0808AF98
	movs r4, #0xd0
	lsls r4, r4, #8
	adds r0, r4, #0
_0808AF3E:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _0808AF3E
	b _0808AF98
	.align 2, 0
_0808AF4C: .4byte 0x00000A15
_0808AF50: .4byte 0x00000A12
_0808AF54: .4byte 0x0300440C
_0808AF58: .4byte 0xFFFFD000
_0808AF5C: .4byte 0x0000D089
_0808AF60: .4byte 0x0000D081
_0808AF64: .4byte 0x0000D080
_0808AF68:
	ldr r1, _0808AFA8 @ =0x00000A15
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808AF98
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r3, #0xd
_0808AF86:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808AF86
	ldr r2, _0808AFA8 @ =0x00000A15
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0808AF98:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AFA8: .4byte 0x00000A15
