	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823C024
	bl Script_GetValue
	bl FUN_0823bc70
	ldr r0, _0823C028 @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C024:
	pop {r0}
	bx r0
	.align 2, 0
_0823C028: .4byte gCamera
