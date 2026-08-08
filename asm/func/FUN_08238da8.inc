	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08238DF0 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _08238E0E
	bl FUN_0823860c
	ldr r3, _08238DF4 @ =0x0300082C
	ldr r0, [r3]
	cmp r0, #0
	beq _08238E04
	ldr r2, _08238DF8 @ =0x03004720
	ldr r0, _08238DFC @ =0x03000828
	ldr r1, [r0]
	lsls r1, r1, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r2, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #2]
	adds r0, r2, #4
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #4]
	adds r2, #6
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r4, #6]
	movs r0, #0
	str r0, [r3]
	ldr r0, _08238E00 @ =0x030046CC
	ldr r4, [r0]
	b _08238E08
	.align 2, 0
_08238DF0: .4byte 0x030046D4
_08238DF4: .4byte 0x0300082C
_08238DF8: .4byte 0x03004720
_08238DFC: .4byte 0x03000828
_08238E00: .4byte 0x030046CC
_08238E04:
	movs r4, #3
	rsbs r4, r4, #0
_08238E08:
	bl FUN_08238618
	adds r0, r4, #0
_08238E0E:
	pop {r4}
	pop {r1}
	bx r1
