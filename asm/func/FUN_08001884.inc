	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x20]
	ldr r1, [sp, #0x24]
	lsrs r5, r5, #1
	movs r0, #0x20
	subs r0, r0, r5
	mov sb, r0
	subs r1, r1, r3
	cmp r1, #0
	beq _0800192E
	cmp r5, #0x1f
	bls _080018CC
	lsls r0, r3, #1
	adds r3, r2, r0
	adds r4, r4, r0
	lsls r1, r1, #1
	cmp r1, #0
	bge _080018B8
	adds r1, #3
_080018B8:
	lsls r2, r1, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r3, #0
	adds r1, r4, #0
	bl CpuSet
	b _0800192E
_080018CC:
	lsls r0, r3, #1
	adds r6, r6, r0
	mov r8, r6
	adds r2, r2, r0
	mov ip, r2
	adds r7, r4, r0
	cmp r1, #0
	ble _0800192E
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	adds r6, r1, #0
_080018E4:
	mov r1, r8
	ldrh r0, [r1]
	ldr r3, _0800193C @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	mov r2, ip
	ldrh r1, [r2]
	adds r0, r1, #0
	ldr r2, _0800193C @ =0x00007C1F
	ands r0, r2
	adds r2, r0, #0
	muls r2, r5, r2
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, _08001940 @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	muls r1, r5, r1
	mov r0, sb
	muls r0, r4, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	strh r2, [r7]
	movs r1, #2
	add r8, r1
	add ip, r1
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _080018E4
_0800192E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800193C: .4byte 0x00007C1F
_08001940: .4byte 0x000F83E0
