	push {r4, r5, r6, lr}
	bl FUN_080d7bac
	ldr r1, _080D7F98 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _080D7FB4
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080D7FB4
	bl Script_GetValue
	adds r6, r0, #0
	ldr r0, _080D7F9C @ =0x00000455
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080D7F82
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl FUN_081df9ac
_080D7F82:
	strb r6, [r4]
	movs r2, #0
	ldrsb r2, [r4, r2]
	ldr r0, _080D7FA0 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _080D7F94
	cmp r2, #0
	bge _080D7FA4
_080D7F94:
	movs r1, #0
	b _080D7FAE
	.align 2, 0
_080D7F98: .4byte 0x03002BE0
_080D7F9C: .4byte 0x00000455
_080D7FA0: .4byte 0x03002C68
_080D7FA4:
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0x88
	adds r1, r1, r0
_080D7FAE:
	adds r0, r5, #0
	bl player_weapon_080ceafc
_080D7FB4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
