	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _081FFAEC @ =0x000007D2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r5, #0
	strh r5, [r0]
	cmp r2, #0
	bgt _081FF9A8
	b _081FFB6C
_081FF9A8:
	ldr r0, _081FFAF0 @ =0x000007FC
	adds r0, r7, r0
	str r0, [sp, #0x20]
	adds r1, #0x2c
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	ldr r3, [sp, #0x20]
	ldrh r0, [r3]
	subs r0, r0, r1
	strh r0, [r3]
	movs r5, #0x90
	adds r5, r5, r7
	mov sl, r5
	ldrh r0, [r5]
	subs r0, r0, r2
	strh r0, [r5]
	ldr r1, _081FFAF4 @ =0x00000802
	adds r0, r7, r1
	movs r3, #0xf
	strh r3, [r0]
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r7, r5
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0xf2
	lsls r3, r3, #2
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _081FFAF8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r1, #0x10
	orrs r0, r1
	ldr r5, _081FFAFC @ =0x0000FFFF
	ands r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r3, r7, #0
	adds r3, #0x50
	add r1, sp, #0x10
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl CreateDamageNumber
	ldr r2, _081FFB00 @ =0x000007DE
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081FFA92
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r3, #0xa4
	orrs r0, r3
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	ldr r6, _081FFB04 @ =0x0203B400
	ldr r3, _081FFB08 @ =0x030046B8
	mov sb, r3
	ldr r0, [r3]
	adds r0, #1
	ldr r5, _081FFB0C @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r4, [r1]
	movs r1, #3
	mov r8, r1
	ands r4, r1
	adds r4, #2
	adds r0, #1
	ands r0, r5
	mov r5, sb
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	mov r0, r8
	ands r1, r0
	adds r1, #0x14
	movs r5, #0x97
	lsls r5, r5, #2
	adds r0, r7, r5
	str r4, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #3
	bl EmitSmoke
_081FFA92:
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081FFB14
	movs r0, #0xe1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r5, #0
	mov r3, sl
	strh r5, [r3]
	movs r2, #2
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #6
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	subs r0, #0x14
	movs r5, #1
	strb r5, [r0]
	ldr r1, _081FFB10 @ =FUN_081fea80
	adds r2, r7, #0
	adds r2, #0xa3
	movs r0, #0xa
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	b _081FFB58
	.align 2, 0
_081FFAEC: .4byte 0x000007D2
_081FFAF0: .4byte 0x000007FC
_081FFAF4: .4byte 0x00000802
_081FFAF8: .4byte 0xFFFF0000
_081FFAFC: .4byte 0x0000FFFF
_081FFB00: .4byte 0x000007DE
_081FFB04: .4byte 0x0203B400
_081FFB08: .4byte 0x030046B8
_081FFB0C: .4byte 0x000003FF
_081FFB10: .4byte FUN_081fea80
_081FFB14:
	ldr r1, _081FFB60 @ =0x00000804
	adds r0, r7, r1
	movs r2, #0xf
	strh r2, [r0]
	ldr r0, _081FFB64 @ =0x000001C1
	bl PlaySound_082406e0
	ldr r3, [sp, #0x20]
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #0
	bgt _081FFB6C
	adds r0, r7, #0
	adds r0, #0x98
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	adds r2, r7, #0
	adds r2, #0xa3
	ldrb r0, [r2]
	cmp r0, #9
	bne _081FFB5A
	ldr r1, _081FFB68 @ =FUN_081fd000
	movs r0, #5
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	movs r3, #0
	str r3, [r0]
	adds r0, #0x1d
	movs r5, #1
_081FFB58:
	strb r5, [r0]
_081FFB5A:
	movs r0, #1
	b _081FFB6E
	.align 2, 0
_081FFB60: .4byte 0x00000804
_081FFB64: .4byte 0x000001C1
_081FFB68: .4byte FUN_081fd000
_081FFB6C:
	movs r0, #0
_081FFB6E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
