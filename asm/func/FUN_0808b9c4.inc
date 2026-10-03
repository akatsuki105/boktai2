	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	movs r4, #0
	cmp r4, r6
	bge _0808B9FE
_0808B9D8:
	adds r2, r7, r4
	movs r0, #0
	mov r1, r8
	bl FUN_0808a420
	adds r2, r4, #1
	cmp r5, #0
	ble _0808B9F8
	ldr r1, _0808BA08 @ =0x0000F002
	adds r3, r1, #0
	adds r1, r5, #0
_0808B9EE:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _0808B9EE
_0808B9F8:
	adds r4, r2, #0
	cmp r4, r6
	blt _0808B9D8
_0808B9FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BA08: .4byte 0x0000F002
