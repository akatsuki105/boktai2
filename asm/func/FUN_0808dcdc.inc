	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	ldr r2, _0808DD90 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r4, _0808DD94 @ =0x0000FFFF
	ands r0, r4
	movs r3, #0x88
	lsls r3, r3, #0x10
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r2
	movs r1, #0xd8
	orrs r0, r1
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
	mov r7, r8
	adds r7, #0xa0
	ldr r0, _0808DD98 @ =0x00010011
	mov sl, r0
	movs r6, #0
	movs r1, #0x3c
	mov sb, r1
_0808DD2C:
	movs r0, #0x64
	adds r4, r5, #0
	muls r4, r0, r4
	add r4, r8
	ldr r0, _0808DD9C @ =0x00000C0C
	adds r4, r4, r0
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0xb6
	mov r3, sl
	bl MainSprite_Add
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	movs r0, #0x68
	muls r0, r5, r0
	add r0, r8
	ldr r1, _0808DDA0 @ =0x00000DA4
	adds r0, r0, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r1, sp, #0x18
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #1
	mov r3, sl
	bl MainSprite_Add
	adds r5, #1
	cmp r5, #3
	ble _0808DD2C
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DD90: .4byte 0xFFFF0000
_0808DD94: .4byte 0x0000FFFF
_0808DD98: .4byte 0x00010011
_0808DD9C: .4byte 0x00000C0C
_0808DDA0: .4byte 0x00000DA4
