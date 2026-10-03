	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _080949AC @ =0x0000F001
	adds r5, r0, #0
_08094990:
	adds r1, r4, #0
	adds r1, #0xe
	movs r0, #0
	movs r2, #8
	bl FUN_0808a420
	strh r5, [r0]
	adds r4, #1
	cmp r4, #2
	ble _08094990
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080949AC: .4byte 0x0000F001
