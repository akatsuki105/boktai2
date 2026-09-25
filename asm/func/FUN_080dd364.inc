	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0
	mov sb, r0
	mov sl, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	add r1, sp, #0x10
	mov r8, r1
	cmp r0, #0
	beq _080DD3E8
	bl VM_GetPC
	cmp r0, #0
	beq _080DD392
	bl Script_GetValue
	b _080DD394
_080DD392:
	movs r0, #0
_080DD394:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD3B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3B4
	bl Script_GetValue
	b _080DD3B6
	.align 2, 0
_080DD3B0: .4byte 0xFFFF0000
_080DD3B4:
	movs r0, #0
_080DD3B6:
	lsls r2, r0, #0x10
	ldr r1, _080DD3D0 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3D4
	bl Script_GetValue
	b _080DD3D6
	.align 2, 0
_080DD3D0: .4byte 0x0000FFFF
_080DD3D4:
	movs r0, #0
_080DD3D6:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD400 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	mov r8, r1
_080DD3E8:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD41C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD404
	bl Script_GetValue
	b _080DD406
	.align 2, 0
_080DD400: .4byte 0xFFFF0000
_080DD404:
	movs r0, #0
_080DD406:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD418
	bl Script_GetValue
	mov sb, r0
	b _080DD41C
_080DD418:
	movs r1, #0
	mov sb, r1
_080DD41C:
	movs r0, #0x76
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD490
	bl VM_GetPC
	cmp r0, #0
	beq _080DD434
	bl Script_GetValue
	b _080DD436
_080DD434:
	movs r0, #0
_080DD436:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD454 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD458
	bl Script_GetValue
	b _080DD45A
	.align 2, 0
_080DD454: .4byte 0xFFFF0000
_080DD458:
	movs r0, #0
_080DD45A:
	lsls r2, r0, #0x10
	ldr r1, _080DD474 @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD478
	bl Script_GetValue
	b _080DD47A
	.align 2, 0
_080DD474: .4byte 0x0000FFFF
_080DD478:
	movs r0, #0
_080DD47A:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD48C @ =0xFFFF0000
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	b _080DD49A
	.align 2, 0
_080DD48C: .4byte 0xFFFF0000
_080DD490:
	ldr r2, _080DD4F4 @ =0xFFFF0000
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
_080DD49A:
	str r0, [r1, #4]
	adds r7, r1, #0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	add r4, sp, #0x20
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r4, #0
	ldr r2, _080DD4F8 @ =0x05000002
	bl CpuSet
	mov r0, sb
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	mov r3, sl
	bl FUN_080dce8c
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r1, #1
	orrs r1, r2
	strh r1, [r0]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD4F4: .4byte 0xFFFF0000
_080DD4F8: .4byte 0x05000002
