	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r2, #0
	cmp r5, #0
	beq _080093D4
	ldrh r0, [r1]
	str r0, [sp]
	movs r3, #0
	add r4, sp, #0x14
	adds r1, #0x14
	add r2, sp, #4
_080093AE:
	movs r6, #0
	ldrsh r0, [r1, r6]
	stm r2!, {r0}
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _080093AE
	ldr r0, _080093DC @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_080093D4:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080093DC: .4byte 0xFFFF0000
