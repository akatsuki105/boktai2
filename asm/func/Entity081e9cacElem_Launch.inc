	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _081E9110 @ =0x030001B4
	ldr r7, [r0]
	cmp r7, #0
	bne _081E90A8
	b _081E91C6
_081E90A8:
	mov r0, r8
	cmp r0, #0
	bne _081E90B0
	b _081E91C6
_081E90B0:
	mov r4, r8
	adds r4, #0x90
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, r8
	ldrb r0, [r1, #2]
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl Entity081e9cac_GetAnimVariant
	mov r6, r8
	adds r6, #0xcc
	ldr r1, [r7, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl AuxAnim_RestartAnim
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9114
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081E911C
	.align 2, 0
_081E9110: .4byte 0x030001B4
_081E9114:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E911C:
	str r0, [r4]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9140
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081E9148
_081E9140:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9148:
	str r0, [r4]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081E9180 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081E91B8
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9184
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081E9178
	ldrb r0, [r6, #5]
_081E9178:
	subs r0, #1
	strh r0, [r6, #8]
	b _081E9194
	.align 2, 0
_081E9180: .4byte 0x0000FFFF
_081E9184:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081E9194
	strh r1, [r6, #8]
_081E9194:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E91B8
	movs r0, #1
	strb r0, [r6, #7]
_081E91B8:
	mov r0, r8
	adds r0, #0xe8
	movs r1, #0
	strh r1, [r0]
	movs r0, #2
	mov r1, r8
	strb r0, [r1]
_081E91C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
