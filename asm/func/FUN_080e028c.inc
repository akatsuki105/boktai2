	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080E030C
	bl VM_GetPC
	cmp r0, #0
	beq _080E02B0
	bl Script_GetValue
	b _080E02B2
_080E02B0:
	movs r0, #0
_080E02B2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080E02D0 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	bl VM_GetPC
	cmp r0, #0
	beq _080E02D4
	bl Script_GetValue
	b _080E02D6
	.align 2, 0
_080E02D0: .4byte 0xFFFF0000
_080E02D4:
	movs r0, #0
_080E02D6:
	lsls r2, r0, #0x10
	ldr r1, _080E02F0 @ =0x0000FFFF
	ldr r0, [sp, #0x1c]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	bl VM_GetPC
	cmp r0, #0
	beq _080E02F4
	bl Script_GetValue
	b _080E02F6
	.align 2, 0
_080E02F0: .4byte 0x0000FFFF
_080E02F4:
	movs r0, #0
_080E02F6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080E0308 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	b _080E0316
	.align 2, 0
_080E0308: .4byte 0xFFFF0000
_080E030C:
	ldr r1, _080E034C @ =0xFFFF0000
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r1
	str r0, [sp, #0x20]
_080E0316:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x24]
	movs r0, #0x73
	movs r1, #0x14
	bl VM_GetKeywordValue
	str r0, [sp, #0x28]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x68
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080E0378
	bl VM_GetPC
	cmp r0, #0
	beq _080E0350
	bl Script_GetValue
	b _080E0352
	.align 2, 0
_080E034C: .4byte 0xFFFF0000
_080E0350:
	movs r0, #0
_080E0352:
	mov sb, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080E0364
	bl Script_GetValue
	mov r8, r0
	b _080E0368
_080E0364:
	movs r1, #0
	mov r8, r1
_080E0368:
	bl VM_GetPC
	cmp r0, #0
	beq _080E037E
	bl Script_GetValue
	adds r7, r0, #0
	b _080E0380
_080E0378:
	movs r0, #0
	mov sb, r0
	mov r8, r0
_080E037E:
	movs r7, #0
_080E0380:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080E03CE
	bl VM_GetPC
	cmp r0, #0
	beq _080E039A
	bl Script_GetValue
	adds r6, r0, #0
	b _080E039C
_080E039A:
	movs r6, #0
_080E039C:
	bl VM_GetPC
	cmp r0, #0
	beq _080E03AC
	bl Script_GetValue
	adds r5, r0, #0
	b _080E03AE
_080E03AC:
	movs r5, #0
_080E03AE:
	bl VM_GetPC
	cmp r0, #0
	beq _080E03BE
	bl Script_GetValue
	adds r4, r0, #0
	b _080E03C0
_080E03BE:
	movs r4, #0
_080E03C0:
	bl VM_GetPC
	cmp r0, #0
	beq _080E03D4
	bl Script_GetValue
	b _080E03D6
_080E03CE:
	movs r6, #0
	movs r5, #0
	movs r4, #0
_080E03D4:
	movs r0, #0
_080E03D6:
	str r7, [sp]
	ldr r1, [sp, #0x28]
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	ldr r1, [sp, #0x24]
	mov r2, sb
	mov r3, r8
	bl FUN_080dfeb0
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
