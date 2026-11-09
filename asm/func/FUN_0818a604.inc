	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r3, [r0]
	ldr r1, _0818A66C @ =0x0000046D
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A628
	movs r0, #0
	strb r0, [r1]
_0818A628:
	movs r6, #0
	ldr r1, _0818A670 @ =0x00000F36
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r4, sp, #8
	mov sl, r4
	ldr r1, _0818A674 @ =0x0000025D
	add r1, r8
	str r1, [sp, #0xc]
	ldr r2, _0818A678 @ =0x000004B7
	add r2, r8
	mov sb, r2
	ldr r4, _0818A67C @ =0x0000046E
	add r4, r8
	str r4, [sp, #0x10]
	cmp r6, r0
	bge _0818A702
_0818A64C:
	lsls r2, r6, #3
	adds r0, r2, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #2
	ldr r4, _0818A680 @ =0x0000077A
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0818A684
	movs r0, #1
	b _0818A686
	.align 2, 0
_0818A66C: .4byte 0x0000046D
_0818A670: .4byte 0x00000F36
_0818A674: .4byte 0x0000025D
_0818A678: .4byte 0x000004B7
_0818A67C: .4byte 0x0000046E
_0818A680: .4byte 0x0000077A
_0818A684:
	movs r0, #0
_0818A686:
	adds r5, r6, #1
	cmp r0, #0
	beq _0818A6F4
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #5
	ldr r2, _0818A6A8 @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818A6AC
	movs r0, #1
	b _0818A6AE
	.align 2, 0
_0818A6A8: .4byte 0x0000077A
_0818A6AC:
	movs r0, #0
_0818A6AE:
	adds r7, r0, #0
	adds r5, r6, #1
	cmp r7, #0
	bne _0818A6F4
	mov r1, r8
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	adds r4, r4, r6
	lsls r4, r4, #3
	adds r4, r4, r6
	lsls r4, r4, #2
	ldr r3, [sp, #0x14]
	adds r4, r3, r4
	ldr r2, _0818A740 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0818A744 @ =0x0000076E
	adds r0, r4, r1
	strh r7, [r0]
	mov r2, r8
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r4, r4, r2
	strh r0, [r4]
	ldr r3, [sp, #0x14]
_0818A6F4:
	adds r6, r5, #0
	ldr r4, _0818A748 @ =0x00000F36
	adds r0, r3, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0818A64C
_0818A702:
	mov r2, r8
	ldrb r0, [r2, #5]
	add r1, sp, #4
	mov r2, sl
	bl Serpent_GetAnimVariant
	movs r0, #0x9f
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818A74C
	mov r0, sb
	strb r2, [r0]
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	b _0818A7C0
	.align 2, 0
_0818A740: .4byte 0x0000076C
_0818A744: .4byte 0x0000076E
_0818A748: .4byte 0x00000F36
_0818A74C:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, r2
	bne _0818A782
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818A782
	cmp r4, #1
	bne _0818A774
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818A7C6
_0818A774:
	cmp r4, #0
	bne _0818A782
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818A7C6
_0818A782:
	mov r0, sb
	strb r2, [r0]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _0818A794
	movs r3, #6
_0818A794:
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818A7B6
	ldr r0, [r5, #8]
	orrs r0, r6
	b _0818A7BE
_0818A7B6:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818A7BE:
	str r0, [r5, #8]
_0818A7C0:
	movs r0, #0
	ldr r1, [sp, #0x10]
	strb r0, [r1]
_0818A7C6:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
