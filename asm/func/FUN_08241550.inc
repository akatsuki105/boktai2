	push {lr}
	bl Script_GetValue
	ldr r1, _0824156C @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	ldr r1, _08241570 @ =0x03004860
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0824156C: .4byte 0x030046A0
_08241570: .4byte 0x03004860
