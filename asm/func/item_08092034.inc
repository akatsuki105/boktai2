	push {r4, r5, lr}
	adds r5, r0, #0
	bl GetNormalItemID
	cmp r0, #0
	blt _0809204C
	ldr r1, _08092050 @ =0x08DAA8D8
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r4, [r0, #4]
	cmp r4, #0
	bne _08092054
_0809204C:
	movs r0, #0xcf
	b _0809206A
	.align 2, 0
_08092050: .4byte 0x08DAA8D8
_08092054:
	adds r0, r5, #0
	bl GetRotCount2
	lsls r0, r0, #2
	lsls r1, r4, #5
	bl Div
	cmp r0, #3
	ble _08092068
	movs r0, #3
_08092068:
	adds r0, #0xd0
_0809206A:
	pop {r4, r5}
	pop {r1}
	bx r1
