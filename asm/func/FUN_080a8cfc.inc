	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A8D38
	ldr r1, [r2, #0x18]
	ldr r0, _080A8D3C @ =0x000003FB
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl KillEntity
_080A8D38:
	pop {r0}
	bx r0
	.align 2, 0
_080A8D3C: .4byte 0x000003FB
