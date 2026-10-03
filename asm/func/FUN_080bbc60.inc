	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BBCCC @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BBCD0 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BBCD4 @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BBCD8 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BBCE4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BBCDC @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBCAC
	b _080BBEE2
_080BBCAC:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BBCE0 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BBCC6
	b _080BBEE2
_080BBCC6:
	movs r0, #0
	strb r0, [r1]
	b _080BBEE2
	.align 2, 0
_080BBCCC: .4byte 0x00001408
_080BBCD0: .4byte 0x00000C78
_080BBCD4: .4byte 0x00000C18
_080BBCD8: .4byte 0x030044E0
_080BBCDC: .4byte 0x00000D98
_080BBCE0: .4byte 0x0000151A
_080BBCE4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r3, _080BBD50 @ =0x00000D98
	adds r4, r5, r3
	movs r0, #0x18
	adds r0, r0, r5
	mov r8, r0
	adds r0, r4, #0
	mov r1, r8
	bl MainSprite_AdvanceAnim
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBD0A
	b _080BBEBC
_080BBD0A:
	ldr r1, _080BBD54 @ =0x0000140B
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BBD70
	ldr r0, _080BBD58 @ =0x00000107
	bl PlaySound_082406e0
	ldr r2, _080BBD5C @ =0x000012E4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r3, _080BBD60 @ =0x00001278
	adds r0, r5, r3
	ldr r1, _080BBD64 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BBD68 @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BBD6C @ =FUN_080bc07c
	b _080BBEAE
	.align 2, 0
_080BBD50: .4byte 0x00000D98
_080BBD54: .4byte 0x0000140B
_080BBD58: .4byte 0x00000107
_080BBD5C: .4byte 0x000012E4
_080BBD60: .4byte 0x00001278
_080BBD64: .4byte 0x000012EF
_080BBD68: .4byte 0x00001438
_080BBD6C: .4byte FUN_080bc07c
_080BBD70:
	ldr r3, _080BBDC4 @ =0x00001409
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BBE18
	movs r7, #1
	ldrb r0, [r4]
	adds r0, r5, r0
	ldr r1, _080BBDC8 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	blt _080BBDBA
	ldr r0, _080BBDCC @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r1, r1, r2
	ldr r2, _080BBDD0 @ =0x08DAA7B0
	lsls r0, r3, #3
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _080BBDBA
	ldr r3, _080BBDD4 @ =0x000012F2
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BBDB6
	movs r7, #0
_080BBDB6:
	cmp r7, #0
	bne _080BBDD8
_080BBDBA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BBEE2
	.align 2, 0
_080BBDC4: .4byte 0x00001409
_080BBDC8: .4byte 0x000012F4
_080BBDCC: .4byte 0x030046A0
_080BBDD0: .4byte 0x08DAA7B0
_080BBDD4: .4byte 0x000012F2
_080BBDD8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE10 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE14 @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE10: .4byte 0x00000E18
_080BBE14: .4byte 0x00000DB8
_080BBE18:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE88 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE8C @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r2, [r4]
	ldr r0, _080BBE90 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	beq _080BBE7A
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _080BBE7A
	ldr r0, _080BBE94 @ =0x08DAA7B0
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080BBE9C
_080BBE7A:
	ldr r1, _080BBE98 @ =0x00001408
	adds r0, r5, r1
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE88: .4byte 0x00000E18
_080BBE8C: .4byte 0x00000DB8
_080BBE90: .4byte 0x030046A0
_080BBE94: .4byte 0x08DAA7B0
_080BBE98: .4byte 0x00001408
_080BBE9C:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BBEA4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
	ldr r1, _080BBEB8 @ =FUN_080bbeec
_080BBEAE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BBEE2
	.align 2, 0
_080BBEB8: .4byte FUN_080bbeec
_080BBEBC:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BBEE2
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	bl FUN_080bb5bc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bb8f4
_080BBEE2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
