	push {lr}
	ldr r0, _08231C9C @ =0x03004698
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl ClearMemory
	ldr r0, _08231CA0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08231CA4 @ =0x00000958
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_08231C9C: .4byte 0x03004698
_08231CA0: .4byte 0x030046A0
_08231CA4: .4byte 0x00000958
