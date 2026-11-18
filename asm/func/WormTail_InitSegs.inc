	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x10]
	mov r5, sb
	mov r6, sb
	adds r6, #0xe8
	movs r2, #0x2c
	add r2, sb
	mov r8, r2
	mov r7, sb
_081F5482:
	mov r0, r8
	ldr r1, [sp, #4]
	bl Video_GetAuxSprite
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r0, r8
	movs r1, #0xd1
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r4, sp
	ldrb r4, [r4, #0xc]
	strb r4, [r6, #0x14]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	ldr r0, _081F54CC @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	str r1, [r6, #0x10]
	mov r2, sl
	cmp r2, #5
	bne _081F54D0
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	b _081F54E6
	.align 2, 0
_081F54CC: .4byte 0x0000922E
_081F54D0:
	movs r3, #2
	mov r0, sl
	cmp r0, #0
	bgt _081F54DA
	movs r3, #1
_081F54DA:
	movs r2, #0
	str r2, [sp]
	adds r0, r6, #0
	movs r2, #6
	bl AuxAnim_SetAnim
_081F54E6:
	adds r1, r7, #0
	adds r1, #0xe8
	adds r3, r1, #0
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _081F5518
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F5520
_081F5518:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F5520:
	str r0, [r5]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _081F5544
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F554C
_081F5544:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F554C:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _081F5584 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _081F55BC
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F5588
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F557C
	ldrb r0, [r3, #5]
_081F557C:
	subs r0, #1
	strh r0, [r3, #8]
	b _081F5598
	.align 2, 0
_081F5584: .4byte 0x0000FFFF
_081F5588:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F5598
	strh r1, [r3, #8]
_081F5598:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F55BC
	movs r4, #1
	strb r4, [r3, #7]
_081F55BC:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r2, #2
	strb r2, [r6, #0x15]
	mov r4, sb
	str r4, [r6, #0x38]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #0x1e]
	movs r1, #0
	strh r1, [r6, #0x1a]
	ldr r2, [sp, #0x10]
	adds r2, #0x18
	str r2, [sp, #0x10]
	movs r4, #0x92
	lsls r4, r4, #1
	adds r5, r5, r4
	adds r6, r6, r4
	add r8, r4
	adds r7, r7, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #5
	bgt _081F55F4
	b _081F5482
_081F55F4:
	movs r1, #0xdb
	lsls r1, r1, #3
	add r1, sb
	movs r0, #5
	strb r0, [r1]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
