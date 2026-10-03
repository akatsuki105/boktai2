	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xec
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0804BB8A
	movs r0, #1
	rsbs r0, r0, #0
	b _0804BB94
_0804BB8A:
	adds r0, r2, #0
	adds r0, #0xee
	ldrh r0, [r0]
	strh r0, [r3]
	movs r0, #0
_0804BB94:
	pop {r1}
	bx r1
