	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r1, #0
	ldrh r0, [r7, #6]
	adds r0, #0x30
	strh r0, [r7, #6]
	cmp r2, #4
	bne _080238D2
	ldrh r0, [r7, #4]
	subs r0, #0xa
	strh r0, [r7, #4]
	ldrh r0, [r7, #8]
	adds r0, #0xa
	strh r0, [r7, #8]
	b _080238E6
_080238D2:
	cmp r2, #0
	bne _080238DC
	ldrh r0, [r7, #4]
	adds r0, #6
	b _080238E4
_080238DC:
	cmp r2, #1
	bne _080238E6
	ldrh r0, [r7, #4]
	adds r0, #0xa
_080238E4:
	strh r0, [r7, #4]
_080238E6:
	ldrh r0, [r7, #2]
	movs r1, #3
	mov sl, r1
	mov r6, sl
	ands r6, r0
	cmp r6, #0
	bne _08023988
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _080239A8 @ =0x0203B400
	mov ip, r2
	ldr r0, _080239AC @ =0x030046B8
	mov sb, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _080239B0 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	add r1, ip
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080239B4 @ =0xFFFF0000
	mov r8, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	add r0, ip
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _080239B8 @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	mov r0, sb
	str r2, [r0]
	lsls r2, r2, #1
	add r2, ip
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
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
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
_08023988:
	ldrh r0, [r7, #2]
	cmp r0, #0xa
	bls _08023996
	adds r0, r7, #0
	movs r1, #2
	bl DuneyrrElem_SetState
_08023996:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080239A8: .4byte 0x0203B400
_080239AC: .4byte 0x030046B8
_080239B0: .4byte 0x000003FF
_080239B4: .4byte 0xFFFF0000
_080239B8: .4byte 0x0000FFFF
