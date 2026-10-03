	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	bge _08098F58
	bl TextBox_Close
	b _08098F76
_08098F58:
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r4, #0x58]
	bl TextBox_Start
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl TextBox_ShowLine
_08098F76:
	pop {r4, r5}
	pop {r0}
	bx r0
