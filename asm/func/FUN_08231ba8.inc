	push {lr}
	sub sp, #4
	ldr r0, _08231BC4 @ =0x03000748
	ldr r0, [r0, #0xc]
	mov r1, sp
	bl ReadScriptOffset
	ldr r1, _08231BC8 @ =0x085B01C8
	bl FUN_08231b58
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08231BC4: .4byte 0x03000748
_08231BC8: .4byte 0x085B01C8
