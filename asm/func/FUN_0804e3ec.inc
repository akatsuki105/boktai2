	push {lr}
	ldr r0, _0804E414 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E426
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E41C
	ldrh r0, [r1, #0x38]
	cmp r0, #4
	bls _0804E426
	ldr r0, _0804E418 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0804E426
	b _0804E430
	.align 2, 0
_0804E414: .4byte 0x03002B58
_0804E418: .4byte 0x03005800
_0804E41C:
	ldr r0, _0804E42C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E430
_0804E426:
	movs r0, #0
	b _0804E432
	.align 2, 0
_0804E42C: .4byte 0x03005800
_0804E430:
	movs r0, #1
_0804E432:
	pop {r1}
	bx r1
	.align 2, 0
