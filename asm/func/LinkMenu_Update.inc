	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0804B020 @ =0x085AB584
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r1, [r4]
	adds r1, #1
	movs r7, #0
	strh r1, [r4]
	ldr r2, _0804B024 @ =0x0000FFFF
	adds r6, r2, #0
	ldr r2, _0804B028 @ =0x085AB598
	adds r0, #2
	adds r3, r5, r0
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _0804B018
	strh r7, [r4]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ands r0, r6
	cmp r0, #5
	bls _0804B006
	strh r7, [r3]
_0804B006:
	ldr r1, _0804B02C @ =0x085AB5A4
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0804B018:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B020: .4byte 0x085AB584
_0804B024: .4byte 0x0000FFFF
_0804B028: .4byte 0x085AB598
_0804B02C: .4byte 0x085AB5A4
