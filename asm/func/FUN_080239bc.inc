	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r1, #0
	cmp r2, #4
	bne _080239E0
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	subs r0, #0xa
	strh r0, [r7, #4]
	ldrh r0, [r7, #8]
	adds r0, #0xa
	strh r0, [r7, #8]
	b _08023A00
_080239E0:
	cmp r2, #0
	bne _080239F0
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	adds r0, #6
	b _080239FE
_080239F0:
	cmp r2, #1
	bne _08023A00
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	adds r0, #0xa
_080239FE:
	strh r0, [r7, #4]
_08023A00:
	ldrh r0, [r7, #2]
	movs r1, #7
	mov ip, r1
	mov r2, ip
	ands r2, r0
	mov ip, r2
	cmp r2, #0
	bne _08023AA4
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r6, _08023ABC @ =0x0203B400
	ldr r0, _08023AC0 @ =0x030046B8
	mov sb, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _08023AC4 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	adds r1, r1, r6
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08023AC8 @ =0xFFFF0000
	mov r8, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08023ACC @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	mov r0, sb
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r6
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
	mov r0, ip
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
_08023AA4:
	ldrh r0, [r7, #2]
	adds r2, r0, #0
	cmp r2, #0x13
	bhi _08023AD0
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08023AE0
	ldr r0, [r7, #0x14]
	movs r1, #1
	orrs r0, r1
	b _08023AE8
	.align 2, 0
_08023ABC: .4byte 0x0203B400
_08023AC0: .4byte 0x030046B8
_08023AC4: .4byte 0x000003FF
_08023AC8: .4byte 0xFFFF0000
_08023ACC: .4byte 0x0000FFFF
_08023AD0:
	movs r1, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08023AE0
	ldr r0, [r7, #0x14]
	orrs r0, r1
	b _08023AE8
_08023AE0:
	ldr r0, [r7, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08023AE8:
	str r0, [r7, #0x14]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _08023B02
	adds r0, r7, #0
	movs r1, #3
	bl DuneyrrElem_SetState
	ldr r0, [r7, #0x14]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x14]
_08023B02:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
