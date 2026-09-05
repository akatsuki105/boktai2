	push {lr}
	adds r2, r0, #0
	ldr r1, _080B2450 @ =0x00000C0F
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B245C
	ldr r0, _080B2454 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080B2458 @ =0x00000942
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	b _080B2462
	.align 2, 0
_080B2450: .4byte 0x00000C0F
_080B2454: .4byte 0x030046A0
_080B2458: .4byte 0x00000942
_080B245C:
	ldr r1, _080B2470 @ =0x00000C11
	adds r0, r2, r1
	ldrb r1, [r0]
_080B2462:
	movs r3, #0xc1
	lsls r3, r3, #4
	adds r0, r2, r3
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080B2470: .4byte 0x00000C11
