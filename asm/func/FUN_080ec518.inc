	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
	ldr r0, _080EC53C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r2, r0, r3
	adds r3, r2, #0
_080EC52C:
	ldrh r0, [r2]
	cmp r0, r5
	bne _080EC540
	ldrh r0, [r2, #2]
	cmp r0, r4
	bne _080EC540
	adds r0, r3, #0
	b _080EC54C
	.align 2, 0
_080EC53C: .4byte 0x030046A0
_080EC540:
	adds r2, #6
	adds r3, #6
	adds r1, #1
	cmp r1, #0x13
	ble _080EC52C
	movs r0, #0
_080EC54C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
