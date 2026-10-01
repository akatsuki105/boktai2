	push {r4, r5, r6, lr}
	sub sp, #0x18
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetTilemapFile
	adds r5, r0, #0
	mov r1, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [sp, #0xc]
	adds r0, r0, r5
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, r0, r5
	str r0, [sp, #0x14]
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000E4A
	bl VM_GetPC
	cmp r0, #0
	beq _08000E4A
	bl VM_GetValueAt
	b _08000E74
_08000E4A:
	movs r4, #0
	movs r0, #0
	cmp r0, #0
	bne _08000E78
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000E78
	bl VM_GetPC
	cmp r0, #0
	beq _08000E78
	bl VM_GetValueAt
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sp
	bl FUN_08000c84
_08000E74:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08000E78:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Video_SetBGLayer
	adds r0, r4, #0
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
