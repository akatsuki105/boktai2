	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
	adds r4, #2
	bl VM_GetControlHandler
	adds r5, r0, #0
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadCtrlNextKeyword
	adds r4, r0, #0
	ldr r0, [sp]
	adds r0, r4, r0
	bl FUN_082314e4
	adds r0, r4, #0
	bl VM_SetPC
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	adds r4, r0, #0
	bl FUN_082314f4
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
