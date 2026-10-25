	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x18
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r6, _080299CC @ =0x0203B400
	ldr r2, _080299D0 @ =0x030046B8
	mov sb, r2
	ldr r1, [r2]
	adds r1, #1
	ldr r5, _080299D4 @ =0x000003FF
	ands r1, r5
	lsls r2, r1, #1
	adds r2, r2, r6
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080299D8 @ =0xFFFF0000
	mov r8, r2
	ldr r4, [sp, #0x10]
	ands r4, r2
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r3, r4, #0x10
	movs r2, #0x3f
	ands r0, r2
	adds r3, r3, r0
	lsls r3, r3, #0x10
	ldr r0, _080299DC @ =0x0000FFFF
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	adds r1, #1
	ands r1, r5
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080299CC: .4byte 0x0203B400
_080299D0: .4byte 0x030046B8
_080299D4: .4byte 0x000003FF
_080299D8: .4byte 0xFFFF0000
_080299DC: .4byte 0x0000FFFF
