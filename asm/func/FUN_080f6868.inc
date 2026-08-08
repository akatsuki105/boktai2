	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	ldr r1, _080F6944 @ =0x000001DF
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	beq _080F687A
	b _080F6AE4
_080F687A:
	ldr r2, _080F6948 @ =0x0000049C
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080F688A
	b _080F6AE4
_080F688A:
	movs r0, #0x80
	lsls r0, r0, #6
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F689E
	b _080F6AE4
_080F689E:
	movs r0, #0x10
	orrs r0, r1
	ldr r1, _080F694C @ =0xFFFF5FF8
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r3, r4, r1
	ldr r0, _080F6950 @ =0xFFFFF634
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _080F6954 @ =0xFFFFBFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F6958 @ =0x00000316
	adds r6, r4, r2
	ldrb r0, [r6]
	cmp r0, #3
	bhi _080F6918
	movs r0, #0x14
	str r0, [sp]
	subs r0, #0x15
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0xa
	bl FUN_080e6408
	movs r3, #0x8c
	lsls r3, r3, #3
	adds r2, r4, r3
	ldrh r0, [r2]
	lsls r0, r0, #1
	subs r3, #8
	adds r1, r4, r3
	adds r1, r1, r0
	movs r0, #0x91
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r0, _080F695C @ =0x00000462
	adds r3, r4, r0
	adds r0, r5, #0
	ldrh r1, [r2]
	lsls r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_080F6918:
	adds r2, r5, #0
	ldrb r6, [r6]
	lsls r2, r6
	ldr r3, _080F6960 @ =0x0000048A
	adds r0, r4, r3
	strh r2, [r0]
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r1, r4, r5
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	ldr r0, _080F6964 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F6968
	movs r0, #1
	b _080F696A
	.align 2, 0
_080F6944: .4byte 0x000001DF
_080F6948: .4byte 0x0000049C
_080F694C: .4byte 0xFFFF5FF8
_080F6950: .4byte 0xFFFFF634
_080F6954: .4byte 0xFFFFBFFF
_080F6958: .4byte 0x00000316
_080F695C: .4byte 0x00000462
_080F6960: .4byte 0x0000048A
_080F6964: .4byte 0x030047A4
_080F6968:
	movs r0, #0
_080F696A:
	cmp r0, #0
	beq _080F69D8
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080F69D8
	cmp r2, #0
	beq _080F69D8
	ldr r0, _080F6990 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080F6994
	movs r0, #1
	rsbs r0, r0, #0
	b _080F6998
	.align 2, 0
_080F6990: .4byte 0x03002C68
_080F6994:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080F6998:
	cmp r0, #1
	beq _080F69BA
	cmp r0, #1
	bgt _080F69A6
	cmp r0, #0
	beq _080F69B0
	b _080F69D8
_080F69A6:
	cmp r0, #2
	beq _080F69C4
	cmp r0, #3
	beq _080F69CE
	b _080F69D8
_080F69B0:
	ldr r0, [r1]
	cmp r0, #1
	beq _080F69D8
	movs r0, #0
	b _080F69DA
_080F69BA:
	ldr r0, [r1]
	cmp r0, #2
	beq _080F69D8
	movs r0, #0
	b _080F69DA
_080F69C4:
	ldr r0, [r1]
	cmp r0, #4
	beq _080F69D8
	movs r0, #0
	b _080F69DA
_080F69CE:
	ldr r0, [r1]
	cmp r0, #8
	beq _080F69D8
	movs r0, #0
	b _080F69DA
_080F69D8:
	movs r0, #1
_080F69DA:
	cmp r0, #0
	beq _080F6A3E
	ldrh r0, [r4]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	adds r3, #0xd0
	adds r2, r4, r3
	ldrh r2, [r2]
	ldr r5, _080F6A84 @ =0x0000025A
	adds r3, r4, r5
	ldrh r3, [r3]
	movs r6, #1
	str r6, [sp]
	bl FUN_0809c344
	add r5, sp, #0xc
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _080F6A88 @ =0x05000002
	bl CpuSet
	ldr r0, _080F6A8C @ =0x0000048A
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _080F6A2A
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080F6A3E
_080F6A2A:
	adds r0, r4, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r4, #0
	adds r3, #8
	str r5, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080F6A3E:
	adds r1, r4, #0
	adds r1, #0x9c
	ldr r2, _080F6A90 @ =0x000004B6
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r2, #1
	eors r2, r0
	ldr r3, _080F6A94 @ =0x000004B4
	adds r0, r4, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b490
	ldr r5, _080F6A98 @ =0x00000464
	adds r1, r4, r5
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _080F6A9C @ =0x0000047E
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _080F6AA0 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F6AA4
	ldr r0, [r4, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080F6AB0
	.align 2, 0
_080F6A84: .4byte 0x0000025A
_080F6A88: .4byte 0x05000002
_080F6A8C: .4byte 0x0000048A
_080F6A90: .4byte 0x000004B6
_080F6A94: .4byte 0x000004B4
_080F6A98: .4byte 0x00000464
_080F6A9C: .4byte 0x0000047E
_080F6AA0: .4byte 0x0000025D
_080F6AA4:
	ldr r2, [r4, #0x44]
	ldr r0, _080F6AD4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080F6AB0:
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _080F6AD8 @ =0x00000494
	adds r1, r4, r5
	ldr r0, _080F6ADC @ =0x00001770
	strh r0, [r1]
	ldr r0, _080F6AE0 @ =0x00000121
	bl PlaySound_082406e0
	movs r0, #1
	b _080F6AE6
	.align 2, 0
_080F6AD4: .4byte 0x03003584
_080F6AD8: .4byte 0x00000494
_080F6ADC: .4byte 0x00001770
_080F6AE0: .4byte 0x00000121
_080F6AE4:
	movs r0, #0
_080F6AE6:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
