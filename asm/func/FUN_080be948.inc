	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BE9A0 @ =0x0000168E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE998
	ldr r1, _080BE9A4 @ =0x00001894
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BE992
	ldr r1, _080BE9A8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BE9AC @ =0x00001658
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080BE992:
	adds r0, r4, #0
	bl KillEntity
_080BE998:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE9A0: .4byte 0x0000168E
_080BE9A4: .4byte 0x00001894
_080BE9A8: .4byte 0xFFFF0000
_080BE9AC: .4byte 0x00001658
