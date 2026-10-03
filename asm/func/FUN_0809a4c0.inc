	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0809A4EC @ =0x030047B8
	movs r5, #1
	str r5, [r0]
	bl Save_WriteToNextSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809A4FC
	ldr r0, _0809A4F0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809A4F4 @ =0x0000093A
	adds r0, r0, r1
	strh r5, [r0]
	ldr r1, _0809A4F8 @ =FUN_0809a510
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809A506
	.align 2, 0
_0809A4EC: .4byte 0x030047B8
_0809A4F0: .4byte 0x030046A0
_0809A4F4: .4byte 0x0000093A
_0809A4F8: .4byte FUN_0809a510
_0809A4FC:
	ldr r1, _0809A50C @ =FUN_0809a574
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A506:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A50C: .4byte FUN_0809a574
