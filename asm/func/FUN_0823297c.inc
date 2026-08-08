	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _08232990 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _08232994
	movs r0, #0
	b _082329D8
	.align 2, 0
_08232990: .4byte 0x030046A4
_08232994:
	adds r4, r0, #0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _082329BA
	cmp r2, #0
	blt _082329BA
	ldr r0, _082329C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082329BA
	ldr r0, _082329C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _082329C8
_082329BA:
	movs r0, #0
	b _082329D2
	.align 2, 0
_082329C0: .4byte 0x030046A8
_082329C4: .4byte 0x030046AC
_082329C8:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_082329D2:
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #0xe]
_082329D8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
