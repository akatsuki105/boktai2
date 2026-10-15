	push {r4, r5, lr}
	adds r4, r2, #0
	ldr r2, _081E4CE4 @ =0x00001610
	adds r5, r0, r2
	ldr r3, _081E4CE8 @ =0xFFBFFFFF
	ldr r2, [r5]
	ands r2, r3
	str r2, [r5]
	ldr r2, _081E4CEC @ =0x0000161C
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r1, #0
	adds r1, r4, #0
	bl LinkShopManager_Send
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CF0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5]
	orrs r0, r1
	b _081E4CF6
	.align 2, 0
_081E4CE4: .4byte 0x00001610
_081E4CE8: .4byte 0xFFBFFFFF
_081E4CEC: .4byte 0x0000161C
_081E4CF0:
	ldr r1, _081E4D00 @ =0xFFF7FFFF
	ldr r0, [r5]
	ands r0, r1
_081E4CF6:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4D00: .4byte 0xFFF7FFFF
