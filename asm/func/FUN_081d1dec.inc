	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, _081D1E64 @ =0x03000190
	ldr r0, [r0]
	cmp r0, #0
	bne _081D1E0A
	bl Entity081d2180_Create
	cmp r0, #0
	bne _081D1E0A
	b _081D209C
_081D1E0A:
	bl FUN_081d1a9c
	adds r6, r0, #0
	cmp r6, #0
	bne _081D1E16
	b _081D209C
_081D1E16:
	adds r1, r6, #0
	adds r1, #0x7e
	movs r0, #1
	strh r0, [r1]
	mov sl, r6
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1E3C
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D1E3C:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sl
	adds r1, #0x48
	strh r0, [r1]
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1E86
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E68
	bl Script_GetValue
	adds r1, r0, #0
	b _081D1E6A
	.align 2, 0
_081D1E64: .4byte 0x03000190
_081D1E68:
	movs r1, #0
_081D1E6A:
	adds r0, r6, #0
	adds r0, #0x4c
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D1E7E
	bl Script_GetValue
	b _081D1E80
_081D1E7E:
	movs r0, #0
_081D1E80:
	adds r1, r6, #0
	adds r1, #0x4e
	strh r0, [r1]
_081D1E86:
	movs r0, #0x53
	bl VM_SeekToKeyword
	adds r7, r6, #0
	adds r7, #0x4a
	movs r1, #0x2c
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0x80
	adds r2, r2, r6
	mov sb, r2
	adds r3, r6, #0
	adds r3, #0x84
	str r3, [sp, #0x10]
	adds r5, r6, #0
	adds r5, #0x86
	str r5, [sp, #0x14]
	mov r1, sl
	adds r1, #0x1c
	str r1, [sp, #0x18]
	adds r2, r6, #0
	adds r2, #0x58
	str r2, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0xc]
	subs r5, #4
	str r5, [sp, #8]
	cmp r0, #0
	beq _081D1EDC
	subs r5, #0x26
	movs r4, #3
_081D1EC4:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1ED2
	bl Script_GetValue
	b _081D1ED4
_081D1ED2:
	movs r0, #0
_081D1ED4:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EC4
_081D1EDC:
	movs r0, #0x57
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D1F04
	adds r5, r6, #0
	adds r5, #0x6c
	movs r4, #3
_081D1EEC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D1EFA
	bl Script_GetValue
	b _081D1EFC
_081D1EFA:
	movs r0, #0
_081D1EFC:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D1EEC
_081D1F04:
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	movs r5, #0
	movs r4, #0
	strh r0, [r7]
	ldrh r1, [r7]
	mov r0, r8
	bl Video_GetAuxSprite
	mov r0, sb
	strh r4, [r0]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081D1F38
	mov r1, sb
	ldrh r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, sb
	strh r0, [r2]
	b _081D1F42
_081D1F38:
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	strh r0, [r3]
_081D1F42:
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _081D1F58
	mov r5, sb
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
_081D1F58:
	mov r0, sl
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _081D1F84
	movs r0, #1
	mov r1, sl
	strh r0, [r1, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D1F90
_081D1F84:
	mov r2, sl
	strh r0, [r2, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081D1F9C @ =0x0000011F
	bl Video_SetAuxSpritePltt
_081D1F90:
	bl FUN_0823b3ec
	cmp r0, #0
	bne _081D1FD0
	b _081D203C
	.align 2, 0
_081D1F9C: .4byte 0x0000011F
_081D1FA0:
	ldrh r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #2
	orrs r0, r1
	ldr r1, _081D1FCC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r3]
	mov r0, ip
	ldr r5, [sp, #0x10]
	strh r0, [r5]
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D203C
	.align 2, 0
_081D1FCC: .4byte 0x0000FFFE
_081D1FD0:
	bl FUN_0823b3ec
	ldr r4, [r0, #0x18]
	cmp r4, #0
	beq _081D203C
	mov r7, sp
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
_081D1FE2:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp r0, #0
	bne _081D2036
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, r8
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, r8
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsrs r3, r0, #0x10
	cmp r2, r0
	bhi _081D2036
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D2036
	cmp r0, #0
	blt _081D2036
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D2036
	cmp r0, #0
	bge _081D1FA0
_081D2036:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1FE2
_081D203C:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0
	ldr r2, [sp, #0x14]
	strh r0, [r2]
	ldr r3, [sp, #0x10]
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	bl FUN_08241574
	ldr r5, [sp, #0x1c]
	strh r0, [r5]
	ldr r0, _081D2070 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r2, [r5]
	cmp r0, r2
	bne _081D2074
	movs r0, #1
	b _081D2076
	.align 2, 0
_081D2070: .4byte 0x030046A0
_081D2074:
	movs r0, #0
_081D2076:
	cmp r0, #0
	bne _081D2086
	mov r3, sl
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	b _081D2092
_081D2086:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_081D2092:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	ldr r2, [sp, #8]
	strb r0, [r2]
_081D209C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
