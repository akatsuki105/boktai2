	push {r4, r5, lr}
	ldr r2, _081651D4 @ =0x000001DD
	adds r1, r0, r2
	movs r3, #0
	strb r3, [r1]
	movs r5, #0x94
	lsls r5, r5, #3
	adds r1, r0, r5
	movs r4, #1
	str r4, [r1]
	subs r2, #0x59
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r5, #0x8b
	lsls r5, r5, #1
	adds r1, r0, r5
	strh r2, [r1]
	ldr r5, _081651D8 @ =0x0000048A
	adds r1, r0, r5
	strh r2, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0x28
	strh r1, [r2]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r0, r2
	str r3, [r1]
	adds r5, #0x12
	adds r1, r0, r5
	str r3, [r1]
	subs r2, #0xc
	adds r1, r0, r2
	strb r4, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081651D4: .4byte 0x000001DD
_081651D8: .4byte 0x0000048A
