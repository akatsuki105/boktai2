	push {r4, r5, r6, lr}
	ldr r3, _0808B900 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x90
	orrs r1, r2
	ldr r2, _0808B904 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r3, r0, r1
_0808B8C6:
	ldr r0, _0808B908 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #3
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B90C @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0808B8C6
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B900: .4byte 0xFFFF0000
_0808B904: .4byte 0x0000FFFF
_0808B908: .4byte 0x00000F84
_0808B90C: .4byte 0x00000F86
