	push {r4, lr}
	ldr r4, _0823D2B4 @ =gSystemSaveData
	ldr r0, [r4]
	cmp r0, #0
	beq _0823D2AE
	bl Save_ReadSystemData
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0823D2AE
	movs r1, #5
	ldr r0, _0823D2B8 @ =0x030046A0
	ldr r0, [r0]
	strh r1, [r0, #0x12]
	movs r1, #0xe6
	ldr r0, [r4]
	str r1, [r0, #4]
	strb r2, [r0, #8]
	ldr r0, [r4]
	strb r2, [r0, #9]
	ldr r0, [r4]
	strb r2, [r0, #0xa]
_0823D2AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823D2B4: .4byte gSystemSaveData
_0823D2B8: .4byte 0x030046A0
