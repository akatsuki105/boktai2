	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6468
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A6460 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A6464 @ =0x0000FFFF
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
	b _080A6472
	.align 2, 0
_080A6460: .4byte 0xFFFF0000
_080A6464: .4byte 0x0000FFFF
_080A6468:
	ldr r1, _080A6484 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A6472:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6488
	bl VM_GetValue
	adds r5, r0, #0
	b _080A648A
	.align 2, 0
_080A6484: .4byte 0xFFFF0000
_080A6488:
	movs r5, #0
_080A648A:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A649C
	bl VM_GetValue
	adds r4, r0, #0
	b _080A649E
_080A649C:
	movs r4, #0
_080A649E:
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A64B0
	bl VM_GetValue
	adds r2, r0, #0
	b _080A64B2
_080A64B0:
	movs r2, #0
_080A64B2:
	asrs r1, r4, #1
	adds r1, #1
	movs r0, #3
	ands r1, r0
	mov r0, sp
	adds r3, r5, #0
	bl Map_AddLoadingZoneIndicator
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
