	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	bl FUN_08013d10
	adds r5, r0, #0
	cmp r5, #0
	beq _08013EAC
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08013d28
	cmp r0, #0
	bne _08013EAC
	movs r0, #0x54
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08013EAC
	adds r0, r4, #0
	movs r1, #0x54
	bl ClearMemory
	strh r6, [r4]
	adds r3, r4, #4
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #4]
	str r1, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xc
	movs r2, #0
	mov r1, r8
	cmp r1, #2
	bne _08013E88
	movs r2, #1
_08013E88:
	adds r1, r3, #0
	bl FUN_0801385c
	cmp r0, #0
	blt _08013EA6
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d48
	cmp r0, #0
	blt _08013EA6
	mov r0, r8
	strb r0, [r4, #2]
	movs r0, #0
	b _08013EB0
_08013EA6:
	adds r0, r4, #0
	bl Free
_08013EAC:
	movs r0, #1
	rsbs r0, r0, #0
_08013EB0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
