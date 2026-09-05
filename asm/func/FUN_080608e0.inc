	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08060940
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08060938 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0806093C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _0806094A
	.align 2, 0
_08060938: .4byte 0xFFFF0000
_0806093C: .4byte 0x0000FFFF
_08060940:
	ldr r1, _0806098C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_0806094A:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08060994
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0806098C @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08060990 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r5, r2, #0
	b _080609A2
	.align 2, 0
_0806098C: .4byte 0xFFFF0000
_08060990: .4byte 0x0000FFFF
_08060994:
	ldr r2, _080609B8 @ =0xFFFF0000
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r5, r1, #0
_080609A2:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080609BC
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	b _080609C2
	.align 2, 0
_080609B8: .4byte 0xFFFF0000
_080609BC:
	movs r4, #0x18
	movs r0, #0x80
	lsls r0, r0, #1
_080609C2:
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	add r2, sp, #8
	adds r3, r5, #0
	bl FUN_080607ec
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
