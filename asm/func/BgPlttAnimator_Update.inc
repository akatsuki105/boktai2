	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _0801B5CE
	adds r0, r4, #0
	bl BgPlttAnimator_SavePltt
_0801B5CE:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	cmp r0, #3
	ble _0801B606
	movs r1, #0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #6
	ble _0801B5E8
	str r1, [r4, #0x1c]
_0801B5E8:
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldr r2, _0801B610 @ =0x03004250
_0801B5F0:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0801B5F0
_0801B606:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B610: .4byte 0x03004250
