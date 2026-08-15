	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823C048
	bl Script_GetValue
	bl FUN_0823bca8
	ldr r0, _0823C04C @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C048:
	pop {r0}
	bx r0
	.align 2, 0
_0823C04C: .4byte gCamera
