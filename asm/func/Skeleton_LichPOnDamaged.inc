	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x21
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	ldr r0, _08112DCC @ =0x00008002
	ands r0, r2
	cmp r0, #0
	beq _08112DE0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	bne _08112D7A
	b _08112E78
_08112D7A:
	ldr r5, _08112DD0 @ =0x03002BE0
	ldr r0, [r5]
	adds r0, #0x2c
	bl Entity081f9cb8_ExistsAt
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08112E78
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08112DD4 @ =0x00000546
	adds r0, r4, r3
	movs r6, #0x3c
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08112DA2
	movs r6, #0x28
_08112DA2:
	ldr r0, [r5]
	adds r0, #0x2c
	ldr r5, _08112DD8 @ =0x0000022A
	adds r1, r4, r5
	ldrh r2, [r1]
	ldr r3, _08112DDC @ =0x00000232
	adds r1, r4, r3
	ldrh r3, [r1]
	adds r5, #0x1e
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp]
	subs r5, #0xe
	adds r1, r4, r5
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	bl Entity081f9cb8_Spawn
	b _08112E78
	.align 2, 0
_08112DCC: .4byte 0x00008002
_08112DD0: .4byte 0x03002BE0
_08112DD4: .4byte 0x00000546
_08112DD8: .4byte 0x0000022A
_08112DDC: .4byte 0x00000232
_08112DE0:
	ldr r1, _08112DF4 @ =0x000006FC
	adds r0, r5, r1
	movs r1, #1
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08112DF8
	movs r0, #1
	b _08112DFA
	.align 2, 0
_08112DF4: .4byte 0x000006FC
_08112DF8:
	movs r0, #0
_08112DFA:
	cmp r0, #0
	bne _08112E4C
	ldr r5, _08112E68 @ =0x03002BE0
	ldr r0, [r5]
	adds r0, #0x2c
	bl Entity081f9cb8_ExistsAt
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08112E4C
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r2, _08112E6C @ =0x00000546
	adds r0, r4, r2
	movs r6, #0x3c
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08112E26
	movs r6, #0x28
_08112E26:
	ldr r0, [r5]
	adds r0, #0x2c
	ldr r3, _08112E70 @ =0x0000022A
	adds r1, r4, r3
	ldrh r2, [r1]
	ldr r5, _08112E74 @ =0x00000232
	adds r1, r4, r5
	ldrh r3, [r1]
	adds r5, #0x16
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp]
	subs r5, #0xe
	adds r1, r4, r5
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	bl Entity081f9cb8_Spawn
_08112E4C:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08112E78
	adds r0, r4, #0
	bl Skeleton_LichPSelectAction
	movs r0, #1
	b _08112E7A
	.align 2, 0
_08112E68: .4byte 0x03002BE0
_08112E6C: .4byte 0x00000546
_08112E70: .4byte 0x0000022A
_08112E74: .4byte 0x00000232
_08112E78:
	movs r0, #0
_08112E7A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
