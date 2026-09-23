	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r1, [r7, #0x18]
	strh r0, [r7, #0x2e]
	strh r0, [r7, #0x1a]
	movs r0, #0x65
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r0, #0
	str r1, [r7, #0x34]
	cmp r1, #0
	beq _08021CF0
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x82
	lsls r1, r1, #3
	adds r4, r7, r1
	str r0, [r4]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CAC @ =0x00000414
	adds r2, r2, r7
	mov sb, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x83
	lsls r1, r1, #3
	adds r1, r1, r7
	mov sl, r1
	str r0, [r1]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB0 @ =0x0000041C
	adds r2, r2, r7
	mov r8, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x84
	lsls r1, r1, #3
	adds r6, r7, r1
	str r0, [r6]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB4 @ =0x00000424
	adds r5, r7, r2
	str r0, [r5]
	movs r0, #0x8c
	bl Malloc
	adds r1, r0, #0
	movs r0, #0x85
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp]
	str r1, [r0]
	ldr r4, [r4]
	cmp r4, #0
	beq _08021C9E
	mov r2, sb
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, sl
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r6]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r5]
	cmp r0, #0
	beq _08021C9E
	cmp r1, #0
	bne _08021CB8
_08021C9E:
	adds r0, r7, #0
	bl KillEntity
_08021CA4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08022058
	.align 2, 0
_08021CAC: .4byte 0x00000414
_08021CB0: .4byte 0x0000041C
_08021CB4: .4byte 0x00000424
_08021CB8:
	adds r0, r4, #0
	movs r1, #0x8c
	bl ClearMemory
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	mov r2, r8
	ldr r0, [r2]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r6]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r5]
	movs r1, #0x8c
	bl ClearMemory
	ldr r1, [sp]
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	b _08021D1C
_08021CF0:
	movs r2, #0x82
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
_08021D1C:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021D58
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D2C:
	bl VM_GetPC
	cmp r0, #0
	beq _08021D3E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021D40
_08021D3E:
	ldr r1, _08021D54 @ =0x00007ACD
_08021D40:
	adds r0, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D2C
	b _08021D72
	.align 2, 0
_08021D54: .4byte 0x00007ACD
_08021D58:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D5E:
	adds r0, r4, #0
	ldr r1, _08021D9C @ =0x00007ACD
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D5E
_08021D72:
	movs r0, #0x6b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021E40
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0
_08021D88:
	bl VM_GetPC
	cmp r0, #0
	beq _08021DA0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021DA2
	.align 2, 0
_08021D9C: .4byte 0x00007ACD
_08021DA0:
	ldr r4, _08021E30 @ =0x00007AD3
_08021DA2:
	mov r0, r8
	adds r1, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021DB0
	b _08021CA4
_08021DB0:
	ldr r0, [r7, #0x34]
	cmp r0, #0
	beq _08021E20
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	ldr r2, _08021E34 @ =0x00000414
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	ldr r2, _08021E38 @ =0x0000041C
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	ldr r2, _08021E3C @ =0x00000424
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl Video_GetAuxSprite
_08021E20:
	movs r2, #0x1c
	add r8, r2
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D88
	b _08021E5E
	.align 2, 0
_08021E30: .4byte 0x00007AD3
_08021E34: .4byte 0x00000414
_08021E38: .4byte 0x0000041C
_08021E3C: .4byte 0x00000424
_08021E40:
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r7, r0
_08021E48:
	adds r0, r4, #0
	ldr r1, _08021E7C @ =0x00007AD3
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021E56
	b _08021CA4
_08021E56:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E48
_08021E5E:
	movs r0, #0x53
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021EA4
	bl VM_GetPC
	cmp r0, #0
	beq _08021E80
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _08021E82
	.align 2, 0
_08021E7C: .4byte 0x00007AD3
_08021E80:
	ldr r6, _08021EA0 @ =0x00007AD2
_08021E82:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021E88:
	adds r0, r4, #0
	adds r1, r6, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021E96
	b _08021CA4
_08021E96:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E88
	b _08021EC0
	.align 2, 0
_08021EA0: .4byte 0x00007AD2
_08021EA4:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021EAA:
	adds r0, r4, #0
	ldr r1, _08021EEC @ =0x00007AD2
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021EB8
	b _08021CA4
_08021EB8:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EAA
_08021EC0:
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021F20
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r6, r7, r2
_08021EDA:
	bl VM_GetPC
	cmp r0, #0
	beq _08021EF0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021EF2
	.align 2, 0
_08021EEC: .4byte 0x00007AD2
_08021EF0:
	ldr r4, _08021F1C @ =0x00007AEE
_08021EF2:
	adds r0, r6, #0
	adds r1, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021F00
	b _08021CA4
_08021F00:
	mov r0, r8
	adds r1, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021F0E
	b _08021CA4
_08021F0E:
	movs r0, #0x1c
	add r8, r0
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EDA
	b _08021F54
	.align 2, 0
_08021F1C: .4byte 0x00007AEE
_08021F20:
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r6, r7, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r4, r7, r2
_08021F2E:
	adds r0, r4, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021F3C
	b _08021CA4
_08021F3C:
	adds r0, r6, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021F4A
	b _08021CA4
_08021F4A:
	adds r6, #0x1c
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F2E
_08021F54:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021F98
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r4, r7, r0
_08021F66:
	bl VM_GetPC
	cmp r0, #0
	beq _08021F7C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021F7E
	.align 2, 0
_08021F78: .4byte 0x00007AD3
_08021F7C:
	ldr r1, _08021F94 @ =0x00007AF3
_08021F7E:
	adds r0, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021F8A
	b _08021CA4
_08021F8A:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F66
	b _08021FB6
	.align 2, 0
_08021F94: .4byte 0x00007AF3
_08021F98:
	movs r5, #0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r4, r7, r1
_08021FA0:
	adds r0, r4, #0
	ldr r1, _08021FDC @ =0x00007AF3
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021FAE
	b _08021CA4
_08021FAE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FA0
_08021FB6:
	movs r0, #0x75
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08021FFC
	movs r5, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r4, r7, r2
_08021FC8:
	bl VM_GetPC
	cmp r0, #0
	beq _08021FE0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021FE2
	.align 2, 0
_08021FDC: .4byte 0x00007AF3
_08021FE0:
	ldr r1, _08021FF8 @ =0x00007AF3
_08021FE2:
	adds r0, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08021FEE
	b _08021CA4
_08021FEE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FC8
	b _0802201A
	.align 2, 0
_08021FF8: .4byte 0x00007AF3
_08021FFC:
	movs r5, #0
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r4, r7, r0
_08022004:
	adds r0, r4, #0
	ldr r1, _08022068 @ =0x00007AF3
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08022012
	b _08021CA4
_08022012:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08022004
_0802201A:
	movs r0, #0x6d
	movs r1, #0x10
	bl VM_GetKeywordValue
	str r0, [r7, #0x30]
	movs r4, #0x8c
	muls r0, r4, r0
	bl Malloc
	ldr r2, _0802206C @ =0x0000042C
	adds r1, r7, r2
	str r0, [r1]
	ldr r1, [r7, #0x30]
	muls r1, r4, r1
	bl ClearMemory
	adds r1, r7, #0
	adds r1, #0x1e
	movs r2, #0
	adds r0, r7, #0
	adds r0, #0x24
_08022044:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08022044
	ldr r0, _08022070 @ =0x000085E6
	adds r1, r7, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
_08022058:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08022068: .4byte 0x00007AF3
_0802206C: .4byte 0x0000042C
_08022070: .4byte 0x000085E6
