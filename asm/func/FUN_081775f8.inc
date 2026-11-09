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
	ldr r7, _0817763C @ =0x00001012
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _0817769C
	mov r5, sp
	add r7, sp, #8
	mov r8, r7
	ldr r0, _08177640 @ =0x00000674
	adds r4, r3, r0
	ldr r1, _08177644 @ =0x00000754
	adds r6, r3, r1
_0817762C:
	movs r1, #1
	ldrb r0, [r6, #1]
	ands r0, r1
	cmp r0, #0
	beq _08177648
	movs r0, #1
	b _0817764A
	.align 2, 0
_0817763C: .4byte 0x00001012
_08177640: .4byte 0x00000674
_08177644: .4byte 0x00000754
_08177648:
	movs r0, #0
_0817764A:
	cmp r0, #0
	bne _08177686
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
_08177686:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _081776A8 @ =0x00001012
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _0817762C
_0817769C:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081776A8: .4byte 0x00001012
