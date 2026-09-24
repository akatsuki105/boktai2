	push {lr}
	adds r3, r0, #0
	movs r0, #0xcf
	adds r0, r0, r3
	mov ip, r0
	movs r2, #0
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xd0
	strh r2, [r0]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r2, r3, r1
	ldr r1, _080B2874 @ =0x085AD0B8
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #3
	bne _080B2878
	movs r0, #0xfb
	bl PlaySound_082406e0
	b _080B2882
	.align 2, 0
_080B2874: .4byte 0x085AD0B8
_080B2878:
	cmp r0, #5
	bne _080B2882
	movs r0, #0xfc
	bl PlaySound_082406e0
_080B2882:
	pop {r0}
	bx r0
	.align 2, 0
