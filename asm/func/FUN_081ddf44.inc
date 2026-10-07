	push {lr}
	sub sp, #0x14
	adds r1, r0, #0
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081DDF7A
	ldrh r0, [r1, #0x1a]
	str r0, [sp]
	ldrh r0, [r1, #0x38]
	str r0, [sp, #4]
	ldrh r0, [r1, #0x3a]
	str r0, [sp, #8]
	ldr r1, _081DDF80 @ =0xFFFF0000
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
_081DDF7A:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_081DDF80: .4byte 0xFFFF0000
