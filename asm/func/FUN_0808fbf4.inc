	push {lr}
	ldr r2, _0808FC10 @ =0x00004038
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0xc
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1, #0xf]
	bl TextBox_ShowLine
	pop {r0}
	bx r0
	.align 2, 0
_0808FC10: .4byte 0x00004038
