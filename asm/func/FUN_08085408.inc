	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _08085444 @ =0x03002BE0
	ldr r5, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #6
	beq _08085448
	movs r3, #0x81
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r2, #1
	movs r1, #6
_08085432:
	ldr r0, [r4]
	orrs r0, r2
	str r0, [r4]
	subs r1, #1
	adds r4, #0x28
	cmp r1, #0
	bge _08085432
	b _08085642
	.align 2, 0
_08085444: .4byte 0x03002BE0
_08085448:
	ldr r7, _08085490 @ =0x000002E6
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r1, _08085494 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r4, [r0, r7]
	ands r3, r2
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r7, _08085498 @ =0x000002E7
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	beq _080854B2
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0808549C
	asrs r0, r0, #0xc
	b _080854A2
	.align 2, 0
_08085490: .4byte 0x000002E6
_08085494: .4byte gSineTable
_08085498: .4byte 0x000002E7
_0808549C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854A2:
	adds r3, r0, #0
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _080854D6
	b _080854DA
_080854B2:
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854C2
	asrs r0, r0, #0xc
	b _080854C8
_080854C2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854C8:
	adds r3, r0, #0
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854DA
_080854D6:
	asrs r0, r0, #0xc
	b _080854E0
_080854DA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854E0:
	adds r5, r0, #0
	mov r0, r8
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08085544 @ =0xFFFF0000
	adds r1, r3, #0
	ldr r2, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x2e]
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r2, _08085548 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x30]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _0808554C
	asrs r1, r0, #0xc
	b _08085552
	.align 2, 0
_08085544: .4byte 0xFFFF0000
_08085548: .4byte 0x0000FFFF
_0808554C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08085552:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085590 @ =0xFFFF0000
	ldr r2, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	ldr r2, _08085594 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08085598
	asrs r1, r0, #0xc
	b _0808559E
	.align 2, 0
_08085590: .4byte 0xFFFF0000
_08085594: .4byte 0x0000FFFF
_08085598:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808559E:
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085654 @ =0xFFFF0000
	ldr r7, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08085658 @ =0x000002E6
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	cmp r0, #4
	bne _080855CE
	movs r7, #0x14
	rsbs r7, r7, #0
	mov sb, r7
_080855CE:
	movs r0, #0x81
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldr r2, [sp, #8]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	ldr r3, [sp]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov sl, r0
	mov r6, ip
	asrs r7, r2, #0x10
	str r7, [sp, #0x10]
	adds r0, r3, #0
	asrs r0, r0, #0x10
	mov r8, r0
	adds r5, r7, #0
_080855F4:
	adds r3, r1, #1
	movs r2, #7
	subs r2, r2, r1
	mov r0, sl
	muls r0, r2, r0
	adds r0, r6, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x18]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x1a]
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r7, [sp, #4]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	muls r0, r2, r0
	adds r1, r1, r0
	asrs r1, r1, #3
	strh r1, [r4, #0x1c]
	mov r0, sb
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r6, ip
	ldr r1, [sp, #0x10]
	adds r5, r5, r1
	adds r1, r3, #0
	adds r4, #0x28
	cmp r1, #6
	ble _080855F4
_08085642:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085654: .4byte 0xFFFF0000
_08085658: .4byte 0x000002E6
