	push {r4, lr}
	ldr r2, _0823AE48 @ =0x03004798
	movs r1, #0
	str r1, [r2]
	str r1, [r0, #0x1c]
	bl FUN_0823a9c4
	bl VM_ClearScratchpad_Proxy
	ldr r0, _0823AE4C @ =0x03002B28
	ldrh r4, [r0]
	cmp r4, #0
	beq _0823AE3A
	adds r0, r4, #0
	movs r1, #0
	bl Script_ExecById
	cmp r4, #0
	bne _0823AE3E
_0823AE3A:
	bl FUN_08231ba8
_0823AE3E:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823AE48: .4byte 0x03004798
_0823AE4C: .4byte 0x03002B28
