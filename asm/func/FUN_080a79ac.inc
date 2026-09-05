	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A79E4 @ =0x00000341
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080A79DE
	ldr r2, _080A79E8 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A79EC @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
	ldr r1, _080A79F0 @ =0x03004788
	movs r0, #0
	str r0, [r1]
	ldr r1, _080A79F4 @ =0x00000343
	adds r0, r4, r1
	ldrb r0, [r0]
	bl FUN_0823a8f4
	adds r0, r4, #0
	bl KillEntity
_080A79DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A79E4: .4byte 0x00000341
_080A79E8: .4byte 0x030047A4
_080A79EC: .4byte 0xFFFFFBFF
_080A79F0: .4byte 0x03004788
_080A79F4: .4byte 0x00000343
