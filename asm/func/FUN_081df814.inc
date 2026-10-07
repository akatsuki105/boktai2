	push {r4, lr}
	sub sp, #8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081DF860
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081DF858 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _081DF85C @ =0x0000FFFF
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
	b _081DF86A
	.align 2, 0
_081DF858: .4byte 0xFFFF0000
_081DF85C: .4byte 0x0000FFFF
_081DF860:
	ldr r1, _081DF88C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_081DF86A:
	movs r0, #0x74
	movs r1, #4
	bl VM_GetNamedArgValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	bne _081DF890
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df698
	b _081DF898
	.align 2, 0
_081DF88C: .4byte 0xFFFF0000
_081DF890:
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df64c
_081DF898:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
