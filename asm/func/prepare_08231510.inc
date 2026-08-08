	push {r4, r5, r6, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0823154C @ =gVM
	ldr r0, [r1, #8]
	subs r0, #4
	ldr r2, [r0]
	add r4, sp, #4
	adds r6, r1, #0
_08231524:
	adds r0, r2, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r1, [sp]
	cmp r1, #0
	beq _08231550
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x50
	bne _08231524
	asrs r0, r1, #0x10
	cmp r0, r5
	bne _08231524
	ldr r0, [sp, #4]
	str r0, [r6]
	b _08231552
	.align 2, 0
_0823154C: .4byte gVM
_08231550:
	movs r0, #0
_08231552:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
