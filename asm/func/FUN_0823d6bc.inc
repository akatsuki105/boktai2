	push {lr}
	ldr r0, _0823D6D4 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	movs r0, #0x70
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	bge _0823D6D8
	movs r1, #0
	b _0823D6E0
	.align 2, 0
_0823D6D4: .4byte gSystemSaveData
_0823D6D8:
	ldr r0, _0823D6EC @ =0x0000270F
	cmp r1, r0
	ble _0823D6E0
	adds r1, r0, #0
_0823D6E0:
	ldr r0, _0823D6F0 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0xc]
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_0823D6EC: .4byte 0x0000270F
_0823D6F0: .4byte gSystemSaveData
