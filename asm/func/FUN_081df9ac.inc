	push {r4, lr}
	sub sp, #0x20
	adds r2, r0, #0
	ldr r0, _081DF9FC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	beq _081DF9F2
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	movs r4, #2
	ldrsh r0, [r2, r4]
	str r0, [sp, #4]
	movs r4, #4
	ldrsh r0, [r2, r4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r1, _081DFA00 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #6
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	bl VM_ExecByID
_081DF9F2:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DF9FC: .4byte 0x03002C68
_081DFA00: .4byte 0xFFFF0000
