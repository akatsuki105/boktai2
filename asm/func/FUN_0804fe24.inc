	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0804FE64 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	blt _0804FE5E
	movs r0, #3
_0804FE44:
	subs r0, #1
	cmp r0, #0
	bge _0804FE44
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, #0
	beq _0804FE5E
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x70]
	bics r0, r1
	str r0, [r5, #0x70]
_0804FE5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE64: .4byte 0x030046A0
