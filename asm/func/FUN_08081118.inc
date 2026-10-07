	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _08081148 @ =0x000009C4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08081142
	ldr r1, _0808114C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	str r3, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_08081142:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08081148: .4byte 0x000009C4
_0808114C: .4byte 0xFFFF0000
