	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	movs r1, #0
	str r1, [sp, #0x30]
	cmp r0, #1
	bne _080B1B90
	movs r2, #1
	str r2, [sp, #0x30]
_080B1B90:
	movs r0, #0x67
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080B1BA4
	movs r3, #0x64
	str r3, [sp, #0x28]
	movs r4, #0
	str r4, [sp, #0x2c]
	b _080B1BB0
_080B1BA4:
	bl VM_GetValue
	str r0, [sp, #0x28]
	bl VM_GetValue
	str r0, [sp, #0x2c]
_080B1BB0:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080B1BE0
	movs r7, #0
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	bge _080B1C04
	movs r0, #0
	add r2, sp, #0x10
	ldr r1, _080B1BDC @ =0x00000BE8
	add r1, r8
_080B1BCC:
	stm r1!, {r0}
	stm r2!, {r0}
	adds r7, #1
	mov r3, r8
	ldrb r3, [r3, #0x1e]
	cmp r7, r3
	blt _080B1BCC
	b _080B1C04
	.align 2, 0
_080B1BDC: .4byte 0x00000BE8
_080B1BE0:
	movs r7, #0
	mov r4, r8
	ldrb r4, [r4, #0x1e]
	cmp r7, r4
	bge _080B1C04
	add r5, sp, #0x10
	ldr r4, _080B1C38 @ =0x00000BE8
	add r4, r8
_080B1BF0:
	movs r0, #0
	stm r4!, {r0}
	bl VM_GetValue
	stm r5!, {r0}
	adds r7, #1
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	blt _080B1BF0
_080B1C04:
	movs r7, #0
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	blt _080B1C10
	b _080B1D48
_080B1C10:
	ldr r2, _080B1C3C @ =0xFFFFFDFE
	mov sl, r2
	add r5, sp, #0x20
	ldr r3, _080B1C40 @ =0xFFFF0000
	mov sb, r3
_080B1C1A:
	movs r0, #0xa0
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	cmp r7, #1
	beq _080B1CD4
	cmp r7, #1
	bgt _080B1C44
	cmp r7, #0
	beq _080B1C4E
	b _080B1D08
	.align 2, 0
_080B1C38: .4byte 0x00000BE8
_080B1C3C: .4byte 0xFFFFFDFE
_080B1C40: .4byte 0xFFFF0000
_080B1C44:
	cmp r7, #2
	beq _080B1C7A
	cmp r7, #3
	beq _080B1CA6
	b _080B1D08
_080B1C4E:
	ldrh r1, [r5]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	mov ip, r0
	movs r6, #0
	movs r2, #6
	b _080B1D10
_080B1C7A:
	ldrh r1, [r5]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r2, sb
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r3, #1
	mov ip, r3
	movs r6, #1
	movs r2, #3
	b _080B1D10
_080B1CA6:
	ldrh r1, [r5]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	ldr r0, _080B1CD0 @ =0x00000202
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	mov ip, r1
	b _080B1D0C
	.align 2, 0
_080B1CD0: .4byte 0x00000202
_080B1CD4:
	ldrh r1, [r5]
	ldr r2, _080B1D04 @ =0x00000202
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0
	mov ip, r4
	movs r6, #1
	movs r2, #9
	b _080B1D10
	.align 2, 0
_080B1D04: .4byte 0x00000202
_080B1D08:
	movs r0, #0
	mov ip, r0
_080B1D0C:
	movs r6, #0
	movs r2, #0
_080B1D10:
	add r1, sp, #0x20
	lsls r4, r7, #2
	mov r0, sp
	adds r0, r0, r4
	adds r0, #0x10
	ldr r3, [r0]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r1, #0
	mov r1, ip
	adds r2, r6, #0
	bl Generator_Create
	ldr r1, _080B1D58 @ =0x00000BE8
	add r1, r8
	adds r1, r1, r4
	str r0, [r1]
	adds r7, #1
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	bge _080B1D48
	b _080B1C1A
_080B1D48:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1D58: .4byte 0x00000BE8
