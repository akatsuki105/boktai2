	push {lr}
	sub sp, #0xc
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C0080
	ldr r1, _080C0088 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080C0080:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080C0088: .4byte 0xFFFF0000
