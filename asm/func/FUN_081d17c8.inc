	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r7, r2, #0
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D1806
	adds r0, r7, #0
	adds r0, #0xba
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	cmp r1, #1
	bne _081D17F8
	movs r1, #4
	b _081D17FE
_081D17F8:
	cmp r1, #0
	bne _081D1820
	movs r1, #0x17
_081D17FE:
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D1820
_081D1806:
	adds r4, r7, #0
	adds r4, #0xc7
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D1816
	ldr r0, _081D181C @ =0x0000014D
	bl PlaySound_082406e0
_081D1816:
	movs r0, #0xa
	strb r0, [r4]
	b _081D18FA
	.align 2, 0
_081D181C: .4byte 0x0000014D
_081D1820:
	adds r1, r7, #0
	adds r1, #0xa4
	ldrh r4, [r1]
	cmp r4, #0
	bne _081D18FA
	adds r0, r7, #0
	adds r0, #0xbd
	movs r2, #3
	strb r2, [r0]
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_081d11b8
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne _081D18E4
	add r6, sp, #0x10
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	ldr r2, _081D190C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r6, #2]
	ldr r5, _081D1910 @ =0x0203B400
	ldr r2, _081D1914 @ =0x030046B8
	mov sl, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r4, _081D1918 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov r8, r1
	mov r1, r8
	ands r0, r1
	adds r0, #0xf
	ldr r1, _081D191C @ =0xFFFF0000
	mov sb, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D1920 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	mov r0, r8
	ands r1, r0
	adds r1, #0xf
	mov r8, r1
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r1, sb
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, r7, #0
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r3, r6, #0
	bl FUN_08014730
_081D18E4:
	adds r0, r7, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D18FA
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_081d0e74
_081D18FA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D190C: .4byte 0x05000002
_081D1910: .4byte 0x0203B400
_081D1914: .4byte 0x030046B8
_081D1918: .4byte 0x000003FF
_081D191C: .4byte 0xFFFF0000
_081D1920: .4byte 0x0000FFFF
