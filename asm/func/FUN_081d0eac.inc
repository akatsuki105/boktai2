	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D0EC8 @ =0x0000097C
	adds r2, r3, r0
	movs r6, #1
_081D0EB8:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D0ECC
	movs r0, #1
	b _081D0ECE
	.align 2, 0
_081D0EC8: .4byte 0x0000097C
_081D0ECC:
	movs r0, #0
_081D0ECE:
	cmp r0, #0
	bne _081D0EF8
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xc8
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0xb4
	strh r5, [r0]
	adds r0, r4, #0
	b _081D0F00
_081D0EF8:
	adds r5, #1
	cmp r5, #0xb
	ble _081D0EB8
	movs r0, #0
_081D0F00:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
