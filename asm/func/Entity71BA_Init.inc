	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strb r0, [r5, #0x1d]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A063C
	bl VM_GetValue
	b _080A063E
_080A063C:
	movs r0, #9
_080A063E:
	strb r0, [r5, #0x1c]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0688
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A0680 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A0684 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _080A0692
	.align 2, 0
_080A0680: .4byte 0xFFFF0000
_080A0684: .4byte 0x0000FFFF
_080A0688:
	ldr r1, _080A06C0 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A0692:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A06BA
	cmp r1, #0
	blt _080A06BA
	ldr r0, _080A06C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A06BA
	ldr r0, _080A06C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A06CC
_080A06BA:
	movs r0, #0
	b _080A06DA
	.align 2, 0
_080A06C0: .4byte 0xFFFF0000
_080A06C4: .4byte 0x030046A8
_080A06C8: .4byte 0x030046AC
_080A06CC:
	ldr r0, _080A0704 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A06DA:
	strh r0, [r5, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A06F4
	bl VM_GetValue
_080A06F4:
	str r0, [r5, #0x34]
	ldrb r1, [r5, #0x1c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A070C
	ldr r0, _080A0708 @ =FUN_080a01d8
	b _080A071E
	.align 2, 0
_080A0704: .4byte 0x030046A4
_080A0708: .4byte FUN_080a01d8
_080A070C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A071C
	ldr r0, _080A0718 @ =FUN_080a035c
	b _080A071E
	.align 2, 0
_080A0718: .4byte FUN_080a035c
_080A071C:
	ldr r0, _080A072C @ =Entity71BA_UpdateTileOverride
_080A071E:
	str r0, [r5, #0x38]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A072C: .4byte Entity71BA_UpdateTileOverride
