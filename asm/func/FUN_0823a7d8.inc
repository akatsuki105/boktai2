	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4]
	cmp r5, #0
	beq _0823A7E8
	movs r0, #0
	b _0823A82C
_0823A7E8:
	ldr r6, _0823A834 @ =0x04000208
	strh r5, [r6]
	ldrb r0, [r4, #1]
	lsls r0, r0, #4
	adds r0, #4
	adds r0, r4, r0
	ldr r2, _0823A838 @ =0x04000004
	bl CpuSet
	str r5, [sp]
	ldrb r1, [r4, #1]
	lsls r1, r1, #4
	adds r1, #4
	adds r1, r4, r1
	ldr r2, _0823A83C @ =0x05000004
	mov r0, sp
	bl CpuSet
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #1]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _0823A826
	movs r0, #1
	strb r0, [r4]
_0823A826:
	movs r0, #1
	strh r0, [r6]
	movs r0, #1
_0823A82C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823A834: .4byte 0x04000208
_0823A838: .4byte 0x04000004
_0823A83C: .4byte 0x05000004
