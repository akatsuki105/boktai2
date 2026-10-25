	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _080C5694
	movs r0, #0x8b
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080C5694:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
	ldrh r0, [r5, #4]
	movs r1, #0x20
	subs r1, r1, r0
	movs r2, #0x16
	muls r1, r2, r1
	adds r1, #0x60
	str r1, [sp, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080C56D2
	movs r2, #1
	adds r1, r5, #0
	adds r1, #8
	movs r7, #0xd
_080C56BE:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C56BE
	movs r0, #0
	strb r0, [r5, #1]
	b _080C5818
_080C56D2:
	movs r2, #0xff
	mov sb, r2
	movs r4, #0x97
	lsls r4, r4, #3
	adds r4, r4, r5
	mov sl, r4
	movs r6, #0x56
	adds r6, r6, r5
	mov ip, r6
	adds r0, r5, #0
	adds r0, #0x52
	str r0, [sp, #0x14]
	movs r1, #0x50
	adds r1, r1, r5
	mov r8, r1
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C56F6:
	mov r2, r8
	ldrh r0, [r2]
	ldr r4, _080C5734 @ =0xFFFFFD44
	adds r0, r0, r4
	ldr r6, [sp, #4]
	adds r0, r6, r0
	str r0, [sp, #0x18]
	cmp r0, #0x5f
	ble _080C57FA
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrh r0, [r5, #4]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C5738
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r4, [sp, #0x14]
	ldrb r0, [r4]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C574C
	b _080C5750
	.align 2, 0
_080C5734: .4byte 0xFFFFFD44
_080C5738:
	mov r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	adds r0, r0, r4
	cmp r0, #0
	blt _080C5750
_080C574C:
	asrs r0, r0, #2
	b _080C5756
_080C5750:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C5756:
	mov r6, ip
	strh r0, [r6]
	adds r0, r3, #0
	adds r0, #0x4e
	ldr r1, [sp]
	cmp r1, #0
	bne _080C5772
	movs r4, #0
	ldrsh r2, [r0, r4]
	str r2, [sp, #8]
	movs r2, #0
	movs r6, #1
	str r6, [sp]
	b _080C5782
_080C5772:
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, [sp, #8]
	ldr r6, _080C57AC @ =0xFFFFFF00
	adds r0, r4, r6
	subs r2, r1, r0
	mov r0, sb
	ands r2, r0
_080C5782:
	ldrb r1, [r5, #3]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r0, r2, r0
	adds r2, r1, r0
	mov r1, sb
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	ldr r4, _080C57B0 @ =gSineTable
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C57B4
	asrs r1, r0, #0xc
	b _080C57BA
	.align 2, 0
_080C57AC: .4byte 0xFFFFFF00
_080C57B0: .4byte gSineTable
_080C57B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C57BA:
	mov r4, sl
	ldr r4, [r4]
	ldrh r6, [r4]
	mov r4, sp
	strh r6, [r4, #0x10]
	adds r1, r6, r1
	strh r1, [r3, #0x1c]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080C57E4 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r4, [sp, #0x18]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C57E8
	asrs r1, r0, #0xc
	b _080C57EE
	.align 2, 0
_080C57E4: .4byte gSineTable
_080C57E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C57EE:
	mov r6, sl
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	b _080C5802
_080C57FA:
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_080C5802:
	movs r0, #0x50
	add ip, r0
	ldr r1, [sp, #0x14]
	adds r1, #0x50
	str r1, [sp, #0x14]
	add r8, r0
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	blt _080C5818
	b _080C56F6
_080C5818:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
