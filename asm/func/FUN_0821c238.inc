	push {lr}
	adds r2, r0, #0
	cmp r1, #1
	beq _0821C28E
	cmp r1, #1
	bgt _0821C24A
	cmp r1, #0
	beq _0821C284
	b _0821C29C
_0821C24A:
	cmp r1, #7
	bne _0821C29C
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821C26C
	ldr r0, _0821C268 @ =0x03003584
	ldr r0, [r0]
	adds r0, #0xe0
	movs r3, #0xc1
	lsls r3, r3, #2
	adds r1, r2, r3
	b _0821C29A
	.align 2, 0
_0821C268: .4byte 0x03003584
_0821C26C:
	ldr r0, _0821C280 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc1
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r0, r2
	b _0821C29A
	.align 2, 0
_0821C280: .4byte 0x03003584
_0821C284:
	movs r3, #0xc1
	lsls r3, r3, #2
	adds r1, r2, r3
	adds r3, #0xfc
	b _0821C298
_0821C28E:
	movs r0, #0xc1
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0xc0
	lsls r3, r3, #3
_0821C298:
	adds r0, r2, r3
_0821C29A:
	str r0, [r1]
_0821C29C:
	pop {r0}
	bx r0
