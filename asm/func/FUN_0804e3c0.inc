	push {lr}
	ldr r0, _0804E3D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E3D4
	ldr r0, _0804E3DC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E3E0
_0804E3D4:
	movs r0, #0
	b _0804E3E6
	.align 2, 0
_0804E3D8: .4byte 0x03002B58
_0804E3DC: .4byte 0x03005800
_0804E3E0:
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
_0804E3E6:
	pop {r1}
	bx r1
	.align 2, 0
