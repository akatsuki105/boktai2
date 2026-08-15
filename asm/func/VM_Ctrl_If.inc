	push {lr}
	bl VM_Ctrl_If_Internal
	cmp r0, #0
	bne _08232346
	movs r0, #0
	b _0823234E
_08232346:
	movs r1, #0
	movs r2, #0
	bl Script_ExecBlock
_0823234E:
	pop {r1}
	bx r1
	.align 2, 0
