	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081EA8D4 @ =0x030001C0
	ldr r4, [r0]
	ldrb r1, [r5, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081EA892
	b _081EA9E0
_081EA892:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081EA8DC
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _081EA8DC
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA8D8 @ =0x085AE478
	ldrb r2, [r0, #0x12]
_081EA8C4:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl MainSprite_SetAnim
	b _081EAA04
	.align 2, 0
_081EA8D4: .4byte 0x030001C0
_081EA8D8: .4byte 0x085AE478
_081EA8DC:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081EA900
	ldr r0, _081EA938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081EA900
	movs r0, #0xd4
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081EA900:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _081EA940
	adds r3, #8
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081EA940
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _081EA93C @ =0x085AE478
	movs r4, #0x95
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r4, #0
	ldrsh r2, [r2, r4]
	adds r0, r0, r2
	adds r0, r0, r3
	ldrb r2, [r0]
	b _081EA8C4
	.align 2, 0
_081EA938: .4byte 0x030047A4
_081EA93C: .4byte 0x085AE478
_081EA940:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r2, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne _081EA9C4
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	ldr r3, _081EA9BC @ =0x0000052C
	adds r2, r4, r3
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl MainSprite_Remove
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r4, r0
	adds r6, r5, #0
	adds r6, #0x60
	cmp r4, #0
	beq _081EA9A4
	adds r0, r6, #0
	bl FUN_08002a58
_081EA9A4:
	adds r0, r6, #0
	bl FUN_0823b284
	ldr r0, _081EA9C0 @ =0x0000FFFF
	strh r0, [r7]
	movs r2, #0x99
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #1
	b _081EAA06
	.align 2, 0
_081EA9BC: .4byte 0x0000052C
_081EA9C0: .4byte 0x0000FFFF
_081EA9C4:
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA9DC @ =0x085AE478
	adds r0, r2, r0
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl MainSprite_SetAnim
	b _081EA9EA
	.align 2, 0
_081EA9DC: .4byte 0x085AE478
_081EA9E0:
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	bl MainSprite_AdvanceAnim
_081EA9EA:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #1
	bne _081EAA04
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_081EAA04:
	movs r0, #0
_081EAA06:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
