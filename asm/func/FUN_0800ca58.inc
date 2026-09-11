	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x6c
	movs r1, #0x64
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #1
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800CABC
	add r5, sp, #0x1c
	add r4, sp, #0xc
_0800CAA4:
	bl VM_GetPC
	cmp r0, #0
	beq _0800CAB0
	bl Script_GetValue
_0800CAB0:
	str r0, [r4]
	adds r4, #4
	add r0, sp, #0x18
	cmp r4, r0
	ble _0800CAA4
	b _0800CACC
_0800CABC:
	add r5, sp, #0x1c
	movs r1, #0
	add r0, sp, #0x18
_0800CAC2:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0xc
	cmp r0, r2
	bge _0800CAC2
_0800CACC:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800CB14
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800CB0C @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800CB10 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r5, #4]
	b _0800CB1E
	.align 2, 0
_0800CB0C: .4byte 0xFFFF0000
_0800CB10: .4byte 0x0000FFFF
_0800CB14:
	ldr r1, _0800CB68 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	ldr r0, [r5, #4]
	ands r0, r1
	str r0, [r5, #4]
_0800CB1E:
	ldr r0, _0800CB6C @ =0xFFFFFF00
	adds r4, r0, #0
	ldrh r1, [r5]
	ands r1, r4
	movs r0, #0x80
	orrs r1, r0
	ldr r3, _0800CB68 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r2, [r0, #4]
	ands r2, r4
	movs r1, #0x80
	orrs r2, r1
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	str r7, [sp]
	str r6, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_0800c820
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CB68: .4byte 0xFFFF0000
_0800CB6C: .4byte 0xFFFFFF00
