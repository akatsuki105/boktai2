	push {lr}
	cmp r0, #0
	bne _08099B8E
	movs r0, #4
	b _08099B98
_08099B8E:
	cmp r0, #1
	beq _08099B96
	movs r0, #1
	b _08099B98
_08099B96:
	movs r0, #2
_08099B98:
	pop {r1}
	bx r1
