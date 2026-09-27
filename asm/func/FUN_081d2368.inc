	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xb8
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081D2388
	subs r0, r2, #1
	b _081D2644
_081D2388:
	adds r0, r5, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsrs r6, r0, #6
	cmp r6, #1
	beq _081D23C8
	cmp r6, #1
	bgt _081D239E
	cmp r6, #0
	beq _081D23A8
	b _081D2646
_081D239E:
	cmp r6, #2
	beq _081D23E0
	cmp r6, #3
	beq _081D2410
	b _081D2646
_081D23A8:
	add r0, sp, #0x38
	ldr r1, _081D23C0 @ =0x0000FF40
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r6, [r0, #4]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	adds r1, r0, #0
	ldr r0, _081D23C4 @ =0x0000FF80
	strh r0, [r1, #0xc]
	movs r0, #0x3e
	b _081D242C
	.align 2, 0
_081D23C0: .4byte 0x0000FF40
_081D23C4: .4byte 0x0000FF80
_081D23C8:
	add r0, sp, #0x38
	ldr r2, _081D23D8 @ =0x0000FFC0
	strh r2, [r0]
	ldr r3, _081D23DC @ =0x0000FF40
	strh r3, [r0, #2]
	strh r2, [r0, #4]
	adds r1, r0, #0
	b _081D2420
	.align 2, 0
_081D23D8: .4byte 0x0000FFC0
_081D23DC: .4byte 0x0000FF40
_081D23E0:
	add r0, sp, #0x38
	ldr r3, _081D2404 @ =0x0000FF7C
	strh r3, [r0]
	ldr r2, _081D2408 @ =0x0000FF40
	strh r2, [r0, #2]
	adds r1, r0, #0
	ldr r0, _081D240C @ =0x0000FFE0
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r3, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x3e
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x18
	b _081D2434
	.align 2, 0
_081D2404: .4byte 0x0000FF7C
_081D2408: .4byte 0x0000FF40
_081D240C: .4byte 0x0000FFE0
_081D2410:
	add r1, sp, #0x38
	ldr r0, _081D2448 @ =0x0000FFC0
	strh r0, [r1]
	adds r0, r1, #0
	ldr r3, _081D244C @ =0x0000FF40
	strh r3, [r0, #2]
	ldr r2, _081D2450 @ =0x0000FFE0
	strh r2, [r0, #4]
_081D2420:
	ldr r0, _081D2454 @ =0x0000FF24
	strh r0, [r1, #8]
	adds r0, r1, #0
	strh r3, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x40
_081D242C:
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x20
_081D2434:
	mov sb, r3
	adds r0, r5, #0
	adds r0, #0xe7
	ldrb r7, [r0]
	cmp r7, #0
	beq _081D2458
	cmp r7, #3
	bne _081D2446
	b _081D254A
_081D2446:
	b _081D2646
	.align 2, 0
_081D2448: .4byte 0x0000FFC0
_081D244C: .4byte 0x0000FF40
_081D2450: .4byte 0x0000FFE0
_081D2454: .4byte 0x0000FF24
_081D2458:
	movs r0, #0xca
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D24EC
	adds r1, r5, #0
	adds r1, #0xfc
	add r0, sp, #0x38
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D24E4 @ =0xFFFF0000
	ldr r2, [sp, #0x48]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x48]
	adds r4, r5, #0
	adds r4, #0xfe
	add r0, sp, #0x38
	ldrh r1, [r0, #2]
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081D24E8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	add r0, sp, #0x38
	ldrh r2, [r0, #4]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x48
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	b _081D263E
	.align 2, 0
_081D24E4: .4byte 0xFFFF0000
_081D24E8: .4byte 0x0000FFFF
_081D24EC:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r5, r3
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	mov r0, r8
	strh r7, [r0]
	b _081D263E
_081D254A:
	movs r1, #0xca
	adds r1, r1, r5
	mov r8, r1
	ldrh r3, [r1]
	cmp r3, #0
	bne _081D25D0
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #2]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _081D25C8 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D25CC @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	movs r0, #1
	mov r3, r8
	strh r0, [r3]
	b _081D263E
	.align 2, 0
_081D25C8: .4byte 0x0000F422
_081D25CC: .4byte 0x0000121B
_081D25D0:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	movs r4, #0
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r1, _081D2658 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D265C @ =0x0000121B
	str r1, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	mov r3, r8
	strh r4, [r3]
_081D263E:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #4
_081D2644:
	strh r0, [r1]
_081D2646:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2658: .4byte 0x0000F422
_081D265C: .4byte 0x0000121B
