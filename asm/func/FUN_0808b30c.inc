	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r0, [sp, #0x14]
	movs r7, #0x31
	cmp r0, #0
	bne _0808B320
	movs r7, #0x91
_0808B320:
	movs r0, #0
	bl FUN_0808a420
	adds r6, r0, #0
	cmp r4, #0
	ble _0808B358
_0808B32C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r4, r0
	subs r5, r5, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	cmp r4, #0
	bgt _0808B32C
_0808B358:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
