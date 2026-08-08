	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _080F8548 @ =0xFEFFFFFF
	ldr r2, [r1]
	ands r2, r0
	str r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xe
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _080F8544
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _080F8544
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	cmp r0, #0
	bne _080F8544
	ldr r1, _080F854C @ =0x0000A13F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F8544
	movs r0, #0x80
	lsls r0, r0, #0x14
	ands r3, r0
	cmp r3, #0
	bne _080F8544
	ldr r6, _080F8550 @ =0x000004BE
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080F8544
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080F8554
_080F8544:
	movs r0, #1
	b _080F8556
	.align 2, 0
_080F8548: .4byte 0xFEFFFFFF
_080F854C: .4byte 0x0000A13F
_080F8550: .4byte 0x000004BE
_080F8554:
	movs r0, #0
_080F8556:
	adds r7, r0, #0
	cmp r7, #0
	beq _080F855E
	b _080F8830
_080F855E:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r7, [r0]
	movs r3, #0
	mov sb, r3
	movs r4, #8
	ldrsh r0, [r5, r4]
	movs r6, #0xc
	ldrsh r1, [r5, r6]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	ldr r4, _080F86D0 @ =0x0000021D
	adds r3, r5, r4
	ldrb r3, [r3]
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov sl, r6
	cmp r0, #0
	bge _080F8594
	b _080F8830
_080F8594:
	ldr r0, _080F86D4 @ =0x00000202
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080F862E
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _080F86D8 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F86DC @ =0x0000021E
	adds r0, r5, r2
	movs r4, #0
	mov r6, sb
	strh r6, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r6, [r0]
	subs r2, #0x1c
	adds r0, r5, r2
	strh r6, [r0]
	movs r0, #0xb4
	strh r0, [r3]
	ldr r3, _080F86E0 @ =0x000001DF
	adds r0, r5, r3
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r6, #0xb9
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r2, [r0]
	movs r1, #9
	ldr r3, _080F86E4 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _080F86E8 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r6, sb
	strh r6, [r0]
	movs r1, #0xb
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r6, _080F86EC @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _080F86F0 @ =0x00000484
	adds r0, r5, r4
	mov r6, sb
	str r6, [r0]
	ldr r1, _080F86F4 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	mov sb, r3
_080F862E:
	movs r6, #0x80
	lsls r6, r6, #5
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	ands r0, r6
	mov r8, r1
	cmp r0, #0
	beq _080F8658
	movs r3, #0x97
	lsls r3, r3, #3
	adds r4, r5, r3
	ldr r0, [r4]
	bl FUN_080f8e3c
	mov r1, r8
	ldrh r0, [r1]
	bics r0, r6
	strh r0, [r1]
	str r7, [r4]
_080F8658:
	mov r2, sl
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_080e8f20
	movs r1, #0x80
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080F8692
	ldr r4, _080F86F8 @ =0x0000024E
	adds r2, r5, r4
	movs r6, #0x96
	lsls r6, r6, #1
	adds r0, r6, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080F8692
	strh r1, [r2]
_080F8692:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F86CA
	cmp r1, #0
	blt _080F86CA
	ldr r0, _080F86FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F86CA
	ldr r0, _080F8700 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F8704
_080F86CA:
	movs r4, #0
	b _080F8712
	.align 2, 0
_080F86D0: .4byte 0x0000021D
_080F86D4: .4byte 0x00000202
_080F86D8: .4byte 0xFFFEBE3F
_080F86DC: .4byte 0x0000021E
_080F86E0: .4byte 0x000001DF
_080F86E4: .4byte 0x0000046D
_080F86E8: .4byte 0x0000046B
_080F86EC: .4byte 0x00000469
_080F86F0: .4byte 0x00000484
_080F86F4: .4byte 0x0000046C
_080F86F8: .4byte 0x0000024E
_080F86FC: .4byte 0x030046A8
_080F8700: .4byte 0x030046AC
_080F8704:
	ldr r0, _080F8724 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F8712:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F8728
	adds r0, #4
	b _080F8734
	.align 2, 0
_080F8724: .4byte 0x030046A4
_080F8728:
	ldr r0, _080F8748 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F8734:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F874C
	cmp r2, #2
	beq _080F8750
	b _080F8754
	.align 2, 0
_080F8748: .4byte 0x030046A4
_080F874C:
	ldrb r0, [r6, #4]
	b _080F8752
_080F8750:
	ldrb r0, [r6]
_080F8752:
	subs r1, r1, r0
_080F8754:
	movs r3, #0
	strh r1, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r2, r5, r6
	ldr r1, [r2]
	ldrh r0, [r5, #0xa]
	strh r0, [r1, #2]
	ldr r0, [r2]
	strh r3, [r0, #6]
	ldr r1, _080F8794 @ =0x000004A4
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r2, #0x81
	lsls r2, r2, #2
	adds r4, r5, r2
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F879C
	ldr r0, _080F8798 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080F87C6
	.align 2, 0
_080F8794: .4byte 0x000004A4
_080F8798: .4byte 0xFFFFFDFF
_080F879C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F87BC
	cmp r0, #2
	beq _080F87B8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F87B8:
	movs r0, #1
	b _080F87C8
_080F87BC:
	ldr r0, _080F87DC @ =0xFFFFFDFF
	mov r4, r8
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_080F87C6:
	movs r0, #0
_080F87C8:
	cmp r0, #0
	bne _080F87E4
	ldr r6, _080F87E0 @ =0x000005C4
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #1
	b _080F8832
	.align 2, 0
_080F87DC: .4byte 0xFFFFFDFF
_080F87E0: .4byte 0x000005C4
_080F87E4:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _080F882C @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x81
	lsls r6, r6, #2
	adds r1, r5, r6
	adds r0, r5, #0
	bl FUN_080e7150
	mov r0, sb
	cmp r0, #0
	beq _080F8830
	movs r0, #1
	b _080F8832
	.align 2, 0
_080F882C: .4byte 0x00000482
_080F8830:
	movs r0, #0
_080F8832:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
