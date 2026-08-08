	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _080F8996
	asrs r0, r1, #0x11
	b _080F89A0
_080F8996:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_080F89A0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080F89E4 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0xc]
	ldr r3, _080F89E8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080F89EC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080F89F0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080F89F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r2, #0x14
	ldrsh r0, [r7, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	mov ip, r3
	cmp r0, #0
	blt _080F89F8
	asrs r0, r1, #0x11
	b _080F8A02
	.align 2, 0
_080F89E4: .4byte 0xFFFF0000
_080F89E8: .4byte 0x030046B8
_080F89EC: .4byte 0x000003FF
_080F89F0: .4byte 0x0203B400
_080F89F4: .4byte 0x0000FFFF
_080F89F8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_080F8A02:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080F8AAC @ =0xFFFF0000
	mov r8, r3
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r6, _080F8AB0 @ =0x0203B400
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _080F8AB4 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r5, #3
	ands r1, r5
	adds r1, #0xf
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r3, _080F8AB8 @ =0x0000FFFF
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	mov r1, ip
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r5
	adds r1, #0xf
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	mov r3, ip
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	adds r0, r7, #0
	bl FUN_080f8abc
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #8
	str r5, [sp]
	movs r0, #0x2d
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	adds r0, r4, #0
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8AAC: .4byte 0xFFFF0000
_080F8AB0: .4byte 0x0203B400
_080F8AB4: .4byte 0x000003FF
_080F8AB8: .4byte 0x0000FFFF
