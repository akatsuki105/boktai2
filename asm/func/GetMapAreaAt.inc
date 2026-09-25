	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08241584 @ =0x03001704
	ldr r0, [r0]
	cmp r0, #0
	bne _0824158C
	b _082415B0
	.align 2, 0
_08241584: .4byte 0x03001704
_08241588:
	ldr r0, [r4]
	b _082415B4
_0824158C:
	movs r5, #0
	adds r4, r0, #0
	adds r4, #0x18
_08241592:
	ldr r0, [r4]
	cmp r0, #0
	ble _082415B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234d50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08241588
	adds r4, #4
	adds r5, #1
	cmp r5, #0xf
	ble _08241592
_082415B0:
	movs r0, #1
	rsbs r0, r0, #0
_082415B4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
