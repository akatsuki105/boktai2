	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08001FD8 @ =gEntity4AE5
	ldr r4, [r0]
	cmp r4, #0
	beq _0800200C
	lsls r0, r3, #1
	ldr r3, _08001FDC @ =0x00000634
	adds r5, r4, r3
	adds r3, r5, r0
	movs r6, #0
	strh r1, [r3]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08002004
	ldrb r1, [r4, #0x1a]
	ands r0, r1
	cmp r0, #0
	beq _08001FE4
	mov r6, sp
	adds r6, #2
	mov r0, sp
	adds r1, r6, #0
	bl FUN_0823ce10
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x28]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #2
	beq _08001FC2
	ldrh r0, [r6]
	cmp r0, #2
	bne _08001FC8
_08001FC2:
	adds r0, r4, #0
	bl FUN_080019dc
_08001FC8:
	adds r0, r4, #0
	bl FUN_08001b58
	movs r0, #0
	strb r0, [r4, #0x1d]
	movs r0, #0x40
	strb r0, [r4, #0x1c]
	b _08001FFC
	.align 2, 0
_08001FD8: .4byte gEntity4AE5
_08001FDC: .4byte 0x00000634
_08001FE0: .4byte 0x000092B3
_08001FE4:
	ldrh r1, [r3]
	ldr r0, _08002014 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldr r1, [r4, #0x2c]
	ldr r2, _08002018 @ =0x04000068
	bl CpuSet
	strb r6, [r4, #0x1d]
	strb r6, [r4, #0x1c]
_08001FFC:
	movs r0, #7
	strb r0, [r4, #0x1e]
	movs r0, #4
	strb r0, [r4, #0x1f]
_08002004:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
_0800200C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002014: .4byte 0x000092B3
_08002018: .4byte 0x04000068
