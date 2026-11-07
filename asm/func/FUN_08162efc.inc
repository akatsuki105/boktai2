	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08162F14 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162F18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162F1A
	.align 2, 0
_08162F14: .4byte 0x0000046D
_08162F18:
	movs r0, #0
_08162F1A:
	cmp r0, #0
	beq _08162F38
	adds r0, r5, #0
	movs r1, #0x12
	bl Enemy_PlayAnimNoFacing
	ldr r2, _08162F94 @ =0x00000482
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_08162F38:
	ldr r6, _08162F98 @ =0x0000046E
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162F8C
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08162F9C @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	subs r6, #4
	adds r0, r5, r6
	strb r1, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	ldr r4, _08162FA0 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08162FA4 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
_08162F8C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08162F94: .4byte 0x00000482
_08162F98: .4byte 0x0000046E
_08162F9C: .4byte 0x00000469
_08162FA0: .4byte Enemy_ClearStateBegun
_08162FA4: .4byte 0x0000046B
