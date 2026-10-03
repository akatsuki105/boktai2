	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _0808D260 @ =0x085AC064
	movs r6, #0
_0808D20C:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r4, r6, #1
	movs r2, #3
_0808D22C:
	ldrh r0, [r7]
	strh r0, [r5]
	adds r5, #2
	ldrh r0, [r7]
	strh r0, [r1]
	adds r1, #2
	adds r7, #2
	subs r2, #1
	cmp r2, #0
	bge _0808D22C
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D20C
	ldr r1, _0808D264 @ =0x00000F3C
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D260: .4byte 0x085AC064
_0808D264: .4byte 0x00000F3C
