	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r2, #0
	ldr r7, _08136A54 @ =0x00000B3A
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _08136AB4
	movs r7, #1
	mov r8, r7
	mov r5, sp
	add r0, sp, #8
	mov sb, r0
	ldr r1, _08136A58 @ =0x00000674
	adds r4, r3, r1
	ldr r7, _08136A5C @ =0x00000754
	adds r6, r3, r7
_08136A46:
	ldrb r0, [r6, #1]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08136A60
	movs r0, #1
	b _08136A62
	.align 2, 0
_08136A54: .4byte 0x00000B3A
_08136A58: .4byte 0x00000674
_08136A5C: .4byte 0x00000754
_08136A60:
	movs r0, #0
_08136A62:
	cmp r0, #0
	bne _08136A9E
	mov r7, sb
	ldrh r0, [r7]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r7, #4
	ldrsh r1, [r5, r7]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl ArcTan2_8
	strb r0, [r6]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, [sp, #0x14]
	ldr r2, [sp, #0x10]
_08136A9E:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _08136AC4 @ =0x00000B3A
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _08136A46
_08136AB4:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136AC4: .4byte 0x00000B3A
