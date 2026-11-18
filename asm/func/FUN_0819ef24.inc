	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	movs r2, #1
	mov sb, r2
	ands r0, r2
	cmp r0, #0
	beq _0819EF4A
	b _0819F134
_0819EF4A:
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r3, _0819EFD0 @ =0x00000E46
	adds r1, r7, r3
	ldrh r1, [r1]
	bl Mod
	mov ip, r0
	cmp r0, #0
	beq _0819EF64
	b _0819F134
_0819EF64:
	mov r6, r8
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	ldr r0, _0819EFD4 @ =0x00000E44
	adds r4, r7, r0
	ldrh r0, [r4]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #5
	ldr r5, _0819EFD8 @ =0x0000073C
	adds r0, r3, r5
	adds r0, r7, r0
	adds r0, #0x48
	ldr r6, _0819EFDC @ =0x00000794
	adds r1, r7, r6
	adds r1, r1, r3
	ldr r1, [r1]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r6, r0, r7
	adds r6, r6, r5
	adds r4, r0, r7
	ldr r0, _0819EFE0 @ =0x00000784
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0819EFE4
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0819EFEC
	.align 2, 0
_0819EFD0: .4byte 0x00000E46
_0819EFD4: .4byte 0x00000E44
_0819EFD8: .4byte 0x0000073C
_0819EFDC: .4byte 0x00000794
_0819EFE0: .4byte 0x00000784
_0819EFE4:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819EFEC:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819F010
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0819F018
_0819F010:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0819F018:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0819F050 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0819F088
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819F054
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0819F048
	ldrb r0, [r4, #5]
_0819F048:
	subs r0, #1
	strh r0, [r4, #8]
	b _0819F064
	.align 2, 0
_0819F050: .4byte 0x0000FFFF
_0819F054:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0819F064
	strh r1, [r4, #8]
_0819F064:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _0819F088
	movs r0, #1
	strb r0, [r4, #7]
_0819F088:
	ldr r3, _0819F144 @ =0x00000E44
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r2, r7, r6
	adds r2, r2, r0
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	subs r6, #0x1c
	adds r3, r7, r6
	adds r0, r3, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, r3, r0
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	strh r1, [r0]
	mov r3, r8
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #6]
	adds r6, #6
	adds r0, r0, r6
	strb r1, [r0]
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #8]
	ldr r2, _0819F148 @ =0x00000744
	adds r0, r0, r2
	strb r1, [r0]
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #9]
	ldr r3, _0819F14C @ =0x00000745
	adds r0, r0, r3
	strb r1, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0819F134
	movs r0, #0
	strh r0, [r4]
_0819F134:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F144: .4byte 0x00000E44
_0819F148: .4byte 0x00000744
_0819F14C: .4byte 0x00000745
