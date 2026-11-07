	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl Crow_SetCurve
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _081448D0 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	add r2, sp, #4
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r1, #0xee
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	movs r2, #0xd6
	lsls r2, r2, #3
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _081448D4 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081448D0: .4byte 0x00000469
_081448D4: .4byte 0x05000002
