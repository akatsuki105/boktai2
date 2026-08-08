	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	cmp r1, #0
	ble _080F894E
	ldr r1, _080F8960 @ =0x000001DD
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r3, #0x80
	movs r6, #0xff
	ands r3, r6
	ldr r0, _080F8964 @ =0x085B0A08
	mov ip, r0
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [sp, #0xc]
	ldr r1, _080F8968 @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0xc]
	ldr r0, _080F896C @ =0x0203B400
	mov sl, r0
	ldr r1, _080F8970 @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	ldr r0, _080F8974 @ =0x000003FF
	mov sb, r0
	ands r2, r0
	str r2, [r1]
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	movs r0, #7
	mov r8, r0
	mov r0, r8
	ands r1, r0
	lsls r1, r1, #0x10
	ldr r5, _080F8978 @ =0x0000FFFF
	adds r0, r5, #0
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0xc]
	ands r3, r6
	lsls r3, r3, #1
	add r3, ip
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ldr r3, _080F8968 @ =0xFFFF0000
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	adds r2, #1
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	ands r0, r1
	adds r0, #3
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	adds r2, #1
	mov r3, sb
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	mov r3, r8
	ands r0, r3
	adds r0, #3
	lsls r0, r0, #0x10
	ands r5, r1
	orrs r5, r0
	str r5, [sp, #0x14]
	adds r2, #1
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	ands r1, r3
	adds r1, #3
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ldr r3, _080F8968 @ =0xFFFF0000
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	adds r2, #1
	mov r0, sb
	ands r2, r0
	ldr r1, _080F8970 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sl
	ldrh r4, [r2]
	movs r0, #1
	ands r4, r0
	adds r4, #2
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
_080F894E:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8960: .4byte 0x000001DD
_080F8964: .4byte 0x085B0A08
_080F8968: .4byte 0xFFFF0000
_080F896C: .4byte 0x0203B400
_080F8970: .4byte 0x030046B8
_080F8974: .4byte 0x000003FF
_080F8978: .4byte 0x0000FFFF
