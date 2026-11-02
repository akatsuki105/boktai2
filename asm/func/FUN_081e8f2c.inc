	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081E8F7A
	ldr r0, [r5, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r5, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl Entity081e9cac_GetAnimVariant
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r6, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #2
	bl AuxAnim_RestartAnim
_081E8F7A:
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _081E8F94
	ldr r0, [r5, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x64]
	b _081E8F98
_081E8F94:
	subs r0, r2, #1
	strh r0, [r1]
_081E8F98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
