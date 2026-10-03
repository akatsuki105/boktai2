	push {r4, lr}
	sub sp, #0xc
	adds r2, r0, #0
	ldr r1, _080C004C @ =0x000005AC
	adds r0, r2, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080C0044
	ldr r1, _080C0050 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r4, sp
	str r4, [r1, #4]
	ldr r4, _080C0054 @ =0x0000057E
	adds r0, r2, r4
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r3, #0
	bl VM_ExecByID
_080C0044:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C004C: .4byte 0x000005AC
_080C0050: .4byte 0xFFFF0000
_080C0054: .4byte 0x0000057E
