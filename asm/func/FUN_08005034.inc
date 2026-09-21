	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6e
	adds r1, r4, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800510A
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080050D0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080050D4 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #8
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080050CC
	cmp r1, #0
	blt _080050CC
	ldr r0, _080050D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080050CC
	ldr r0, _080050DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080050E0
_080050CC:
	movs r2, #0
	b _080050EE
	.align 2, 0
_080050D0: .4byte 0xFFFF0000
_080050D4: .4byte 0x0000FFFF
_080050D8: .4byte 0x030046A8
_080050DC: .4byte 0x030046AC
_080050E0:
	ldr r0, _080050FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_080050EE:
	add r0, sp, #8
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08005100
	asrs r0, r0, #8
	b _08005106
	.align 2, 0
_080050FC: .4byte 0x030046A4
_08005100:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08005106:
	adds r1, r0, #0
	b _0800510E
_0800510A:
	adds r1, r4, #0
	adds r2, r1, #0
_0800510E:
	str r2, [sp]
	str r1, [sp, #4]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl Entity08004fac_SetNodeParamsById
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
