	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x1c]
	lsrs r4, r4, #1
	subs r2, r0, r3
	cmp r2, #0
	beq _080019C8
	cmp r4, #0x1f
	bls _08001980
	lsls r0, r3, #1
	adds r1, r1, r0
	adds r3, r5, r0
	lsls r0, r2, #1
	cmp r0, #0
	bge _0800196C
	adds r0, #3
_0800196C:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	b _080019C8
_08001980:
	lsls r0, r3, #1
	adds r6, r1, r0
	adds r5, r5, r0
	cmp r2, #0
	ble _080019C8
	ldr r0, _080019D4 @ =0x00007C1F
	mov sb, r0
	ldr r1, _080019D8 @ =0x000F83E0
	mov r8, r1
	adds r3, r2, #0
	movs r0, #0xf8
	lsls r0, r0, #2
	mov ip, r0
	movs r7, #0xf8
	lsls r7, r7, #7
_0800199E:
	ldrh r2, [r6]
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	adds r1, r0, #0
	muls r1, r4, r1
	mov r0, r8
	ands r1, r0
	mov r0, ip
	ands r2, r0
	adds r0, r2, #0
	muls r0, r4, r0
	ands r0, r7
	orrs r1, r0
	lsrs r1, r1, #5
	strh r1, [r5]
	adds r6, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bne _0800199E
_080019C8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080019D4: .4byte 0x00007C1F
_080019D8: .4byte 0x000F83E0
