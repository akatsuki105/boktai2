	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x9c
	movs r0, #0x74
	movs r1, #0
	bl VM_GetNamedArgValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x73
	movs r1, #0
	bl VM_GetNamedArgValue
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08000F54 @ =0x0000CEEF
	adds r1, r4, #0
	bl GetFile
	mov r8, r0
	movs r6, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000F58
	movs r5, #0
	add r4, sp, #4
_08000F38:
	cmp r5, #0x3f
	bgt _08000F68
	bl VM_GetPC
	cmp r0, #0
	beq _08000F68
	bl VM_GetValueAt
	strh r0, [r4]
	adds r6, #1
	adds r4, #2
	adds r5, #1
	b _08000F38
	.align 2, 0
_08000F54: .4byte 0x0000CEEF
_08000F58:
	movs r1, #0
	mov r0, sp
	adds r0, #0x82
_08000F5E:
	strh r1, [r0]
	subs r0, #2
	add r2, sp, #4
	cmp r0, r2
	bge _08000F5E
_08000F68:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000F8C
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetTilemapFile
	add r2, sp, #0x84
	adds r1, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldrh r7, [r2, #0xa]
_08000F8C:
	str r7, [sp]
	mov r0, sb
	mov r1, r8
	adds r2, r6, #0
	add r3, sp, #4
	bl FUN_0822bc44
	movs r0, #0
	add sp, #0x9c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
