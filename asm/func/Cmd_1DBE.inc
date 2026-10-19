	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	ldr r0, _0809FFB0 @ =0x03000144
	ldr r6, [r0]
	cmp r6, #0
	bne _0809FF9A
	bl Entity1DBE_Create
	adds r6, r0, #0
_0809FF9A:
	ldrh r0, [r6, #0x18]
	cmp r0, #7
	bhi _080A0074
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809FFB4
	bl VM_GetValue
	b _0809FFB6
	.align 2, 0
_0809FFB0: .4byte 0x03000144
_0809FFB4:
	movs r0, #0
_0809FFB6:
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0000
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809FFF8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809FFFC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _080A000A
	.align 2, 0
_0809FFF8: .4byte 0xFFFF0000
_0809FFFC: .4byte 0x0000FFFF
_080A0000:
	ldr r1, _080A001C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_080A000A:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0020
	bl VM_GetValue
	adds r7, r0, #0
	b _080A0022
	.align 2, 0
_080A001C: .4byte 0xFFFF0000
_080A0020:
	movs r7, #0
_080A0022:
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0034
	bl VM_GetValue
	adds r5, r0, #0
	b _080A0036
_080A0034:
	movs r5, #0
_080A0036:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0048
	bl VM_GetValue
	adds r4, r0, #0
	b _080A004A
_080A0048:
	movs r4, #0
_080A004A:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A005A
	bl VM_GetValue
	b _080A005C
_080A005A:
	movs r0, #0
_080A005C:
	str r5, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	mov r1, r8
	add r2, sp, #0xc
	adds r3, r7, #0
	bl Entity1DBE_AddElem
	ldrh r0, [r6, #0x18]
	adds r0, #1
	strh r0, [r6, #0x18]
_080A0074:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
