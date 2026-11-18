	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r5, #0
	strb r5, [r0]
	ldr r1, _081B8FD8 @ =0x0000065C
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #0x58
	adds r0, r4, r2
	str r5, [r0]
	adds r1, #0x5a
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	movs r2, #0xda
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _081B8FDC @ =0x000006E2
	adds r4, r4, r2
	strh r5, [r4]
	adds r0, r6, #0
	bl Enemy_StepTowardPathNode
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081B8FE0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081B8FE8
	.align 2, 0
_081B8FD8: .4byte 0x0000065C
_081B8FDC: .4byte 0x000006E2
_081B8FE0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081B8FE8:
	str r0, [r5]
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
	beq _081B900C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081B9014
_081B900C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081B9014:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081B904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081B9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081B9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081B9044
	ldrb r0, [r4, #5]
_081B9044:
	subs r0, #1
	strh r0, [r4, #8]
	b _081B9060
	.align 2, 0
_081B904C: .4byte 0x0000FFFF
_081B9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081B9060
	strh r1, [r4, #8]
_081B9060:
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
	bne _081B9084
	movs r0, #1
	strb r0, [r4, #7]
_081B9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
