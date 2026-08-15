	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl Video_GenerateBGMapCore
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
