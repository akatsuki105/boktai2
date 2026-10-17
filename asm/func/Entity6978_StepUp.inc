	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _080027B8 @ =0x0300445C
	ldrh r0, [r2, #0x20]
	lsls r0, r0, #6
	ldrh r1, [r2, #0x22]
	asrs r0, r1
	str r0, [r3]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r4, [r2, #0x22]
	lsls r0, r4
	cmp r1, r0
	blt _080027B2
	movs r0, #0x40
	str r0, [r3]
	movs r0, #0
	strh r0, [r2, #0x1e]
_080027B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080027B8: .4byte 0x0300445C
