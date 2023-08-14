	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r5, #0
_082426F6:
	adds r0, r5, #0
	bl GetNormalItemID
	adds r4, r0, #0
	adds r7, r5, #1
	cmp r4, #0
	blt _082427CE
	ldr r0, _08242734 @ =0x08DAA8D8
	lsls r1, r4, #4
	adds r6, r1, r0
	ldrh r0, [r6, #4]
	cmp r0, #0
	beq _082427CE
	adds r0, r5, #0
	bl GetRotCount2
	mov r2, r8
	adds r1, r0, r2
	ldr r0, _08242738 @ =0x00007FFF
	cmp r1, r0
	ble _08242722
	adds r1, r0, #0
_08242722:
	ldrh r0, [r6, #4]
	lsls r0, r0, #5
	cmp r1, r0
	bge _0824273C
	adds r0, r5, #0
	bl SetRotCount2
	b _082427CE
	.align 2, 0
_08242734: .4byte 0x08DAA8D8
_08242738: .4byte 0x00007FFF
_0824273C:
	cmp r4, #0x12
	beq _08242758
	adds r0, r4, #0
	bl GetRottenItemID
	adds r1, r0, #0
	adds r0, r5, #0
	bl SetItem
	adds r0, r5, #0
	movs r1, #0
	bl SetRotCount
	b _082427CE
_08242758:
	adds r0, r5, #0
	bl RemoveItem
	movs r6, #0
	adds r4, r5, #4
	cmp r4, #0xf
	bgt _082427C0
_08242766:
	adds r0, r4, #0
	bl GetNormalItemID
	adds r1, r0, #0
	cmp r1, #0
	blt _082427B6
	subs r0, #0x12
	cmp r0, #1
	bhi _0824277E
	adds r0, r4, #0
	movs r1, #0x15
	b _082427A0
_0824277E:
	cmp r1, #4
	bne _08242788
	adds r0, r4, #0
	movs r1, #5
	b _082427A0
_08242788:
	cmp r1, #0x15
	beq _0824279A
	cmp r1, #5
	beq _0824279A
	adds r0, r4, #0
	bl IsChocolateCovered
	cmp r0, #0
	beq _082427AE
_0824279A:
	subs r4, #4
	adds r0, r4, #0
	movs r1, #0x13
_082427A0:
	bl SetItem
	adds r0, r4, #0
	movs r1, #0
	bl SetRotCount
	b _082427B4
_082427AE:
	adds r0, r4, #0
	bl CoverChocolate
_082427B4:
	movs r6, #1
_082427B6:
	adds r4, #4
	cmp r6, #0
	bne _082427CE
	cmp r4, #0xf
	ble _08242766
_082427C0:
	cmp r6, #0
	bne _082427CE
	subs r4, #4
	adds r0, r4, #0
	movs r1, #0x13
	bl SetItem
_082427CE:
	adds r5, r7, #0
	cmp r5, #0xf
	ble _082426F6
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
