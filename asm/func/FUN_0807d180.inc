	push {lr}
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	bne _0807D190
	movs r0, #0
	b _0807D194
_0807D190:
	bl Script_GetValue
_0807D194:
	pop {r1}
	bx r1
