	push {lr}
	ldr r0, _0809ABD8 @ =0x030044E0
	ldr r0, [r0]
	ldr r1, _0809ABDC @ =0x00020004
	ands r0, r1
	cmp r0, r1
	bne _0809ABE8
	ldr r0, _0809ABE0 @ =0x03004864
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809ABE4
	bl FUN_082416c8
	b _0809ABE8
	.align 2, 0
_0809ABD8: .4byte 0x030044E0
_0809ABDC: .4byte 0x00020004
_0809ABE0: .4byte 0x03004864
_0809ABE4:
	bl FUN_082416bc
_0809ABE8:
	movs r0, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _0809AC10 @ =0x03004864
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809AC18
	ldr r2, _0809AC14 @ =0x0000F001
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x90
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x20
	adds r0, r2, #0
	b _0809AC26
	.align 2, 0
_0809AC10: .4byte 0x03004864
_0809AC14: .4byte 0x0000F001
_0809AC18:
	ldr r2, _0809AC2C @ =0x0000F091
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x1f
	adds r0, r2, #0
	strh r0, [r1]
_0809AC26:
	strh r0, [r1, #2]
	pop {r0}
	bx r0
	.align 2, 0
_0809AC2C: .4byte 0x0000F091
