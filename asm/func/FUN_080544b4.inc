	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080544DE
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, #0x78
	ldr r0, _0805450C @ =0x000008FC
	strh r0, [r1]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0x40
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r3, #0x11]
	movs r0, #2
	strb r0, [r3, #0x10]
_080544DE:
	adds r4, r3, #0
	adds r4, #0x78
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r1, [r5, #0x24]
	ldr r0, _08054510 @ =0x00000CE4
	subs r1, r0, r1
	cmp r2, r1
	blt _08054514
	movs r0, #0
	strh r1, [r4]
	movs r1, #6
	strb r1, [r3, #0xb]
	movs r1, #1
	strb r1, [r3, #0xc]
	str r0, [r3, #0x18]
	adds r0, r3, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl BlackPantherElem_ShowEmote
	b _0805451A
	.align 2, 0
_0805450C: .4byte 0x000008FC
_08054510: .4byte 0x00000CE4
_08054514:
	ldrh r0, [r4]
	adds r0, #6
	strh r0, [r4]
_0805451A:
	pop {r4, r5}
	pop {r0}
	bx r0
