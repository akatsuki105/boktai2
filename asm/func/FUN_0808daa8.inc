	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808DB50 @ =0x00000C01
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DAFA
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DAFA
	adds r6, r0, #0
_0808DACC:
	ldr r1, _0808DB54 @ =0x00000C02
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x64
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB58 @ =0x00000C2E
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DACC
_0808DAFA:
	ldr r2, _0808DB5C @ =0x00000F41
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DB46
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DB46
	adds r6, r0, #0
_0808DB18:
	ldr r1, _0808DB60 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	ldr r1, _0808DB5C @ =0x00000F41
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x68
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB64 @ =0x00000DC6
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DB18
_0808DB46:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DB50: .4byte 0x00000C01
_0808DB54: .4byte 0x00000C02
_0808DB58: .4byte 0x00000C2E
_0808DB5C: .4byte 0x00000F41
_0808DB60: .4byte 0x00000D98
_0808DB64: .4byte 0x00000DC6
