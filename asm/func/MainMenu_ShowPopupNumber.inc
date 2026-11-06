	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r5, #0
	ble _08092956
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r5, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	str r1, [sp, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r4, r4, r0
	str r4, [sp, #8]
	ldr r0, [sp]
	movs r2, #0
	str r2, [sp, #0xc]
	cmp r0, #0
	bgt _080928BC
	movs r0, #2
	str r0, [sp, #0xc]
	cmp r1, #0
	ble _080928BC
	movs r1, #1
	str r1, [sp, #0xc]
_080928BC:
	ldr r4, [r6]
	ldr r5, [r6, #4]
	movs r0, #3
	ldr r2, [sp, #0xc]
	subs r0, r0, r2
	lsls r0, r0, #2
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08092900 @ =0xFFFF0000
	ands r1, r4
	orrs r1, r0
	asrs r0, r1, #0x10
	subs r0, #4
	lsls r0, r0, #0x10
	ldr r2, _08092904 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r0, #0
	mov sb, r0
	mov r8, sp
	ldr r6, _08092908 @ =0x0000216C
	add r6, sl
	ldr r7, _0809290C @ =0x00002164
	add r7, sl
_080928F0:
	ldr r1, [sp, #0xc]
	cmp sb, r1
	bge _08092910
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _08092944
	.align 2, 0
_08092900: .4byte 0xFFFF0000
_08092904: .4byte 0x0000FFFF
_08092908: .4byte 0x0000216C
_0809290C: .4byte 0x00002164
_08092910:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	mov r0, r8
	ldr r2, [r0]
	adds r2, #0xa
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, sl
	adds r1, #0x60
	movs r3, #1
	bl MainSprite_SetPose
	str r4, [r6, #0x18]
	str r5, [r6, #0x1c]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08092968 @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
_08092944:
	movs r1, #4
	add r8, r1
	adds r6, #0x60
	adds r7, #0x60
	movs r2, #1
	add sb, r2
	mov r0, sb
	cmp r0, #2
	ble _080928F0
_08092956:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092968: .4byte 0xFFFF0000
