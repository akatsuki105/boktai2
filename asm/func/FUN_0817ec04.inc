	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, _0817EC2C @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0817EC30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _0817EC54
	.align 2, 0
_0817EC2C: .4byte 0x000004A4
_0817EC30:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0817EC4E
	cmp r0, #2
	beq _0817EC5C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0817EC5C
_0817EC4E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_0817EC54:
	ldr r1, _0817ECA4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0817EC5C:
	adds r0, r5, #0
	bl FUN_0817ce48
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _0817ECA8 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817ECA4: .4byte 0xFFFFFDFF
_0817ECA8: .4byte 0x000004A4
