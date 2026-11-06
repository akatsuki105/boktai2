	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	str r0, [sp, #0x2c]
	adds r4, r3, #0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	ldr r2, [sp, #0x68]
	subs r1, r2, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	ldr r3, [sp, #0x68]
	cmp sl, r3
	blt _081F5838
	b _081F5994
_081F5838:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x34]
	add r7, sp, #0xc
	mov sb, r7
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x38]
	add r2, sp, #0x1c
	mov r8, r2
	mov r3, sp
	adds r3, #0x24
	str r3, [sp, #0x40]
_081F5852:
	adds r4, r0, #1
	ldr r7, [sp, #0x30]
	adds r5, r7, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _081F5898 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _081F589C
	asrs r0, r0, #0xa
	b _081F58A2
	.align 2, 0
_081F5898: .4byte 0x05000002
_081F589C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081F58A2:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081F58B0
	asrs r1, r0, #0xa
	b _081F58B6
_081F58B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F58B6:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F58F4
	asrs r1, r0, #0xa
	b _081F58FA
_081F58F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F58FA:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F5934
	asrs r1, r0, #0xa
	b _081F593A
_081F5934:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F593A:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081F596C
	asrs r1, r0, #0xa
	b _081F5972
_081F596C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F5972:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl Entity081f73ec_SetSegPos
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _081F5994
	b _081F5852
_081F5994:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
