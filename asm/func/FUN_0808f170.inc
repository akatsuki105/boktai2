	push {r4, lr}
	adds r4, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl TextBox_SetRect
	ldr r0, [r4, #0x54]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldr r1, _0808F1AC @ =0x0000401F
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808F1B0
	adds r0, r4, #0
	bl FUN_0808ede4
	b _0808F1B6
	.align 2, 0
_0808F1AC: .4byte 0x0000401F
_0808F1B0:
	adds r0, r4, #0
	bl FUN_0808ebe8
_0808F1B6:
	pop {r4}
	pop {r0}
	bx r0
