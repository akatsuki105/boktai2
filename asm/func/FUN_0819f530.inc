	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov sb, r1
	ldr r7, [r0, #0x44]
	ldr r3, _0819F5B4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x78
	orrs r0, r2
	ldr r1, _0819F5B8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	add r6, sp, #0xc
	ldr r0, [r6, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r6, #4]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r4, sp, #0x14
	movs r5, #0
	str r5, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _0819F5BC @ =0x05000002
	bl CpuSet
	add r0, sp, #0x1c
	mov r8, r0
	str r5, [sp, #8]
	add r0, sp, #8
	mov r1, r8
	ldr r2, _0819F5BC @ =0x05000002
	bl CpuSet
	ldr r0, _0819F5C0 @ =0x0000FF74
	strh r0, [r4]
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r3, [r4, r1]
	ldr r2, _0819F5C4 @ =gSineTable
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	mov sl, r6
	adds r6, r4, #0
	mov ip, r8
	cmp r0, #0
	blt _0819F5C8
	asrs r0, r0, #0xc
	b _0819F5CE
	.align 2, 0
_0819F5B4: .4byte 0xFFFF0000
_0819F5B8: .4byte 0x0000FFFF
_0819F5BC: .4byte 0x05000002
_0819F5C0: .4byte 0x0000FF74
_0819F5C4: .4byte gSineTable
_0819F5C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F5CE:
	adds r5, r0, #0
	movs r3, #4
	ldrsh r2, [r6, r3]
	ldr r1, _0819F5EC @ =gSineTable
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	mov r8, r1
	cmp r0, #0
	blt _0819F5F0
	asrs r0, r0, #0xc
	b _0819F5F6
	.align 2, 0
_0819F5EC: .4byte gSineTable
_0819F5F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F5F6:
	add r3, sp, #0x24
	adds r1, r5, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F628 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819F62C
	asrs r0, r0, #0xc
	b _0819F630
	.align 2, 0
_0819F628: .4byte 0xFFFF0000
_0819F62C:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819F630:
	adds r4, r0, #0
	movs r0, #4
	ldrsh r2, [r6, r0]
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819F650
	asrs r0, r0, #0xc
	b _0819F656
_0819F650:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F656:
	adds r1, r4, r0
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F690 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r3, #0
	mov r1, ip
	mov r2, sl
	mov r3, sb
	bl DustManager_Spawn
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F690: .4byte 0xFFFF0000
