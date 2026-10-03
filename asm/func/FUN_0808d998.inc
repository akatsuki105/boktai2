	push {lr}
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _0808D9C4 @ =0x00000D98
	adds r1, r0, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x68
	muls r1, r2, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl Player_ApplyWeapon
	pop {r0}
	bx r0
	.align 2, 0
_0808D9C4: .4byte 0x00000D98
