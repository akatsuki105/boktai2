	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0
	str r1, [r6, #0x20]
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x22
	strb r1, [r0]
	ldr r2, _0820E8E8 @ =0x0000110C
	adds r0, r6, r2
	movs r2, #0
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0x49
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x4a
	strb r2, [r0]
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E8E0
	bl FUN_0823d340
	ldr r7, _0820E8EC @ =0x00001110
	adds r1, r6, r7
	str r0, [r1]
	cmp r0, #0
	bne _0820E8F0
_0820E8E0:
	movs r0, #1
	rsbs r0, r0, #0
	b _0820EAA8
	.align 2, 0
_0820E8E8: .4byte 0x0000110C
_0820E8EC: .4byte 0x00001110
_0820E8F0:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x28
	movs r7, #5
_0820E8F8:
	movs r0, #3
	adds r1, r7, #0
	movs r2, #0x17
	movs r3, #2
	bl TextPanel_Create
	str r0, [r4]
	ldr r2, _0820EAB0 @ =0x00001110
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #0
	bl TextPanel_SetMessage
	ldm r4!, {r0}
	bl TextPanel_Hide
	adds r7, #2
	adds r5, #1
	cmp r5, #7
	ble _0820E8F8
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E94C
	bl FUN_0823d34c
	bl VM_SetPC
	movs r4, #0
	ldr r7, _0820EAB4 @ =0x00001114
	adds r5, r6, r7
_0820E93E:
	bl Script_GetValue
	adds r1, r5, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0x38
	ble _0820E93E
_0820E94C:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E996
	bl FUN_0823d34c
	adds r2, r0, #0
	ldr r0, _0820EAB8 @ =0x00001150
	adds r0, r0, r6
	mov ip, r0
	adds r5, r6, #0
	movs r4, #0x38
	ldr r1, _0820EABC @ =0x00001151
	adds r3, r6, r1
_0820E96A:
	ldrb r0, [r2]
	mov r7, ip
	strb r0, [r7]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r3]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r3, #1]
	adds r2, #1
	ldrb r1, [r2]
	ldr r7, _0820EAC0 @ =0x00001153
	adds r0, r5, r7
	strb r1, [r0]
	adds r2, #1
	movs r0, #4
	add ip, r0
	adds r3, #4
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _0820E96A
_0820E996:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9AA
	bl FUN_0823d340
	ldr r2, _0820EAC4 @ =0x00001234
	adds r1, r6, r2
	str r0, [r1]
_0820E9AA:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9BE
	bl FUN_0823d340
	ldr r7, _0820EAC8 @ =0x0000123C
	adds r1, r6, r7
	str r0, [r1]
_0820E9BE:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9D2
	bl FUN_0823d340
	ldr r2, _0820EACC @ =0x00001238
	adds r1, r6, r2
	str r0, [r1]
_0820E9D2:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9E8
	bl FUN_0823d340
	movs r7, #0x92
	lsls r7, r7, #5
	adds r1, r6, r7
	str r0, [r1]
_0820E9E8:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9FC
	bl FUN_0823d340
	ldr r2, _0820EAD0 @ =0x00001244
	adds r1, r6, r2
	str r0, [r1]
_0820E9FC:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA10
	bl FUN_0823d340
	ldr r7, _0820EAD4 @ =0x00001248
	adds r1, r6, r7
	str r0, [r1]
_0820EA10:
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA24
	bl FUN_0823d340
	ldr r2, _0820EAD8 @ =0x0000124C
	adds r1, r6, r2
	str r0, [r1]
_0820EA24:
	movs r0, #0x75
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA38
	bl FUN_0823d340
	ldr r7, _0820EADC @ =0x00001250
	adds r1, r6, r7
	str r0, [r1]
_0820EA38:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA4C
	bl FUN_0823d340
	ldr r2, _0820EAE0 @ =0x00001254
	adds r1, r6, r2
	str r0, [r1]
_0820EA4C:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r7, _0820EAE4 @ =0x00001258
	adds r1, r6, r7
	str r0, [r1]
	ldr r0, _0820EAE8 @ =0x0000110E
	adds r1, r6, r0
	movs r4, #0
	movs r0, #5
	strh r0, [r1]
	bl FUN_08049e5c
	movs r0, #0
	movs r1, #0
	bl EntityC946_Create
	ldr r2, _0820EAEC @ =0x0000125C
	adds r1, r6, r2
	str r0, [r1]
	bl FUN_0820fea8
	adds r0, r6, #0
	bl FUN_0820d6e4
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0820e080
	movs r0, #4
	str r0, [sp]
	ldr r0, _0820EAF0 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0
_0820EAA8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820EAB0: .4byte 0x00001110
_0820EAB4: .4byte 0x00001114
_0820EAB8: .4byte 0x00001150
_0820EABC: .4byte 0x00001151
_0820EAC0: .4byte 0x00001153
_0820EAC4: .4byte 0x00001234
_0820EAC8: .4byte 0x0000123C
_0820EACC: .4byte 0x00001238
_0820EAD0: .4byte 0x00001244
_0820EAD4: .4byte 0x00001248
_0820EAD8: .4byte 0x0000124C
_0820EADC: .4byte 0x00001250
_0820EAE0: .4byte 0x00001254
_0820EAE4: .4byte 0x00001258
_0820EAE8: .4byte 0x0000110E
_0820EAEC: .4byte 0x0000125C
_0820EAF0: .4byte 0x0000FFFF
