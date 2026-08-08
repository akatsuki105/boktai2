	push {r4, r5, lr}
	sub sp, #0xc
	adds r1, r0, #0
	add r4, sp, #4
	add r5, sp, #8
_082322E6:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
_082322F2:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r5, #0
	bl VM_Step
	adds r1, r0, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _08232308
	ldr r0, [sp, #8]
	b _08232330
_08232308:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
	cmp r1, #0
	beq _0823232E
	ldr r0, [sp]
	asrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, [sp, #4]
	cmp r0, #0x65
	bne _0823232A
	movs r0, #1
	str r0, [sp, #4]
	b _082322F2
_0823232A:
	cmp r0, #0x69
	beq _082322E6
_0823232E:
	movs r0, #0
_08232330:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
  .align 2, 0
