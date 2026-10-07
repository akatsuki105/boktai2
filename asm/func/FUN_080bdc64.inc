	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BDC98 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BDD4E
	adds r0, r5, #0
	bl FUN_080bd83c
	adds r4, r0, #0
	ldr r1, _080BDC9C @ =0x000017B4
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BDCBC
	cmp r4, #4
	bgt _080BDCA0
	cmp r4, #1
	beq _080BDCA6
	b _080BDD44
	.align 2, 0
_080BDC98: .4byte 0x030044E0
_080BDC9C: .4byte 0x000017B4
_080BDCA0:
	cmp r4, #5
	beq _080BDCFC
	b _080BDD44
_080BDCA6:
	adds r0, r5, #0
	bl FUN_080bd47c
	ldr r1, _080BDCB8 @ =Entity744F_SwapSelectedWeapon
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD62
	.align 2, 0
_080BDCB8: .4byte Entity744F_SwapSelectedWeapon
_080BDCBC:
	ldr r0, _080BDCEC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDCF0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDCF4 @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDCF8 @ =FUN_080bde60
	b _080BDD28
	.align 2, 0
_080BDCEC: .4byte 0x00000107
_080BDCF0: .4byte 0x00001644
_080BDCF4: .4byte 0x000015D8
_080BDCF8: .4byte FUN_080bde60
_080BDCFC:
	ldr r0, _080BDD34 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDD38 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #1
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDD3C @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BDD40 @ =FUN_080bdf94
_080BDD28:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD92
	.align 2, 0
_080BDD34: .4byte 0x00000107
_080BDD38: .4byte 0x00001644
_080BDD3C: .4byte 0x000015D8
_080BDD40: .4byte FUN_080bdf94
_080BDD44:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDD62
_080BDD4E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BDD68
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bd964
_080BDD62:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BDD92
_080BDD68:
	ldr r0, _080BDDB4 @ =0x00001784
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BDD92
	ldr r0, _080BDDB8 @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
_080BDD92:
	ldr r1, _080BDDB4 @ =0x00001784
	adds r0, r5, r1
	ldr r1, _080BDDBC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BDDB8 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BDDB4: .4byte 0x00001784
_080BDDB8: .4byte 0x00000EB8
_080BDDBC: .4byte 0x00000C78
