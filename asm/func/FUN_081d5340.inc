	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5388 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D53C2
	cmp r1, #0
	beq _081D53C2
	adds r0, r1, #0
	bl Elevator_FindByID
	adds r6, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D53AA
	bl VM_GetPC
	cmp r0, #0
	beq _081D538C
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _081D538E
	.align 2, 0
_081D5388: .4byte 0x03000194
_081D538C:
	movs r1, #0
_081D538E:
	adds r7, r1, #0
	movs r1, #0
	mov r8, r1
	bl VM_GetPC
	cmp r0, #0
	beq _081D53A6
	bl VM_GetValue
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _081D53A8
_081D53A6:
	movs r3, #0
_081D53A8:
	adds r5, r3, #0
_081D53AA:
	adds r4, r6, #0
	adds r4, #0xe8
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_08234de8
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
_081D53C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
