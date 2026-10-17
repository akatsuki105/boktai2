	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _08085CA4 @ =0x03003584
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _08085CA8 @ =0x00000207
	adds r0, r0, r3
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp, #4]
	ldr r4, _08085CAC @ =0x000041E0
	adds r4, r1, r4
	str r4, [sp, #8]
	ldr r1, [sp]
	adds r2, #0x18
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	mov sb, r0
	mov ip, r1
	movs r3, #0
	mov sl, r3
	movs r4, #0x1f
	mov r8, r4
	movs r7, #0x1f
_08085C14:
	ldr r0, [sp, #4]
	ldrh r1, [r0]
	adds r2, r7, #0
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x15
	mov r3, r8
	ands r6, r3
	lsrs r1, r1, #0x1a
	ands r1, r3
	ldr r0, [sp, #8]
	ldrh r4, [r0]
	adds r0, r7, #0
	ands r0, r4
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x15
	ands r5, r3
	lsrs r4, r4, #0x1a
	ands r4, r3
	mov r3, sb
	muls r3, r2, r3
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r3, r0
	asrs r3, r3, #6
	ands r3, r7
	mov r2, sb
	muls r2, r6, r2
	mov r0, ip
	muls r0, r5, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	ands r2, r7
	mov r0, sb
	muls r0, r1, r0
	adds r1, r0, #0
	mov r0, ip
	muls r0, r4, r0
	adds r1, r1, r0
	asrs r1, r1, #6
	ands r1, r7
	mov r4, sl
	lsls r0, r4, #1
	ldr r4, [sp]
	adds r4, #0x20
	adds r4, r4, r0
	lsls r2, r2, #5
	orrs r3, r2
	lsls r1, r1, #0xa
	orrs r3, r1
	strh r3, [r4]
	ldr r0, [sp, #4]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #0xf
	ble _08085C14
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085CA4: .4byte 0x03003584
_08085CA8: .4byte 0x00000207
_08085CAC: .4byte 0x000041E0
