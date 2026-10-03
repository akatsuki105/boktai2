	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	movs r1, #0
_0808C7D2:
	lsls r0, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _0808C830 @ =0x00003B8C
	adds r0, r0, r2
	mov r2, sb
	adds r6, r2, r0
	ldrb r0, [r6, #4]
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _0808C81C
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0x40
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_0808C7F6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808C810
	ldr r1, [r6]
	ldr r2, [r4, #4]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _0808C810
	movs r3, #1
_0808C810:
	adds r4, #0x40
	adds r5, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808C7F6
	strb r3, [r6, #4]
_0808C81C:
	mov r1, r8
	cmp r1, #1
	ble _0808C7D2
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C830: .4byte 0x00003B8C
