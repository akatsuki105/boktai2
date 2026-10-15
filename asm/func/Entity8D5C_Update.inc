	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _080557D4 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080557E8
	movs r0, #0x40
	ands r1, r0
	movs r4, #1
	cmp r1, #0
	beq _080557B4
	subs r4, #2
_080557B4:
	ldr r0, [r5, #0x2c]
	cmp r0, r4
	bne _080557D8
	ldr r0, [r5, #0x28]
	subs r0, #1
	str r0, [r5, #0x28]
	cmp r0, #0
	bge _080557EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity8D5C_MoveSelection
	movs r0, #4
	str r0, [r5, #0x28]
	b _080557EA
	.align 2, 0
_080557D4: .4byte 0x030044E0
_080557D8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity8D5C_MoveSelection
	movs r0, #0x14
	str r0, [r5, #0x28]
	str r4, [r5, #0x2c]
	b _080557EA
_080557E8:
	str r0, [r5, #0x2c]
_080557EA:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08055804
_080557F4:
	ldr r4, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #1
	bl Entity8D5C_MoveSelection
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bne _080557F4
_08055804:
	ldrh r1, [r6, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805581C
	ldr r0, [r5, #0x20]
	movs r1, #0
	bl VM_ExecByID
	adds r0, r5, #0
	bl KillEntity
_0805581C:
	bl FUN_0823d4c8
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
