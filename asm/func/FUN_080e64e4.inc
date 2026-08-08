	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E65FC
	movs r0, #0xc7
	lsls r0, r0, #2
	add r0, r8
	str r0, [sp, #0x28]
	add r6, sp, #0x1c
	movs r1, #0xc5
	lsls r1, r1, #2
	add r1, r8
	str r1, [sp, #0x24]
	movs r0, #2
	mov sl, r0
	ldr r4, _080E660C @ =0xFFFF0000
	ldr r1, _080E6610 @ =0x0000FFFF
	mov sb, r1
	add r7, sp, #0xc
	add r5, sp, #0x14
_080E6524:
	ldr r0, _080E6614 @ =0x030046B8
	ldr r2, [r0]
	adds r2, #1
	ldr r1, _080E6618 @ =0x000003FF
	ands r2, r1
	lsls r0, r2, #1
	ldr r1, _080E661C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0xc]
	ands r3, r4
	orrs r3, r0
	str r3, [sp, #0xc]
	adds r2, #1
	ldr r0, _080E6618 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080E661C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ldr r0, _080E6618 @ =0x000003FF
	ands r2, r0
	ldr r1, _080E6614 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r0, _080E661C @ =0x0203B400
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #0xf
	ands r1, r0
	subs r1, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r7, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r7, #4]
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r2, #5
	orrs r0, r2
	mov r1, sb
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r5, #4]
	ldr r0, [sp, #0x28]
	ldr r3, [r0]
	ldrh r0, [r3]
	ldr r2, [sp, #0x1c]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldrh r1, [r3, #2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #4]
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	str r5, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	movs r1, #3
	adds r2, r6, #0
	add r3, sp, #0xc
	bl FUN_08246728
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r0, sl
	cmp r0, #0
	bge _080E6524
	movs r0, #0xc9
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080E6620 @ =0x000004BE
	add r0, r8
	strh r1, [r0]
_080E65FC:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E660C: .4byte 0xFFFF0000
_080E6610: .4byte 0x0000FFFF
_080E6614: .4byte 0x030046B8
_080E6618: .4byte 0x000003FF
_080E661C: .4byte 0x0203B400
_080E6620: .4byte 0x000004BE
