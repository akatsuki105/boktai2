	push {lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldrh r0, [r2, #0x12]
	cmp r0, #0
	beq _0800809E
	ldrh r0, [r2, #0x10]
	str r0, [sp]
	ldrb r0, [r2, #2]
	cmp r0, #3
	bne _0800807A
	movs r0, #1
	b _08008080
_0800807A:
	cmp r0, #4
	bne _08008082
	movs r0, #0
_08008080:
	str r0, [sp, #4]
_08008082:
	ldr r0, [r2, #0x1c]
	str r0, [sp, #8]
	ldr r1, _080080A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2, #0x12]
	bl VM_ExecByID
_0800809E:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_080080A4: .4byte 0xFFFF0000
