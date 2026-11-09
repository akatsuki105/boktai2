	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081723C4 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081723C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081723CA
	.align 2, 0
_081723C4: .4byte 0x0000046D
_081723C8:
	movs r0, #0
_081723CA:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r6
	mov sl, r4
	movs r7, #0x83
	lsls r7, r7, #2
	adds r7, r6, r7
	str r7, [sp]
	movs r1, #0x85
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	beq _08172448
	movs r0, #0x20
	subs r1, #0x94
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r4, _08172474 @ =0x00001023
	adds r1, r5, r4
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	ldr r1, _08172478 @ =0x00001022
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _08172448
	adds r5, r5, r1
_0817243A:
	adds r0, r6, #0
	bl FUN_08178470
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0817243A
_08172448:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, sl
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [sp]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, r1, r0
	cmp r0, #0
	blt _0817247C
	asrs r0, r0, #2
	b _08172482
	.align 2, 0
_08172474: .4byte 0x00001023
_08172478: .4byte 0x00001022
_0817247C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08172482:
	adds r2, r0, #0
	ldr r4, [sp, #4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r1, r0
	cmp r0, #0
	blt _0817249A
	asrs r0, r0, #2
	b _081724A0
_0817249A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081724A0:
	adds r1, r0, #0
	cmp r2, #0xc8
	ble _081724AA
	movs r2, #0xc8
	b _081724B4
_081724AA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081724B4
	adds r2, r0, #0
_081724B4:
	cmp r1, #0xc8
	ble _081724BC
	movs r1, #0xc8
	b _081724C6
_081724BC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081724C6
	adds r1, r0, #0
_081724C6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r2
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	ldrh r0, [r7]
	adds r0, r0, r2
	strh r0, [r7]
	mov r7, r8
	ldrh r0, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	cmp r2, #0
	bne _081724EC
	cmp r1, #0
	bne _081724EC
	movs r0, #1
	b _081724EE
_081724EC:
	movs r0, #0
_081724EE:
	cmp r0, #0
	beq _08172564
	ldr r1, _08172574 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r4, _08172578 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r7, _0817257C @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r5, [r0]
	movs r2, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08172580 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08172584 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08172588 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r3, [r0]
_08172564:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172574: .4byte 0x0000046B
_08172578: .4byte Enemy_ClearStateBegun
_0817257C: .4byte 0x0000046D
_08172580: .4byte 0x00000469
_08172584: .4byte 0x00000484
_08172588: .4byte 0x0000046C
