	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080892F0 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080892BE
	adds r0, r4, #0
	movs r1, #0xb
	bl Coffin_SetState
_080892BE:
	ldr r3, _080892F4 @ =0x0000032A
	adds r0, r4, r3
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r3, #0x6a
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r0, [r3]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080892F0: .4byte 0x000001F5
_080892F4: .4byte 0x0000032A
