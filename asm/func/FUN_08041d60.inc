	push {r4, r5, lr}
	ldr r0, _08041D88 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041D80
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r4, r0, #0
	cmp r4, #0
	bne _08041D8C
_08041D80:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041DC4
	.align 2, 0
_08041D88: .4byte 0x03002B50
_08041D8C:
	ldr r1, _08041DA8 @ =0x00000217
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	cmp r2, #0
	beq _08041DAC
	cmp r2, #1
	beq _08041DBA
	b _08041DC4
	.align 2, 0
_08041DA8: .4byte 0x00000217
_08041DAC:
	movs r1, #1
	strb r2, [r4, #2]
	strb r2, [r4, #3]
	strb r1, [r4, #4]
	str r2, [r4, #0x14]
	strb r1, [r4, #8]
	b _08041DC4
_08041DBA:
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
	strb r2, [r4, #8]
_08041DC4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
