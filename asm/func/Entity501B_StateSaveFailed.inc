	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E06B0 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E06A0
	bl Sio_Disconnect
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #8
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #5
	bl TextPanel_SetMessage
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _081E06B4 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E06A0:
	ldr r2, _081E06B4 @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E06B8
	adds r0, #1
	strh r0, [r1]
	b _081E06C8
	.align 2, 0
_081E06B0: .4byte 0x000003E9
_081E06B4: .4byte 0x000003EA
_081E06B8:
	ldr r0, _081E06D0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E06D4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E06C8
	bl SoftReset_0823a928
_081E06C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E06D0: .4byte 0x030044E0
_081E06D4: .4byte 0x0000030F
