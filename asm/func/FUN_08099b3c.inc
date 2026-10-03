	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	bge _08099B4A
	bl TextBox_Close
	b _08099B56
_08099B4A:
	movs r0, #1
	bl TextBox_SetInstant
	adds r0, r4, #0
	bl TextBox_ShowLine
_08099B56:
	pop {r4}
	pop {r0}
	bx r0
