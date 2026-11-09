	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
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
	ldr r7, _0818F8A8 @ =0x00000F36
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _0818F908
	mov r5, sp
	add r7, sp, #8
	mov r8, r7
	ldr r0, _0818F8AC @ =0x00000674
	adds r4, r3, r0
	ldr r1, _0818F8B0 @ =0x00000754
	adds r6, r3, r1
_0818F898:
	movs r1, #1
	ldrh r0, [r6, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _0818F8B4
	movs r0, #1
	b _0818F8B6
	.align 2, 0
_0818F8A8: .4byte 0x00000F36
_0818F8AC: .4byte 0x00000674
_0818F8B0: .4byte 0x00000754
_0818F8B4:
	movs r0, #0
_0818F8B6:
	cmp r0, #0
	bne _0818F8F2
	mov r7, r8
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
_0818F8F2:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _0818F914 @ =0x00000F36
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _0818F898
_0818F908:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F914: .4byte 0x00000F36
