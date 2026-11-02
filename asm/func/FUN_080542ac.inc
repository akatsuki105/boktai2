	push {r4, r5, lr}
	adds r3, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r5, #1
	str r5, [r0]
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080542E2
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, r3, #0
	adds r1, #0x78
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r1]
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r5, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0xc0
	strb r0, [r3, #0xf]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #0
	strb r0, [r3, #0x10]
_080542E2:
	adds r2, r3, #0
	adds r2, #0x78
	ldrh r1, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	ldr r4, _0805430C @ =0x00000DAC
	cmp r0, r4
	bgt _08054310
	movs r1, #0
	strh r4, [r2]
	movs r0, #2
	strb r0, [r3, #0xb]
	strb r5, [r3, #0xc]
	str r1, [r3, #0x18]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl BlackPantherElem_ShowEmote
	b _08054314
	.align 2, 0
_0805430C: .4byte 0x00000DAC
_08054310:
	subs r0, r1, #4
	strh r0, [r2]
_08054314:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
