	push {r4, lr}
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080795E2
	cmp r1, #0
	blt _080795E2
	ldr r0, _080795E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080795E2
	ldr r0, _080795EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080795F0
_080795E2:
	movs r4, #0
	b _080795FE
	.align 2, 0
_080795E8: .4byte 0x030046A8
_080795EC: .4byte 0x030046AC
_080795F0:
	ldr r0, _08079610 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080795FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08079614
	adds r0, #4
	b _08079620
	.align 2, 0
_08079610: .4byte 0x030046A4
_08079614:
	ldr r0, _08079638 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079620:
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0807963C
	adds r0, r1, #0
	bl FUN_08065ad0
	cmp r0, #0
	bne _0807963C
	movs r0, #0
	b _0807963E
	.align 2, 0
_08079638: .4byte 0x030046A4
_0807963C:
	movs r0, #1
_0807963E:
	pop {r4}
	pop {r1}
	bx r1
