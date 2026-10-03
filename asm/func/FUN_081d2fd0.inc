	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r5, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D306E
	ldr r0, _081D3014 @ =0x03000194
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xd4
	ldr r2, _081D3018 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3060
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D3060
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D302A
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D301C
	movs r0, #1
	b _081D301E
	.align 2, 0
_081D3014: .4byte 0x03000194
_081D3018: .4byte 0x000012B0
_081D301C:
	movs r0, #0
_081D301E:
	cmp r0, #0
	beq _081D3026
	movs r0, #2
	b _081D3030
_081D3026:
	movs r0, #1
	b _081D3030
_081D302A:
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D3030:
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081D3060:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r0, #2
	strb r2, [r0]
_081D306E:
	ldr r6, _081D30F4 @ =0x03000194
	adds r0, r5, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3108
	adds r4, r5, #0
	adds r4, #0xe8
	ldrb r1, [r4, #3]
	adds r0, r1, #1
	strb r0, [r4, #3]
	lsls r1, r1, #0x18
	ldr r0, [r4, #8]
	ldrh r2, [r0, #4]
	ldr r0, _081D30F8 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	blo _081D3108
	adds r0, r4, #0
	bl Map_AdvancePathWalker
	adds r1, r5, #0
	adds r1, #0xfc
	adds r0, r4, #0
	movs r2, #0x10
	movs r3, #0x10
	bl Map_IsPosOutsidePathNode
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3100
	adds r0, r5, #0
	adds r0, #0xb2
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r6]
	adds r2, r5, #0
	adds r2, #0xd4
	ldr r1, _081D30FC @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3108
	adds r3, r5, #0
	adds r3, #0xc4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D3108
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r3]
	bl VM_ExecByID
	b _081D3108
	.align 2, 0
_081D30F0: .4byte 0xFFFF0000
_081D30F4: .4byte 0x03000194
_081D30F8: .4byte 0x00000FFF
_081D30FC: .4byte 0x000012B0
_081D3100:
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D3108:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
