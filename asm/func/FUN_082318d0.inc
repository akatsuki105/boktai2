	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x50
	adds r2, r0, #0
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	adds r2, #2
	movs r4, #0
	add r6, sp, #0x40
	add r5, sp, #0x44
	add r7, sp, #0x48
	b _08231900
_082318F4:
	lsls r0, r4, #2
	mov r3, sp
	adds r1, r3, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	adds r4, #1
_08231900:
	adds r0, r2, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _082318F4
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08231938 @ =0xFFFF0000
	ldr r0, [sp, #0x48]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	mov r0, sp
	str r0, [r7, #4]
	mov r0, r8
	adds r1, r7, #0
	bl Script_ExecById
	add sp, #0x50
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08231938: .4byte 0xFFFF0000
