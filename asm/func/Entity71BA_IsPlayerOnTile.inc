	push {lr}
	adds r3, r0, #0
	ldr r0, _080A00B0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A00AC
	cmp r1, #0
	blt _080A00AC
	ldr r0, _080A00B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A00AC
	ldr r0, _080A00B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A00BC
_080A00AC:
	movs r0, #0
	b _080A00CA
	.align 2, 0
_080A00B0: .4byte 0x03002BE0
_080A00B4: .4byte 0x030046A8
_080A00B8: .4byte 0x030046AC
_080A00BC:
	ldr r0, _080A00D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A00CA:
	ldrh r3, [r3, #0x1e]
	cmp r0, r3
	beq _080A00D8
	movs r0, #0
	b _080A00DA
	.align 2, 0
_080A00D4: .4byte 0x030046A4
_080A00D8:
	movs r0, #1
_080A00DA:
	pop {r1}
	bx r1
	.align 2, 0
