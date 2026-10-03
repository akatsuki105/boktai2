	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #8]
	movs r0, #0
	mov r8, r0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r4, r0, #0
	movs r6, #0
	ldr r1, _0808E13C @ =0xFFFFD000
	adds r7, r1, #0
	mov r5, sp
_0808E128:
	ldr r0, [r5]
	cmp r0, #0
	ble _0808E140
	movs r1, #1
	mov r8, r1
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
	.align 2, 0
_0808E13C: .4byte 0xFFFFD000
_0808E140:
	mov r1, r8
	cmp r1, #0
	bne _0808E14A
	cmp r6, #2
	bne _0808E154
_0808E14A:
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
_0808E154:
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
_0808E15A:
	strh r0, [r4]
	adds r4, #2
	adds r5, #4
	adds r6, #1
	cmp r6, #2
	ble _0808E128
	ldr r1, _0808E178 @ =0x0000D07B
	adds r0, r1, #0
	strh r0, [r4]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E178: .4byte 0x0000D07B
