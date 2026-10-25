	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _080C3958 @ =0x03003584
	ldr r2, _080C395C @ =0x085AD0D8
	ldr r5, _080C3960 @ =0x000025BE
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	adds r5, #1
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r7, r1, r0
	cmp r3, #0xf
	ble _080C396C
	ldr r0, _080C3964 @ =0x0000259C
	adds r1, r4, r0
	ldr r2, _080C3968 @ =0x04000008
	adds r0, r7, #0
	bl CpuSet
	b _080C39F2
	.align 2, 0
_080C3958: .4byte 0x03003584
_080C395C: .4byte 0x085AD0D8
_080C3960: .4byte 0x000025BE
_080C3964: .4byte 0x0000259C
_080C3968: .4byte 0x04000008
_080C396C:
	movs r0, #0x10
	subs r0, r0, r3
	mov sb, r0
	mov r8, r3
	movs r1, #0x1f
	mov sl, r1
	ldr r2, _080C3A04 @ =0x0000259C
	adds r2, r2, r4
	mov ip, r2
	movs r3, #0xf
	str r3, [sp, #4]
_080C3982:
	ldr r5, [sp]
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r0, sl
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	mov r5, sl
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sb
	muls r5, r2, r5
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, sb
	muls r2, r6, r2
	mov r0, r8
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, sb
	muls r0, r3, r0
	mov r3, r8
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	mov r5, ip
	strh r0, [r5]
	ldr r0, [sp]
	adds r0, #2
	str r0, [sp]
	adds r7, #2
	movs r1, #2
	add ip, r1
	ldr r2, [sp, #4]
	subs r2, #1
	str r2, [sp, #4]
	cmp r2, #0
	bge _080C3982
_080C39F2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3A04: .4byte 0x0000259C
