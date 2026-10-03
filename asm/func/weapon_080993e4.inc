	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08099404
	b _08099534
_08099404:
	ldr r4, _08099464 @ =0x030046A0
	ldr r0, [r4]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x63
	bl MinS32
	movs r5, #0
	str r5, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #3
	bl FUN_0808b30c
	ldr r0, [r4]
	ldr r0, [r0, #0x50]
	ldr r7, _08099468 @ =0x000F423F
	adds r1, r7, #0
	bl MinS32
	ldr r1, _0809946C @ =0x000186A0
	mov r8, r1
	str r5, [sp]
	movs r2, #0x17
	movs r3, #4
	bl FUN_0808b30c
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x62
	ble _08099474
	movs r0, #0
	movs r1, #0x17
	movs r2, #5
	bl FUN_0808a420
	ldr r3, _08099470 @ =0x0000F0BC
	adds r1, r3, #0
	movs r4, #5
_08099458:
	strh r1, [r0]
	adds r0, #2
	subs r4, #1
	cmp r4, #0
	bge _08099458
	b _0809948C
	.align 2, 0
_08099464: .4byte 0x030046A0
_08099468: .4byte 0x000F423F
_0809946C: .4byte 0x000186A0
_08099470: .4byte 0x0000F0BC
_08099474:
	adds r0, r6, #0
	bl weapon_080993c4
	adds r1, r7, #0
	bl MinS32
	str r5, [sp]
	mov r1, r8
	movs r2, #0x17
	movs r3, #5
	bl FUN_0808b30c
_0809948C:
	movs r4, #0
_0809948E:
	movs r5, #0
	cmp r4, #0
	bne _080994B4
	ldr r0, _080994B0 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _080994D6
	bl GetWeaponKind
	cmp r0, #0
	bne _080994D6
	b _080994DA
	.align 2, 0
_080994B0: .4byte 0x030046A0
_080994B4:
	subs r0, r4, #1
	cmp r0, #1
	bhi _080994D4
	ldr r0, _080994D0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080994D6
	b _080994DA
	.align 2, 0
_080994D0: .4byte 0x030046A0
_080994D4:
	movs r5, #1
_080994D6:
	cmp r5, #0
	beq _08099502
_080994DA:
	adds r0, r4, #0
	bl GetWeaponSkillLevel
	movs r1, #0x63
	bl MinS32
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #2
	adds r2, r2, r1
	adds r2, #0x14
	asrs r3, r4, #1
	adds r3, #8
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	bl FUN_0808b30c
	adds r1, r4, #1
	b _08099528
_08099502:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, #0x12
	asrs r2, r4, #1
	adds r2, #8
	movs r0, #0
	bl FUN_0808a420
	adds r1, r4, #1
	ldr r3, _08099530 @ =0x0000F001
	adds r2, r3, #0
	movs r4, #1
_0809951E:
	strh r2, [r0]
	adds r0, #2
	subs r4, #1
	cmp r4, #0
	bge _0809951E
_08099528:
	adds r4, r1, #0
	cmp r4, #4
	ble _0809948E
	b _0809959E
	.align 2, 0
_08099530: .4byte 0x0000F001
_08099534:
	ldr r0, _080995AC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0xa
	movs r1, #0x63
	bl MinS32
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #3
	bl FUN_0808b30c
	movs r0, #6
	movs r1, #0x17
	movs r2, #4
	bl FUN_0808b360
	movs r0, #6
	movs r1, #0x17
	movs r2, #5
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x14
	movs r2, #8
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x19
	movs r2, #8
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x14
	movs r2, #9
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x19
	movs r2, #9
	bl FUN_0808b360
	str r4, [sp]
	movs r0, #0x63
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0xa
	bl FUN_0808b30c
_0809959E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080995AC: .4byte 0x030046A0
