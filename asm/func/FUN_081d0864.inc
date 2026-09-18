	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _081D092C @ =0x03000188
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D0886
	bl Entity081d0e20_Create
	mov sl, r0
	cmp r0, #0
	bne _081D0886
	b _081D0B6C
_081D0886:
	mov r0, sl
	bl Entity081d0e20_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _081D0894
	b _081D0B6C
_081D0894:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r5, #0
	adds r1, #0x80
	str r1, [sp, #0x10]
	cmp r0, #0
	beq _081D08C8
	bl Script_GetValue
	ldr r2, [sp, #0x10]
	strh r0, [r2]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x82
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x84
	strh r0, [r1]
_081D08C8:
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r5, #0
	adds r4, #0x88
	strh r0, [r4]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x8a
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
	str r4, [sp, #0x14]
	adds r7, r5, #0
	adds r7, #0x8c
	movs r1, #0xb0
	adds r1, r1, r5
	mov r8, r1
	movs r2, #0x1c
	add r2, sl
	mov sb, r2
	adds r1, r5, #0
	adds r1, #0x70
	str r1, [sp, #0x28]
	adds r2, r5, #0
	adds r2, #0xbb
	str r2, [sp, #0x24]
	adds r1, #0x4a
	str r1, [sp, #0x20]
	subs r2, #3
	str r2, [sp, #0x1c]
	subs r1, #8
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _081D093A
	adds r6, r5, #0
	adds r6, #0x90
	movs r4, #5
_081D091E:
	bl VM_GetPC
	cmp r0, #0
	beq _081D0930
	bl Script_GetValue
	b _081D0932
	.align 2, 0
_081D092C: .4byte 0x03000188
_081D0930:
	movs r0, #0
_081D0932:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D091E
_081D093A:
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D096C
	adds r6, r5, #0
	adds r6, #0xa8
	movs r4, #1
_081D0954:
	bl VM_GetPC
	cmp r0, #0
	beq _081D0962
	bl Script_GetValue
	b _081D0964
_081D0962:
	movs r0, #0
_081D0964:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081D0954
_081D096C:
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	mov r2, r8
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _081D0984
	movs r1, #4
_081D0984:
	mov r0, r8
	strh r1, [r0]
	adds r7, r5, #0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r1, _081D09AC @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r5, #0x1c]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D09B0
	cmp r0, #1
	beq _081D09C0
	b _081D09C8
	.align 2, 0
_081D09AC: .4byte 0xFFFFFF00
_081D09B0:
	ldr r1, _081D09BC @ =0x00000282
	mov r0, sb
	bl Video_SetAuxSpritePltt
	b _081D09C8
	.align 2, 0
_081D09BC: .4byte 0x00000282
_081D09C0:
	ldr r1, _081D0A14 @ =0x00000283
	mov r0, sb
	bl Video_SetAuxSpritePltt
_081D09C8:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_0822a470
	mov r2, sl
	ldr r1, [r2, #0x18]
	mov r0, r8
	ldrb r3, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	movs r2, #0
	bl FUN_08236fac
	ldr r4, [sp, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x70]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0A18
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D0A20
	.align 2, 0
_081D0A14: .4byte 0x00000283
_081D0A18:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D0A20:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0A44
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D0A4C
_081D0A44:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D0A4C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D0A84 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0ABC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D0A88
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D0A7C
	ldrb r0, [r4, #5]
_081D0A7C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D0A98
	.align 2, 0
_081D0A84: .4byte 0x0000FFFF
_081D0A88:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D0A98
	strh r1, [r4, #8]
_081D0A98:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D0ABC
	movs r0, #1
	strb r0, [r4, #7]
_081D0ABC:
	ldr r0, [r7]
	movs r2, #1
	orrs r0, r2
	str r0, [r7]
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	ldr r0, [sp, #0x24]
	strb r1, [r0]
	ldr r0, [sp, #0x20]
	strb r1, [r0]
	ldr r1, [sp, #0x1c]
	strh r2, [r1]
	movs r0, #0x6f
	movs r1, #0x3c
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D0B1E
	ldr r1, [sp, #0x1c]
	ldrh r0, [r1]
	movs r1, #0x10
	orrs r0, r1
	ldr r2, [sp, #0x1c]
	strh r0, [r2]
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D0B0C
	cmp r0, #1
	beq _081D0B16
	b _081D0B1E
_081D0B0C:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081d0838
	b _081D0B1E
_081D0B16:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081d0718
_081D0B1E:
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	bl FUN_081ee9bc
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D0B6C
	ldr r0, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #8
	orrs r0, r1
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x10]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
_081D0B6C:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
