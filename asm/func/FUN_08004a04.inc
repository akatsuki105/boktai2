	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x4d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08004A48
	bl Script_GetValue
	cmp r0, #0
	beq _08004A48
	movs r0, #0x10
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_08004A48:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08004A90
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08004A88 @ =0xFFFF0000
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08004A8C @ =0x0000FFFF
	ldr r1, [sp, #0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	b _08004A9A
	.align 2, 0
_08004A88: .4byte 0xFFFF0000
_08004A8C: .4byte 0x0000FFFF
_08004A90:
	ldr r1, _08004AA8 @ =0xFFFF0000
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	ands r0, r1
	str r0, [sp, #0x1c]
_08004A9A:
	cmp r7, #0
	beq _08004AEC
	cmp r7, #1
	bne _08004AB0
	ldr r1, _08004AAC @ =0x000084EE
	b _08004AEE
	.align 2, 0
_08004AA8: .4byte 0xFFFF0000
_08004AAC: .4byte 0x000084EE
_08004AB0:
	cmp r7, #2
	bne _08004ABC
	ldr r1, _08004AB8 @ =0x00009D40
	b _08004AEE
	.align 2, 0
_08004AB8: .4byte 0x00009D40
_08004ABC:
	cmp r7, #3
	bne _08004AC8
	ldr r1, _08004AC4 @ =0x00009D43
	b _08004AEE
	.align 2, 0
_08004AC4: .4byte 0x00009D43
_08004AC8:
	cmp r7, #4
	bne _08004AD4
	ldr r1, _08004AD0 @ =0x00002097
	b _08004AEE
	.align 2, 0
_08004AD0: .4byte 0x00002097
_08004AD4:
	cmp r7, #5
	bne _08004AE0
	ldr r1, _08004ADC @ =0x000005A2
	b _08004AEE
	.align 2, 0
_08004ADC: .4byte 0x000005A2
_08004AE0:
	cmp r7, #6
	bne _08004AEC
	ldr r1, _08004AE8 @ =0x0000B306
	b _08004AEE
	.align 2, 0
_08004AE8: .4byte 0x0000B306
_08004AEC:
	ldr r1, _08004B14 @ =0x00009D41
_08004AEE:
	movs r0, #0x61
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0x80
	bl VM_GetKeywordValue
	mov sl, r0
	cmp r7, #0
	bne _08004B1C
	ldr r5, _08004B18 @ =0x0000023D
	b _08004B6A
	.align 2, 0
_08004B14: .4byte 0x00009D41
_08004B18: .4byte 0x0000023D
_08004B1C:
	cmp r7, #1
	bne _08004B28
	ldr r5, _08004B24 @ =0x00000241
	b _08004B6A
	.align 2, 0
_08004B24: .4byte 0x00000241
_08004B28:
	cmp r7, #2
	beq _08004B38
	cmp r7, #3
	bne _08004B34
	movs r5, #0x4f
	b _08004B6A
_08004B34:
	cmp r7, #4
	bne _08004B40
_08004B38:
	ldr r5, _08004B3C @ =0x000001FD
	b _08004B6A
	.align 2, 0
_08004B3C: .4byte 0x000001FD
_08004B40:
	cmp r7, #5
	bne _08004B48
	movs r5, #0x8b
	b _08004B6A
_08004B48:
	cmp r7, #6
	bne _08004B5E
	mov r0, r8
	cmp r0, #0
	beq _08004B56
	cmp r0, #2
	bne _08004B5A
_08004B56:
	movs r5, #2
	b _08004B6A
_08004B5A:
	movs r5, #3
	b _08004B6A
_08004B5E:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl VM_GetKeywordValue
	adds r5, r0, #0
_08004B6A:
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	str r6, [sp]
	mov r1, r8
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	mov r2, sb
	add r3, sp, #0x18
	bl FUN_080046c8
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
