	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081E9648 @ =0x030001B4
	ldr r0, [r0]
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xe6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E95F0
	ldrb r0, [r5, #2]
	mov r2, sp
	adds r2, #5
	add r1, sp, #4
	bl Entity081e9cac_GetAnimVariant
	adds r0, r5, #0
	adds r0, #0xbc
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #3
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r2, r5, #0
	adds r2, #0x80
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	strh r4, [r6]
_081E95F0:
	adds r1, r5, #0
	adds r1, #0x80
	ldrh r0, [r5, #0xc]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0xe]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0x10]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x64
	adds r4, r5, #0
	adds r4, #0xbc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E964C
	ldr r0, [r5, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9654
	.align 2, 0
_081E9648: .4byte 0x030001B4
_081E964C:
	ldr r0, [r5, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9654:
	str r0, [r5, #0x64]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9678
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E9680
_081E9678:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9680:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E96B8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E96FE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E96C2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E96BC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E96D8
	.align 2, 0
_081E96B8: .4byte 0x0000FFFF
_081E96BC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E96D6
_081E96C2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E96D6
	strh r1, [r4, #8]
	movs r2, #1
	b _081E96D8
_081E96D6:
	movs r2, #0
_081E96D8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9700
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9700
_081E96FE:
	movs r2, #0
_081E9700:
	cmp r2, #0
	beq _081E9736
	mov r0, ip
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x90
	bl AuxSprite_Remove
	adds r4, r5, #0
	adds r4, #0xe4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	movs r1, #0xf4
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5]
_081E9736:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
