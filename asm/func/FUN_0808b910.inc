	push {r4, r5, r6, lr}
	ldr r3, _0808B96C @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x40
	orrs r1, r2
	ldr r2, _0808B970 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x98
	lsls r2, r2, #0xf
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xd8
	lsls r1, r1, #4
	adds r3, r0, r1
_0808B932:
	ldr r0, _0808B974 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B978 @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #3
	ble _0808B932
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B96C: .4byte 0xFFFF0000
_0808B970: .4byte 0x0000FFFF
_0808B974: .4byte 0x00000F84
_0808B978: .4byte 0x00000F86
