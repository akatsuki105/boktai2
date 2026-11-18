	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r2, r0
	ldr r0, [r3]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081985AC
	adds r1, r2, #0
	adds r1, #0xea
	adds r0, r2, #0
	adds r0, #0xf2
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_081985AC:
	ldr r0, [r3]
	subs r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _081985C4
	adds r1, r2, #0
	adds r1, #0xf2
	ldrh r0, [r1]
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r0, #0x28
	str r0, [r3]
_081985C4:
	adds r0, r2, #0
	adds r0, #0xea
	ldrh r0, [r0]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
