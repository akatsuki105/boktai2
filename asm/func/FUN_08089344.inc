	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089368 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0808935A
	adds r0, r4, #0
	movs r1, #0xc
	bl Coffin_SetState
_0808935A:
	ldrb r0, [r4, #0x1a]
	cmp r0, #6
	bne _08089370
	ldr r0, _0808936C @ =0x0000032A
	adds r1, r4, r0
	movs r0, #1
	b _08089396
	.align 2, 0
_08089368: .4byte 0x000001F5
_0808936C: .4byte 0x0000032A
_08089370:
	cmp r0, #7
	bne _08089390
	ldr r0, _08089388 @ =0x00000406
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0808938C @ =0x0000032A
	adds r0, r4, r1
	strh r2, [r0]
	b _08089398
	.align 2, 0
_08089388: .4byte 0x00000406
_0808938C: .4byte 0x0000032A
_08089390:
	ldr r0, _080893BC @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
_08089396:
	strh r0, [r1]
_08089398:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080893BC: .4byte 0x0000032A
