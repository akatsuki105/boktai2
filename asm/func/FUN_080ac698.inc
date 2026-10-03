	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AC6AE
	bl VM_GetValue
	adds r5, r0, #0
	b _080AC6B0
_080AC6AE:
	movs r5, #0
_080AC6B0:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AC6F8
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080AC6F0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080AC6F4 @ =0x0000FFFF
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
	b _080AC702
	.align 2, 0
_080AC6F0: .4byte 0xFFFF0000
_080AC6F4: .4byte 0x0000FFFF
_080AC6F8:
	ldr r1, _080AC71C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080AC702:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AC720
	bl VM_GetValue
	adds r4, r0, #0
	bl VM_GetValue
	adds r3, r0, #0
	b _080AC724
	.align 2, 0
_080AC71C: .4byte 0xFFFF0000
_080AC720:
	movs r4, #0x10
	movs r3, #0
_080AC724:
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_080ac60c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
