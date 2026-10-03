	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _0808C520
	ldr r0, _0808C544 @ =0x00000107
	bl PlaySound_082406e0
_0808C520:
	bl FUN_08049e5c
	adds r0, r4, #0
	bl TextBox_Start
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl TextBox_ShowLine
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C544: .4byte 0x00000107
