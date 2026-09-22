	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r1, _08047D68 @ =0x030000C4
	ldr r3, [r1]
	cmp r3, #0
	bne _08047D6C
	movs r0, #0
	b _08047D8C
	.align 2, 0
_08047D68: .4byte 0x030000C4
_08047D6C:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	movs r1, #0
	strb r4, [r2]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r3, r4
	strh r5, [r2]
	adds r4, #2
	adds r2, r3, r4
	strh r1, [r2]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r3, r2
	str r6, [r1]
_08047D8C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
