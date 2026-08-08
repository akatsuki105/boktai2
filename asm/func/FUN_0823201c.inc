	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	bl FUN_08230ab0
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232058
	adds r0, r4, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r3, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r3, r0, #0
	ldr r0, [sp, #4]
	strh r0, [r5, #4]
	ldr r0, [sp, #8]
	strh r0, [r5, #6]
	b _08232062
_08232058:
	adds r3, r4, #4
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_08232062:
	adds r0, r3, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
