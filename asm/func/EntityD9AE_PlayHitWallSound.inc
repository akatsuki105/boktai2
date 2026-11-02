	push {lr}
	cmp r0, #5
	bne _080031C0
	ldr r0, _080031BC @ =0x00000151
	bl PlaySound_082406e0
	b _080031C6
	.align 2, 0
_080031BC: .4byte 0x00000151
_080031C0:
	ldr r0, _080031CC @ =0x00000151
	bl PlaySound_082406e0
_080031C6:
	pop {r0}
	bx r0
	.align 2, 0
_080031CC: .4byte 0x00000151
