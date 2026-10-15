	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r0, [r3, #6]
	adds r4, r0, #0
	cmp r4, #0
	bne _08019400
	ldr r1, [r2, #0x1c]
	cmp r1, #0
	blt _080193CA
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bge _08019404
_080193CA:
	movs r0, #1
	strb r0, [r3]
	ldr r2, _080193F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080193F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080193FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #1]
	strh r4, [r3, #2]
	ldr r0, [r3, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #8]
	b _08019404
	.align 2, 0
_080193F4: .4byte 0x030046B8
_080193F8: .4byte 0x000003FF
_080193FC: .4byte 0x0203B400
_08019400:
	subs r0, #1
	strh r0, [r3, #6]
_08019404:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
