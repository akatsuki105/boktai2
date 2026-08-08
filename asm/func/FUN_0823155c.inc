	push {r4, lr}
	sub sp, #8
	ldr r0, _08231594 @ =gVM
	ldr r1, [r0]
	cmp r1, #0
	beq _08231598
	ldrb r0, [r1]
	cmp r0, #0
	beq _08231598
	add r4, sp, #4
_08231570:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
	ldr r2, [sp]
	cmp r2, #0
	beq _08231598
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x50
	bne _08231570
	ldr r0, _08231594 @ =gVM
	ldr r1, [sp, #4]
	str r1, [r0]
	asrs r0, r2, #0x10
	b _0823159A
	.align 2, 0
_08231594: .4byte gVM
_08231598:
	movs r0, #0
_0823159A:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
