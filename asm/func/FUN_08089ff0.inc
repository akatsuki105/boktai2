	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x64]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bne _0808A00C
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _0808A00C
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4, #0x68]
_0808A00C:
	ldr r0, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
