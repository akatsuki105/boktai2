	push {lr}
	ldr r1, _0807A4D8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	beq _0807A4DC
	ldrh r0, [r0, #6]
	b _0807A51A
	.align 2, 0
_0807A4D8: .4byte 0x03002BE0
_0807A4DC:
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A500
	cmp r1, #0
	blt _0807A500
	ldr r0, _0807A504 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A500
	ldr r0, _0807A508 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A50C
_0807A500:
	movs r0, #0
	b _0807A51A
	.align 2, 0
_0807A504: .4byte 0x030046A8
_0807A508: .4byte 0x030046AC
_0807A50C:
	ldr r0, _0807A520 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0807A51A:
	pop {r1}
	bx r1
	.align 2, 0
_0807A520: .4byte 0x030046A4
